## 0162 · Matriz esparsa

Um streaming guarda a nota (1 a 5) de cada cliente para cada filme: 1 milhão
de clientes, 50 mil filmes. A matriz `int` cheia ocupa 5 × 10¹⁰ posições de 4
bytes: **200 GB**. Cada cliente avalia uns 20 filmes, então mais de 99,9% é
zero.

Uma matriz quase toda de zeros é uma **matriz esparsa** (a rede social, o grafo
grande). A regra: **zero não se guarda**. Só os valores diferentes de zero
ocupam memória; o resto vale 0.

O jeito mais simples é um vetor de **triplas** `(linha, coluna, valor)` em
ordem: serve para gravar em arquivo ou matriz que não muda, pois inserir no
meio empurra todo mundo.

Quando a matriz muda, use a **lista por linha**: um vetor de ponteiros, um por
linha, e em cada uma uma lista encadeada (módulo 11) com as células em ordem
de coluna:

```c
typedef struct Celula {
    int col;
    int valor;           // nunca é 0
    struct Celula *prox; // próxima célula da mesma linha
} Celula;

typedef struct {
    int linhas, colunas, nao_zeros;
    Celula **linha; // linha[i]: a lista da linha i
} Esparsa;
```

Ler `m[i][j]` é percorrer a lista da linha `i` até passar da coluna `j`; se
a célula não aparece, vale 0. Gravar é uma **inserção ordenada** (assunto
0078) com uma regra a mais: gravar 0 numa célula existente a **remove**.

Uma locadora tem 4 clientes (Ana, Bruno, Carla e Davi, linhas 0 a 3) e 8
filmes (colunas 0 a 7). Chegam seis notas e Bruno apaga a dele: das 32
posições, sobram 5 células. A linha de Carla é `NULL`:

{{ideia}}

No TAD (`esparsa.h`, `esparsa.c`), `esp_define` anda na linha com dois
ponteiros, `ant` e `p`, como na lista ordenada:

```c
void esp_define(Esparsa *m, int i, int j, int valor) {
    Celula *ant = NULL;
    Celula *p = m->linha[i];
    while (p != NULL && p->col < j) { // a linha está em ordem de coluna
        ant = p;
        p = p->prox;
    }
    if (p != NULL && p->col == j) { // a célula já existe
        if (valor != 0) {
            p->valor = valor;
            return;
        }
        if (ant == NULL) { // virou zero: sai da lista
            m->linha[i] = p->prox;
        } else {
            ant->prox = p->prox;
        }
        free(p);
        m->nao_zeros--;
        return;
    }
    if (valor == 0) {
        return; // já era zero: nada a guardar
    }
    Celula *nova = aloca(sizeof(Celula)); // entra entre ant e p
    nova->col = j;
    nova->valor = valor;
    nova->prox = p;
    if (ant == NULL) {
        m->linha[i] = nova;
    } else {
        ant->prox = nova;
    }
    m->nao_zeros++;
}
```

(O `esparsa.c` também confere `i` e `j`.) O programa da locadora:

```c
#include <stdio.h>
#include "esparsa.h"

int main(void) {
    Esparsa *notas = esp_cria(4, 8); // 4 clientes x 8 filmes, tudo zero

    esp_define(notas, 0, 6, 5); // Ana deu 5 ao filme 6
    esp_define(notas, 0, 1, 4); // entra antes do 6: a linha fica em ordem
    esp_define(notas, 1, 3, 2);
    esp_define(notas, 3, 7, 1);
    esp_define(notas, 3, 0, 5);
    esp_define(notas, 3, 3, 4);

    printf("Davi deu %d ao filme 3\n", esp_valor(notas, 3, 3));
    printf("Carla deu %d ao filme 5\n", esp_valor(notas, 2, 5));

    esp_define(notas, 1, 3, 0); // Bruno apagou a nota: a célula sai
    printf("Notas guardadas: %d de %d\n", notas->nao_zeros, 4 * 8);
    esp_mostra(notas);

    esp_libera(notas);
    return 0;
}
// Saída:
// Davi deu 4 ao filme 3
// Carla deu 0 ao filme 5
// Notas guardadas: 5 de 32
//   0  4  0  0  0  0  5  0
//   0  0  0  0  0  0  0  0
//   0  0  0  0  0  0  0  0
//   5  0  0  4  0  0  0  1
```

`esp_define` cai em um de quatro casos (trocar, remover, ignorar ou criar). O
verde é Bruno apagando a nota: a coluna 3 existe e o valor novo é 0:

{{fluxograma}}

> [!WARNING]
> Se `esp_define(m, 1, 3, 0)` trocasse o valor, a célula guardaria um 0 e
> `nao_zeros` mentiria. Toda operação que pode gerar zero (gravar, somar,
> subtrair) precisa remover a célula.

> [!TIP]
> Cada `Celula` ocupa 16 bytes em 64 bits, contra 4 do `int` da matriz cheia.
> A conta só compensa quando menos de 1/4 das posições tem valor: no
> streaming, 2 × 10⁷ células dão 320 MB, contra 200 GB.

> [!NOTE]
> **Pergunta para você:** quantas células são visitadas por
> `esp_valor(notas, 3, 5)`? E por `esp_valor(notas, 2, 5)`? O custo depende
> do tamanho da matriz ou das células da linha?

{{pratique}}

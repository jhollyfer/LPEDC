## 0162 · Matriz esparsa

Um serviço de streaming quer guardar a nota (de 1 a 5) que cada cliente deu a
cada filme. São 1 milhão de clientes e 50 mil filmes. Uma matriz `int` cheia,
com uma linha por cliente e uma coluna por filme, ocupa 5 × 10¹⁰ posições de 4
bytes: **200 GB**. Só que cada cliente avalia, em média, uns 20 filmes. Mais de
99,9% dessa matriz é zero.

Uma matriz assim, quase toda de zeros, é uma **matriz esparsa**. Ela aparece em
todo lugar: quem segue quem numa rede social, voos diretos entre aeroportos,
produtos comprados por cliente, as ligações de um grafo grande. A ideia para
guardá-la é simples: **zero não se guarda**. Só os valores diferentes de zero
ocupam memória, e quem não está guardado vale 0.

O jeito mais simples é uma lista de **triplas** `(linha, coluna, valor)`, num
vetor de structs em ordem de linha e coluna. Serve bem para gravar em arquivo ou
para uma matriz que não muda. Mas inserir no meio do vetor obriga a empurrar
todo mundo, como em qualquer vetor ordenado.

Quando a matriz muda o tempo todo, a escolha é a **lista por linha**: um vetor
de ponteiros, um por linha, e em cada linha uma lista encadeada (módulo 11) com
as células daquela linha, em ordem de coluna. Cada célula guarda a coluna, o
valor e o ponteiro para a próxima:

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

Ler `m[i][j]` é percorrer a lista da linha `i` até passar da coluna `j`. Se a
célula não aparecer, a resposta é 0. Gravar é uma **inserção ordenada** (assunto
0078) com uma regra a mais: gravar 0 numa célula que existe **remove** a célula.
Se o zero ficasse guardado, a matriz ia engordando com nada dentro.

Vamos ver na prática. Uma locadora pequena tem 4 clientes (Ana, Bruno, Carla e
Davi, linhas 0 a 3) e 8 filmes (colunas 0 a 7). Chegam seis notas; depois Bruno
apaga a dele. Das 32 posições, sobram 5 células. A linha de Carla nem tem lista:
o ponteiro dela é `NULL`, e a linha inteira vale zero:

{{ideia}}

O TAD fica em `esparsa.h` e `esparsa.c`. O coração dele é `esp_define`, que
anda na linha com dois ponteiros, `ant` e `p`, como na lista ordenada:

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

(A versão do `esparsa.c` também confere se `i` e `j` estão dentro da matriz.)
O programa da locadora só usa a interface:

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

Repara no fluxograma: depois de andar pela linha, `esp_define` cai em um de
quatro casos (trocar, remover, ignorar ou criar). O caminho verde é o de Bruno
apagando a nota: a coluna 3 existe e o valor novo é 0, então a célula sai:

{{fluxograma}}

> [!WARNING]
> Esquecer a regra do zero é o erro clássico. Se `esp_define(m, 1, 3, 0)`
> apenas trocasse o valor, a célula ficaria na lista guardando um 0: `nao_zeros`
> mentiria, e uma matriz que recebe muitas atualizações acabaria cheia de células
> inúteis, gastando mais memória que a matriz cheia. Toda operação que pode gerar
> zero (gravar, somar, subtrair) precisa remover a célula.

> [!TIP]
> **Por dentro do C:** cada `Celula` ocupa 16 bytes numa máquina de 64 bits (4
> da coluna, 4 do valor, 8 do ponteiro), contra 4 bytes de um `int` na matriz
> cheia. Fora isso, o vetor `linha` gasta 8 bytes por linha. A locadora gasta
> 5 × 16 + 4 × 8 = 112 bytes contra 32 × 4 = 128: quase empate, porque a matriz
> é pequena e 16% dela está ocupado. A conta só compensa quando menos de 1/4 das
> posições tem valor. No streaming, 2 × 10⁷ células de 16 bytes dão 320 MB, mais
> 8 MB de ponteiros de linha: de 200 GB para menos de 1 GB.

> [!NOTE]
> **Pergunta para você:** quantas células são visitadas por
> `esp_valor(notas, 3, 5)`? E por `esp_valor(notas, 2, 5)`? O custo de uma
> leitura depende do tamanho da matriz ou de quantas células a linha tem?

{{pratique}}

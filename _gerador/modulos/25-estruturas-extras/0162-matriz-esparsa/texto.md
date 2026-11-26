## 0162 · Matriz esparsa

Um serviço de streaming guarda a nota, de 1 a 5, que cada cliente deu a
cada filme. São 1 milhão de clientes e 50 mil filmes. Numa matriz `int`
cheia, isso dá 5 × 10¹⁰ posições de 4 bytes cada: **200 GB**. O detalhe é
que cada cliente avalia uns 20 filmes, então mais de 99,9% dessas posições
guardam 0. Quase toda a memória vai para registrar que nada aconteceu.

Uma matriz quase toda de zeros se chama **matriz esparsa**, e ela aparece
muito: quem segue quem numa rede social, as ligações de um grafo grande, as
notas do streaming. A regra para guardá-la é uma só: **zero não se guarda**.
Só as posições com valor diferente de zero ocupam memória; qualquer posição
que não está guardada vale 0 (SZWARCFITER; MARKENZON, 2010). É como a lista
de presença que anota só quem faltou: quem não aparece nela estava lá.

O jeito mais simples de seguir a regra é um vetor de **triplas**
`(linha, coluna, valor)`, uma para cada valor não nulo, em ordem de linha e
depois de coluna (CELES; CERQUEIRA; RANGEL, 2004). As notas de Ana e Davi
ficam `(0, 1, 4)`, `(0, 6, 5)`, `(3, 0, 5)`. O vetor de triplas é ótimo
para gravar a matriz num arquivo ou para uma matriz que não muda. Mas ele
sofre com mudança: uma nota nova no meio empurra todas as triplas seguintes
uma casa para a frente, como inserir num vetor ordenado.

Quando a matriz muda o tempo todo, a estrutura certa é a **lista por
linha**: um vetor de ponteiros, um para cada linha, e em cada um uma lista
encadeada (módulo 11) com as células daquela linha, em ordem de coluna
(SZWARCFITER; MARKENZON, 2010). Cada **célula** guarda a coluna, o valor e
o ponteiro para a próxima célula da mesma linha. Uma linha sem nenhum valor
é só um ponteiro `NULL`.

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

Ler `m[i][j]` vira percorrer a lista da linha `i`. Como as células estão em
ordem de coluna, você para assim que encontrar a coluna `j` ou passar dela.
Se a célula não apareceu, o valor é 0. Repare no custo: ele depende de
quantas células a linha tem, não do tamanho da matriz. Ler uma nota do
cliente que avaliou 20 filmes olha no máximo 20 células, por maior que seja
o catálogo.

Gravar `m[i][j] = v` é uma **inserção ordenada** (assunto 0078): ande na
linha com dois ponteiros, o anterior e o atual, até a posição da coluna `j`.
Há uma regra a mais, e ela vem direto do "zero não se guarda". Se a célula
já existe e o valor novo é 0, a célula sai da lista e é liberada
(FEOFILOFF, 2009). Assim, gravar cai em um de quatro casos: trocar o valor
de uma célula que existe, remover a célula quando o valor novo é 0, ignorar
um 0 gravado numa posição que já era 0, ou criar uma célula nova.

Por fim, quando a lista compensa? Cada `Celula` ocupa 16 bytes em 64 bits
(dois `int` e um ponteiro), contra os 4 bytes de um `int` na matriz cheia.
Então a lista só ganha quando menos de 1/4 das posições têm valor. No
streaming, os 2 × 10⁷ valores dão 2 × 10⁷ células de 16 bytes, uns
**320 MB**, contra os 200 GB da matriz cheia.

> [!WARNING]
> Se gravar 0 numa célula existente só trocasse o valor, a célula guardaria
> um 0 e `nao_zeros` mentiria. Toda operação que pode gerar zero (gravar,
> somar, subtrair) precisa remover a célula.

{{exemplo}}

Uma locadora tem 4 clientes (linhas 0 a 3) e 8 filmes (colunas 0 a 7). Chegam
seis notas e Bruno apaga a dele: das 32 posições, sobram 5 células. A linha de
Carla é `NULL`:

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

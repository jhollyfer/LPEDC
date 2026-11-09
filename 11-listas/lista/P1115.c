// Lista · Módulo 11 · Listas
// Exercício P1115 · ★★☆ · Quem lava a louça (Josefo com nomes)
//
// Depois do almoço de domingo, seis primos fazem uma roda: Ana, Bia, Caio,
// Duda, Edu e Fê. Começando em Ana, contam 1, 2, 3, e quem disser "3" sai da
// roda; a contagem recomeça do seguinte. O último que sobrar lava a louça.
// Monte a roda como uma lista circular de nomes guardada pelo ÚLTIMO nó e
// escreva
//
//   No *elimina(No *ultimo, int k)
//
// que mostra quem sai, na ordem, libera cada nó que sai e devolve o nó que
// sobrou. Mostre o vencedor e libere esse último nó também.
//
//   Saída esperada:
//   Saem: Caio Fê Duda Bia Edu
//   Lava a louça: Ana
//
// Dicas:
// 1. Guarde ant = ultimo (o anterior do primeiro). Para contar k pessoas,
//    avance ant k - 1 vezes: o que sai é ant->prox.
// 2. Para tirar: No *sai = ant->prox; ant->prox = sai->prox; free(sai). A
//    contagem recomeça em ant->prox, sem mexer em ant.
// 3. Pare quando sobrar um só: ant->prox == ant.
// 4. Resposta esperada: a saída acima. São n - 1 eliminações de k passos:
//    O(n · k).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[12];
    struct no *prox;
} No;

int main(void) {

    return 0;
}

// 0165 · Juntando tudo
// Exercício E985 · ★☆☆
//
// A média esconde quem espera mais. Escreva
// void mede(const Estrutura *e, const int ordem[], const int buscas[],
// double *media, int *pior): insere as chaves de ordem na estrutura, faz as
// buscas e guarda em *media o custo médio e em *pior o maior custo de uma
// busca só. O main já gera os dados (chaves embaralhadas); acrescente a
// ele o laço que mostra as duas medidas de cada concorrente.
//
//   Saída esperada:
//   BST        média   11.9   pior   21
//   AVL        média    8.9   pior   12
//   skip list  média   16.4   pior   29
//   lista MTF  média  114.6   pior 1000
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "0165-bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20

int buscas[BUSCAS];

int main(void) {
    unsigned estado = 7;
    int embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado);
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    return 0;
}

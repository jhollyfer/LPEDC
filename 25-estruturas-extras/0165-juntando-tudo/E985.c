// 0165 · Juntando tudo
// Exercício E985 · ★☆☆
//
// A média esconde quem espera mais. Complete mede para guardar em *media o
// custo médio das buscas e em *pior o maior custo de uma busca só. O main
// já monta o teste do texto (chaves embaralhadas) e mostra as duas medidas.
//
//   Saída esperada:
//   BST        média   11.9   pior   21
//   AVL        média    8.9   pior   12
//   skip list  média   16.4   pior   29
//   lista MTF  média  114.6   pior 1000
//
// Dicas:
// 1. É a função mede do texto com uma variável a mais: zere *pior antes do
//    laço e troque quando aparecer um custo maior.
// 2. Não esqueça do e->libera(d) no fim.
// 3. Resposta esperada: a saída acima. Na lista MTF, alguma busca percorreu
//    os 1000 nós; na AVL, nenhuma passou de 12.
//
// Escreva sua resposta abaixo (complete mede):

#include <stdio.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20

void mede(const Estrutura *e, const int ordem[], const int buscas[], double *media, int *pior) {
    (void)e; // apague estas três linhas
    (void)ordem;
    (void)buscas;
    *media = 0;
    *pior = 0;
}

int main(void) {
    unsigned estado = 7;
    int embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        double media;
        int pior;
        mede(&CONCORRENTES[k], embaralhada, buscas, &media, &pior);
        printf("%-10s média %6.1f   pior %4d\n", CONCORRENTES[k].nome, media, pior);
    }
    return 0;
}

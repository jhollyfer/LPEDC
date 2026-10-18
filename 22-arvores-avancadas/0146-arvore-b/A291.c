// A291 · Quantas idas ao disco

#include <math.h>
#include <stdio.h>
#include "arvoreb.h"

// Num banco de dados, cada nó da árvore B é um bloco do disco, e ler um bloco
// custa muito mais que comparar chaves na memória. O que importa é a altura.

int main(void) {
    // 1. na prática, com o TAD (T = 2, até 3 chaves por nó)
    NoB *r = NULL;
    int n = 100000;
    for (int i = 1; i <= n; i++) {
        r = ab_insere(r, i);
    }
    int lidos;
    ab_busca(r, 77777, &lidos);
    printf("TAD com T = 2 e %d chaves: altura %d, busca do 77777 leu %d nós\n",
           n, ab_altura(r), lidos);
    printf("Uma árvore binária perfeita com %d chaves teria altura %d\n",
           n, (int)floor(log2(n)));
    r = ab_libera(r);

    // 2. na teoria: altura máxima de uma árvore B, h <= log_t((n + 1) / 2)
    int ts[] = {2, 50, 500};
    double ns[] = {1e6, 1e9};
    printf("\nAltura máxima (nós lidos = altura + 1):\n");
    printf("%14s %8s %8s %8s\n", "chaves", "T=2", "T=50", "T=500");
    for (int j = 0; j < 2; j++) {
        printf("%14.0f", ns[j]);
        for (int i = 0; i < 3; i++) {
            double h = log((ns[j] + 1) / 2) / log(ts[i]); // log na base t
            printf(" %8d", (int)floor(h));
        }
        printf("\n");
    }
    return 0;
}
// Saída:
// TAD com T = 2 e 100000 chaves: altura 15, busca do 77777 leu 16 nós
// Uma árvore binária perfeita com 100000 chaves teria altura 16
//
// Altura máxima (nós lidos = altura + 1):
//         chaves      T=2     T=50    T=500
//        1000000       18        3        2
//     1000000000       28        5        3

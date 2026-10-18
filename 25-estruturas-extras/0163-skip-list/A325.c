// A325 · A moeda decide os andares

#include <stdio.h>
#include "skip.h"

#define N 1000

int main(void) {
    Skip *s = skip_cria(2024); // a mesma semente dá sempre a mesma skip list
    for (int i = 1; i <= N; i++) {
        skip_insere(s, i * 10); // códigos de produto: 10, 20, ..., 10000
    }

    // quantos nós em cada andar: anda pela lista daquele andar
    int ponteiros = 0;
    for (int k = 0; k < s->andares; k++) {
        int qtd = 0;
        for (const NoSkip *x = s->cabeca.prox[k]; x != NULL; x = x->prox[k]) {
            qtd++;
        }
        ponteiros += qtd;
        printf("andar %2d: %4d nós (esperado ~%d)\n", k, qtd, N >> k);
    }
    printf("Ponteiros em uso: %d, média de %.2f por nó\n", ponteiros, (double)ponteiros / N);

    // a média de nós olhados, buscando cada uma das 1000 chaves
    long total = 0;
    int pior = 0;
    for (int i = 1; i <= N; i++) {
        int passos;
        skip_busca(s, i * 10, &passos);
        total += passos;
        if (passos > pior) {
            pior = passos;
        }
    }
    printf("Busca: média de %.1f nós olhados, pior %d\n", (double)total / N, pior);
    printf("Lista simples: média de %.1f, pior %d\n", (N + 1) / 2.0, N);

    skip_libera(s);
    return 0;
}
// Saída:
// andar  0: 1000 nós (esperado ~1000)
// andar  1:  503 nós (esperado ~500)
// andar  2:  251 nós (esperado ~250)
// andar  3:  129 nós (esperado ~125)
// andar  4:   62 nós (esperado ~62)
// andar  5:   27 nós (esperado ~31)
// andar  6:   13 nós (esperado ~15)
// andar  7:    6 nós (esperado ~7)
// andar  8:    4 nós (esperado ~3)
// andar  9:    2 nós (esperado ~1)
// Ponteiros em uso: 1997, média de 2.00 por nó
// Busca: média de 18.2 nós olhados, pior 31
// Lista simples: média de 500.5, pior 1000

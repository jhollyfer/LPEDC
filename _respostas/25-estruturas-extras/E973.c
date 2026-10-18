// 0163 · Skip list
// Exercício E973 · ★☆☆

#include <stdio.h>
#include "skip.h"

int maior(const Skip *s, int *avancos) {
    *avancos = 0;
    const NoSkip *x = &s->cabeca;
    for (int k = s->andares - 1; k >= 0; k--) {
        while (x->prox[k] != NULL) { // vai até o fim do andar
            x = x->prox[k];
            (*avancos)++;
        }
    }
    return x->chave;
}

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    Skip *paradas = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(paradas, km[i], andares[i]);
    }
    Skip *codigos = skip_cria(2024);
    for (int i = 1; i <= 1000; i++) {
        skip_insere(codigos, i * 10);
    }

    int av;
    int m = maior(paradas, &av);
    printf("Paradas: maior %d, %d avanços (pelo andar 0 seriam %d)\n", m, av, paradas->n);
    m = maior(codigos, &av);
    printf("Códigos: maior %d, %d avanços (pelo andar 0 seriam %d)\n", m, av, codigos->n);

    skip_libera(paradas);
    skip_libera(codigos);
    return 0;
}

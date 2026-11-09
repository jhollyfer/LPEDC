// Lista · Módulo 07 · Memória dinâmica
// Exercício P0707 · ★☆☆ · Faixas de idade do tamanho certo

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int idades[12] = {67, 8, 34, 71, 15, 42, 88, 3, 59, 64, 27, 80};
    int maior = idades[0];
    for (int i = 1; i < 12; i++) {
        if (idades[i] > maior) {
            maior = idades[i];
        }
    }

    int faixas = maior / 10 + 1;
    int *cont = calloc(faixas, sizeof *cont); // já começa tudo em 0
    if (cont == NULL) {
        return 1;
    }
    for (int i = 0; i < 12; i++) {
        cont[idades[i] / 10]++;
    }

    printf("%d faixas\n", faixas);
    for (int f = 0; f < faixas; f++) {
        printf("%2d-%2d: %d\n", f * 10, f * 10 + 9, cont[f]);
    }
    free(cont);
    return 0;
}

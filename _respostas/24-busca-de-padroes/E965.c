// 0161 · Juntando tudo
// Exercício E965 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "padroes.h"

#define N 100000

static unsigned long semente = 2026;
static int sorteia(int limite) {
    semente = (semente * 1103515245UL + 12345UL) % 2147483648UL;
    return (int) (semente / 65536 % (unsigned long) limite);
}

int main(void) {
    char *dna = malloc(N + 1);
    if (dna == NULL) {
        return 1;
    }
    const char *bases = "ACGT";
    for (int i = 0; i < N; i++) {
        dna[i] = bases[sorteia(4)];
    }
    dna[N] = '\0';

    Busca buscas[] = {pb_forca_bruta, pb_kmp, pb_horspool, pb_rabin_karp};
    printf("  m    bruta      KMP  Horspool  Rabin-Karp  ocorrências\n");
    for (int m = 4; m <= 32; m *= 2) {
        char padrao[33];
        for (int j = 0; j < m; j++) {
            padrao[j] = dna[50000 + j];      // um trecho que existe no texto
        }
        padrao[m] = '\0';
        long comp[4];
        int achou = 0;
        for (int a = 0; a < 4; a++) {
            comp[a] = 0;
            achou = buscas[a](dna, N, padrao, m, NULL, 0, &comp[a]);
        }
        printf("%3d %8ld %8ld %9ld %11ld %12d\n", m, comp[0], comp[1], comp[2],
               comp[3], achou);
    }
    free(dna);
    return 0;
}

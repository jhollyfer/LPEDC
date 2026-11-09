// Lista · Módulo 07 · Memória dinâmica
// Exercício P0724 · ★★★ · Multiplicar números que não cabem em nenhum tipo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiplicar(const char *a, const char *b) {
    int na = (int) strlen(a), nb = (int) strlen(b);
    int total = na + nb;
    int *casas = calloc(total, sizeof *casas);
    if (casas == NULL) {
        return NULL;
    }
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            casas[i + j] += (a[na - 1 - i] - '0') * (b[nb - 1 - j] - '0');
        }
    }
    for (int k = 0; k < total - 1; k++) {
        casas[k + 1] += casas[k] / 10; // o "vai um"
        casas[k] %= 10;
    }
    int topo = total - 1;
    while (topo > 0 && casas[topo] == 0) {
        topo--; // tira os zeros à esquerda (deixa pelo menos um dígito)
    }
    char *r = malloc(topo + 2);
    if (r == NULL) {
        free(casas);
        return NULL;
    }
    for (int k = topo; k >= 0; k--) {
        r[topo - k] = (char) ('0' + casas[k]);
    }
    r[topo + 1] = '\0';
    free(casas);
    return r;
}

int main(void) {
    const char *pares[4][2] = {{"12", "34"},
                               {"99999999999", "99999999999"},
                               {"123456789012345678901234567890", "987654321"},
                               {"2026", "0"}};

    for (int k = 0; k < 4; k++) {
        char *r = multiplicar(pares[k][0], pares[k][1]);
        if (r == NULL) {
            return 1;
        }
        printf("%s x %s =\n  %s (tamanho %zu)\n", pares[k][0], pares[k][1], r, strlen(r));
        free(r);
    }
    return 0;
}

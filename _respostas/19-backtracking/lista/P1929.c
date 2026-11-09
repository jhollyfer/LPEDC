// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1929 · ★★★ · A balança de dois pratos

#include <stdio.h>

#define NP 3
#define MAXK 13

const int peso[NP] = {1, 3, 9};
int lado[NP];
int resp[MAXK + 1][NP];
int achou[MAXK + 1];

void gera(int i, int soma) {
    if (i == NP) {
        if (soma >= 1 && soma <= MAXK && !achou[soma]) {
            achou[soma] = 1;
            for (int j = 0; j < NP; j++) {
                resp[soma][j] = lado[j];
            }
        }
        return;
    }
    const int opcoes[3] = {1, -1, 0};
    for (int o = 0; o < 3; o++) {
        lado[i] = opcoes[o];
        gera(i + 1, soma + opcoes[o] * peso[i]);
    }
}

int main(void) {
    gera(0, 0);
    for (int k = 1; k <= MAXK; k++) {
        printf("%2d =", k);
        int primeiro = 1;
        for (int j = NP - 1; j >= 0; j--) {
            if (resp[k][j] == 0) {
                continue;
            }
            if (primeiro) {
                printf(" %d", peso[j]);
                primeiro = 0;
            } else {
                printf(" %c %d", resp[k][j] > 0 ? '+' : '-', peso[j]);
            }
        }
        printf("\n");
    }
    return 0;
}

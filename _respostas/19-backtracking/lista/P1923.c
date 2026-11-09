// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1923 · ★★★ · Três programadores, carga igual

#include <stdio.h>

#define N 9
#define K 3
#define META 15

const int horas[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int carga[K], dono[N];
long chamadas = 0;

int distribui(int i) {
    chamadas++;
    if (i == N) {
        return 1;
    }
    for (int p = 0; p < K; p++) {
        if (carga[p] + horas[i] > META) {
            continue;
        }
        int repetido = 0;
        for (int p2 = 0; p2 < p; p2++) {
            if (carga[p2] == carga[p]) {
                repetido = 1;
            }
        }
        if (repetido) {
            continue;
        }
        carga[p] += horas[i];
        dono[i] = p;
        if (distribui(i + 1)) {
            return 1;
        }
        carga[p] -= horas[i];
    }
    return 0;
}

int main(void) {
    if (distribui(0)) {
        for (int p = 0; p < K; p++) {
            printf("Programador %d:", p + 1);
            for (int i = 0; i < N; i++) {
                if (dono[i] == p) {
                    printf(" %d", horas[i]);
                }
            }
            printf(" (%d h)\n", carga[p]);
        }
    } else {
        printf("Não dá para dividir\n");
    }
    printf("Chamadas: %ld\n", chamadas);
    return 0;
}

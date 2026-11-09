// Lista · Módulo 21 · Programação dinâmica
// Exercício P2125 · ★★★ · Dois times equilibrados

#include <stdbool.h>
#include <stdio.h>

#define N 10
#define K 5
#define SMAX 66

int main(void) {
    const char *nome[N] = {"Ana", "Beto", "Caio", "Duda", "Enzo", "Fábio", "Gabi", "Hugo", "Iara", "João"};
    const int nota[N] = {8, 6, 9, 4, 7, 5, 10, 3, 6, 7};
    bool pode[K + 1][SMAX] = {{false}};
    int quem[K + 1][SMAX];
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += nota[i];
    }
    pode[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int k = K; k >= 1; k--) {
            for (int s = SMAX - 1; s >= nota[i]; s--) {
                if (!pode[k][s] && pode[k - 1][s - nota[i]]) {
                    pode[k][s] = true;
                    quem[k][s] = i;
                }
            }
        }
    }
    int melhor = -1, melhor_dif = SMAX;
    for (int s = 0; s <= total; s++) {
        int dif = total - 2 * s < 0 ? 2 * s - total : total - 2 * s;
        if (pode[K][s] && dif < melhor_dif) {
            melhor = s;
            melhor_dif = dif;
        }
    }
    bool time1[N] = {false};
    for (int k = K, s = melhor; k > 0; k--) {
        int j = quem[k][s];
        time1[j] = true;
        s -= nota[j];
    }
    for (int t = 1; t <= 2; t++) {
        int soma = 0;
        printf("Time %d:", t);
        for (int i = 0; i < N; i++) {
            if (time1[i] == (t == 1)) {
                printf(" %s", nome[i]);
                soma += nota[i];
            }
        }
        printf(" (%d pontos)\n", soma);
    }
    return 0;
}

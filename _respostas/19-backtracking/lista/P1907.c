// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1907 · ★☆☆ · A playlist de 30 minutos

#include <stdio.h>

#define N 6
#define ALVO 30

const int dur[N] = {7, 12, 5, 9, 11, 4};
int leva[N];

int acha(int i, int soma) {
    if (soma == ALVO) {
        return 1;
    }
    if (soma > ALVO || i == N) {
        return 0;
    }
    leva[i] = 1;
    if (acha(i + 1, soma + dur[i])) {
        return 1;
    }
    leva[i] = 0;
    return acha(i + 1, soma);
}

int main(void) {
    if (acha(0, 0)) {
        printf("Playlist:");
        int total = 0;
        for (int i = 0; i < N; i++) {
            if (leva[i]) {
                printf(" %d", dur[i]);
                total += dur[i];
            }
        }
        printf(" = %d minutos\n", total);
    } else {
        printf("Não dá para fechar %d minutos\n", ALVO);
    }
    return 0;
}

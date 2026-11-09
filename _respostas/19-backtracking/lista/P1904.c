// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1904 · ★☆☆ · Quantas vezes a função foi chamada

#include <stdio.h>

#define N 4

const char *ingr[N] = {"queijo", "coco", "banana", "tucumã"};
int leva[N];
int chamadas = 0, folhas = 0;

void gera(int i) {
    chamadas++;
    if (i == N) {
        folhas++;
        printf("{");
        for (int j = 0; j < N; j++) {
            if (leva[j]) {
                printf(" %s", ingr[j]);
            }
        }
        printf(" }\n");
        return;
    }
    leva[i] = 1;
    gera(i + 1);
    leva[i] = 0;
    gera(i + 1);
}

int main(void) {
    gera(0);
    printf("Chamadas: %d, folhas: %d\n", chamadas, folhas);
    return 0;
}

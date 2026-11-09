// Lista · Módulo 21 · Programação dinâmica
// Exercício P2115 · ★★☆ · A trilha que só sobe

#include <stdio.h>

#define N 12

int main(void) {
    const int alt[N] = {640, 702, 655, 690, 735, 610, 760, 720, 805, 780, 850, 830};
    int lis[N], ant[N], fim = 0;
    for (int i = 0; i < N; i++) {
        lis[i] = 1;
        ant[i] = -1;
        for (int j = 0; j < i; j++) {
            if (alt[j] < alt[i] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
                ant[i] = j;
            }
        }
        if (lis[i] > lis[fim]) {
            fim = i;
        }
    }
    int seq[N], k = 0;
    for (int i = fim; i != -1; i = ant[i]) {
        seq[k++] = alt[i];
    }
    printf("Fotos: %d\n", k);
    printf("Altitudes:");
    for (int i = k - 1; i >= 0; i--) {
        printf(" %d", seq[i]);
    }
    printf("\n");
    return 0;
}

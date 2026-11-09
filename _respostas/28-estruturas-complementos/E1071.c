// 0179 · Sondagem quadrática e dupla
// Exercício E1071 · ★★☆

#include <stdio.h>

#define M 16

int h1(int k) {
    return k % M;
}

int h2(int k) {
    return 2 * ((k / M) % 8) + 1; // ímpar e tirado dos bits que o h1 não usa
}

int main(void) {
    int tabela[M];
    for (int j = 0; j < M; j++) {
        tabela[j] = -1;
    }
    int chaves[] = {3, 19, 35, 51, 67, 83};
    for (int c = 0; c < 6; c++) {
        int k = chaves[c];
        for (int i = 0; i < M; i++) {
            int j = (h1(k) + i * h2(k)) % M;
            if (tabela[j] == -1) {
                tabela[j] = k;
                printf("%2d: h2 = %2d -> posição %2d, %d sondagens\n", k, h2(k), j, i + 1);
                break;
            }
        }
    }
    printf("tabela:");
    for (int j = 0; j < M; j++) {
        if (tabela[j] == -1) {
            printf(" .");
        } else {
            printf(" %d", tabela[j]);
        }
    }
    printf("\n");
    return 0;
}

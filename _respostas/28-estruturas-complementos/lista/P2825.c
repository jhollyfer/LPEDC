// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2825 · ★★★ · As três sondagens lado a lado

#include <stdio.h>

#define M 17

int posicao(int metodo, int k, int i) {
    int h = k % M;
    switch (metodo) {
    case 0:
        return (h + i) % M;
    case 1:
        return (h + i * i) % M;
    default:
        return (h + i * (1 + k % (M - 1))) % M;
    }
}

int main(void) {
    const char *nomes[] = {"linear:    ", "quadrática:", "dupla:     "};
    int chaves[] = {20, 37, 54, 71, 88, 5, 22, 39};
    for (int metodo = 0; metodo < 3; metodo++) {
        int t[M];
        for (int j = 0; j < M; j++) {
            t[j] = -1;
        }
        int total = 0;
        for (int c = 0; c < 8; c++) {
            for (int i = 0; i < M; i++) {
                int j = posicao(metodo, chaves[c], i);
                if (t[j] == -1) {
                    t[j] = chaves[c];
                    total += i + 1;
                    break;
                }
            }
        }
        printf("%s", nomes[metodo]);
        for (int j = 0; j < M; j++) {
            if (t[j] == -1) {
                printf("  .");
            } else {
                printf(" %2d", t[j]);
            }
        }
        printf(" | %d sondagens\n", total);
    }
    return 0;
}

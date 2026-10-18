// 0115 · Teorema mestre
// Exercício E685 · ★☆☆

#include <stdio.h>

long potencia(int b, int k) {
    long p = 1;
    for (int i = 0; i < k; i++) {
        p *= b;
    }
    return p;
}

// 1: folhas dominam; 2: empate; 3: raiz domina
int caso(int a, int b, int k) {
    long bk = potencia(b, k);
    if (a > bk) {
        return 1;
    }
    if (a == bk) {
        return 2;
    }
    return 3;
}

int main(void) {
    int r[][3] = {{2, 2, 1}, {4, 2, 1}, {1, 2, 1}, {9, 3, 2}, {5, 4, 1}, {2, 4, 1}, {16, 4, 2}};
    const char *resposta[] = {"???", "folhas: Θ(n^(log_b a))", "empate: Θ(n^k log n)", "raiz: Θ(n^k)"};
    for (int i = 0; i < 7; i++) {
        int c = caso(r[i][0], r[i][1], r[i][2]);
        printf("%2d T(n/%d) + n^%d -> caso %d, %s\n", r[i][0], r[i][1], r[i][2], c, resposta[c]);
    }
    return 0;
}

// 0115 · Teorema mestre
// Exercício E690 · ★★★

#include <stdio.h>

// O bug: log(125) / log(5) dá 3.0000000000000004 (e log(1000) / log(10),
// 2.9999999999999996). O == entre doubles falhava. Agora a comparação é
// entre inteiros: a contra b^k.
long potencia(int b, int k) {
    long p = 1;
    for (int i = 0; i < k; i++) {
        p *= b;
    }
    return p;
}

const char *classifica(int a, int b, int k) {
    long bk = potencia(b, k);
    if (a > bk) {
        return "folhas";
    }
    if (a == bk) {
        return "empate";
    }
    return "raiz";
}

int main(void) {
    int r[][3] = {{2, 2, 1}, {4, 2, 1}, {1, 2, 1}, {125, 5, 3}, {1000, 10, 3}, {216, 6, 3}, {8, 2, 3}};
    for (int i = 0; i < 7; i++) {
        printf("%4d T(n/%d)%s + n^%d -> %s\n", r[i][0], r[i][1], r[i][1] < 10 ? " " : "",
               r[i][2], classifica(r[i][0], r[i][1], r[i][2]));
    }
    return 0;
}

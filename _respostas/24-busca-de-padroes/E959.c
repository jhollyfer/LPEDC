// 0160 · Rabin-Karp
// Exercício E959 · ★★★

#include <stdio.h>
#include <string.h>

#define Q 101

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

int conta(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int pot = 1;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * 10 % Q;
    }
    int hp = 0, ht = 0;
    for (int j = 0; j < m; j++) {
        hp = (hp * 10 + (p[j] - '0')) % Q;
        ht = (ht * 10 + (t[j] - '0')) % Q;
    }
    int total = 0;
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp && iguais(t + i, p, m)) {
            total++;
        }
        if (i < n - m) {
            // a subtração pode ficar negativa, e % de negativo dá negativo
            // em C: somar Q antes do % deixa o resultado entre 0 e Q - 1
            ht = (ht - (t[i] - '0') * pot % Q + Q) % Q;
            ht = (ht * 10 + (t[i + m] - '0')) % Q;
        }
    }
    return total;
}

int main(void) {
    printf("8922: %d\n", conta("4002892240028922", "8922"));
    printf("800: %d\n", conta("0800729072908007", "800"));
    return 0;
}

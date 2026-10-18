// 0160 · Rabin-Karp
// Exercício E956 · ★☆☆

#include <stdio.h>
#include <string.h>

#define BASE 256
#define Q 101

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    const char *t = "o rato roeu a roupa do rato rei";
    const char *p = "rato";
    int n = (int) strlen(t);
    int m = (int) strlen(p);

    int pot = 1;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * BASE % Q;
    }
    int hp = 0, ht = 0;
    for (int j = 0; j < m; j++) {
        hp = (hp * BASE + (unsigned char) p[j]) % Q;
        ht = (ht * BASE + (unsigned char) t[j]) % Q;
    }
    int verificacoes = 0;
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp) {
            verificacoes++;
            if (iguais(t + i, p, m)) {
                printf("achou na posição %d\n", i);
            }
        }
        if (i < n - m) {
            ht = (ht - (unsigned char) t[i] * pot % Q + Q) % Q;  // tira t[i]
            ht = (ht * BASE + (unsigned char) t[i + m]) % Q;      // põe t[i+m]
        }
    }
    printf("%d verificações letra a letra\n", verificacoes);
    return 0;
}

// 0160 · Rabin-Karp
// Exercício E960 · ★★★

#include <stdio.h>
#include <string.h>

#define BASE 256
#define Q 1000003LL

int iguais(const char *t, const char *p, int m) {
    for (int j = 0; j < m; j++) {
        if (t[j] != p[j]) {
            return 0;
        }
    }
    return 1;
}

// hash fraco: a soma dos bytes; rolar é tirar um e somar outro
void busca_soma(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int hp = 0, ht = 0, verif = 0, achou = 0;
    for (int j = 0; j < m; j++) {
        hp += (unsigned char) p[j];
        ht += (unsigned char) t[j];
    }
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp) {
            verif++;
            if (iguais(t + i, p, m)) {
                achou++;
            }
        }
        if (i < n - m) {
            ht += (unsigned char) t[i + m] - (unsigned char) t[i];
        }
    }
    printf("soma:       %d verificações, %d ocorrências\n", verif, achou);
}

// hash polinomial: a posição de cada letra pesa
void busca_polinomial(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    long long pot = 1, hp = 0, ht = 0;
    int verif = 0, achou = 0;
    for (int j = 0; j < m - 1; j++) {
        pot = pot * BASE % Q;
    }
    for (int j = 0; j < m; j++) {
        hp = (hp * BASE + (unsigned char) p[j]) % Q;
        ht = (ht * BASE + (unsigned char) t[j]) % Q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (ht == hp) {
            verif++;
            if (iguais(t + i, p, m)) {
                achou++;
            }
        }
        if (i < n - m) {
            ht = (ht - (unsigned char) t[i] * pot % Q + Q) % Q;
            ht = (ht * BASE + (unsigned char) t[i + m]) % Q;
        }
    }
    printf("polinomial: %d verificações, %d ocorrências\n", verif, achou);
}

int main(void) {
    const char *poema = "roma, amor, mora, ramo, omar e amora";
    busca_soma(poema, "amor");
    busca_polinomial(poema, "amor");
    return 0;
}

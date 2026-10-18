// 0160 · Rabin-Karp
// Exercício E958 · ★★☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BASE 256
#define Q 1000003LL
#define K 8
#define MAX 100

int iguais(const char *a, const char *b, int m) {
    for (int j = 0; j < m; j++) {
        if (a[j] != b[j]) {
            return 0;
        }
    }
    return 1;
}

// guarda em h[] o hash de todas as janelas de K letras de s; devolve quantas
int hashes(const char *s, long long h[]) {
    int n = (int) strlen(s);
    long long pot = 1, x = 0;
    for (int j = 0; j < K - 1; j++) {
        pot = pot * BASE % Q;
    }
    for (int j = 0; j < K; j++) {
        x = (x * BASE + (unsigned char) s[j]) % Q;
    }
    for (int i = 0; i <= n - K; i++) {
        h[i] = x;
        if (i < n - K) {
            x = (x - (unsigned char) s[i] * pot % Q + Q) % Q;
            x = (x * BASE + (unsigned char) s[i + K]) % Q;
        }
    }
    return n - K + 1;
}

int main(void) {
    const char *original = "o projeto mede a agua da chuva com sensores baratos";
    char suspeito[] = "nosso trabalho mede a agua da chuva com um balde";
    long long ha[MAX], hb[MAX];
    int na = hashes(original, ha);
    int nb = hashes(suspeito, hb);
    int copiada[MAX] = {0};

    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < na; j++) {
            if (hb[i] == ha[j] && iguais(suspeito + i, original + j, K)) {
                for (int c = 0; c < K; c++) {
                    copiada[i + c] = 1;   // marca as K letras da janela
                }
                break;
            }
        }
    }
    int n = (int) strlen(suspeito), total = 0;
    for (int i = 0; i < n; i++) {
        if (copiada[i]) {
            suspeito[i] = (char) toupper((unsigned char) suspeito[i]);
            total++;
        }
    }
    printf("%s\n", suspeito);
    printf("%d de %d letras em trechos copiados (%d%%)\n", total, n, 100 * total / n);
    return 0;
}

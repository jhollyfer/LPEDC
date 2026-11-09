// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2412 · ★★☆ · Os alarmes falsos do Rabin-Karp

#include <stdio.h>
#include <string.h>

#define B 256

int busca(const char *t, const char *p, int q, int mostrar) {
    int n = (int)strlen(t), m = (int)strlen(p);
    int pot = 1;
    for (int k = 1; k < m; k++) pot = pot * B % q;
    int hp = 0, ht = 0;
    for (int k = 0; k < m; k++) {
        hp = (hp * B + (unsigned char)p[k]) % q;
        ht = (ht * B + (unsigned char)t[k]) % q;
    }
    int achou = 0, falsos = 0;
    for (int i = 0; i + m <= n; i++) {
        if (ht == hp) {
            if (strncmp(t + i, p, m) == 0) achou++;
            else {
                falsos++;
                if (mostrar) printf("  falso positivo em %2d: \"%.*s\"\n", i, m, t + i);
            }
        }
        if (i + m < n) {
            ht = (ht - (unsigned char)t[i] * pot % q + q) % q;
            ht = (ht * B + (unsigned char)t[i + m]) % q;
        }
    }
    printf("q = %4d: %d ocorrência(s), %d falso(s) positivo(s)\n", q, achou, falsos);
    return falsos;
}

int main(void) {
    const char *frase = "o rato roeu a roupa do rei de roma e a rainha riu";
    busca(frase, "roma", 11, 1);
    busca(frase, "roma", 101, 1);
    busca(frase, "roma", 1009, 1);
    return 0;
}

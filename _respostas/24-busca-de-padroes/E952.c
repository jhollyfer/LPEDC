// 0159 · Horspool
// Exercício E952 · ★★☆

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

long forca_bruta(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    long comp = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comp++;
            if (t[i + j] != p[j]) {
                break;
            }
            j++;
        }
    }
    return comp;
}

long horspool(const char *t, const char *p, int *alinhamentos) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) p[j]] = m - 1 - j;
    }
    long comp = 0;
    *alinhamentos = 0;
    int i = 0;
    while (i <= n - m) {
        (*alinhamentos)++;
        int j = m - 1;
        while (j >= 0) {
            comp++;
            if (t[i + j] != p[j]) {
                break;
            }
            j--;
        }
        i += salto[(unsigned char) t[i + m - 1]];
    }
    return comp;
}

int main(void) {
    char texto[31];
    for (int i = 0; i < 30; i++) {
        texto[i] = 'a';              // trinta 'a'
    }
    texto[30] = '\0';
    const char *padroes[] = {"baaa", "aaab", "abbb"};
    int al;

    for (int k = 0; k < 3; k++) {
        long fb = forca_bruta(texto, padroes[k]);
        long h = horspool(texto, padroes[k], &al);
        printf("%s: força bruta %3ld, Horspool %3ld (%d alinhamentos)\n",
               padroes[k], fb, h, al);
    }
    return 0;
}

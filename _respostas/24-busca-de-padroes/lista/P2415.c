// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2415 · ★★☆ · O Horspool que confunde bolo com rolo

#include <stdio.h>
#include <string.h>

int horspool(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), salto[256], achou = 0;
    for (int c = 0; c < 256; c++) salto[c] = m;
    for (int j = 0; j < m - 1; j++) salto[(unsigned char)p[j]] = m - 1 - j;
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && t[i + j] == p[j]) j--; // o conserto: j >= 0 confere também a 1ª letra
        if (j < 0) {
            printf("  %s em %d\n", p, i);
            achou++;
        }
        i += salto[(unsigned char)t[i + m - 1]];
    }
    return achou;
}

int main(void) {
    const char *padaria = "bolo de rolo, bolo de milho e um tolo pedindo bolo";
    printf("bolo: %d\n", horspool(padaria, "bolo"));
    printf("de: %d\n", horspool(padaria, "de"));
    return 0;
}

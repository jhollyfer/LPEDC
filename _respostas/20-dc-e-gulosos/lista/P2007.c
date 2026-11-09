// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2007 · ★☆☆ · O código que confunde

#include <stdio.h>
#include <string.h>

#define N 5

const char simb[N] = {'A', 'B', 'C', 'D', 'E'};

int prefixo(const char *a, const char *b) {
    size_t ta = strlen(a);
    return ta <= strlen(b) && strncmp(a, b, ta) == 0;
}

int livre_de_prefixo(const char *cod[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prefixo(cod[i], cod[j])) {
                printf("  %c=%s é começo de %c=%s\n", simb[i], cod[i], simb[j], cod[j]);
                return 0;
            }
            if (prefixo(cod[j], cod[i])) {
                printf("  %c=%s é começo de %c=%s\n", simb[j], cod[j], simb[i], cod[i]);
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    const char *t1[N] = {"0", "10", "110", "1110", "1111"};
    const char *t2[N] = {"0", "01", "110", "111", "10"};
    const char *t3[N] = {"00", "01", "10", "110", "111"};
    const char **tabs[3] = {t1, t2, t3};
    for (int k = 0; k < 3; k++) {
        printf("Tabela %d:\n", k + 1);
        printf("  %s\n", livre_de_prefixo(tabs[k], N) ? "serve" : "não serve");
    }
    return 0;
}

// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1913 · ★★☆ · ARARA em pedaços palíndromos

#include <stdio.h>
#include <string.h>

const char *s = "ARARA";
int n;
int fimp[16], np = 0;
int total = 0;

int eh_pal(int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void corta(int ini) {
    if (ini == n) {
        total++;
        int a = 0;
        for (int p = 0; p < np; p++) {
            if (p > 0) {
                printf("|");
            }
            printf("%.*s", fimp[p] - a + 1, s + a);
            a = fimp[p] + 1;
        }
        printf("\n");
        return;
    }
    for (int fim = ini; fim < n; fim++) {
        if (eh_pal(ini, fim)) {
            fimp[np++] = fim;
            corta(fim + 1);
            np--;
        }
    }
}

int main(void) {
    n = (int)strlen(s);
    corta(0);
    printf("Total: %d jeitos\n", total);
    return 0;
}

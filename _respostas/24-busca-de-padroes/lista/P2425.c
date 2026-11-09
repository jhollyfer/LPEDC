// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2425 · ★★★ · Todos os palíndromos de uma palavra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXP 128
#define MAXT 32

char achados[MAXP][MAXT];
int n_achados;

int compara(const void *a, const void *b) {
    const char *x = a, *y = b;
    if (strlen(x) != strlen(y)) return (int)strlen(x) - (int)strlen(y);
    return strcmp(x, y);
}

void guarda(const char *s, int ini, int tam) {
    char t[MAXT];
    memcpy(t, s + ini, tam);
    t[tam] = '\0';
    for (int k = 0; k < n_achados; k++)
        if (strcmp(achados[k], t) == 0) return; // já tinha
    strcpy(achados[n_achados++], t);
}

void todos(const char *s) {
    int n = (int)strlen(s), ocorrencias = 0;
    n_achados = 0;
    for (int c = 0; c < 2 * n - 1; c++) { // 2n - 1 centros
        int e = c / 2, d = e + c % 2;
        while (e >= 0 && d < n && s[e] == s[d]) {
            ocorrencias++;
            guarda(s, e, d - e + 1);
            e--;
            d++;
        }
    }
    qsort(achados, n_achados, MAXT, compara);
    printf("%s: %d ocorrências, %d diferentes:", s, ocorrencias, n_achados);
    for (int k = 0; k < n_achados; k++) printf(" %s", achados[k]);
    printf("\n");
}

int main(void) {
    todos("abacaba");
    todos("arara");
    todos("aaaa");
    todos("tucano");
    return 0;
}

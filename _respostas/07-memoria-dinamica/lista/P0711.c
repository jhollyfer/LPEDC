// Lista · Módulo 07 · Memória dinâmica
// Exercício P0711 · ★★☆ · Juntar a lista com um malloc só

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *juntar_todas(const char **itens, int n, const char *sep) {
    size_t tam = 1; // o '\0'
    for (int i = 0; i < n; i++) {
        tam += strlen(itens[i]);
    }
    if (n > 1) {
        tam += (n - 1) * strlen(sep);
    }
    char *s = malloc(tam);
    if (s == NULL) {
        return NULL;
    }
    char *fim = s; // onde o próximo pedaço entra
    *fim = '\0';
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            strcpy(fim, sep);
            fim += strlen(sep);
        }
        strcpy(fim, itens[i]);
        fim += strlen(itens[i]);
    }
    return s;
}

void testar(const char **itens, int n, const char *sep) {
    char *s = juntar_todas(itens, n, sep);
    if (s == NULL) {
        return;
    }
    printf("\"%s\" -> malloc(%zu)\n", s, strlen(s) + 1);
    free(s);
}

int main(void) {
    const char *feira[5] = {"farinha", "tucumã", "jambu", "cheiro-verde", "pupunha"};

    testar(feira, 5, ", ");
    testar(feira, 5, " | ");
    testar(feira, 0, ", ");
    return 0;
}

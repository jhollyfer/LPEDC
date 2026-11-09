// Lista · Módulo 07 · Memória dinâmica
// Exercício P0720 · ★★☆ · A borda e o miolo do terreno

#include <stdio.h>
#include <stdlib.h>

void liberar(int **m, int l) {
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < l; i++) {
        free(m[i]);
    }
    free(m);
}

int **criar(int l, int c) {
    int **m = malloc(l * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < l; i++) {
        m[i] = malloc(c * sizeof *m[i]);
        if (m[i] == NULL) {
            liberar(m, i);
            return NULL;
        }
    }
    return m;
}

int main(void) {
    int l, c;
    printf("Linhas e colunas: ");
    if (scanf("%d %d", &l, &c) != 2 || l < 1 || c < 1) {
        printf("Tamanho inválido\n");
        return 1;
    }
    int **m = criar(l, c);
    if (m == NULL) {
        return 1;
    }
    printf("Alturas:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", &m[i][j]) != 1) {
                printf("Leitura incompleta\n");
                liberar(m, l);
                return 1;
            }
        }
    }

    int borda = 0, miolo = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || i == l - 1 || j == 0 || j == c - 1) {
                borda += m[i][j];
            } else {
                miolo += m[i][j];
            }
        }
    }
    printf("Borda: %d\n", borda);
    printf("Miolo: %d\n", miolo);
    liberar(m, l);
    return 0;
}

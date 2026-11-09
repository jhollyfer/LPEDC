// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2725 · ★★★ · Girar a foto 90 graus

#include <stdbool.h>
#include <stdio.h>

void girar(int l, int c, int a[l][c], int r[c][l]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            r[j][l - 1 - i] = a[i][j];
        }
    }
}

void mostrar(int l, int c, int m[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

bool iguais(int l, int c, int a[l][c], int b[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int l = 2, c = 3;
    int foto[l][c];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            foto[i][j] = i * c + j + 1;
        }
    }
    int girada[c][l];
    girar(l, c, foto, girada);
    printf("girada (%d x %d):\n", c, l);
    mostrar(c, l, girada);

    int n = 3;
    int orig[n][n], atual[n][n], prox[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            orig[i][j] = atual[i][j] = i * n + j + 1;
        }
    }
    for (int g = 0; g < 4; g++) {
        girar(n, n, atual, prox);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                atual[i][j] = prox[i][j];
            }
        }
    }
    printf("4 giros na 3 x 3 voltam ao original? %s\n", iguais(n, n, orig, atual) ? "sim" : "não");
    return 0;
}

// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1029 · ★★☆

#include <stdio.h>

void mostrar(int l, int c, int m[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void transpor(int l, int c, int a[l][c], int t[c][l]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }
}

int main(void) {
    int l = 2, c = 3;
    int a[l][c];
    int t[c][l];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = i * c + j + 1;
        }
    }
    transpor(l, c, a, t);
    printf("original (%d x %d):\n", l, c);
    mostrar(l, c, a);
    printf("transposta (%d x %d):\n", c, l);
    mostrar(c, l, t);
    return 0;
}

// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1024 · ★★★ · A busca em escada na tabela de preços

#include <stdbool.h>
#include <stdio.h>

bool escada(int m[4][5], int x, int *lin, int *col, int *comp) {
    int i = 0, j = 4;
    *comp = 0;
    while (i < 4 && j >= 0) {
        (*comp)++;
        if (m[i][j] == x) {
            *lin = i;
            *col = j;
            return true;
        }
        if (m[i][j] > x) {
            j--; // a coluna j, daqui para baixo, só tem maiores
        } else {
            i++; // a linha i, daqui para a esquerda, só tem menores
        }
    }
    return false;
}

bool bruta(int m[4][5], int x, int *comp) {
    *comp = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            (*comp)++;
            if (m[i][j] == x) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    int m[4][5] = {
        {2, 5, 9, 14, 20},
        {4, 8, 13, 18, 25},
        {7, 11, 16, 22, 30},
        {10, 15, 21, 27, 35},
    };
    int procurados[2] = {16, 17};
    for (int k = 0; k < 2; k++) {
        int lin, col, ce, cb;
        bool achou = escada(m, procurados[k], &lin, &col, &ce);
        bruta(m, procurados[k], &cb);
        if (achou) {
            printf("%d: linha %d, coluna %d (escada: %d comparações, força bruta: %d)\n", procurados[k], lin,
                   col, ce, cb);
        } else {
            printf("%d: não está (escada: %d comparações, força bruta: %d)\n", procurados[k], ce, cb);
        }
    }
    return 0;
}

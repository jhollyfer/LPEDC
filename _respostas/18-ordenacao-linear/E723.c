// 0121 · Radix sort
// Exercício E723 · ★★☆

#include <stdio.h>
#include <stdbool.h>

#define MAX 16

// uma fila simples sobre vetor: entra no fim, sai do começo
typedef struct {
    int itens[MAX];
    int ini, fim;
} Fila;

void enfileira(Fila *f, int x) {
    f->itens[f->fim++] = x;
}

int desenfileira(Fila *f) {
    return f->itens[f->ini++];
}

bool vazia(const Fila *f) {
    return f->ini == f->fim;
}

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %03d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int v[] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
    int n = 10;

    for (int exp = 1; exp <= 100; exp *= 10) {   // 3 dígitos: 3 passadas
        Fila filas[10];
        for (int d = 0; d < 10; d++) {
            filas[d].ini = filas[d].fim = 0;
        }
        for (int i = 0; i < n; i++) {            // distribui
            enfileira(&filas[(v[i] / exp) % 10], v[i]);
        }
        int k = 0;
        for (int d = 0; d < 10; d++) {           // recolhe, da fila 0 à 9
            while (!vazia(&filas[d])) {
                v[k++] = desenfileira(&filas[d]);
            }
        }
        printf("exp = %3d:", exp);
        mostra(v, n);
    }
    return 0;
}

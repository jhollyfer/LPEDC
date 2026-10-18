// 0102 · Heap e fila de prioridade
// Exercício E607 · ★☆☆

#include <stdio.h>

void mostra_filhos(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        printf("v[%d] = %d: ", i, v[i]);
        if (esq >= n) {
            printf("folha\n");
        } else if (dir >= n) {
            printf("filho %d\n", v[esq]);
        } else {
            printf("filhos %d e %d\n", v[esq], v[dir]);
        }
    }
}

int main(void) {
    int heap[] = {90, 70, 30, 40, 50, 20};
    mostra_filhos(heap, 6);
    return 0;
}

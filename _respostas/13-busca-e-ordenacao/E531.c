// 0089 · Busca sequencial
// Exercício E531 · ★★☆

#include <stdio.h>

// busca comum: olha até achar ou acabar
int busca(const int v[], int n, int x, int *olhados) {
    *olhados = 0;
    for (int i = 0; i < n; i++) {
        (*olhados)++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

// vetor crescente: se v[i] já passou de x, x não pode estar mais à frente
int busca_ordenada(const int v[], int n, int x, int *olhados) {
    *olhados = 0;
    for (int i = 0; i < n; i++) {
        (*olhados)++;
        if (v[i] == x) {
            return i;
        }
        if (v[i] > x) {
            return -1; // passou do lugar onde x estaria
        }
    }
    return -1;
}

int main(void) {
    int precos[] = {12, 19, 25, 31, 38, 44, 52, 60, 73, 89};
    int n = 10;
    int chaves[] = {47, 60};
    int a, b;

    for (int k = 0; k < 2; k++) {
        int p1 = busca(precos, n, chaves[k], &a);
        int p2 = busca_ordenada(precos, n, chaves[k], &b);
        printf("R$ %d: comum %d (%d olhados), ordenada %d (%d olhados)\n",
               chaves[k], p1, a, p2, b);
    }
    return 0;
}

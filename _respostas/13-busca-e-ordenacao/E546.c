// 0091 · Bubble sort
// Exercício E546 · ★★★
//
// Cada troca de vizinhos a > b desfaz exatamente a inversão entre eles e não
// mexe na ordem relativa dos outros pares: por isso trocas = inversões, e o
// vetor ordenado termina com 0.

#include <stdio.h>

int inversoes(const int v[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                total++;
            }
        }
    }
    return total;
}

int trocas_bubble(int v[], int n) {
    int trocas = 0;
    for (int p = 1; p < n; p++) {
        for (int j = 0; j < n - p; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                trocas++;
            }
        }
    }
    return trocas;
}

void testa(int v[], int n) {
    int inv = inversoes(v, n);       // conta antes de ordenar
    int tr = trocas_bubble(v, n);
    printf("n = %d: %d inversões, %d trocas, %d depois\n", n, inv, tr, inversoes(v, n));
}

int main(void) {
    int a[] = {42, 17, 35, 8, 23};
    int b[] = {6, 5, 4, 3, 2, 1};
    int c[] = {3, 1, 2};
    testa(a, 5);
    testa(b, 6);
    testa(c, 3);
    return 0;
}

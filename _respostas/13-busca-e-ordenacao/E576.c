// 0096 · Bubble sort
// Exercício E576 · ★★★
//
// Por que sempre dá igual: o bubble só troca VIZINHOS fora de ordem. Trocar
// dois vizinhos a > b desfaz exatamente a inversão entre eles e não muda a
// ordem relativa de nenhum outro par (quem estava antes dos dois continua
// antes, quem estava depois continua depois). Então cada troca diminui as
// inversões em 1, e o vetor ordenado tem 0 inversões: trocas = inversões.
// No pior caso (invertido), todos os n(n-1)/2 pares são inversões.

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
    printf("n = %d: %d inversões, %d trocas\n", n, inv, tr);
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

// 0102 · Heap e fila de prioridade
// Exercício E608 · ★☆☆

#include <stdio.h>
#include <stdbool.h>

bool eh_heap(const int v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i] > v[(i - 1) / 2]) {
            return false; // filho maior que o pai
        }
    }
    return true;
}

int main(void) {
    int a[] = {95, 60, 80, 20, 60, 75, 10};
    int b[] = {50, 40, 45, 42, 10, 30, 44};
    int c[] = {7};
    int d[] = {10, 20};
    int e[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("a) %s\n", eh_heap(a, 7) ? "heap" : "não é heap");
    printf("b) %s\n", eh_heap(b, 7) ? "heap" : "não é heap");
    printf("c) %s\n", eh_heap(c, 1) ? "heap" : "não é heap");
    printf("d) %s\n", eh_heap(d, 2) ? "heap" : "não é heap");
    printf("e) %s\n", eh_heap(e, 9) ? "heap" : "não é heap");
    return 0;
}

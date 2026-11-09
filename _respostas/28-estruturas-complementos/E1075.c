// 0180 · Pigeonhole e chave composta
// Exercício E1075 · ★☆☆

#include <stdio.h>

#define MIN 18
#define MAX 25

int main(void) {
    int idades[] = {22, 19, 25, 18, 22, 20, 19, 24, 22, 18};
    int n = 10;
    int casa[MAX - MIN + 1] = {0}; // uma casa para cada idade possível
    for (int i = 0; i < n; i++) {
        casa[idades[i] - MIN]++;
    }
    int usadas = 0;
    for (int c = 0; c <= MAX - MIN; c++) {
        usadas += casa[c] > 0;
    }
    int k = 0;
    for (int c = 0; c <= MAX - MIN; c++) {
        while (casa[c] > 0) {
            idades[k++] = c + MIN;
            casa[c]--;
        }
    }
    printf("ordenadas:");
    for (int i = 0; i < n; i++) {
        printf(" %d", idades[i]);
    }
    printf("\ncasas usadas: %d de %d\n", usadas, MAX - MIN + 1);
    return 0;
}

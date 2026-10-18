// 0126 · Permutações
// Exercício E755 · ★★★
//
// Resposta: a chamada recursiva usava j + 1. Quando j > i, a recursão pulava
// posições (a posição i + 1 nunca era decidida naquele ramo) e várias ordens
// sumiam. A próxima posição a decidir é sempre i + 1.

#include <stdio.h>

#define N 4

int total = 0;

void troca(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void embaralha(char v[], int i) {
    if (i == N) {
        total++;
        printf("%s%s", v, total % 6 == 0 ? "\n" : " ");
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);
        embaralha(v, i + 1); // a próxima posição é i + 1
        troca(&v[i], &v[j]);
    }
}

int main(void) {
    char cartas[N + 1] = "A234";
    embaralha(cartas, 0);
    if (total % 6 != 0) {
        printf("\n");
    }
    printf("%d ordens\n", total);
    return 0;
}

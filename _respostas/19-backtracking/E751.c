// 0126 · Permutações
// Exercício E751 · ★☆☆

#include <stdio.h>

#define N 3

int soma = 0;

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void senhas(int v[], int i) {
    if (i == N) {
        int numero = 0;
        for (int k = 0; k < N; k++) {
            numero = numero * 10 + v[k];
        }
        printf("%d\n", numero);
        soma += numero;
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);
        senhas(v, i + 1);
        troca(&v[i], &v[j]);
    }
}

int main(void) {
    int digitos[N] = {4, 7, 9};
    senhas(digitos, 0);
    printf("soma: %d\n", soma);
    return 0;
}

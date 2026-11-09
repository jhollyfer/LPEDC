// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1805 · ★☆☆ · O 3º posto mais barato, partição por partição

#include <stdio.h>

#define N 9

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particiona(int v[], int ini, int fim) { // Lomuto: pivô no fim
    int pivo = v[fim], i = ini;
    for (int j = ini; j < fim; j++)
        if (v[j] < pivo) troca(&v[i++], &v[j]);
    troca(&v[i], &v[fim]);
    return i;
}

int quickselect(int v[], int n, int k) {
    int ini = 0, fim = n - 1, alvo = k - 1;
    while (ini <= fim) {
        int pivo = v[fim];
        int p = particiona(v, ini, fim);
        printf("[%d, %d] pivô %d foi para %d -> ", ini, fim, pivo, p);
        if (p == alvo) {
            printf("achou\n");
            return v[p];
        }
        if (alvo < p) {
            printf("esquerda\n");
            fim = p - 1;
        } else {
            printf("direita\n");
            ini = p + 1;
        }
    }
    return -1;
}

int main(void) {
    int preco[N] = {629, 575, 612, 599, 589, 649, 579, 605, 594};
    int r = quickselect(preco, N, 3);
    printf("3º menor preço: %d centavos (R$ %d,%02d)\n", r, r / 100, r % 100);
    return 0;
}

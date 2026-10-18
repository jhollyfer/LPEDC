// 0047 · Ponteiros e vetores
// Exercício E279 · ★★☆

#include <stdio.h>

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void inverte(int *v, int n) {
    int *ini = v;
    int *fim = v + n - 1;
    while (ini < fim) {
        troca(ini, fim);
        ini++;
        fim--;
    }
}

int main(void) {
    int faixas[7] = {11, 23, 35, 47, 52, 68, 74};

    inverte(faixas, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", faixas[i]);
    }
    printf("\n");
    return 0;
}

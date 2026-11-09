// 0168 · Complexidade espacial
// Exercício E1004 · ★☆☆

#include <stdio.h>

// conta pares e ímpares sem copiar nada: Θ(1) de espaço extra
void separa(const int senhas[], int n, int *pares, int *impares) {
    *pares = 0;
    *impares = 0;
    for (int i = 0; i < n; i++) {
        if (senhas[i] % 2 == 0) {
            (*pares)++;
        } else {
            (*impares)++;
        }
    }
}

int main(void) {
    int senhas[10] = {41, 12, 7, 30, 18, 25, 4, 16, 9, 22};
    int pares, impares;
    separa(senhas, 10, &pares, &impares);
    printf("pares: %d, ímpares: %d\n", pares, impares);
    return 0;
}

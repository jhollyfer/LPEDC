// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1030 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 3000000;
    double *precos = malloc(n * sizeof *precos); // 24 MB no heap
    if (precos == NULL) {
        printf("sem memória\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        precos[i] = i % 100 + 0.5;
    }

    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += precos[i];
    }
    printf("n = %d, media = R$ %.2f\n", n, soma / n);
    free(precos);
    return 0;
}

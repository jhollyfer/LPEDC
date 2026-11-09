// Lista · Módulo 03 · Laços
// Exercício P0316 · ★★☆ · O triângulo de Floyd

#include <stdio.h>

int main(void) {
    int n = 1;
    int soma = 0;

    for (int linha = 1; linha <= 5; linha++) {
        soma = 0;
        for (int col = 1; col <= linha; col++) {
            printf("%3d", n);
            soma += n;
            n++;
        }
        printf("\n");
    }
    printf("Soma da linha 5: %d\n", soma);
    return 0;
}

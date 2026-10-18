// 0055 · calloc e realloc
// Exercício E327 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int capacidade = 2;
    int quantidade = 0;
    int *numeros = malloc(capacidade * sizeof *numeros);
    if (numeros == NULL) {
        return 1;
    }

    printf("Números (0 para parar): ");
    int x;
    while (scanf("%d", &x) == 1 && x != 0) {
        if (quantidade == capacidade) {
            int *maior = realloc(numeros, 2 * capacidade * sizeof *numeros);
            if (maior == NULL) {
                free(numeros);
                return 1;
            }
            numeros = maior;
            capacidade *= 2;
        }
        numeros[quantidade++] = x;
    }

    printf("Ao contrário:");
    for (int i = quantidade - 1; i >= 0; i--) {
        printf(" %d", numeros[i]);
    }
    printf("\nCapacidade final: %d\n", capacidade);
    free(numeros);
    return 0;
}
// Exemplo de uso:
// Números (0 para parar): 5 8 2 9 4 0
// Ao contrário: 4 9 2 8 5
// Capacidade final: 8

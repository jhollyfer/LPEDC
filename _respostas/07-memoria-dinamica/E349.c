// 0059 · malloc e free
// Exercício E349 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int dias;
    printf("Quantos dias? ");
    if (scanf("%d", &dias) != 1 || dias <= 0) {
        printf("Quantidade inválida\n");
        return 1;
    }
    int *temps = malloc(dias * sizeof(int));
    if (temps == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    for (int i = 0; i < dias; i++) {
        printf("Temperatura %d: ", i + 1);
        if (scanf("%d", &temps[i]) != 1) {
            free(temps);
            return 1;
        }
    }
    int maior = temps[0];
    int menor = temps[0];
    for (int i = 1; i < dias; i++) {
        if (temps[i] > maior) {
            maior = temps[i];
        }
        if (temps[i] < menor) {
            menor = temps[i];
        }
    }
    printf("Máxima: %d\n", maior);
    printf("Mínima: %d\n", menor);
    free(temps);
    return 0;
}

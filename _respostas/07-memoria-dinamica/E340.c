// 0057 · Erros de memória
// Exercício E340 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *original = "QTX3E21";
    char *placa = malloc(strlen(original) + 1); // + 1 para o '\0'
    if (placa == NULL) {
        return 1;
    }
    strcpy(placa, original);

    int dias = 5;
    int *km = malloc(dias * sizeof *km);
    if (km == NULL) {
        free(placa);
        return 1;
    }
    km[0] = 42;
    km[1] = 55;
    km[2] = 38;
    km[3] = 61;
    km[4] = 42;

    int total = 0;
    for (int i = 0; i < dias; i++) { // índices 0 a 4
        total += km[i];
    }
    printf("Placa: %s\n", placa);
    printf("Km da semana: %d\n", total);
    free(km);
    free(placa);
    return 0;
}

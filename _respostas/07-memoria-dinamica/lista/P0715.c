// Lista · Módulo 07 · Memória dinâmica
// Exercício P0715 · ★★☆ · Conserte o diário de bordo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *nome_barco = "Comandante Paiva";
    char *barco = malloc(strlen(nome_barco) + 1); // + 1 do '\0'
    if (barco == NULL) {
        return 1;
    }
    strcpy(barco, nome_barco);

    int horas[5] = {0, 6, 14, 20, 31}; // horas de viagem até cada parada
    int cap = 2, n = 0;
    int *paradas = malloc(cap * sizeof *paradas);
    if (paradas == NULL) {
        free(barco);
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        if (n == cap) {
            int *novo = realloc(paradas, cap * 2 * sizeof *paradas); // bytes
            if (novo == NULL) {
                free(paradas); // o bloco antigo continua valendo
                free(barco);
                return 1;
            }
            paradas = novo;
            cap *= 2;
        }
        paradas[n++] = horas[i];
    }

    printf("Barco: %s\n", barco);
    printf("Paradas (h):");
    for (int i = 0; i < n; i++) {
        printf(" %d", paradas[i]);
    }
    printf("\nViagem total: %d horas\n", paradas[n - 1]);
    free(paradas);
    free(barco);
    return 0;
}

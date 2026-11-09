// Lista · Módulo 07 · Memória dinâmica
// Exercício P0705 · ★☆☆ · Conserte os dois free

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int total_paes = 0;
    int *encomendas = malloc(4 * sizeof *encomendas);
    if (encomendas == NULL) {
        return 1;
    }
    encomendas[0] = 30; // pães da dona Graça
    encomendas[1] = 12;
    encomendas[2] = 50;
    encomendas[3] = 8;

    for (int i = 0; i < 4; i++) {
        total_paes += encomendas[i];
    }

    printf("Maior encomenda: %d\n", encomendas[2]);
    printf("Total: %d pães\n", total_paes);
    free(encomendas); // só depois do último uso
    // total_paes mora na pilha: não se passa para o free
    return 0;
}

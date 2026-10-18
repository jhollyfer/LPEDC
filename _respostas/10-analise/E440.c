// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E440 · ★☆☆

#include <stdio.h>

#include "contador.h"

int main(void) {
    Contador *fila = contador_cria(50);
    if (fila == NULL) {
        return 1;
    }
    contador_incrementa(fila);
    contador_incrementa(fila);
    printf("Na fila: %d\n", contador_valor(fila));

    contador_zera(fila); // fim do expediente
    printf("Na fila: %d\n", contador_valor(fila));

    printf("Tirar da fila vazia: %s\n", contador_decrementa(fila) ? "ok" : "negado");

    contador_libera(fila);
    return 0;
}

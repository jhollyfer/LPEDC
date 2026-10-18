// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E440 · ★☆☆
//
// Resposta: a) no cliente, struct contador é um tipo incompleto: o compilador
// não conhece os campos nem o tamanho, então não deixa usar ->; b) para
// proteger o invariante 0 <= valor <= limite: só o contador.c mexe nos
// campos. Conserto: contador_valor para ler e contador_zera para zerar.

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

    contador_libera(fila);
    return 0;
}

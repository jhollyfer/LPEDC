// 0050 · Ponteiros
// Exercício E297 · ★★☆
//
// Resposta: (1) faltava o * em meta_ptr na declaração; (2) meta_ptr = meta
// guardava o valor, o certo é &meta; (3) peso_ptr não apontava para nada
// antes de *peso_ptr = 82.

#include <stdio.h>

int main(void) {
    int peso = 0, meta = 78;
    int *peso_ptr, *meta_ptr;

    peso_ptr = &peso;
    *peso_ptr = 82;
    meta_ptr = &meta;

    printf("Peso: %d\n", peso);
    printf("Meta: %d\n", *meta_ptr);
    return 0;
}

// A123 · O carrinho que não vaza

#include <stdio.h>
#include <stdlib.h>

// Soma os preços de um pedido. A cópia é temporária: nasce e morre aqui.
int total_do_pedido(const int *precos, int itens) {
    int *copia = malloc(itens * sizeof *copia);
    if (copia == NULL) {
        return -1;
    }
    int total = 0;
    for (int i = 0; i < itens; i++) {
        copia[i] = precos[i];
        total += copia[i];
    }
    free(copia); // sem esta linha, cada pedido deixaria 16 bytes para trás
    return total;
}

int main(void) {
    int pedido[] = {30, 12, 45, 8};
    for (int p = 1; p <= 3; p++) {
        printf("Pedido %d: R$ %d\n", p, total_do_pedido(pedido, 4));
    }
    return 0;
}
// Saída:
// Pedido 1: R$ 95
// Pedido 2: R$ 95
// Pedido 3: R$ 95
//
// Apague o free(copia) e rode de novo: a saída é a mesma, mas no fim o
// LeakSanitizer (parte do AddressSanitizer) avisa:
//   ERROR: LeakSanitizer: detected memory leaks
//   Direct leak of 48 byte(s) in 3 object(s) allocated from:
//       #1 ... in total_do_pedido A123.c:8

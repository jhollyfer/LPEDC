// Lista · Módulo 02 · Decisões
// Exercício P0213 · ★★☆ · A divisão por zero do estoque

#include <stdio.h>

int main(void) {
    int estoque = 0;
    int pedido = 5;

    printf("Estoque: %d, pedido: %d\n", estoque, pedido);
    if (estoque > 0 && pedido / estoque >= 2) { // com estoque 0, a divisão nem roda
        printf("Pedido grande: confira antes de vender.\n");
    } else if (estoque == 0) {
        printf("Sem estoque: avise o cliente.\n");
    } else {
        printf("Pedido normal.\n");
    }
    return 0;
}

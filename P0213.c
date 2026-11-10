// Lista · Módulo 02 · Decisões
// Exercício P0213 · ★★☆ · A divisão por zero do estoque
//
// A loja quer avisar quando o pedido é maior que o dobro do estoque. O programa
// abaixo testa pedido / estoque >= 2 e, com estoque zerado, divide por zero e
// quebra. O bug está lá de propósito. Conserte só a condição, usando o
// curto-circuito do &&, para que a divisão nunca aconteça com estoque 0:
//
//   Saída esperada:
//   Estoque: 0, pedido: 5
//   Sem estoque: avise o cliente.
//
// Dicas:
// 1. Em a && b, se a for falso, o C nem calcula b.
// 2. Ponha estoque > 0 ANTES da divisão: estoque > 0 && pedido / estoque >= 2.
// 3. Resposta esperada: Sem estoque: avise o cliente.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int estoque = 0;
    int pedido = 5;

    printf("Estoque: %d, pedido: %d\n", estoque, pedido);
    if (pedido / estoque >= 2 && estoque > 0) {
        printf("Pedido grande: confira antes de vender.\n");
    } else if (estoque == 0) {
        printf("Sem estoque: avise o cliente.\n");
    } else {
        printf("Pedido normal.\n");
    }
    return 0;
}

// A324 · O total de cada pedido

#include <stdio.h>
#include "esparsa.h"

#define PRODUTOS 1000 // o catálogo inteiro

int main(void) {
    // preço de cada produto do catálogo, em centavos (vetor cheio)
    int preco[PRODUTOS];
    for (int j = 0; j < PRODUTOS; j++) {
        preco[j] = 250 + (j % 40) * 50;
    }

    // 4 pedidos x 1000 produtos; cada pedido leva poucos itens
    Esparsa *pedidos = esp_cria(4, PRODUTOS);
    esp_define(pedidos, 0, 12, 2);  // pedido 0: 2 unidades do produto 12
    esp_define(pedidos, 0, 731, 1);
    esp_define(pedidos, 1, 40, 6);
    esp_define(pedidos, 2, 5, 1);
    esp_define(pedidos, 2, 999, 3);
    esp_define(pedidos, 2, 500, 2);
    esp_define(pedidos, 3, 12, 1);

    // total[i] = soma de quantidade x preço, só nas células da linha i
    int contas = 0;
    for (int i = 0; i < pedidos->linhas; i++) {
        int total = 0;
        for (const Celula *c = pedidos->linha[i]; c != NULL; c = c->prox) {
            total += c->valor * preco[c->col];
            contas++;
        }
        printf("Pedido %d: R$ %d,%02d\n", i, total / 100, total % 100);
    }
    printf("Multiplicações: %d (a matriz cheia faria %d)\n", contas, 4 * PRODUTOS);

    esp_libera(pedidos);
    return 0;
}
// Saída:
// Pedido 0: R$ 25,00
// Pedido 1: R$ 15,00
// Pedido 2: R$ 96,00
// Pedido 3: R$ 8,50
// Multiplicações: 7 (a matriz cheia faria 4000)

// 0106 · Encadeamento
// Exercício E633 · ★★☆
//
// No balcão da pizzaria, os pedidos prontos ficam numa tabela com 4 baldes e
// encadeamento (h = pedido % 4, inserção no início da corrente). Quando o
// cliente retira, o pedido sai da tabela. Escreva do zero: o nó, insere,
// "bool remove_pedido(No *baldes[], int pedido)", mostra e libera. Insira
// 101, 205, 309, 120, 222 e 315, mostre, retire 205, 309 e 999, e mostre de
// novo.
//
//   Saída esperada:
//   [0] 120
//   [1] 309 205 101
//   [2] 222
//   [3] 315
//   pedido 205 retirado
//   pedido 309 retirado
//   pedido 999 não existe
//   [0] 120
//   [1] 101
//   [2] 222
//   [3] 315
//
// Dicas:
// 1. É a remoção de lista encadeada do módulo 11, aplicada só à corrente
//    de baldes[pedido % 4]. Guarde o anterior enquanto anda.
// 2. Cuidado com o primeiro nó da corrente (o 309): não tem anterior, então
//    quem muda é a própria cabeça, baldes[1].
// 3. Resposta esperada: a saída acima, e o AddressSanitizer quieto (todo nó
//    removido leva free, e o libera solta o resto).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

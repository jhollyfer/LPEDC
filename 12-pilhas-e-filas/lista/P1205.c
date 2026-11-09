// Lista · Módulo 12 · Pilhas e filas
// Exercício P1205 · ★☆☆ · A fila do forno da pizzaria
//
// Os pedidos entram no forno na ordem em que chegam. Escreva uma fila
// ENCADEADA de pedidos (nome do cliente e sabor), com ponteiros para o
// início e o fim, e as operações entra (no fim), sai (do início, copiando o
// pedido e liberando o nó) e tamanho (guardado num campo, O(1)). Faça:
// entram Ana/calabresa, Beto/marguerita e Caio/portuguesa; sai um; entra
// Duda/frango; mostre o tamanho e esvazie a fila.
//
//   Saída esperada:
//   Saiu: Ana (calabresa)
//   Na fila: 3 pedidos
//   Saiu: Beto (marguerita)
//   Saiu: Caio (portuguesa)
//   Saiu: Duda (frango)
//   Na fila: 0 pedidos
//
// Dicas:
// 1. typedef struct { Pedido *inicio, *fim; int n; } Fila; começando com
//    {NULL, NULL, 0}.
// 2. Quando a fila esvazia em sai, o fim também tem que voltar a NULL. Se
//    não voltar, a próxima entrada escreve num nó já liberado.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedido {
    char cliente[16];
    char sabor[16];
    struct pedido *prox;
} Pedido;

int main(void) {

    return 0;
}

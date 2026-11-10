// 0086 · Fila encadeada
// Exercício E514 · ★★☆
//
// A fila de pedidos da cozinha é encadeada, com ponteiros para o início e para o
// fim. Com os tipos abaixo, escreva bool cozinha_entra(Cozinha *f, int numero) e
// bool cozinha_sai(Cozinha *f, int *numero), que libera o nó. A fila tem que
// continuar funcionando depois de esvaziar e receber pedidos novos. No main,
// entrem os pedidos 11 e 12 e saiam todos; entrem 13 e 14 e saiam todos,
// mostrando "Pronto: N" a cada saída.
//
//   Saída esperada:
//   Pronto: 11
//   Pronto: 12
//   Pronto: 13
//   Pronto: 14
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pedido {
    int numero;
    struct pedido *prox;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Cozinha;

int main(void) {

    return 0;
}

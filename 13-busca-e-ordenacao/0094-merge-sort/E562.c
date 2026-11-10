// 0094 · Merge sort
// Exercício E562 · ★★☆
//
// A fila de pedidos de uma padaria chegou nesta ordem:
//
//   typedef struct { char cliente[8]; int valor; } Pedido;
//   {"Ana", 50}, {"Bruno", 30}, {"Carla", 50}, {"Davi", 30}, {"Eva", 20}
//
// Ordene por valor com merge sort (adapte o código do assunto para Pedido) e
// mostre a fila. Quem empatou no valor deve continuar na ordem de chegada
// (Bruno antes de Davi, Ana antes de Carla). Para ver o papel do <= da
// intercalação, dê à intercala (e ao merge_sort) um parâmetro bool estavel:
// verdadeiro compara com <=, falso compara com <. Ordene duas cópias da fila,
// uma de cada jeito, e mostre as duas.
//
//   Saída esperada:
//   com <=: Eva 20, Bruno 30, Davi 30, Ana 50, Carla 50
//   com <:  Eva 20, Davi 30, Bruno 30, Carla 50, Ana 50
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

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
// Dicas:
// 1. O rascunho agora é Pedido *w = malloc(n * sizeof *w); confira NULL e
//    dê free no fim.
// 2. Compare v[i].valor <= v[j].valor; copie a struct inteira com =.
// 3. A condição pode ser (estavel ? v[i].valor <= v[j].valor
//    : v[i].valor < v[j].valor).
// 4. Resposta esperada: a saída acima. Com <, no empate a intercalação pega
//    o da direita primeiro e o merge sort deixa de ser estável.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

// 0099 · Merge sort
// Exercício E592 · ★★☆
//
// A fila de pedidos de uma padaria chegou nesta ordem:
//
//   typedef struct { char cliente[8]; int valor; } Pedido;
//   {"Ana", 50}, {"Bruno", 30}, {"Carla", 50}, {"Davi", 30}, {"Eva", 20}
//
// Ordene por valor com merge sort (adapte o A197 para Pedido) e mostre a
// fila. Quem empatou no valor deve continuar na ordem de chegada (Bruno antes
// de Davi, Ana antes de Carla). Depois troque o <= da intercalação por < e
// anote, num comentário, o que muda.
//
//   Saída esperada:
//   Eva 20, Bruno 30, Davi 30, Ana 50, Carla 50
//
// Dicas:
// 1. O rascunho agora é Pedido *w = malloc(n * sizeof *w); confira NULL e
//    dê free no fim.
// 2. Compare v[i].valor <= v[j].valor; copie a struct inteira com =.
// 3. Com <, no empate a intercalação pega o da direita primeiro.
// 4. Resposta esperada: a saída acima; com <, sai Eva 20, Davi 30, Bruno 30,
//    Carla 50, Ana 50 (deixa de ser estável).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

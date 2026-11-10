// 0116 · Análise amortizada
// Exercício E695 · ★★★
//
// Monte uma fila de pedidos com duas pilhas, entrada e saida. enfileira(x)
// empilha x na entrada; desenfileira() passa TODOS os itens da entrada para a
// saida se esta estiver vazia e desempilha da saida, devolvendo o custo (1 +
// transferências) por um ponteiro. Conte as transferências num contador
// global. Sequência: enfileira 1 a 5, atende 2, enfileira 6 e 7, atende 4,
// enfileira 8, atende 2. Depois, com as pilhas zeradas, faça 1 milhão de
// operações: na operação i, se i for múltiplo de 3 e a fila não estiver
// vazia, atenda; senão, enfileire i.
//
//   Saída esperada:
//   atendidos: 1 2 3 4 5 6 7 8
//   8 pedidos, 8 transferências
//   666667 enfileirados, 524286 transferências, pior atendimento: 262145
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 1000000

int main(void) {

    return 0;
}

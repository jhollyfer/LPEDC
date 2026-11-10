// 0116 · Análise amortizada
// Exercício E695 · ★★★
//
// A gráfica do bairro só tem pilhas no sistema, mas precisa de uma FILA de
// pedidos (o primeiro a chegar é o primeiro a sair). Monte a fila com duas
// pilhas, entrada e saida:
//
// - enfileira(x): empilha x na entrada;
// - desenfileira(): se a saida estiver vazia, passa TODOS os itens da
// entrada para a saida (um por um, desempilhando de uma e empilhando na
// outra: isso inverte a ordem); depois desempilha da saida.
//
// Conte as transferências num contador global. Faça desenfileira devolver
// também o custo da operação (1 + transferências feitas nela), por um
// ponteiro. Rode esta sequência: enfileira 1 a 5, atende 2, enfileira 6 e
// 7, atende 4, enfileira 8, atende 2. Depois, com as pilhas zeradas, faça
// 1 milhão de operações: na operação i (de 1 a 1000000), se i for múltiplo
// de 3 e a fila não estiver vazia, atenda; senão, enfileire i.
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

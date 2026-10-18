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
// Dicas:
// 1. Pilhas de 1 milhão de int ocupam 4 MB cada: declare-as como
//    variáveis globais, não dentro do main (a pilha de chamadas tem uns
//    8 MB e estouraria).
// 2. Cada pedido é transferido no máximo UMA vez: entra na entrada, passa
//    para a saida, sai. Por isso as transferências nunca passam do número
//    de enfileirados, e cada operação custa O(1) amortizado.
// 3. O "pior atendimento" mostra o outro lado: uma única operação chegou a
//    mover 262.144 pedidos de uma vez.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 1000000

int main(void) {

    return 0;
}

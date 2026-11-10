// 0106 · Encadeamento
// Exercício E636 · ★★★
//
// No encadeamento a tabela nunca enche, mas as correntes crescem. A solução
// das bibliotecas é o rehash: quando o fator de carga passa de 1 (n > m), a
// tabela cria um vetor de baldes com 2 * m + 1 posições e muda cada nó para o
// balde novo, sem malloc de nó. Escreva a tabela de inteiros (struct com m, n
// e o vetor de baldes, alocado com calloc) com insere, cresce, mostra e
// libera. Comece com m = 2, insira 14, 5, 23, 8, 19, 40, 12, 31, 21 e 2, avise
// cada vez que a tabela crescer e mostre o resultado.
//
//   Saída esperada:
//   cresceu: m = 5
//   cresceu: m = 11
//   n = 10, m = 11
//   [0]
//   [1] 12 23
//   [2] 2
//   [3] 14
//   [4]
//   [5] 5
//   [6]
//   [7] 40
//   [8] 19 8
//   [9] 31
//   [10] 21
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

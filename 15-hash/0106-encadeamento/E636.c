// 0106 · Encadeamento
// Exercício E636 · ★★★
//
// No encadeamento a tabela nunca enche, mas as correntes crescem. A solução
// das bibliotecas é o rehash: quando o fator de carga passa de 1 (n > m), a
// tabela cria um vetor de baldes maior, com 2 * m + 1 posições, e muda cada
// nó para o seu balde novo, sem fazer malloc de nó nenhum.
//
// Escreva a tabela de inteiros (struct com m, n e o vetor de baldes alocado
// com calloc) com insere, cresce, mostra e libera. Comece com m = 2, insira
// 14, 5, 23, 8, 19, 40, 12, 31, 21 e 2, avise cada vez que a tabela crescer
// e mostre o resultado final.
//
//   Saída esperada:
//   cresceu: m = 5
//   cresceu: m = 11
//   n = 10, m = 11
//   [0]
//   [1] 12 23
//   [2] 2
//   ...
//   [10] 21
//
// Dicas:
// 1. O balde de cada nó muda com o m (k % 5 não é k % 11): por isso não dá
//    para copiar o vetor velho, tem que redistribuir nó por nó.
// 2. Para mudar um nó de lugar: guarde p->prox, faça p->prox = novos[i] e
//    novos[i] = p. Depois do laço, free no vetor velho.
// 3. Resposta esperada: cresce ao inserir o 3º número (m vira 5) e o 6º
//    (m vira 11). No fim: [1] 12 23, [2] 2, [3] 14, [5] 5, [7] 40,
//    [8] 19 8, [9] 31, [10] 21 e os outros vazios. A ordem dentro de uma
//    corrente pode mudar conforme a sua implementação; o conteúdo, não.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    return 0;
}

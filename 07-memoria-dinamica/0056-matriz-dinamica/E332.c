// 0056 · Matriz dinâmica
// Exercício E332 · ★☆☆
//
// Uma matriz de 5 linhas e 8 colunas vai morar num bloco único:
// int *v = malloc(5 * 8 * sizeof *v); e o elemento (i, j) fica em
// v[i * 8 + j]. Escreva as duas funções de conversão:
//
//   int indice(int i, int j, int colunas);             // (i, j) -> k
//   void posicao(int k, int colunas, int *i, int *j);  // k -> (i, j)
//
// No main, aloque o bloco, guarde em cada (i, j) o valor i * 10 + j (usando
// indice) e mostre os quatro casos abaixo. O valor guardado confere a conta:
// o 23 só pode estar na linha 2, coluna 3. Libere o bloco no fim.
//
//   Saída esperada:
//   (2, 3) -> índice 19, valor 23
//   (4, 7) -> índice 39, valor 47
//   (0, 5) -> índice 5, valor 5
//   índice 26 -> (3, 2), valor 32
//
// Dicas:
// 1. Cada linha completa "pula" 8 posições: k = i * colunas + j.
// 2. Para voltar: *i = k / colunas e *j = k % colunas (os dois resultados
//    voltam por ponteiro, como no assunto 0046).
// 3. Resposta esperada: a saída acima. O (4, 7) cai no índice 39 = 5 * 8 - 1,
//    a última das 40 posições.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

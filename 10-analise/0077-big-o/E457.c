// 0077 · Notação O: como o custo cresce
// Exercício E457 · ★☆☆
//
// Dê a classe O de cada trecho, em função de n. Escreva a resposta como
// comentário e justifique em uma linha (quantas vezes o corpo roda?).
//
//   a) for (i = 0; i < n; i++)  for (j = 0; j < 10; j++)  x++;
//   b) for (i = 1; i < n; i = i * 2)  x++;
//   c) for (i = 0; i < n; i++)  for (j = 0; j < i; j++)  x++;
//   d) x = v[n / 2] + v[0];
//   e) for (i = 0; i < n; i++)  x++;
//      for (j = 0; j < n; j++)  x++;
//   f) for (i = 0; i < n; i++)  for (j = n; j > 1; j = j / 2)  x++;
//
// Dicas:
// 1. Um laço de dentro com tamanho fixo (10) é constante: não depende de n.
// 2. Laços em sequência somam; laços aninhados multiplicam.
// 3. Em c), o de dentro roda 0 + 1 + 2 + ... + (n - 1) = n(n - 1)/2 vezes.
// 4. Resposta esperada: a) O(n) (10n); b) O(log n); c) O(n²); d) O(1);
//    e) O(n) (2n); f) O(n log n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

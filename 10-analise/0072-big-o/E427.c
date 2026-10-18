// 0072 · Notação O: como o custo cresce
// Exercício E427 · ★☆☆
//
// Transforme cada trecho abaixo numa função long trecho_a(int n), ...,
// trecho_f(int n), que roda o trecho e devolve quantas vezes o x++ (ou a
// conta do d) aconteceu. No main, mostre uma tabela com a contagem para
// n = 16 e n = 1024. No rótulo de cada linha, escreva a classe O que a
// contagem indica.
//
//   a) for (i = 0; i < n; i++)  for (j = 0; j < 10; j++)  x++;
//   b) for (i = 1; i < n; i = i * 2)  x++;
//   c) for (i = 0; i < n; i++)  for (j = 0; j < i; j++)  x++;
//   d) x = v[n / 2] + v[0];
//   e) for (i = 0; i < n; i++)  x++;
//      for (j = 0; j < n; j++)  x++;
//   f) for (i = 0; i < n; i++)  for (j = n; j > 1; j = j / 2)  x++;
//
//   Saída esperada:
//   trecho           n=16   n=1024
//   a) O(n)           160    10240
//   b) O(log n)         4       10
//   c) O(n^2)         120   523776
//   d) O(1)             1        1
//   e) O(n)            32     2048
//   f) O(n log n)      64    10240
//
// Dicas:
// 1. No d) não há laço: a função só devolve 1 (use (void)n; para o gcc não
//    reclamar do parâmetro sem uso).
// 2. Um laço de dentro com tamanho fixo (10) não depende de n. Laços em
//    sequência somam; laços aninhados multiplicam.
// 3. Formato da linha: printf("%-14s %6ld %8ld\n", "a) O(n)", ...).
// 4. Resposta esperada: a tabela acima. Repare que a) e f) dão 10240 com
//    n = 1024, mas por motivos diferentes: 10 é constante, log₂ 1024 = 10
//    cresce com n.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

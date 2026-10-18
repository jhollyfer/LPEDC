// 0114 · Recorrências e árvore de recursão
// Exercício E684 · ★★★
//
// Quantas chamadas o fib ingênuo faz? A própria contagem segue uma
// recorrência: fib(n) é 1 chamada mais as chamadas de fib(n-1) e de
// fib(n-2). Com C(n) = número de chamadas:
//
//   C(0) = C(1) = 1
//   C(n) = C(n-1) + C(n-2) + 1
//
// Escreva um programa com três funções:
// - fib(n), a recursiva ingênua, com um contador global de chamadas;
// - conta_chamadas(n), que calcula C(n) com um LAÇO (sem recursão);
// - fib_laco(n), que calcula o Fibonacci F(n) com um laço.
//
// Mostre, para n = 5, 10, ..., 25, as chamadas contadas de verdade, C(n) e a
// fórmula 2F(n+1) - 1. No fim, use só o laço para mostrar C(40) (rodar o
// fib(40) levaria muito tempo) e a razão C(40) / C(39):
//
//   Saída esperada:
//    n  contadas    C(n)  2F(n+1)-1
//    5        15      15         15
//   10       177     177        177
//   15      1973    1973       1973
//   20     21891   21891      21891
//   25    242785  242785     242785
//   C(40) = 331160281
//   C(40) / C(39) = 1.6180
//
// Dicas:
// 1. O laço de conta_chamadas guarda só os dois últimos valores, como o
//    Fibonacci iterativo: proximo = atual + anterior + 1.
// 2. Zere o contador antes de cada fib(n).
// 3. A razão tende a 1,618... (o número de ouro): cada n a mais multiplica
//    as chamadas por 1,6. É isso que quer dizer Θ(1,618ⁿ).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

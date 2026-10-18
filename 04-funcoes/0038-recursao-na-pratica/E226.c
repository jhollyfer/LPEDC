// 0038 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E226 · ★★☆
//
// Sem rodar, responda sobre fib(6) com o código do A075:
//
// a) Quanto vale fib(6)?
// b) Quantas chamadas de fib, no total, fib(6) faz (contando a primeira)?
// c) Quantas vezes fib(2) é calculado?
// d) Qual é o maior número de quadros de fib na pilha ao mesmo tempo?
//
// Depois altere o A075 para conferir (b) e (c): conte as chamadas e, numa
// segunda global, só as chamadas com n == 2.
//
// Dicas:
// 1. Chamadas(n) = 1 + Chamadas(n - 1) + Chamadas(n - 2), com Chamadas(0) =
//    Chamadas(1) = 1. Do A075: Chamadas(5) = 15. Falta Chamadas(4).
// 2. fib(6) chama fib(5) e fib(4); conte quantas vezes fib(2) aparece em cada
//    uma (em fib(5) são 3).
// 3. Resposta esperada: a) 8; b) 25; c) 5; d) 6 (fib(6), fib(5), fib(4),
//    fib(3), fib(2), fib(1)).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

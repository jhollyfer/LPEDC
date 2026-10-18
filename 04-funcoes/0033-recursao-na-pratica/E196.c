// 0033 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E196 · ★★☆
//
// Meça o desperdício do Fibonacci recursivo. Copie o fib do texto (o de duas
// chamadas por vez) e acrescente três globais:
//
//   chamadas      quantas vezes fib foi chamada, no total
//   repetidas     quantas dessas chamadas foram com n == 2
//   maior_altura  o maior número de quadros de fib na pilha ao mesmo tempo
//
// Para a altura, use uma quarta global, altura: some 1 ao entrar em fib e
// tire 1 logo antes de cada return. Mostre tudo para fib(6).
//
//   Saída esperada:
//   fib(6) = 8
//   chamadas: 25
//   fib(2) calculado 5 vezes
//   maior altura: 6
//
// Dicas:
// 1. Ao entrar: chamadas++; altura++; if (altura > maior_altura)
//    maior_altura = altura; e if (n == 2) repetidas++.
// 2. Para tirar 1 da altura antes de devolver, guarde o resultado numa
//    local: int r = fib(n - 1) + fib(n - 2); altura--; return r;
// 3. Resposta esperada: a saída acima. O caminho mais fundo é fib(6),
//    fib(5), fib(4), fib(3), fib(2), fib(1): 6 quadros. A altura cresce
//    devagar (n), mas as chamadas crescem muito rápido.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

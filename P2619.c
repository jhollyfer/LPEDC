// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2619 · ★★☆ · O maior n que cabe no orçamento
//
// O servidor da prefeitura aguenta 100 milhões de operações por consulta.
// Para cada custo, ache o maior n tal que custo(n) <= 100000000: n, n log2 n,
// n², n³ e 2ⁿ. Faça uma busca: dobre n até passar do orçamento e depois
// faça uma busca binária entre o último que coube e o primeiro que não
// coube:
//
//   Saída esperada:
//   n      : n até 100000000
//   n log n: n até 4523071
//   n^2    : n até 10000
//   n^3    : n até 464
//   2^n    : n até 26
//
// Dicas:
// 1. Calcule os custos em double: n³ e 2ⁿ estouram long rápido.
// 2. Guarde os cinco custos num vetor de ponteiros para função double
//    f(double n).
// 3. O orçamento que roda 100 milhões em Θ(n) roda só 26 em Θ(2ⁿ).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}

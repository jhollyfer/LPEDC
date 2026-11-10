// Lista · Módulo 04 · Funções e modularização
// Exercício P0427 · ★★★ · As marcas da régua
//
// Uma régua tem marcas de tamanhos diferentes: a do meio é a maior, as do meio
// de cada metade são um pouco menores, e assim por diante. Isso é recursão
// pura: a régua de ordem n é uma régua de ordem n − 1, uma marca de tamanho n e
// outra régua de ordem n − 1. Escreva "void regua(int n)" e "void marca(int
// tamanho)", e mostre a régua de ordem 4 (uma marca por linha) e quantas vezes
// regua foi chamada:
//
//   Saída esperada:
//   -
//   --
//   -
//   ---
//   -
//   --
//   -
//   ----
//   -
//   --
//   -
//   ---
//   -
//   --
//   -
//   Chamadas de regua: 31
//
// Dicas:
// 1. Caso base: regua(0) não faz nada.
// 2. Caso recursivo: regua(n - 1); marca(n); regua(n - 1);.
// 3. A estrutura é a mesma da Torre de Hanói: as marcas são 2^n − 1 e as
//    chamadas são 2^(n + 1) − 1.
// 4. Resposta esperada: 15 marcas e 31 chamadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// 0118 · Juntando tudo
// Exercício E706 · ★★☆
//
// Descubra a classe de uma função dobrando n. Escreva quatro "long
// misterio_x(long n)" que devolvem os passos (um passos++ no laço mais
// interno) e "const char *classe(long (*f)(long), double *razao)", que guarda
// f(128) / f(64) em *razao e devolve a classe: razão abaixo de 2,15, Θ(n);
// abaixo de 3, Θ(n log n); abaixo de 6, Θ(n²); senão Θ(n³). a: i de 0 a n-1,
// j de i+1 a n-1. b: recursiva, 1 se n <= 1, senão b(n/2) + b(n - n/2) + 1.
// c: i de 0 a n-1, j de 1 a n-1 dobrando (j *= 2). d: i e j de 0 a n-1, k de
// j a n-1 de 2 em 2.
//
//   Saída esperada:
//   misterio_a: dobrou n, custo x4.03 -> Θ(n²)
//   misterio_b: dobrou n, custo x2.01 -> Θ(n)
//   misterio_c: dobrou n, custo x2.33 -> Θ(n log n)
//   misterio_d: dobrou n, custo x7.88 -> Θ(n³)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

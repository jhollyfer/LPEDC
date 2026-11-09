// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1803 · ★☆☆ · Radix com base 100: dois dígitos por passada
//
// As matrículas dos calouros têm 6 dígitos. Em base 10, o radix sort LSD faz
// 6 passadas. Em base 100, cada "dígito" é um par de dígitos decimais (de 00
// a 99), e bastam 3 passadas: (m / 1) % 100, (m / 100) % 100 e
// (m / 10000) % 100.
//
// Escreva o radix sort LSD em base 100, com um counting sort estável de 100
// posições em cada passada, e mostre o vetor depois de cada passada, com o
// divisor usado.
//
//   Saída esperada:
//   div     1: 230105 190305 241012 241077 210477 230388 180399
//   div   100: 230105 190305 230388 180399 210477 241012 241077
//   div 10000: 180399 190305 210477 230105 230388 241012 241077
//
// Dicas:
// 1. Mesma estrutura do radix em base 10: só troque 10 por 100. O vetor C
//    passa a ter 100 posições.
// 2. Com d passadas de base b, o custo é Θ(d (n + b)). Aqui d = 3 e b = 100
//    contra d = 6 e b = 10: com poucos números, b = 100 pesa; com milhões,
//    metade das passadas ganha.
// 3. Depois da primeira passada, o vetor está ordenado pelos dois últimos
//    dígitos; depois da segunda, pelos quatro últimos.
// 4. Resposta esperada: na primeira passada, 230105 e 190305 (final 05) vêm
//    antes de 241012; no fim, 180399 190305 210477 230105 230388 241012
//    241077.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 7

int main(void) {
    int mat[N] = {241077, 230105, 241012, 190305, 230388, 180399, 210477};

    for (int i = 0; i < N; i++) printf("%d ", mat[i]);
    printf("\n");
    return 0;
}

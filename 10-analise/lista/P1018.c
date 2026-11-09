// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1018 · ★★☆ · Euclides, o invariante e o pior caso
//
// O marceneiro quer cortar duas tábuas em pedaços iguais, do maior tamanho
// possível: é o mdc dos comprimentos. Escreva int mdc(int a, int b, int
// *passos), o algoritmo de Euclides iterativo (troca (a, b) por (b, a % b)
// até b == 0), contando as divisões. Ponha um assert com o invariante: o
// mdc do par atual é sempre o mesmo do par original. Para conferir, escreva
// int mdc_lento(int a, int b), que testa os divisores de cima para baixo.
// Teste com (1071, 462), (89, 55) e (100, 75).
//
//   Saída esperada:
//   mdc(1071, 462) = 21 em 3 passos
//   mdc(89, 55) = 1 em 9 passos
//   mdc(100, 75) = 25 em 2 passos
//
// Dicas:
// 1. Guarde g = mdc_lento(a, b) antes do laço e, no começo de cada volta,
//    assert(mdc_lento(a, b) == g). Cuidado: mdc_lento(x, 0) é x.
// 2. O invariante vale porque todo divisor de a e b também divide a % b
//    (e vice-versa).
// 3. Dois Fibonacci seguidos (89 e 55) são o pior caso de Euclides: cada
//    passo só desce um degrau na sequência. Mesmo assim o número de passos
//    é O(log n).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdio.h>

int main(void) {

    return 0;
}

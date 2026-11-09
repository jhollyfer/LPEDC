// Lista · Módulo 07 · Memória dinâmica
// Exercício P0726 · ★★★ · Multiplicar polinômios
//
// Um polinômio de grau g pode ser guardado como g + 1 coeficientes, do termo
// independente para o de maior grau: 3 - 2x + x² vira {3, -2, 1}. Escreva:
//
//   int *mult_poli(const int *p, int gp, const int *q, int gq, int *gr);
//   long long valor(const int *p, int g, int x);
//   void mostrar(const int *p, int g);
//
// mult_poli devolve um vetor novo (calloc) com o produto, de grau gp + gq:
// o coeficiente k soma p[i] * q[j] para todo i + j = k. valor calcula p(x)
// pelo método de Horner (de dentro para fora: ((a3 x + a2) x + a1) x + a0).
// Com p = 3 - 2x + x² e q = 1 + 4x, mostre p, q, o produto, e confira que
// r(2) = p(2) * q(2). Depois eleve (1 + x) à quinta potência multiplicando
// cinco vezes:
//
//   Saída esperada:
//   p(x) = 3 - 2x + x^2
//   q(x) = 1 + 4x
//   r(x) = 3 + 10x - 7x^2 + 4x^3
//   r(2) = 27; p(2) * q(2) = 27
//   (1 + x)^5 = 1 + 5x + 10x^2 + 10x^3 + 5x^4 + x^5
//
// Dicas:
// 1. O vetor do produto tem gp + gq + 1 casas, todas começando em 0 (por
//    isso calloc): r[i + j] += p[i] * q[j].
// 2. Horner: r = 0; para i de g até 0: r = r * x + p[i].
// 3. Para a potência, guarde o resultado atual, multiplique, libere o
//    antigo e fique com o novo. Comece com o polinômio 1 (grau 0).
// 4. No mostrar, pule coeficientes zero e mostre "x^k" (x^1 como x).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

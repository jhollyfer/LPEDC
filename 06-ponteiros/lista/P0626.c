// Lista · Módulo 06 · Ponteiros
// Exercício P0626 · ★★★ · O ponto de equilíbrio pela bisseção
//
// Uma fábrica de açaí em pó tem lucro, em milhares de reais, de
// lucro(x) = -0.5x² + 12x - 40 quando produz x toneladas. Ela quer saber a
// partir de quantas toneladas o lucro deixa de ser negativo: a RAIZ de lucro
// entre 0 e 10. Escreva o método da bisseção, que serve para QUALQUER
// função:
//
//   double bissecao(double (*f)(double), double a, double b, double tol,
//                   int *voltas);
//
// Se f(a) e f(b) têm sinais opostos, existe raiz entre eles. Olhe o meio m:
// se f(a) e f(m) têm sinais opostos, a raiz está em [a, m]; senão, em [m, b].
// Repita até o intervalo ficar menor que tol e devolva o meio. Use tol =
// 0.0001 e resolva também x³ - x - 2 = 0 entre 1 e 2:
//
//   Saída esperada:
//   lucro: raiz 4.0000 em 17 voltas (f = -0.00018)
//   x³ - x - 2: raiz 1.5214 em 14 voltas (f = 0.00008)
//   lucro: sem troca de sinal em [5.0, 10.0]
//
// Dicas:
// 1. Sinais opostos: f(a) * f(m) < 0.
// 2. while (b - a > tol) { m = (a + b) / 2; ...; (*voltas)++; } e, no fim,
//    return (a + b) / 2;
// 3. Antes do laço, se f(a) * f(b) > 0 não há garantia de raiz: devolva a
//    e deixe *voltas = -1 (o main avisa).
// 4. A raiz exata da primeira é 12 - sqrt(64) = 4: a bisseção chega em
//    4.0000 com 17 voltas.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

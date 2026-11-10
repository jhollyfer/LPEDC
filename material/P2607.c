// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2607 · ★☆☆ · A pilha do Euclides
//
// O MDC de Euclides recursivo, mdc(a, b) = mdc(b, a % b) com mdc(a, 0) = a,
// é usado para simplificar frações de receitas. Meça a profundidade máxima
// da pilha (prof e prof_max globais) para mdc(84, 36), mdc(89, 55) e
// mdc(1000000, 3):
//
//   Saída esperada:
//   mdc(84, 36) = 12, profundidade 3
//   mdc(89, 55) = 1, profundidade 10
//   mdc(1000000, 3) = 1, profundidade 3
//
// Dicas:
// 1. prof++ na entrada (atualizando prof_max), prof-- antes de devolver;
//    guarde o resultado numa variável.
// 2. 89 e 55 são Fibonacci vizinhos: o pior caso do Euclides, mas ainda Θ(log
//    n) de pilha.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

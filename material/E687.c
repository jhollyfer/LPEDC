// 0115 · Teorema mestre
// Exercício E687 · ★★☆
//
// As 1024 notas de um concurso (0 a 10) estão em ordem crescente:
// notas[i] = i * 11 / 1024. Escreva duas funções recursivas, com um contador
// global de chamadas. conta_lento(v, ini, fim, x) conta as notas x olhando
// SEMPRE as duas metades (T(n) = 2 T(n/2) + 1, caso 1, Θ(n)). primeira(v, ini,
// fim, x) devolve a primeira posição de v[ini..fim-1] com valor >= x (ou fim),
// seguindo só UMA metade (T(n) = T(n/2) + 1, caso 2, Θ(log n)). As notas 7 são
// primeira(..., 8) - primeira(..., 7).
//
//   Saída esperada:
//   lento:  93 notas 7 em 2047 chamadas
//   rápido: 93 notas 7 em 22 chamadas
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

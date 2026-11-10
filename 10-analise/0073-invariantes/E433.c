// 0073 · Invariantes de laço e corretude
// Exercício E433 · ★☆☆
//
// Escreva um programa com os quatro laços abaixo. Em cada um, ponha um assert
// com o invariante logo no começo do corpo e outro depois do laço (o término).
// Escreva também as funções que conferem os invariantes: soma_ate(v, i),
// aprovados_ate(v, i) (quantos de v[0..i-1] são >= 6), potencia_de_2(k) e
// nao_esta(v, ini, fim, x) (x não aparece em v[ini..fim-1]).
//
//   a) gastos = {20, 35, 15, 50};  s = 0;  for (i = 0; i < n; i++)  s = s + gastos[i];
//   b) notas = {7, 4, 9, 6, 5};  c = 0;  for (i = 0; i < n; i++)  if (notas[i] >= 6) c++;
//   c) e = 10;  p = 1;  for (k = 0; k < e; k++)  p = p * 2;
//   d) v = {3, 8, 5, 8, 1}, x = 8;  k = n - 1;  while (k >= 0 && v[k] != x)  k--;
//
//   Saída esperada:
//   a) gastos: R$ 120
//   b) aprovados: 3
//   c) 2 elevado a 10: 1024
//   d) último 8 na posição 3
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

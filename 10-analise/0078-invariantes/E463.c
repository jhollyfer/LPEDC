// 0078 · Invariantes de laço e corretude
// Exercício E463 · ★☆☆
//
// Escreva o invariante de cada laço: a frase que vale no começo de cada volta,
// logo antes do teste. Use a notação v[0..i-1].
//
//   a) s = 0;
//      for (i = 0; i < n; i++)  s = s + gastos[i];
//
//   b) c = 0;
//      for (i = 0; i < n; i++)  if (notas[i] >= 6) c++;
//
//   c) p = 1;
//      for (k = 0; k < e; k++)  p = p * 2;
//
//   d) k = n - 1;
//      while (k >= 0 && v[k] != x)  k--;
//
// Dicas:
// 1. Pergunte: "o que o laço já sabe sobre a parte que ele já viu?".
// 2. Confira o início: com i = 0, o pedaço v[0..-1] está vazio. A soma de
//    nada é 0; a contagem de nada é 0.
// 3. Em d), o laço anda de trás para frente: a parte já vista fica à direita
//    de k.
// 4. Resposta esperada: a) s é a soma de gastos[0..i-1]; b) c é o número de
//    notas >= 6 em notas[0..i-1]; c) p == 2 elevado a k; d) x não está em
//    v[k+1..n-1].
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

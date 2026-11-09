// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1711 · ★★☆ · A árvore de 3T(n/4) + n² contada por nível
//
// A recorrência T(n) = 3 T(n/4) + n² é o exemplo clássico da árvore de
// recursão no Cormen. Transforme-a num programa: trabalho(n, nivel) faz n²
// unidades de trabalho (um laço duplo que soma 1 num contador do nível) e se
// chama três vezes com n/4; com n == 1, faz 1 unidade e para.
//
// Rode com n = 256 e mostre, por nível: o número de chamadas, o tamanho de
// cada pedaço e o custo do nível. Mostre também o total e a razão total / n²,
// que tem de ficar abaixo de 1/(1 - 3/16) = 16/13 ≈ 1,2308: a soma é uma
// progressão geométrica de razão 3/16, e a RAIZ domina (caso 3 do teorema
// mestre, Θ(n²)).
//
//   Saída esperada:
//   nível  chamadas  tamanho  custo
//       0         1      256  65536
//       1         3       64  12288
//       2         9       16   2304
//       3        27        4    432
//       4        81        1     81
//   Total: 80641 | total / n² = 1.2305 (limite 16/13 = 1.2308)
//
// Dicas:
// 1. Guarde chamadas[nivel] e custo[nivel] em vetores globais; 256 = 4^4,
//    então são 5 níveis (0 a 4).
// 2. O nível i tem 3^i chamadas com pedaços de n/4^i: o custo é
//    3^i (n/4^i)² = (3/16)^i n².
// 3. Faça o laço duplo de verdade (for i < n, for j < n, custo++): com
//    n = 256 são 65536 voltas na raiz, nada que demore.
// 4. Resposta esperada: custos 65536, 12288, 2304, 432 e 81; total 80641;
//    razão 1.2305.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

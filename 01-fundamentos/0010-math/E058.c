// 0010 · math.h
// Exercício E058 · ★★☆
//
// Você aplica R$ 1000.00 num investimento que rende 1% ao mês, com juros
// compostos (juros sobre juros). O montante depois de n meses é
// capital * (1 + taxa) elevado a n. Mostre o montante e o rendimento depois
// de 12 e de 24 meses. Para comparar, mostre também quanto teria em 24
// meses com juros simples (1% do capital por mês, sem juros sobre juros) e
// a diferença entre os dois em 24 meses.
//
//   Saída esperada:
//   12 meses: R$ 1126.83 (rendeu R$ 126.83)
//   24 meses: R$ 1269.73 (rendeu R$ 269.73)
//   Juros simples, 24 meses: R$ 1240.00
//   Diferença: R$ 29.73
//
// Dicas:
// 1. A taxa de 1% é 0.01. pow(1 + taxa, 12).
// 2. Rendimento = montante - capital.
// 3. Juros simples: capital + capital * taxa * 24.
// 4. Resposta esperada: as quatro linhas acima. Os compostos rendem também
//    sobre o que já rendeu, e essa parte cresce a cada mês.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}

// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2917 · ★★☆ · Contando as soluções de uma fórmula
//
// A escala de um posto de saúde usa cinco variáveis (x1 a x5: cada médico
// está ou não de plantão) e esta fórmula 3-CNF, guardada no formato +v/-v:
//
//   (x1 ou x2 ou x3) (não x1 ou não x2 ou x4) (x2 ou não x3 ou x5)
//   (não x4 ou não x5 ou x1) (x3 ou x4 ou não x2) (não x1 ou não x3 ou não x5)
//
// Escreva o verificador e a força bruta pelas 2^5 máscaras (bit v-1 é xv).
// Mostre cada atribuição que satisfaz como uma sequência de 0 e 1 (x1 a
// x5) e o total.
//
//   Saída esperada:
//   10000
//   01100
//   10010
//   01010
//   11010
//   01110
//   11110
//   10001
//   00101
//   01101
//   10011
//   11011
//   Total: 12 de 32
//
// Dicas:
// 1. Literal lit é verdadeiro se lit > 0 ? x[lit] : !x[-lit]; cláusula
//    verdadeira se algum literal for; fórmula, se todas forem.
// 2. Percorra as máscaras de 0 a 31 em ordem e mostre x1 primeiro.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

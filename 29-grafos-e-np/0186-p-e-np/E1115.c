// 0186 · P e NP
// Exercício E1115 · ★★★
//
// Por que 3-SAT é tão difícil quanto SAT? Porque toda cláusula longa vira
// cláusulas de 3 literais com variáveis novas, sem mudar a resposta. A
// cláusula (x1 ou x2 ou x3 ou x4 ou x5) vira:
//
//   (x1 ou x2 ou y1) (não y1 ou x3 ou y2) (não y2 ou x4 ou x5)
//
// Escreva o programa que:
//   1. gera essas K - 2 cláusulas para K = 5 numa matriz int nova[3][3]
//      (literais 1 a 5 são x1..x5; 6 e 7 são y1 e y2) e as mostra;
//   2. confere a equivalência por força bruta: para cada uma das 32
//      atribuições dos x, a cláusula original é verdadeira exatamente
//      quando EXISTE uma escolha de y1, y2 que satisfaz as três novas.
//
//   Saída esperada:
//   (x1 ou x2 ou y1)
//   (não y1 ou x3 ou y2)
//   (não y2 ou x4 ou x5)
//   Equivalentes em 32 de 32 atribuições dos x
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2708 · ★☆☆ · Dia útil ou fim de semana
//
// Crie typedef enum { DOM, SEG, TER, QUA, QUI, SEX, SAB } Dia; e um vetor com
// os nomes. Escreva const char *tipo(Dia d) com um switch em que DOM e SAB
// dividem o mesmo case (um embaixo do outro, sem break entre eles) e os
// outros dias caem no default. Mostre o tipo de DOM, QUA e SAB e, no fim, o
// dia que fica 2 depois de QUA, usando que um enum é um int.
//
//   Saída esperada:
//   DOM: fim de semana
//   QUA: dia útil
//   SAB: fim de semana
//   QUA + 2 = SEX (5)
//
// Dicas:
// 1. case DOM:
//    case SAB:
//        return "fim de semana";
// 2. O enum começa em 0: QUA vale 3, e QUA + 2 vale 5, que é SEX.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

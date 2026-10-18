// 0046 · Passagem por referência
// Exercício E276 · ★★★
//
// Esta função troca dois valores sem usar variável auxiliar, mas tem uma
// armadilha:
//
//   void troca_sem_aux(int *a, int *b) {
//       *a = *a + *b;
//       *b = *a - *b;
//       *a = *a - *b;
//   }
//
// Escreva um programa com essa função e, no main, faça:
//
//   int x = 4, y = 9;
//   troca_sem_aux(&x, &y);   e mostre "x = ..., y = ..."
//   troca_sem_aux(&x, &x);   e mostre "x = ..."
//
// Rode: a segunda chamada zera o x, porque a e b apontam para a MESMA
// gaveta. Conserte a função para que, quando os dois ponteiros forem
// iguais, ela não faça nada. Rode de novo.
//
//   Saída esperada (depois do conserto):
//   x = 9, y = 4
//   x = 9
//
// Dicas:
// 1. Antes do conserto, a saída é "x = 9, y = 4" e depois "x = 0": com a e
//    b iguais, *a = 18; *b = 18 - 18 = 0 zera também o *a.
// 2. Ponteiros se comparam com ==: if (a == b) { return; } logo no começo.
// 3. Resposta esperada: "x = 9, y = 4" e "x = 9". Trocar uma gaveta com ela
//    mesma não muda nada; a troca com tmp já se comporta assim sem o if.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// 0046 · Passagem por referência
// Exercício E276 · ★★★
//
// Esta função troca dois valores sem usar variável auxiliar. Preveja a
// saída SEM rodar, fazendo o teste de mesa das duas chamadas:
//
//   void troca_sem_aux(int *a, int *b) {
//       *a = *a + *b;
//       *b = *a - *b;
//       *a = *a - *b;
//   }
//
//   int x = 4, y = 9;
//   troca_sem_aux(&x, &y);
//   printf("x = %d, y = %d\n", x, y);
//   troca_sem_aux(&x, &x);
//   printf("x = %d\n", x);
//
// Depois explique: por que a segunda chamada dá um resultado estranho? A
// troca com tmp do A091 tem o mesmo problema?
//
// Dicas:
// 1. Na segunda chamada, a e b apontam para a MESMA gaveta: escrever em *a
//    é escrever em *b.
// 2. Refaça o teste de mesa com uma coluna só para x.
// 3. Resposta esperada: "x = 9, y = 4" e depois "x = 0". Na segunda
//    chamada, *a = 18; *b = 18 - 18 = 0 (e *a também vira 0); *a = 0 - 0.
//    Quando dois ponteiros apontam para o mesmo lugar (aliasing), cada
//    escrita muda os dois. A troca com tmp não sofre disso: x continua
//    igual.
//
// Escreva sua resposta abaixo (cole o código e confira):

#include <stdio.h>

int main(void) {

    return 0;
}

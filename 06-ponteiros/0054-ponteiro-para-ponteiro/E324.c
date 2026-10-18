// 0054 · Ponteiro para ponteiro
// Exercício E324 · ★★★
//
// Preveja a saída SEM rodar. Monte um teste de mesa com x, y e para onde
// p, q e pp apontam a cada linha.
//
//   int x = 1, y = 2;
//   int *p = &x, *q = &y;
//   int **pp = &p;
//
//   **pp = 10;
//   *pp = q;
//   **pp += 5;
//   pp = &q;
//   *q = **pp * 2;
//   *pp = &x;
//   *p = 3;
//
//   printf("x=%d y=%d *p=%d *q=%d **pp=%d\n", x, y, *p, *q, **pp);
//
// Dicas:
// 1. *pp = algo muda o ponteiro para onde pp aponta (p no começo, q
//    depois de pp = &q).
// 2. Depois de *pp = q, p aponta para y.
// 3. Resposta esperada: x=10 y=3 *p=3 *q=10 **pp=10.
//
// Escreva sua resposta abaixo (cole o código e confira):

#include <stdio.h>

int main(void) {

    return 0;
}

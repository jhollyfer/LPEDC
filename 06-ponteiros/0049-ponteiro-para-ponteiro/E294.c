// 0049 · Ponteiro para ponteiro
// Exercício E294 · ★★★
//
// Transforme o trecho abaixo num teste de mesa que o próprio programa
// imprime. Cole o código no main e, depois das declarações e depois de
// CADA uma das sete linhas, mostre a linha executada e os valores de x, y,
// *p, *q e **pp naquele momento.
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
//   Saída esperada:
//   início          x=1 y=2 *p=1 *q=2 **pp=1
//   **pp = 10       x=10 y=2 *p=10 *q=2 **pp=10
//   *pp = q         x=10 y=2 *p=2 *q=2 **pp=2
//   ...
//   *p = 3          x=10 y=3 *p=3 *q=10 **pp=10
//
// Dicas:
// 1. *pp = algo muda o ponteiro para onde pp aponta (p no começo, q
//    depois de pp = &q). Depois de *pp = q, p aponta para y.
// 2. Escreva o printf uma vez, teste, e copie para as outras linhas,
//    mudando só o texto.
// 3. Resposta esperada: oito linhas; a última é
//    "*p = 3  x=10 y=3 *p=3 *q=10 **pp=10" e a do *pp = &x é
//    "*pp = &x  x=10 y=14 *p=14 *q=10 **pp=10".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

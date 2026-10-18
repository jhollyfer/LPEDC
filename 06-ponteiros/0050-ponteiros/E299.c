// 0050 · Ponteiros
// Exercício E299 · ★★★
//
// Preveja a saída SEM rodar. Faça um teste de mesa com uma coluna para a,
// b e para onde p e q apontam. Só depois rode para conferir.
//
//   int a = 3, b = 8;
//   int *p = &a, *q = &b;
//
//   *p = *q + 1;
//   p = q;
//   *p = *p * 2;
//   q = &a;
//   *q -= 4;
//
//   printf("a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
//
// Dicas:
// 1. Linha a linha: quem é mudado é a variável apontada, não o ponteiro
//    (exceto em p = q e q = &a, que só trocam o alvo).
// 2. Depois de p = q, p aponta para b.
// 3. Resposta esperada: a = 5, b = 16, *p = 16, *q = 5.
//
// Escreva sua resposta abaixo (cole o código e confira):

#include <stdio.h>

int main(void) {

    return 0;
}

// 0049 · Ponteiro para ponteiro
// Exercício E290 · ★☆☆
//
// Complete o programa, que já monta o gaveteiro:
//
//   int x = 5;
//   int *p = &x;
//   int **pp = &p;
//
// 1. Mostre, um por linha, x, p, *p, pp, *pp, **pp, &pp e &*pp (use %d
//    para int e %p com (void *) para endereço). Três linhas já estão lá.
// 2. Mostre com %d o resultado de quatro comparações: *pp == p,
//    *pp == &x, &*pp == pp e **pp == x.
// 3. Usando só pp, mude x para 8 e mostre x.
//
//   Saída esperada (os endereços mudam a cada execução):
//   x    = 5
//   p    = 0x7f...30
//   *p   = 5
//   pp   = 0x7f...40
//   *pp  = 0x7f...30
//   **pp = 5
//   &pp  = 0x7f...60
//   &*pp = 0x7f...40
//   comparações: 1 1 1 1
//   x agora = 8
//
// Dicas:
// 1. Cada * dá um salto: vai até o endereço e pega o que tem lá.
// 2. & e * se anulam: &*pp é o mesmo que pp.
// 3. Resposta esperada: p e *pp mostram o mesmo endereço (o de x); pp e
//    &*pp, o de p; &pp é um terceiro endereço. As quatro comparações dão 1
//    e **pp = 8; faz x valer 8 ("x agora = 8").
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("x    = %d\n", x);
    printf("p    = %p\n", (void *)p);
    // *p, pp e *pp
    printf("**pp = %d\n", **pp);
    // &pp e &*pp

    // 2. as quatro comparações

    // 3. mude x para 8 usando só pp

    return 0;
}

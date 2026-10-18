// 0044 · Memória e endereços
// Exercício E263 · ★★★
//
// Resposta: (a) os elementos do vetor sempre ficam colados, de 4 em 4 e em
// ordem; (b) a, b e c ficam onde o compilador quiser (com o rodar, 16 bytes
// distantes; sem sanitizer, em geral 4 bytes, na ordem que o compilador escolher);
// (c) só o vetor tem ordem garantida; nunca suponha vizinhança entre
// variáveis soltas.

#include <stdio.h>

int main(void) {
    int a = 1, b = 2, c = 3;
    int v[3] = {1, 2, 3};

    printf("a em %p (%d)\n", (void *)&a, a);
    printf("b em %p (%d)\n", (void *)&b, b);
    printf("c em %p (%d)\n", (void *)&c, c);
    for (int i = 0; i < 3; i++) {
        printf("v[%d] em %p (%d)\n", i, (void *)&v[i], v[i]);
    }
    return 0;
}

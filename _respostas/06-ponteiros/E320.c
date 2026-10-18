// 0054 · Ponteiro para ponteiro
// Exercício E320 · ★☆☆
//
// Resposta (endereços do gaveteiro fictício):
//   x = 5; p = 0x4000; *p = 5; pp = 0x4010; *pp = 0x4000; **pp = 5;
//   &pp = 0x4020; &*pp = 0x4010 (& e * se anulam: é o próprio pp).
// O programa confere com endereços reais: os pares iguais continuam iguais.

#include <stdio.h>

int main(void) {
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("x = %d, p = %p, *p = %d\n", x, (void *)p, *p);
    printf("pp = %p, *pp = %p, **pp = %d\n", (void *)pp, (void *)*pp, **pp);
    printf("&pp = %p, &*pp = %p\n", (void *)&pp, (void *)&*pp);
    return 0;
}

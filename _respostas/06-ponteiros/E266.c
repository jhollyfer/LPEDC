// 0045 · Ponteiros
// Exercício E266 · ★☆☆

#include <stdio.h>

int main(void) {
    int vagas = 7;
    int *p = &vagas;

    printf("vagas   = %d\n", vagas);
    printf("&vagas  = %p\n", (void *)&vagas);
    printf("p       = %p\n", (void *)p);
    printf("*p      = %d\n", *p);
    printf("&p      = %p\n", (void *)&p);
    printf("*&vagas = %d\n", *&vagas);
    printf("p == &vagas: %d\n", p == &vagas);
    printf("*p == vagas: %d\n", *p == vagas);
    printf("&p == &vagas: %d\n", (void *)&p == (void *)&vagas);
    return 0;
}

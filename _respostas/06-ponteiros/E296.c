// 0050 · Ponteiros
// Exercício E296 · ★☆☆
//
// Resposta: vagas = 7; &vagas = 0x3000; p = 0x3000; *p = 7; &p = 0x3008;
// *&vagas = 7. No programa, &vagas e p saem iguais; &p sai diferente.

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
    return 0;
}

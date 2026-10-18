// 0044 · Memória e endereços
// Exercício E260 · ★☆☆
//
// Resposta: a) gols vale 3 e &gols vale 0x2000; b) &media vale 0x2008;
// c) o último byte de media é 0x200F (0x2008 + 7); d) gols ocupa 0x2000,
// 0x2001, 0x2002 e 0x2003; e) não: os endereços reais mudam a cada execução
// (ASLR). O programa abaixo mostra os endereços de verdade.

#include <stdio.h>

int main(void) {
    int gols = 3;
    double media = 1.5;
    char result = 'V';

    printf("gols   = %d em %p\n", gols, (void *)&gols);
    printf("media  = %.1f em %p\n", media, (void *)&media);
    printf("result = %c em %p\n", result, (void *)&result);
    return 0;
}

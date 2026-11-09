// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2720 · ★★☆ · Uma biblioteca de bits em macros

#include <stdint.h>
#include <stdio.h>

#define BIT(n) (1u << (n))
#define LIGA(x, n) ((x) | BIT(n))
#define DESLIGA(x, n) ((x) & ~BIT(n))
#define TESTA(x, n) (((x) >> (n)) & 1u)

int main(void) {
    uint8_t flags = 0;
    printf("BIT(1 + 1) = %u\n", BIT(1 + 1));
    flags = (uint8_t)LIGA(flags, 1 + 1);
    flags = (uint8_t)LIGA(flags, 6);
    printf("depois de ligar 2 e 6: %d\n", flags);
    flags = (uint8_t)DESLIGA(flags, 2 * 3);
    printf("depois de desligar 6: %d\n", flags);
    printf("!TESTA(flags, 2) = %d\n", !TESTA(flags, 2));
    printf("TESTA(flags, 7 - 1) = %u\n", TESTA(flags, 7 - 1));
    return 0;
}

// 0012 · Aritmética
// Exercício E071 · ★★★
//
// Resposta: o original mostra "3 kits: R$ 65". O pré-processador cola o
// texto, e 3 * KIT vira 3 * 20 + 5; pela precedência, 60 + 5 = 65. Com os
// parênteses no #define, vira 3 * (20 + 5) = 75.

#include <stdio.h>

#define KIT (20 + 5)

int main(void) {
    printf("3 kits: R$ %d\n", 3 * KIT);
    return 0;
}

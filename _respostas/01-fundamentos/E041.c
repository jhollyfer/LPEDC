// 0007 · Aritmética
// Exercício E041 · ★★★
//
// Sem parênteses, 3 * KIT virava 3 * 20 + 5 = 65 e KIT / 5 virava
// 20 + 5 / 5 = 21. Com eles, 3 * (20 + 5) = 75 e (20 + 5) / 5 = 5.

#include <stdio.h>

#define KIT (20 + 5)

int main(void) {
    printf("3 kits: R$ %d\n", 3 * KIT);
    printf("Kit em 5x: R$ %d\n", KIT / 5);
    return 0;
}

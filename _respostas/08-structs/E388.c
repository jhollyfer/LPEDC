// 0065 · Bits, máscaras e flags
// Exercício E388 · ★★☆

#include <stdio.h>

#define EMAIL 1u
#define SMS   2u
#define PUSH  4u

void mostrar(unsigned f) {
    printf("email: %s | ", (f & EMAIL) == 0 ? "desligado" : "ligado");
    printf("sms: %s | ", (f & SMS) ? "ligado" : "desligado");
    printf("push: %s\n", (f & PUSH) ? "ligado" : "desligado");
}

int main(void) {
    unsigned f = EMAIL | PUSH;
    mostrar(f);

    f &= ~PUSH; // desliga o push
    mostrar(f);
    return 0;
}

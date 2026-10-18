// 0065 · Bits, máscaras e flags
// Exercício E388 · ★★☆
//
// Resposta: (1) f & EMAIL == 0 era lido como f & (EMAIL == 0), sempre 0:
// faltavam parênteses; (2) f && SMS só pergunta se os dois são diferentes de
// zero (sempre verdade aqui): o teste de bit é f & SMS; (3) f &= PUSH
// apagava todos os bits MENOS o push: para desligar, f &= ~PUSH.

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

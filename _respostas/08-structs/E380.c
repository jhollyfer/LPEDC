// 0064 · Struct
// Exercício E380 · ★☆☆
//
// Resposta: mostra "a: 5 x 1" e "b: 2 x 3". b = a copia os campos; depois
// b.fora = 3 só muda b, e a.casa vira 2 + 3 = 5. No JS, const b = a faria b
// apontar para o MESMO objeto: b.fora = 3 mudaria a.fora também, e os dois
// mostrariam 5 x 3.

#include <stdio.h>

struct placar {
    int casa;
    int fora;
};

int main(void) {
    struct placar a = {2, 1};
    struct placar b = a;
    b.fora = 3;
    a.casa = a.casa + b.fora;
    printf("a: %d x %d\n", a.casa, a.fora);
    printf("b: %d x %d\n", b.casa, b.fora);
    return 0;
}

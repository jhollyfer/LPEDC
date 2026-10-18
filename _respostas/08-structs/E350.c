// 0059 · Struct
// Exercício E350 · ★☆☆

#include <stdio.h>

struct placar {
    int casa;
    int fora;
};

void mostrar(const char *nome, struct placar p) {
    printf("%s: %d x %d\n", nome, p.casa, p.fora);
}

int main(void) {
    struct placar a = {2, 1};
    struct placar b = a; // cópia: daqui em diante, a e b são independentes

    b.fora = 3;
    a.casa = a.casa + b.fora;
    mostrar("a", a);
    mostrar("b", b);

    struct placar c = b;
    c.casa = 0;
    c.fora = 0;
    mostrar("c", c);
    mostrar("b", b); // zerar c não mexeu em b
    return 0;
}

// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2704 · ★☆☆ · Quatro operações sobre um bit

#include <stdbool.h>
#include <stdio.h>

bool testar(unsigned x, int n) { return (x >> n) & 1u; }
unsigned ligar(unsigned x, int n) { return x | (1u << n); }
unsigned desligar(unsigned x, int n) { return x & ~(1u << n); }
unsigned inverter(unsigned x, int n) { return x ^ (1u << n); }

void mostrar(unsigned x) {
    for (int b = 7; b >= 0; b--) {
        printf("%u", (x >> b) & 1u);
    }
    printf("\n");
}

int main(void) {
    unsigned x = 0x2C;
    printf("x = ");
    mostrar(x);
    printf("bit 3 ligado? %s\n", testar(x, 3) ? "sim" : "não");
    printf("ligar 0 -> ");
    mostrar(ligar(x, 0));
    printf("desligar 5 -> ");
    mostrar(desligar(x, 5));
    printf("inverter 7 -> ");
    mostrar(inverter(x, 7));
    return 0;
}

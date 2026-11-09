// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2722 · ★★★ · O byte de trás para a frente

#include <stdint.h>
#include <stdio.h>

int contar(uint8_t b) {
    int n = 0;
    for (int i = 0; i < 8; i++) {
        n += (b >> i) & 1;
    }
    return n;
}

int paridade(uint8_t b) {
    return contar(b) % 2;
}

uint8_t espelhar(uint8_t b) {
    uint8_t r = 0;
    for (int i = 0; i < 8; i++) {
        if ((b >> i) & 1) {
            r = (uint8_t)(r | (1u << (7 - i)));
        }
    }
    return r;
}

uint8_t girar(uint8_t b, int n) {
    n %= 8;
    if (n == 0) {
        return b;
    }
    return (uint8_t)((b << n) | (b >> (8 - n)));
}

void mostrar(const char *rotulo, uint8_t b) {
    printf("%s", rotulo);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
    }
    printf(" (0x%02X)\n", b);
}

int main(void) {
    uint8_t b = 0x1D;
    mostrar("b = ", b);
    printf("bits ligados: %d\n", contar(b));
    printf("paridade: %d\n", paridade(b));
    mostrar("espelhado: ", espelhar(b));
    mostrar("girado 3: ", girar(b, 3));
    mostrar("girado 0: ", girar(b, 0));
    return 0;
}

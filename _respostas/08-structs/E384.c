// 0064 · Union
// Exercício E384 · ★★★

#include <stdint.h>
#include <stdio.h>

typedef union {
    uint32_t n;
    uint16_t m[2];
    unsigned char b[4];
} Visao;

void mostrar_memoria(Visao x) {
    printf("memória:");
    for (int i = 0; i < 4; i++) {
        printf(" %02X", x.b[i]);
    }
    printf("\n");
}

int little_endian(void) {
    Visao t;
    t.n = 1;
    return t.b[0] == 1; // o byte menos significativo veio primeiro?
}

// devolve o número com os bytes na ordem de rede (big-endian)
uint32_t ordem_de_rede(uint32_t x) {
    if (!little_endian()) {
        return x; // já está na ordem certa
    }
    Visao de, para;
    de.n = x;
    for (int i = 0; i < 4; i++) {
        para.b[i] = de.b[3 - i];
    }
    return para.n;
}

int main(void) {
    Visao x;
    x.n = 0x11223344;

    mostrar_memoria(x);
    printf("m[0] = 0x%04X, m[1] = 0x%04X\n", (unsigned)x.m[0], (unsigned)x.m[1]);
    printf("esta máquina é %s\n", little_endian() ? "little-endian" : "big-endian");

    Visao rede;
    rede.n = ordem_de_rede(x.n);
    printf("em ordem de rede, ");
    mostrar_memoria(rede);
    return 0;
}

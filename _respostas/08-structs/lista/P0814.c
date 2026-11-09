// Lista · Módulo 08 · Tipos compostos
// Exercício P0814 · ★★☆ · A cor em 16 bits

#include <stdio.h>
#include <stdint.h>

uint16_t para_565(int r, int g, int b) {
    return (uint16_t) (((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3));
}

void de_565(uint16_t c, int *r, int *g, int *b) {
    int r5 = (c >> 11) & 0x1F;
    int g6 = (c >> 5) & 0x3F;
    int b5 = c & 0x1F;
    *r = (r5 << 3) | (r5 >> 2); // repete os bits de cima embaixo
    *g = (g6 << 2) | (g6 >> 4);
    *b = (b5 << 3) | (b5 >> 2);
}

int main(void) {
    const char *nomes[3] = {"laranja", "verde-bandeira", "branco"};
    int cores[3][3] = {{255, 136, 0}, {0, 156, 59}, {255, 255, 255}};

    for (int i = 0; i < 3; i++) {
        uint16_t c = para_565(cores[i][0], cores[i][1], cores[i][2]);
        int r, g, b;
        de_565(c, &r, &g, &b);
        printf("%-14s (%3d, %3d, %3d) -> 0x%04X -> (%3d, %3d, %3d)\n", nomes[i],
               cores[i][0], cores[i][1], cores[i][2], (unsigned) c, r, g, b);
    }
    return 0;
}

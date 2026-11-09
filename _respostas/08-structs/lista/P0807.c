// Lista · Módulo 08 · Tipos compostos
// Exercício P0807 · ★☆☆ · O endereço IP em 32 bits

#include <stdio.h>
#include <stdint.h>

uint32_t montar(int a, int b, int c, int d) {
    return ((uint32_t) a << 24) | ((uint32_t) b << 16) | ((uint32_t) c << 8) | (uint32_t) d;
}

void mostrar(const char *rotulo, uint32_t ip) {
    printf("%3u.%3u.%3u.%3u  0x%08X  %s\n", (unsigned) (ip >> 24) & 0xFF,
           (unsigned) (ip >> 16) & 0xFF, (unsigned) (ip >> 8) & 0xFF,
           (unsigned) ip & 0xFF, (unsigned) ip, rotulo);
}

int main(void) {
    uint32_t ip = montar(192, 168, 10, 42);
    int prefixos[2] = {24, 16};

    mostrar("IP", ip);
    for (int k = 0; k < 2; k++) {
        uint32_t mascara = 0xFFFFFFFFu << (32 - prefixos[k]);
        printf("Com /%d:\n", prefixos[k]);
        mostrar("máscara", mascara);
        mostrar("rede", ip & mascara);
        mostrar("máquina", ip & ~mascara);
    }
    return 0;
}

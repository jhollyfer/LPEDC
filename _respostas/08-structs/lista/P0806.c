// Lista · Módulo 08 · Tipos compostos
// Exercício P0806 · ★☆☆ · As permissões do arquivo

#include <stdio.h>

void mostrar(const char *rotulo, unsigned modo) {
    printf("%-22s %03o ", rotulo, modo);
    for (int b = 8; b >= 0; b--) {
        putchar((modo >> b) & 1u ? "rwx"[(8 - b) % 3] : '-');
    }
    printf("\n");
}

int main(void) {
    mostrar("chmod 754:", 0754);
    unsigned modo = 0644;
    mostrar("chmod 644:", modo);
    modo |= 1u << 6;    // x do dono
    mostrar("liga x do dono:", modo);
    modo &= ~(1u << 2); // r dos outros
    mostrar("desliga r dos outros:", modo);
    modo ^= 1u << 4;    // w do grupo
    mostrar("inverte w do grupo:", modo);
    return 0;
}

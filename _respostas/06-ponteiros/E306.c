// 0051 · void * e cast
// Exercício E306 · ★★★

#include <stdio.h>

void mostra_bytes(const char *rotulo, const void *p, size_t tam) {
    const unsigned char *byte = p;
    printf("%s:", rotulo);
    for (size_t i = 0; i < tam; i++) {
        printf(" %02x", byte[i]);
    }
    printf("\n");
}

int main(void) {
    short curto = 258;
    unsigned int cor = 0x0A0B0C0D;
    int negativo = -2;
    char sigla[] = "BR";

    mostra_bytes("curto", &curto, sizeof curto);
    mostra_bytes("cor", &cor, sizeof cor);
    mostra_bytes("negativo", &negativo, sizeof negativo);
    mostra_bytes("sigla", sigla, sizeof sigla);

    unsigned char *b = (unsigned char *)&cor;
    b[0] = 0xFF; // o primeiro byte na memória é o menos significativo
    printf("cor depois: %#010x\n", cor);

    b = (unsigned char *)&negativo;
    b[0] = 0x00; // fe ff ff ff vira 00 ff ff ff = 0xFFFFFF00
    printf("negativo depois: %d\n", negativo);
    return 0;
}

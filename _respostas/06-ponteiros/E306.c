// 0051 · void * e cast
// Exercício E306 · ★★★
//
// Resposta (little-endian: o byte menos significativo primeiro):
//   curto: 02 01        (258 = 0x0102)
//   cor: 0d 0c 0b 0a    (0x0A0B0C0D)
//   negativo: fe ff ff ff  (-2 = 0xFFFFFFFE)
//   sigla: 42 52 00     ('B', 'R' e o '\0')

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
    return 0;
}

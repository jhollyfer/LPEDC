// A112 · Os bytes de verdade

#include <stdio.h>

// mostra, em hexa, os bytes que estão a partir de um endereço qualquer
void mostra_bytes(const char *rotulo, const void *p, size_t tam) {
    const unsigned char *byte = p;
    printf("%-10s", rotulo);
    for (size_t i = 0; i < tam; i++) {
        printf(" %02x", byte[i]);
    }
    printf("\n");
}

int main(void) {
    int mil = 1000;              // 1000 = 0x000003E8
    int menos_um = -1;
    char pix[] = "Pix";
    double meio = 0.5;

    mostra_bytes("1000", &mil, sizeof mil);
    mostra_bytes("-1", &menos_um, sizeof menos_um);
    mostra_bytes("\"Pix\"", pix, sizeof pix);
    mostra_bytes("0.5", &meio, sizeof meio);

    void *qualquer = &mil;
    printf("de volta: %d\n", *(int *)qualquer); // para ler, converta para o tipo certo
    return 0;
}
// Saída (num PC Intel/AMD ou ARM, que são little-endian):
// 1000       e8 03 00 00
// -1         ff ff ff ff
// "Pix"      50 69 78 00
// 0.5        00 00 00 00 00 00 e0 3f
// de volta: 1000

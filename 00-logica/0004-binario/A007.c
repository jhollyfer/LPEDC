// A007 · O 13 em três bases

#include <stdio.h>

int main(void) {
    int n = 13;

    printf("decimal: %d\n", n);     // %d mostra em base 10
    printf("hexa:    0x%X\n", n);   // %X mostra em base 16

    printf("binário: ");
    for (int casa = 3; casa >= 0; casa--) {
        printf("%d", (n >> casa) & 1); // pega o bit daquela casa
    }
    printf("\n");
    return 0;
}
// Saída:
// decimal: 13
// hexa:    0xD
// binário: 1101

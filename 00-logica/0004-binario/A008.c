// A008 · O odômetro de um byte

#include <stdio.h>

// unsigned char ocupa 1 byte: guarda de 0 a 255. Somar 1 em 255 "dá a volta",
// como o odômetro do carro passando de 99999 para 00000.
int main(void) {
    unsigned char byte = 253;

    for (int i = 0; i < 5; i++) {
        printf("%3d = 0x%02X\n", byte, byte);
        byte = byte + 1;
    }
    printf("Um byte tem %d valores possíveis (2 elevado a 8)\n", 1 << 8);
    return 0;
}
// Saída:
// 253 = 0xFD
// 254 = 0xFE
// 255 = 0xFF
//   0 = 0x00
//   1 = 0x01
// Um byte tem 256 valores possíveis (2 elevado a 8)

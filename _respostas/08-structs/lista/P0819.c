// Lista · Módulo 08 · Tipos compostos
// Exercício P0819 · ★★☆ · A senha escondida com XOR

#include <stdio.h>
#include <string.h>

void cifrar(char *s, size_t n, unsigned char chave) {
    for (size_t i = 0; i < n; i++) {
        s[i] = (char) ((unsigned char) s[i] ^ chave);
    }
}

void hexa(const char *s, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%02X%s", (unsigned char) s[i], (i + 1) % 16 == 0 || i + 1 == n ? "\n" : " ");
    }
}

int main(void) {
    char msg[] = "Encontro no Teatro Amazonas, 19h";
    size_t n = strlen(msg); // antes de cifrar: depois pode surgir um byte 0
    unsigned char chave = 0x5A;

    cifrar(msg, n, chave);
    printf("Cifrada:\n");
    hexa(msg, n);
    cifrar(msg, n, chave); // a mesma chave desfaz
    printf("Decifrada: %s\n", msg);

    int bits = 0;
    for (unsigned x = chave; x != 0; x >>= 1) {
        bits += x & 1u;
    }
    printf("Chave 0x%02X = ", chave);
    for (int b = 7; b >= 0; b--) {
        putchar((chave >> b) & 1 ? '1' : '0');
    }
    printf(" (%d bits ligados)\n", bits);
    return 0;
}

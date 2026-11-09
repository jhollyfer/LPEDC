// 0171 · Com sinal e sem sinal
// Exercício E1025 · ★★★

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

unsigned char verificador(const unsigned char *d, size_t n) {
    unsigned char soma = 0;
    for (size_t i = 0; i < n; i++) {
        soma += d[i]; // guarda num byte: dá a volta em 256
    }
    return (unsigned char)(0u - soma);
}

bool confere(const unsigned char *d, size_t n, unsigned char v) {
    unsigned char soma = 0;
    for (size_t i = 0; i < n; i++) {
        soma += d[i];
    }
    return (unsigned char)(soma + v) == 0; // sem o cast, 226 + 30 = 256 em int
}

int main(void) {
    unsigned char boleto[] = {0x12, 0xA0, 0xFF, 0x31};
    unsigned char v = verificador(boleto, 4);
    printf("verificador = 0x%02X\n", v);
    printf("original: %s\n", confere(boleto, 4, v) ? "confere" : "nao confere");

    boleto[1] = 0xA1; // um bit trocado
    printf("alterado: %s\n", confere(boleto, 4, v) ? "confere" : "nao confere");
    return 0;
}

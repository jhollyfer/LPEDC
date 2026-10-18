// A120 · A cor do site

#include <stdint.h>
#include <stdio.h>

typedef uint8_t Byte; // uint8_t já é um typedef (de unsigned char)

typedef struct {
    Byte r, g, b;     // cada canal de 0 a 255
} Cor;

Cor misturar(Cor a, Cor b) {
    Cor m = {(a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2};
    return m;
}

void mostrar(const char *nome, Cor c) {
    printf("%-8s #%02X%02X%02X  (%3d, %3d, %3d)\n", nome, c.r, c.g, c.b, c.r, c.g, c.b);
}

int main(void) {
    Cor laranja = {255, 136, 0};
    Cor branco = {255, 255, 255};

    mostrar("laranja", laranja);
    mostrar("branco", branco);
    mostrar("mistura", misturar(laranja, branco));
    printf("Uma Cor ocupa %zu bytes\n", sizeof(Cor));
    return 0;
}
// Saída:
// laranja  #FF8800  (255, 136,   0)
// branco   #FFFFFF  (255, 255, 255)
// mistura  #FFC37F  (255, 195, 127)
// Uma Cor ocupa 3 bytes

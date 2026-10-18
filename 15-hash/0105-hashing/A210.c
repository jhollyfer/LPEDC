// A210 · Anagramas: soma contra polinômio

#include <stdio.h>

#define M 11

// soma dos códigos: a ordem das letras não importa (ruim)
unsigned hash_soma(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h += (unsigned char)s[i];
    }
    return h % M;
}

// polinômio de base 31: cada letra pesa conforme a posição
unsigned hash_pol(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h % M;
}

int main(void) {
    const char *palavras[] = {"amor", "roma", "mora", "ramo"};

    printf("palavra  soma  polinômio\n");
    for (int i = 0; i < 4; i++) {
        printf("%-7s  %4u  %9u\n", palavras[i], hash_soma(palavras[i]), hash_pol(palavras[i]));
    }
    return 0;
}
// Saída:
// palavra  soma  polinômio
// amor        2          3
// roma        2          5
// mora        2          2
// ramo        2          7

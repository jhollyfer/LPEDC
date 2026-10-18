// 0040 · Caracteres
// Exercício E240 · ★★★

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool meu_isdigit(int c) {
    return c >= '0' && c <= '9';
}

bool meu_isupper(int c) {
    return c >= 'A' && c <= 'Z';
}

bool meu_islower(int c) {
    return c >= 'a' && c <= 'z';
}

bool meu_isalpha(int c) {
    return meu_isupper(c) || meu_islower(c);
}

int meu_toupper(int c) {
    if (meu_islower(c)) {
        return c - ('a' - 'A');
    }
    return c;
}

int main(void) {
    int diferencas = 0;

    for (int c = 0; c < 128; c++) {
        if ((isdigit(c) != 0) != meu_isdigit(c) ||
            (isupper(c) != 0) != meu_isupper(c) ||
            (islower(c) != 0) != meu_islower(c) ||
            (isalpha(c) != 0) != meu_isalpha(c) ||
            toupper(c) != meu_toupper(c)) {
            printf("Falhou no código %d\n", c);
            diferencas++;
        }
    }

    printf("meu_toupper('q') = %c\n", meu_toupper('q'));
    printf("meu_toupper('7') = %c\n", meu_toupper('7'));
    printf("Diferenças em 128 códigos: %d\n", diferencas);
    return 0;
}

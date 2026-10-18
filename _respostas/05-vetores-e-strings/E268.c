// 0045 · Caracteres
// Exercício E268 · ★★☆

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define DIGITOS 8

int main(void) {
    char cep[DIGITOS];
    int quantos = 0;
    bool valido = true;
    int c;

    printf("CEP: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (isdigit(c)) {
            if (quantos < DIGITOS) {
                cep[quantos] = (char) c;
            }
            quantos++;
        } else if (c != '-') {
            valido = false;
        }
    }

    if (valido && quantos == DIGITOS) {
        printf("CEP válido: ");
        for (int i = 0; i < DIGITOS; i++) {
            putchar(cep[i]);
        }
        printf("\n");
    } else {
        printf("CEP inválido.\n");
    }
    return 0;
}

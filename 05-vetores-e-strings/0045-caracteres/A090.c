// A090 · Contando o que foi digitado, letra por letra

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int letras = 0, digitos = 0, espacos = 0, outros = 0;
    int c; // int, e não char: getchar pode devolver EOF, que não é um caractere

    printf("Digite o endereço: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (isalpha(c)) {
            letras++;
        } else if (isdigit(c)) {
            digitos++;
        } else if (isspace(c)) {
            espacos++;
        } else {
            outros++;
        }
    }

    printf("Letras: %d\n", letras);
    printf("Dígitos: %d\n", digitos);
    printf("Espaços: %d\n", espacos);
    printf("Outros: %d\n", outros);
    return 0;
}
// Digite o endereço: Rua 7 de Setembro, 1500
// Letras: 13
// Dígitos: 5
// Espaços: 4
// Outros: 1

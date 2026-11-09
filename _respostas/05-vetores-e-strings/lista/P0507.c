// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0507 · ★☆☆ · Raio-x do endereço

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char endereco[] = "Rua 7 de Setembro, 1500 - Centro";
    int maiusc = 0, minusc = 0, digitos = 0, espacos = 0, outros = 0;

    for (int i = 0; endereco[i] != '\0'; i++) {
        unsigned char c = endereco[i];
        if (isupper(c)) {
            maiusc++;
        } else if (islower(c)) {
            minusc++;
        } else if (isdigit(c)) {
            digitos++;
        } else if (isspace(c)) {
            espacos++;
        } else {
            outros++;
        }
    }

    printf("Maiúsculas: %d\n", maiusc);
    printf("Minúsculas: %d\n", minusc);
    printf("Dígitos: %d\n", digitos);
    printf("Espaços: %d\n", espacos);
    printf("Outros: %d\n", outros);
    printf("Total: %d (strlen = %zu)\n", maiusc + minusc + digitos + espacos + outros,
           strlen(endereco));
    return 0;
}

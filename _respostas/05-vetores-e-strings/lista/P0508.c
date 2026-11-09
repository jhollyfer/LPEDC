// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0508 · ★☆☆ · O nome do crachá

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char nome[] = "Raimunda";
    char sobrenome[] = "Nonato";
    char cracha[40];

    strcpy(cracha, sobrenome);
    for (int i = 0; cracha[i] != '\0'; i++) {
        cracha[i] = toupper((unsigned char) cracha[i]);
    }
    strcat(cracha, ", ");
    strcat(cracha, nome);

    printf("Crachá: %s\n", cracha);
    printf("Tamanho: %zu\n", strlen(cracha));
    printf("Iniciais: %c.%c.\n", nome[0], sobrenome[0]);
    return 0;
}

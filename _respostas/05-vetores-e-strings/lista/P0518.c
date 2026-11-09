// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0518 · ★★☆ · O telefone digitado de qualquer jeito

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void mostrar_trecho(const char s[], int de, int ate) {
    for (int i = de; i < ate; i++) {
        printf("%c", s[i]);
    }
}

int main(void) {
    char linha[40];
    char digitos[40];

    if (fgets(linha, sizeof linha, stdin) == NULL) {
        return 1;
    }

    int k = 0;
    for (int i = 0; linha[i] != '\0'; i++) {
        if (isdigit((unsigned char) linha[i])) {
            digitos[k++] = linha[i];
        }
    }
    digitos[k] = '\0';

    if (strlen(digitos) != 11) {
        printf("Inválido: %zu dígitos\n", strlen(digitos));
        return 0;
    }
    printf("Celular: (");
    mostrar_trecho(digitos, 0, 2);
    printf(") ");
    mostrar_trecho(digitos, 2, 7);
    printf("-");
    mostrar_trecho(digitos, 7, 11);
    printf("\n");
    return 0;
}

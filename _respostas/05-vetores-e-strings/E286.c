// 0048 · Juntando tudo
// Exercício E286 · ★★☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define DIGITOS 11

// usa os n primeiros dígitos, com pesos n + 1, n, ..., 2
int verificador(const int d[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += d[i] * (n + 1 - i);
    }
    int r = soma % 11;
    return r < 2 ? 0 : 11 - r;
}

int main(void) {
    char linha[40];
    int d[DIGITOS];
    int quantos = 0;
    bool valido = true;

    printf("CPF: ");
    if (fgets(linha, sizeof(linha), stdin) == NULL) {
        return 1;
    }
    linha[strcspn(linha, "\n")] = '\0';

    for (int i = 0; linha[i] != '\0'; i++) {
        unsigned char c = (unsigned char) linha[i];
        if (isdigit(c)) {
            if (quantos < DIGITOS) {
                d[quantos] = c - '0';
            }
            quantos++;
        } else if (c != '.' && c != '-') {
            valido = false;
        }
    }

    if (valido && quantos == DIGITOS) {
        bool todos_iguais = true;
        for (int i = 1; i < DIGITOS; i++) {
            if (d[i] != d[0]) {
                todos_iguais = false;
            }
        }
        if (todos_iguais || verificador(d, 9) != d[9] || verificador(d, 10) != d[10]) {
            valido = false;
        }
    } else {
        valido = false;
    }

    printf(valido ? "CPF válido.\n" : "CPF inválido.\n");
    return 0;
}

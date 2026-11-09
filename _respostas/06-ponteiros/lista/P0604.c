// Lista · Módulo 06 · Ponteiros
// Exercício P0604 · ★☆☆ · A placa no padrão Mercosul

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void maiusculas(char *s) {
    while (*s != '\0') {
        *s = toupper((unsigned char) *s);
        s++; // anda a cópia local do endereço
    }
}

bool padrao_mercosul(const char *p) {
    return isalpha((unsigned char) p[0]) && isalpha((unsigned char) p[1])
        && isalpha((unsigned char) p[2]) && isdigit((unsigned char) p[3])
        && isalpha((unsigned char) p[4]) && isdigit((unsigned char) p[5])
        && isdigit((unsigned char) p[6]) && p[7] == '\0';
}

int main(void) {
    char placas[3][8] = {"rio2a18", "abc1234", "qxz9b07"};

    for (int i = 0; i < 3; i++) {
        maiusculas(placas[i]);
        printf("%s: %s\n", placas[i], padrao_mercosul(placas[i]) ? "Mercosul" : "modelo antigo");
    }
    return 0;
}

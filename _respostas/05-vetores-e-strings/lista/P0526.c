// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0526 · ★★★ · O cartão passa no teste de Luhn?

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool luhn(const char s[], int soma[1]) {
    int pos = 0; // quantos dígitos já vimos, da direita
    soma[0] = 0;
    for (int i = (int) strlen(s) - 1; i >= 0; i--) {
        unsigned char c = s[i];
        if (c == ' ') {
            continue;
        }
        if (!isdigit(c)) {
            soma[0] = -1;
            return false;
        }
        int d = c - '0';
        if (pos % 2 == 1) {
            d *= 2;
            if (d > 9) {
                d -= 9;
            }
        }
        soma[0] += d;
        pos++;
    }
    return pos > 0 && soma[0] % 10 == 0;
}

int main(void) {
    char cartoes[4][24] = {"4539 1488 0343 6467", "4539 1488 0343 6468",
                           "79927398713", "1234-5678"};

    for (int k = 0; k < 4; k++) {
        int soma[1];
        bool ok = luhn(cartoes[k], soma);
        printf("%-20s soma %3d -> %s\n", cartoes[k], soma[0], ok ? "válido" : "inválido");
    }
    return 0;
}

// 0121 · Radix sort
// Exercício E721 · ★☆☆

#include <stdio.h>

// quantas passadas o radix sort em base 10 faria para x
int quantos_digitos(int x) {
    int d = 1;
    while (x >= 10) {
        x /= 10;
        d++;
    }
    return d;
}

// dígito da posição pos (0 = unidade, 1 = dezena, ...)
int digito(int x, int pos) {
    for (int i = 0; i < pos; i++) {
        x /= 10;
    }
    return x % 10;
}

int main(void) {
    int numeros[] = {5082, 7, 340, 19000};
    const char *casas[] = {"unidade", "dezena", "centena", "milhar", "dezena de milhar"};
    for (int i = 0; i < 4; i++) {
        int d = quantos_digitos(numeros[i]);
        printf("%d: %d dígito%s;", numeros[i], d, d > 1 ? "s" : "");
        for (int pos = 0; pos < d; pos++) {
            printf(" %s %d%s", casas[pos], digito(numeros[i], pos), pos < d - 1 ? "," : "\n");
        }
    }
    return 0;
}

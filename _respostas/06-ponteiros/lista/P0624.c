// Lista · Módulo 06 · Ponteiros
// Exercício P0624 · ★★★ · Números romanos nos dois sentidos

#include <stdio.h>

int valor(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romano_para_int(const char *s) {
    int total = 0;
    for (; *s != '\0'; s++) {
        if (valor(*s) < valor(*(s + 1))) {
            total -= valor(*s); // IV: o I vem antes de um maior
        } else {
            total += valor(*s);
        }
    }
    return total;
}

void int_para_romano(int n, char *saida) {
    const int valores[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *simbolos[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                                "X", "IX", "V", "IV", "I"};
    char *p = saida;
    for (int i = 0; i < 13; i++) {
        while (n >= valores[i]) {
            for (const char *q = simbolos[i]; *q != '\0'; q++) {
                *p++ = *q; // escreve e avança
            }
            n -= valores[i];
        }
    }
    *p = '\0';
}

int main(void) {
    const char *romanos[4] = {"XIV", "XCIX", "MMXXVI", "CDXLIV"};
    int numeros[3] = {1987, 3999, 49};
    char buf[20];

    for (int i = 0; i < 4; i++) {
        printf("%s = %d\n", romanos[i], romano_para_int(romanos[i]));
    }
    for (int i = 0; i < 3; i++) {
        int_para_romano(numeros[i], buf);
        printf("%d = %s\n", numeros[i], buf);
    }
    return 0;
}

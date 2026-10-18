// 0116 · Análise amortizada
// Exercício E694 · ★★☆

#include <stdio.h>

#define BITS 10

int incrementa(int b[]) {
    int i = 0, trocas = 0;
    while (i < BITS && b[i] == 1) {
        b[i] = 0;
        trocas++;
        i++;
    }
    if (i < BITS) {
        b[i] = 1;
        trocas++;
    }
    return trocas;
}

// subtrai 1: os 0 do fim viram 1 (empresta), o primeiro 1 vira 0
int decrementa(int b[]) {
    int i = 0, trocas = 0;
    while (i < BITS && b[i] == 0) {
        b[i] = 1;
        trocas++;
        i++;
    }
    if (i < BITS) {
        b[i] = 0;
        trocas++;
    }
    return trocas;
}

// coloca o valor x nos bits
void carrega(int b[], int x) {
    for (int i = 0; i < BITS; i++) {
        b[i] = (x >> i) & 1;
    }
}

int main(void) {
    int b[BITS];

    carrega(b, 0);
    int total = 0;
    for (int k = 0; k < 100; k++) {
        total += incrementa(b);
    }
    printf("100 incrementos a partir de 0: %d trocas (%.2f por operação)\n", total, total / 100.0);

    carrega(b, 511);
    total = 0;
    for (int k = 0; k < 100; k++) {
        total += (k % 2 == 0) ? incrementa(b) : decrementa(b);
    }
    printf("inc/dec alternados a partir de 511: %d trocas (%.2f por operação)\n", total, total / 100.0);
    return 0;
}

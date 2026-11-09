// Lista · Módulo 04 · Funções e modularização
// Exercício P0426 · ★★★ · De quantas formas dar o troco

#include <stdio.h>

long chamadas = 0;

int moeda(int i) {
    switch (i) {
        case 0: return 100;
        case 1: return 50;
        case 2: return 25;
        case 3: return 10;
        case 4: return 5;
        default: return 1;
    }
}

int formas(int valor, int i) {
    chamadas++;
    if (valor == 0) {
        return 1;
    }
    if (valor < 0 || i == 6) {
        return 0;
    }
    // usa a moeda i (e ainda pode usar de novo) + desiste dela
    return formas(valor - moeda(i), i) + formas(valor, i + 1);
}

void contar(int centavos) {
    chamadas = 0;
    int f = formas(centavos, 0);
    printf("R$ %d,%02d: %d forma(s), %ld chamada(s)\n", centavos / 100, centavos % 100, f, chamadas);
}

int main(void) {
    contar(10);
    contar(25);
    contar(100);
    return 0;
}

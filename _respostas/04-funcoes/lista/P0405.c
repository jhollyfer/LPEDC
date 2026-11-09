// Lista · Módulo 04 · Funções e modularização
// Exercício P0405 · ★☆☆ · O protótipo esquecido

#include <stdio.h>

double area_terreno(double frente, double fundo); // protótipo: avisa que ela existe

int main(void) {
    printf("Área do terreno: %.1f m2\n", area_terreno(12.5, 30.0));
    return 0;
}

double area_terreno(double frente, double fundo) {
    return frente * fundo;
}

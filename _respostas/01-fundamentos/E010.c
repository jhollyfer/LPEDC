// 0002 · Variáveis
// Exercício E010 · ★★☆

#include <stdio.h>

int main(void) {
    int casa = 1;
    int visitante = 3;

    int aux = casa;   // guarda o 1 antes que ele se perca
    casa = visitante; // casa vira 3
    visitante = aux;  // visitante vira 1

    printf("Casa %d x %d Visitante\n", casa, visitante);
    return 0;
}

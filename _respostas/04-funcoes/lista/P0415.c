// Lista · Módulo 04 · Funções e modularização
// Exercício P0415 · ★★☆ · O app de treinos refatorado

#include <stdio.h>

int minutos(int hora, int minuto) {
    return hora * 60 + minuto;
}

void mostrar(int duracao) {
    printf("%d h %d min\n", duracao / 60, duracao % 60);
}

int main(void) {
    int d1 = minutos(7, 45) - minutos(6, 30);
    int d2 = minutos(19, 10) - minutos(18, 20);
    int d3 = minutos(10, 5) - minutos(8, 0);

    printf("Treino 1: ");
    mostrar(d1);
    printf("Treino 2: ");
    mostrar(d2);
    printf("Treino 3: ");
    mostrar(d3);
    printf("Total: ");
    mostrar(d1 + d2 + d3);
    return 0;
}

// Lista · Módulo 04 · Funções e modularização
// Exercício P0410 · ★☆☆ · A barra de progresso do download

#include <stdio.h>

void barra(int percentual) {
    int cheios = percentual / 10;

    printf("[");
    for (int i = 1; i <= 10; i++) {
        printf("%c", i <= cheios ? '#' : '.');
    }
    printf("] %d%%\n", percentual);
}

int main(void) {
    barra(0);
    barra(30);
    barra(75);
    barra(100);
    return 0;
}

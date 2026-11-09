// Lista · Módulo 03 · Laços
// Exercício P0307 · ★☆☆ · A fofoca no grupo da família

#include <stdio.h>

int main(void) {
    int sabem = 1;
    int rodada = 0;

    while (sabem <= 1000000) {
        sabem *= 3;
        rodada++;
        printf("Rodada %d: %d pessoas\n", rodada, sabem);
    }
    printf("Passou de 1 milhão na rodada %d\n", rodada);
    return 0;
}

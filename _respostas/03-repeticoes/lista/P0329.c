// Lista · Módulo 03 · Laços
// Exercício P0329 · ★★★ · Monty Hall no programa de auditório

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int RODADAS = 1000000;
    int ganha_ficando = 0, ganha_trocando = 0;

    srand((unsigned) time(NULL));
    for (int r = 0; r < RODADAS; r++) {
        int carro = rand() % 3;
        int escolha = rand() % 3;
        if (escolha == carro) {
            ganha_ficando++;
        } else {
            ganha_trocando++; // o apresentador abriu o outro bode: trocar leva ao carro
        }
    }

    printf("Rodadas: %d\n", RODADAS);
    printf("Ficando: %.0f%% de vitórias\n", ganha_ficando * 100.0 / RODADAS);
    printf("Trocando: %.0f%% de vitórias\n", ganha_trocando * 100.0 / RODADAS);
    return 0;
}

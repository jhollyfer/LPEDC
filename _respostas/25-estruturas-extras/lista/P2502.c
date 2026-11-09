// Lista · Módulo 25 · Estruturas especiais
// Exercício P2502 · ★☆☆ · O mapa do estacionamento

#include <stdio.h>

#define L 4
#define C 8

typedef struct {
    int lin, col, valor;
} Tripla;

int main(void) {
    // (andar, vaga, horas parado), em ordem de andar e vaga
    Tripla t[] = {{0, 2, 3}, {0, 7, 1}, {1, 0, 5}, {1, 1, 2}, {2, 5, 8}, {3, 3, 4}, {3, 4, 1}};
    int n = (int)(sizeof t / sizeof t[0]);

    int k = 0;
    for (int i = 0; i < L; i++) {
        printf("andar %d:", i);
        for (int j = 0; j < C; j++) {
            if (k < n && t[k].lin == i && t[k].col == j) printf(" %d", t[k++].valor);
            else printf(" .");
        }
        printf("\n");
    }
    int total = 0;
    for (int x = 0; x < n; x++) total += t[x].valor;
    printf("Carros: %d, horas somadas: %d\n", n, total);
    return 0;
}

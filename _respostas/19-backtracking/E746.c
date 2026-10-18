// 0125 · Subconjuntos
// Exercício E746 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define N 3

const int moedas[N] = {100, 50, 25}; // centavos
bool pega[N];

void gera(int i) {
    if (i == N) {
        int total = 0;
        for (int j = 0; j < N; j++) {
            if (pega[j]) {
                total += moedas[j];
            }
        }
        printf("R$ %d.%02d:", total / 100, total % 100);
        for (int j = 0; j < N; j++) {
            if (pega[j]) {
                printf(" %d", moedas[j]);
            }
        }
        printf("\n");
        return;
    }
    pega[i] = true;  // caminho 1: com a moeda i
    gera(i + 1);
    pega[i] = false; // caminho 2: sem a moeda i
    gera(i + 1);
}

int main(void) {
    gera(0);
    return 0;
}

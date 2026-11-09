// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2008 · ★☆☆ · Os consertos da oficina

#include <stdio.h>

#define N 6
#define DIAS 3

const char nome[N] = {'A', 'B', 'C', 'D', 'E', 'F'};
const int valor[N] = {300, 250, 200, 150, 100, 80};
const int prazo[N] = {2, 1, 2, 3, 3, 1};

int main(void) {
    int dia[DIAS + 1];
    for (int d = 1; d <= DIAS; d++) {
        dia[d] = -1;
    }
    for (int i = 0; i < N; i++) {
        int achou = 0;
        for (int d = prazo[i]; d >= 1; d--) {
            if (dia[d] == -1) {
                dia[d] = i;
                achou = 1;
                break;
            }
        }
        if (!achou) {
            printf("Recusado: %c (R$ %d)\n", nome[i], valor[i]);
        }
    }
    int total = 0;
    for (int d = 1; d <= DIAS; d++) {
        if (dia[d] >= 0) {
            printf("Dia %d: %c (R$ %d)\n", d, nome[dia[d]], valor[dia[d]]);
            total += valor[dia[d]];
        }
    }
    printf("Total: R$ %d\n", total);
    return 0;
}

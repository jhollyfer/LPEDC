// Lista · Módulo 12 · Pilhas e filas
// Exercício P1216 · ★★☆ · Quantos dias até esquentar?

#include <stdio.h>

void espera(const int t[], int n, int resposta[], int *operacoes) {
    int pilha[64], topo = 0; // índices dos dias que ainda esperam
    *operacoes = 0;
    for (int i = 0; i < n; i++) {
        resposta[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        while (topo > 0 && t[pilha[topo - 1]] < t[i]) {
            int j = pilha[--topo];
            (*operacoes)++;
            resposta[j] = i - j;
        }
        pilha[topo++] = i;
        (*operacoes)++;
    }
}

int main(void) {
    int t[7] = {28, 26, 27, 30, 25, 29, 31};
    int r[7], ops;
    espera(t, 7, r, &ops);
    for (int i = 0; i < 7; i++) {
        printf(i == 0 ? "%2d" : " %2d", t[i]);
    }
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf(i == 0 ? "%2d" : " %2d", r[i]);
    }
    printf("\noperações na pilha: %d\n", ops);
    return 0;
}

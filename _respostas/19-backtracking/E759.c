// 0127 · Backtracking
// Exercício E759 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define N 5
#define CAPACIDADE 100

const int pesos[N] = {47, 39, 28, 23, 16};
bool leva[N];
bool melhor[N];
int melhor_soma = -1;
int resto[N + 1]; // resto[i] = soma dos pesos de i até o fim

void tenta(int i, int soma) {
    if (soma > CAPACIDADE) {
        return;                          // poda 1: estourou
    }
    if (soma + resto[i] <= melhor_soma) {
        return;                          // poda 2 (bônus): não supera a melhor
    }
    if (soma > melhor_soma) {            // nova melhor carga
        melhor_soma = soma;
        for (int j = 0; j < N; j++) {
            melhor[j] = j < i && leva[j];
        }
    }
    if (i == N) {
        return;
    }
    leva[i] = true;
    tenta(i + 1, soma + pesos[i]);
    leva[i] = false;
    tenta(i + 1, soma);
}

int main(void) {
    resto[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        resto[i] = resto[i + 1] + pesos[i];
    }
    tenta(0, 0);
    printf("melhor carga: %d kg\n", melhor_soma);
    printf("caixas:");
    for (int j = 0; j < N; j++) {
        if (melhor[j]) {
            printf(" %d", pesos[j]);
        }
    }
    printf("\n");
    return 0;
}

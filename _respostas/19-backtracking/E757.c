// 0127 · Backtracking
// Exercício E757 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define N 5
#define ALVO 12

const char *itens[N] = {"barraca", "comida", "água", "saco", "fogareiro"};
const int pesos[N] = {7, 5, 4, 3, 2};
bool leva[N];
int chamadas = 0;

void mostra(int ate) {
    int primeiro = 1;
    for (int j = 0; j < ate; j++) {
        if (leva[j]) {
            printf(primeiro ? "%s" : " %s", itens[j]);
            primeiro = 0;
        }
    }
    printf("\n");
}

void tenta(int i, int soma) {
    chamadas++;
    if (soma > ALVO) {
        return;              // poda: passou do peso
    }
    if (soma == ALVO) {
        mostra(i);           // fechou: só os itens 0..i-1 foram decididos
        return;
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
    tenta(0, 0);
    printf("%d chamadas\n", chamadas);
    return 0;
}

// 0127 · Backtracking
// Exercício E761 · ★★★
//
// Resposta: a soma global nunca era desfeita. Depois do caminho "com o
// item", ela continuava valendo com a porção, e o caminho "sem o item"
// começava com o peso errado. Quem altera um estado global antes da chamada
// recursiva precisa restaurá-lo depois dela.

#include <stdbool.h>
#include <stdio.h>

#define N 5
#define ALVO 500

const char *nomes[N] = {"pudim", "mousse", "torta", "gelatina", "brigadeiro"};
const int porcoes[N] = {250, 200, 150, 100, 50};
bool leva[N];
int soma = 0;

void tenta(int i) {
    if (soma > ALVO) {
        return;
    }
    if (soma == ALVO) {
        int primeiro = 1;
        for (int j = 0; j < i; j++) {
            if (leva[j]) {
                printf(primeiro ? "%s" : " %s", nomes[j]);
                primeiro = 0;
            }
        }
        printf("\n");
        return;
    }
    if (i == N) {
        return;
    }
    leva[i] = true;
    soma += porcoes[i];
    tenta(i + 1);
    soma -= porcoes[i]; // desfaz a soma antes de tentar sem o item
    leva[i] = false;
    tenta(i + 1);
}

int main(void) {
    tenta(0);
    return 0;
}

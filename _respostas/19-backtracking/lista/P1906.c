// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1906 · ★☆☆ · Presidente e vice do grêmio

#include <stdbool.h>
#include <stdio.h>

#define N 4
#define K 2

const char *nomes[N] = {"Davi", "Eva", "Fábio", "Gil"};
bool usado[N];
int esc[K];
int chapas = 0;

void escolhe(int k) {
    if (k == K) {
        chapas++;
        printf("%s / %s\n", nomes[esc[0]], nomes[esc[1]]);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (usado[i]) {
            continue;
        }
        usado[i] = true;
        esc[k] = i;
        escolhe(k + 1);
        usado[i] = false;
    }
}

int main(void) {
    escolhe(0);
    printf("Total: %d chapas\n", chapas);
    return 0;
}

// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1915 · ★★☆ · Quanto a poda economiza

#include <stdio.h>

#define N 12
#define ALVO 100

const int v[N] = {45, 38, 30, 27, 22, 20, 15, 12, 10, 8, 5, 3};
long chamadas;
int solucoes;

void sem_poda(int i, int soma) {
    chamadas++;
    if (i == N) {
        if (soma == ALVO) {
            solucoes++;
        }
        return;
    }
    sem_poda(i + 1, soma + v[i]);
    sem_poda(i + 1, soma);
}

void com_poda(int i, int soma, int resto) {
    chamadas++;
    if (soma > ALVO || soma + resto < ALVO) {
        return;
    }
    if (soma == ALVO) {
        solucoes++;
        return;
    }
    if (i == N) {
        return;
    }
    com_poda(i + 1, soma + v[i], resto - v[i]);
    com_poda(i + 1, soma, resto - v[i]);
}

int main(void) {
    chamadas = 0;
    solucoes = 0;
    sem_poda(0, 0);
    printf("Sem poda: %d soluções, %ld chamadas\n", solucoes, chamadas);
    int resto = 0;
    for (int i = 0; i < N; i++) {
        resto += v[i];
    }
    chamadas = 0;
    solucoes = 0;
    com_poda(0, 0, resto);
    printf("Com poda: %d soluções, %ld chamadas\n", solucoes, chamadas);
    return 0;
}

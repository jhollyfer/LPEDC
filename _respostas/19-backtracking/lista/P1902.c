// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1902 · ★☆☆ · Cara ou coroa quatro vezes

#include <stdio.h>

#define N 4

const char simbolos[2] = {'C', 'K'};
char seq[N + 1];
int total = 0, empates = 0;

void sorteia(int pos) {
    if (pos == N) {
        int caras = 0;
        for (int i = 0; i < N; i++) {
            if (seq[i] == 'C') {
                caras++;
            }
        }
        total++;
        if (caras == 2) {
            empates++;
        }
        printf("%s\n", seq);
        return;
    }
    for (int s = 0; s < 2; s++) {
        seq[pos] = simbolos[s];
        sorteia(pos + 1);
    }
}

int main(void) {
    seq[N] = '\0';
    sorteia(0);
    printf("%d sequências, %d com duas caras\n", total, empates);
    return 0;
}

// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1914 · ★★☆ · Os anagramas de BOLO sem repetir

#include <stdio.h>

#define TAM 4
#define D 3

const char letra[D] = {'B', 'L', 'O'};
int sobra[D] = {1, 1, 2};
char pal[TAM + 1];
int total = 0;

void monta(int pos) {
    if (pos == TAM) {
        total++;
        printf("%s\n", pal);
        return;
    }
    for (int j = 0; j < D; j++) {
        if (sobra[j] == 0) {
            continue;
        }
        sobra[j]--;
        pal[pos] = letra[j];
        monta(pos + 1);
        sobra[j]++;
    }
}

int main(void) {
    pal[TAM] = '\0';
    monta(0);
    printf("Total: %d anagramas\n", total);
    return 0;
}

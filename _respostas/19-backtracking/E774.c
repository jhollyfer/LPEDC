// 0129 · Labirinto
// Exercício E774 · ★★★

#include <stdio.h>

#define L 5
#define C 6

char mapa[L][C + 1] = {
    "S.....",
    ".##.#.",
    "......",
    ".#.##.",
    "...#.F",
};
char melhor[L][C + 1];
int menor = L * C + 1;   // "infinito": nenhum caminho tem tantos passos
long chamadas = 0;

void anda(int l, int c, int passos) {
    chamadas++;
    if (passos >= menor) {
        return;                      // poda: já não dá para ganhar do melhor
    }
    if (l < 0 || l >= L || c < 0 || c >= C) {
        return;
    }
    if (mapa[l][c] == 'F') {
        menor = passos;              // chegou com menos passos que o melhor
        for (int i = 0; i < L; i++) {
            for (int j = 0; j <= C; j++) {
                melhor[i][j] = mapa[i][j];
            }
        }
        return;
    }
    if (mapa[l][c] != '.' && mapa[l][c] != 'S') {
        return;
    }
    char antes = mapa[l][c];
    mapa[l][c] = '*';
    anda(l, c + 1, passos + 1);
    anda(l + 1, c, passos + 1);
    anda(l, c - 1, passos + 1);
    anda(l - 1, c, passos + 1);
    mapa[l][c] = antes;              // desfaz: outro caminho pode passar aqui
}

int main(void) {
    anda(0, 0, 0);
    printf("menor caminho: %d passos\n", menor);
    for (int l = 0; l < L; l++) {
        printf("%s\n", melhor[l]);
    }
    printf("%ld chamadas\n", chamadas);
    return 0;
}

// Lista · Módulo 08 · Tipos compostos
// Exercício P0816 · ★★☆ · Batalha naval

#include <stdio.h>
#include <stdbool.h>

#define N 5

typedef struct {
    bool navio;
    bool atingida;
} Casa;

const char *atirar(Casa t[N][N], int l, int c) {
    Casa *alvo = &t[l][c];
    if (alvo->atingida) {
        return "repetido";
    }
    alvo->atingida = true;
    return alvo->navio ? "fogo!" : "água";
}

int main(void) {
    const char *mapa[5] = {".##..", ".....", "#...#", "#...#", "#...."};
    int tiros[7][2] = {{0, 1}, {2, 2}, {0, 2}, {3, 0}, {0, 1}, {4, 4}, {2, 4}};
    Casa t[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            t[i][j].navio = (mapa[i][j] == '#');
            t[i][j].atingida = false;
        }
    }
    for (int k = 0; k < 7; k++) {
        printf("Tiro (%d, %d): %s\n", tiros[k][0], tiros[k][1],
               atirar(t, tiros[k][0], tiros[k][1]));
    }

    int sobram = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch = '.';
            if (t[i][j].navio) {
                ch = t[i][j].atingida ? 'X' : '#';
                sobram += !t[i][j].atingida;
            } else if (t[i][j].atingida) {
                ch = 'o';
            }
            putchar(ch);
        }
        putchar('\n');
    }
    printf("Sobram %d casas de navio\n", sobram);
    return 0;
}

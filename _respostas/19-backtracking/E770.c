// 0129 · Labirinto
// Exercício E770 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define L 5
#define C 5

char lab[L][C + 1];

const char *lab1[L] = {
    "..#..",
    "#.#.#",
    "..#..",
    ".#...",
    "...#Q",
};
const char *lab2[L] = {
    "...#.",
    "#..#.",
    ".#.#.",
    "...#.",
    ".#.#Q",
};

bool chega(int l, int c) {
    if (l < 0 || l >= L || c < 0 || c >= C) {
        return false;
    }
    if (lab[l][c] == 'Q') {
        return true;
    }
    if (lab[l][c] != '.') {
        return false;              // parede ou já visitada
    }
    lab[l][c] = 'v';
    return chega(l, c + 1) || chega(l + 1, c) || chega(l, c - 1) || chega(l - 1, c);
}

void testa(int numero, const char *origem[]) {
    for (int l = 0; l < L; l++) {
        strcpy(lab[l], origem[l]);
    }
    printf("labirinto %d: %s\n", numero,
           chega(0, 0) ? "o rato chega ao queijo" : "sem caminho até o queijo");
}

int main(void) {
    testa(1, lab1);
    testa(2, lab2);
    return 0;
}

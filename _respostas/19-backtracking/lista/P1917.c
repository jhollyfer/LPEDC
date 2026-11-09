// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1917 · ★★☆ · Todos os caminhos até a saída

#include <stdbool.h>
#include <stdio.h>

#define L 4
#define C 5

const char mapa[L][C + 1] = {
    "S...#",
    ".#...",
    "...#.",
    "#...F",
};
bool visto[L][C];
int caminhos = 0, menor = 1000, maior = 0;

void anda(int l, int c, int passos) {
    if (l < 0 || l >= L || c < 0 || c >= C || mapa[l][c] == '#' || visto[l][c]) {
        return;
    }
    if (mapa[l][c] == 'F') {
        caminhos++;
        if (passos < menor) {
            menor = passos;
        }
        if (passos > maior) {
            maior = passos;
        }
        return;
    }
    visto[l][c] = true;
    anda(l - 1, c, passos + 1);
    anda(l + 1, c, passos + 1);
    anda(l, c - 1, passos + 1);
    anda(l, c + 1, passos + 1);
    visto[l][c] = false;
}

int main(void) {
    anda(0, 0, 0);
    printf("Caminhos: %d\n", caminhos);
    printf("Mais curto: %d passos\n", menor);
    printf("Mais longo: %d passos\n", maior);
    return 0;
}

// 0111 · DFS: busca em profundidade
// Exercício E663 · ★★☆

#include <stdio.h>

#define L 5
#define C 7

char mapa[L][C + 1] = {
    "##~~~#~",
    "#~~~##~",
    "~~#~~~~",
    "~###~~#",
    "~~#~~##",
};

int pintar(int l, int c) {
    if (l < 0 || l >= L || c < 0 || c >= C) return 0; // fora da foto
    if (mapa[l][c] != '#') return 0;                  // água ou já pintada
    mapa[l][c] = 'x';                                 // marca como visitada
    return 1 + pintar(l - 1, c) + pintar(l + 1, c) + pintar(l, c - 1) + pintar(l, c + 1);
}

int main(void) {
    int ilhas = 0, maior = 0;
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            if (mapa[l][c] != '#') continue;
            int tamanho = pintar(l, c);
            ilhas++;
            printf("Ilha %d: %d casa(s)\n", ilhas, tamanho);
            if (tamanho > maior) maior = tamanho;
        }
    }
    printf("Total: %d ilhas, a maior tem %d casas\n", ilhas, maior);
    return 0;
}

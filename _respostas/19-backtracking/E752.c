// 0126 · Permutações
// Exercício E752 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define N 3

const char *pessoas[N] = {"Lia", "Max", "Nina"};
int foto[N];
bool usado[N];

void fotos(int pos) {
    if (pos == N) {
        printf("%s %s %s\n", pessoas[foto[0]], pessoas[foto[1]], pessoas[foto[2]]);
        return;
    }
    for (int p = 0; p < N; p++) {
        if (usado[p]) {
            continue;
        }
        usado[p] = true;   // escolhe
        foto[pos] = p;
        fotos(pos + 1);    // desce
        usado[p] = false;  // desfaz
    }
}

int main(void) {
    fotos(0);
    return 0;
}

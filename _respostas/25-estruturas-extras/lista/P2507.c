// Lista · Módulo 25 · Estruturas especiais
// Exercício P2507 · ★☆☆ · Os emojis usados por último

#include <stdio.h>
#include <string.h>

#define N 6

// procura e leva para a posição 0; devolve o custo (comparações)
int usa(const char *v[], const char *emoji) {
    for (int i = 0; i < N; i++) {
        if (strcmp(v[i], emoji) == 0) {
            const char *achado = v[i];
            for (int k = i; k > 0; k--) v[k] = v[k - 1]; // os da frente andam uma casa
            v[0] = achado;
            return i + 1;
        }
    }
    return N;
}

int main(void) {
    const char *teclado[N] = {"risada", "coracao", "joinha", "palmas", "fogo", "choro"};
    const char *usados[] = {"fogo", "fogo", "joinha", "fogo", "choro", "joinha", "fogo"};
    int total = 0;
    for (int k = 0; k < 7; k++) {
        int c = usa(teclado, usados[k]);
        total += c;
        printf("%-7s custo %d:", usados[k], c);
        for (int i = 0; i < N; i++) printf(" %s", teclado[i]);
        printf("\n");
    }
    printf("Custo total: %d\n", total);
    return 0;
}

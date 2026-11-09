// Lista · Módulo 07 · Memória dinâmica
// Exercício P0709 · ★☆☆ · O realloc não zera

#include <stdio.h>
#include <stdlib.h>

int *crescer_zerado(int *v, int n_velho, int n_novo) {
    int *novo = realloc(v, n_novo * sizeof *novo);
    if (novo == NULL) {
        return NULL; // v continua valendo para quem chamou
    }
    for (int i = n_velho; i < n_novo; i++) {
        novo[i] = 0; // a parte nova vem com lixo
    }
    return novo;
}

void placar(const int *v, int n) {
    printf("Placar (%d jogadores):", n);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int *pontos = calloc(3, sizeof *pontos);
    if (pontos == NULL) {
        return 1;
    }
    pontos[0] += 2;
    pontos[2] += 1;
    placar(pontos, 3);

    int *maior = crescer_zerado(pontos, 3, 5);
    if (maior == NULL) {
        free(pontos);
        return 1;
    }
    pontos = maior;
    pontos[4] += 3;
    pontos[0] += 1;
    placar(pontos, 5);
    free(pontos);
    return 0;
}

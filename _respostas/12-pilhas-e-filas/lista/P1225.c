// Lista · Módulo 12 · Pilhas e filas
// Exercício P1225 · ★★★ · Os lagos da várzea (preenchimento com pilha)

#include <stdbool.h>
#include <stdio.h>

#define L 6
#define C 8

typedef struct {
    int l, c;
} Pos;

typedef struct {
    Pos v[L * C];
    int n;
} Pilha;

int main(void) {
    const char *mapa[L] = {
        "~~..~...",
        "~...~~..",
        "..~.....",
        ".~~~..~~",
        "......~.",
        "~~....~.",
    };
    bool visitada[L][C] = {{false}};
    int dl[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
    int lagos = 0, maior = 0;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (mapa[i][j] != '~' || visitada[i][j]) {
                continue;
            }
            Pilha p = {.n = 0};
            visitada[i][j] = true;
            p.v[p.n++] = (Pos){i, j};
            int casas = 0;
            while (p.n > 0) {
                Pos atual = p.v[--p.n];
                casas++;
                for (int k = 0; k < 4; k++) {
                    int nl = atual.l + dl[k], nc = atual.c + dc[k];
                    if (nl >= 0 && nl < L && nc >= 0 && nc < C && mapa[nl][nc] == '~' &&
                        !visitada[nl][nc]) {
                        visitada[nl][nc] = true; // marca ao empilhar
                        p.v[p.n++] = (Pos){nl, nc};
                    }
                }
            }
            lagos++;
            printf("Lago %d: %d casas (começa em %d,%d)\n", lagos, casas, i, j);
            if (casas > maior) {
                maior = casas;
            }
        }
    }
    printf("Maior: %d casas\n", maior);
    return 0;
}

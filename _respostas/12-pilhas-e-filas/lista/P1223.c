// Lista · Módulo 12 · Pilhas e filas
// Exercício P1223 · ★★★ · O menor caminho na feira (busca em largura)

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define L 5
#define C 6
#define CAP (L * C)

typedef struct {
    int l, c;
} Pos;

typedef struct {
    Pos v[CAP];
    int inicio, n;
} Fila;

void insere(Fila *f, Pos p) {
    f->v[(f->inicio + f->n) % CAP] = p;
    f->n++;
}

Pos retira(Fila *f) {
    Pos p = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return p;
}

int main(void) {
    char mapa[L][C + 1] = {
        "S.#...",
        ".##.#.",
        "...#..",
        "#....#",
        "...#.F",
    };
    int dist[L][C];
    Pos veio[L][C];
    Pos s = {0, 0}, f = {0, 0};
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            dist[i][j] = -1;
            if (mapa[i][j] == 'S') {
                s = (Pos){i, j};
            } else if (mapa[i][j] == 'F') {
                f = (Pos){i, j};
            }
        }
    }

    int dl[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // cima, baixo, esquerda, direita
    Fila fila = {.inicio = 0, .n = 0};
    dist[s.l][s.c] = 0;
    insere(&fila, s);
    while (fila.n > 0) {
        Pos p = retira(&fila);
        for (int k = 0; k < 4; k++) {
            int nl = p.l + dl[k], nc = p.c + dc[k];
            if (nl < 0 || nl >= L || nc < 0 || nc >= C) {
                continue;
            }
            if (mapa[nl][nc] == '#' || dist[nl][nc] != -1) {
                continue;
            }
            dist[nl][nc] = dist[p.l][p.c] + 1;
            veio[nl][nc] = p;
            insere(&fila, (Pos){nl, nc});
        }
    }

    if (dist[f.l][f.c] == -1) {
        printf("Não há caminho\n");
        return 0;
    }
    printf("Menor caminho: %d passos\n", dist[f.l][f.c]);
    Pos p = veio[f.l][f.c];
    while (p.l != s.l || p.c != s.c) { // de F para trás, sem marcar S e F
        mapa[p.l][p.c] = '*';
        p = veio[p.l][p.c];
    }
    for (int i = 0; i < L; i++) {
        printf("%s\n", mapa[i]);
    }
    return 0;
}

// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0506 · ★☆☆ · É identidade?

#include <stdio.h>
#include <stdbool.h>

#define N 4

void montar_identidade(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = (i == j); // 1 na diagonal, 0 fora
        }
    }
}

bool eh_identidade(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] != (i == j)) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int id[N][N];
    int quase[N][N] = {{1, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    montar_identidade(id);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%s", id[i][j], j < N - 1 ? " " : "\n");
        }
    }
    printf("id é identidade? %s\n", eh_identidade(id) ? "sim" : "não");
    printf("quase é identidade? %s\n", eh_identidade(quase) ? "sim" : "não");
    return 0;
}

// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0512 · ★★☆ · A tabela de distâncias é simétrica?

#include <stdio.h>
#include <stdbool.h>

#define N 4

bool simetrica(int m[N][N], int erro[2]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // só acima da diagonal
            if (m[i][j] != m[j][i]) {
                erro[0] = i;
                erro[1] = j;
                return false;
            }
        }
    }
    return true;
}

int soma_acima(int m[N][N]) {
    int soma = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            soma += m[i][j];
        }
    }
    return soma;
}

void conferir(const char nome[], int m[N][N]) {
    int erro[2];
    if (simetrica(m, erro)) {
        printf("%s: simétrica, soma acima da diagonal = %d km\n", nome, soma_acima(m));
    } else {
        printf("%s: NÃO simétrica em [%d][%d] (%d x %d)\n", nome, erro[0], erro[1],
               m[erro[0]][erro[1]], m[erro[1]][erro[0]]);
    }
}

int main(void) {
    int d1[N][N] = {{0, 12, 30, 8}, {12, 0, 25, 17}, {30, 25, 0, 21}, {8, 17, 21, 0}};
    int d2[N][N] = {{0, 12, 30, 8}, {12, 0, 25, 17}, {30, 52, 0, 21}, {8, 17, 21, 0}};

    conferir("d1", d1);
    conferir("d2", d2);
    return 0;
}

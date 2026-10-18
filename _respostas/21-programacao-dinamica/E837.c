// 0140 · Mochila 0/1
// Exercício E837 · ★★☆

#include <stdio.h>

#define N 6
#define MAXU 40 // unidades de meia hora que cabem na tabela

int main(void) {
    const char *materia[N + 1] = {"", "Matemática", "Português", "História",
                                  "Física", "Química", "Inglês"};
    double horas[N + 1] = {0, 2.5, 1.5, 1.0, 2.0, 1.5, 0.5};
    int pontos[N + 1] = {0, 30, 18, 10, 25, 16, 6};
    double disponivel = 6.0;

    // horas viram meias horas inteiras; o + 0.5 arredonda (2.5 * 2 pode dar 4.9999...)
    int u[N + 1];
    for (int i = 1; i <= N; i++) {
        u[i] = (int) (horas[i] * 2 + 0.5);
    }
    int W = (int) (disponivel * 2 + 0.5);

    int t[N + 1][MAXU + 1];
    for (int c = 0; c <= W; c++) {
        t[0][c] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= W; c++) {
            t[i][c] = t[i - 1][c];
            if (u[i] <= c && pontos[i] + t[i - 1][c - u[i]] > t[i][c]) {
                t[i][c] = pontos[i] + t[i - 1][c - u[i]];
            }
        }
    }
    printf("Máximo: %d pontos em %.1f h\n", t[N][W], disponivel);

    printf("Estudar:");
    int c = W;
    double usadas = 0;
    for (int i = N; i >= 1; i--) {
        if (t[i][c] != t[i - 1][c]) {
            printf(" %s", materia[i]);
            c -= u[i];
            usadas += horas[i];
        }
    }
    printf("\nHoras usadas: %.1f\n", usadas);
    return 0;
}

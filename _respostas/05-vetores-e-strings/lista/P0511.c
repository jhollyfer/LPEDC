// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0511 · ★★☆ · Quanto custa cada receita em cada mercado

#include <stdio.h>

void multiplicar(double a[2][3], double b[3][2], double c[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j]; // linha i de a com coluna j de b
            }
        }
    }
}

int main(void) {
    double q[2][3] = {{2.0, 1.0, 0.5},    // bolo
                      {1.0, 0.5, 1.0}};   // brigadeirão
    double p[3][2] = {{5.50, 4.90},       // farinha: mercado A, B
                      {4.20, 4.80},       // açúcar
                      {38.00, 41.50}};    // chocolate
    double c[2][2];
    char receitas[2][16] = {"Bolo", "Brigadeirão"};

    multiplicar(q, p, c);
    for (int i = 0; i < 2; i++) {
        printf("%s: A = R$ %.2f, B = R$ %.2f -> mais barato no %c\n",
               receitas[i], c[i][0], c[i][1], c[i][0] <= c[i][1] ? 'A' : 'B');
    }
    return 0;
}

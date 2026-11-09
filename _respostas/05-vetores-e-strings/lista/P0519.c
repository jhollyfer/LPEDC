// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0519 · ★★☆ · Totais da planilha de vendas

#include <stdio.h>

int main(void) {
    int v[3][4] = {{40, 35, 52, 48}, {22, 30, 27, 31}, {15, 18, 12, 25}};
    char sabor[3][10] = {"Coco", "Manga", "Tapioca"};
    int tot_lin[3] = {0};
    int tot_col[4] = {0};
    int geral = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            tot_lin[i] += v[i][j];
            tot_col[j] += v[i][j];
            geral += v[i][j];
        }
    }

    printf("%-9s %4s %4s %4s %4s %6s\n", "", "S1", "S2", "S3", "S4", "Total");
    for (int i = 0; i < 3; i++) {
        printf("%-9s", sabor[i]);
        for (int j = 0; j < 4; j++) {
            printf(" %4d", v[i][j]);
        }
        printf(" %6d\n", tot_lin[i]);
    }
    printf("%-9s", "Total");
    for (int j = 0; j < 4; j++) {
        printf(" %4d", tot_col[j]);
    }
    printf(" %6d\n", geral);
    return 0;
}

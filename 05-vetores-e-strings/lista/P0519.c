// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0519 · ★★☆ · Totais da planilha de vendas
//
// A sorveteria anota as vendas (em potes) de 3 sabores em 4 semanas:
//
//   int v[3][4] = {{40, 35, 52, 48}, {22, 30, 27, 31}, {15, 18, 12, 25}};
//
// Complete o programa: falta calcular o total de cada sabor (linha), o total
// de cada semana (coluna) e o total geral, para a tabela sair assim:
//
//   Saída esperada:
//               S1   S2   S3   S4  Total
//   Coco        40   35   52   48    175
//   Manga       22   30   27   31    110
//   Tapioca     15   18   12   25     70
//   Total       77   83   91  104    355
//
// Dicas:
// 1. O total da linha i soma v[i][j] variando j; o da coluna j soma v[i][j]
//    variando i.
// 2. Você pode fazer tudo num par de for só, acumulando em tot_lin[i],
//    tot_col[j] e geral ao mesmo tempo.
// 3. Confira: a soma dos totais das linhas é igual à soma dos totais das
//    colunas, e as duas dão o total geral.
// 4. Resposta esperada: a saída acima (total geral 355).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int v[3][4] = {{40, 35, 52, 48}, {22, 30, 27, 31}, {15, 18, 12, 25}};
    char sabor[3][10] = {"Coco", "Manga", "Tapioca"};
    int tot_lin[3] = {0};
    int tot_col[4] = {0};
    int geral = 0;

    // calcule os totais aqui

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

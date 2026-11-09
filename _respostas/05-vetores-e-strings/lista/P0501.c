// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0501 · ★☆☆ · O melhor dia da padaria

#include <stdio.h>

#define DIAS 7

int main(void) {
    int vendas[DIAS] = {1830, 920, 1045, 870, 1110, 1490, 2210};
    char dias[DIAS][5] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sáb"};

    int total = 0;
    int i_maior = 0;
    int i_menor = 0;
    for (int i = 0; i < DIAS; i++) {
        total += vendas[i];
        if (vendas[i] > vendas[i_maior]) {
            i_maior = i;
        }
        if (vendas[i] < vendas[i_menor]) {
            i_menor = i;
        }
    }

    printf("Total da semana: R$ %d\n", total);
    printf("Média por dia: R$ %.2f\n", total / (double) DIAS);
    printf("Maior: %s (R$ %d)\n", dias[i_maior], vendas[i_maior]);
    printf("Menor: %s (R$ %d)\n", dias[i_menor], vendas[i_menor]);
    return 0;
}

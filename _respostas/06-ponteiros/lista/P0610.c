// Lista · Módulo 06 · Ponteiros
// Exercício P0610 · ★☆☆ · O maior da matriz por um ponteiro só

#include <stdio.h>

int main(void) {
    int v[3][4] = {{12, 18, 9, 14}, {20, 7, 16, 11}, {13, 15, 22, 8}};
    int *inicio = &v[0][0];
    int *fim = inicio + 3 * 4;
    int *p_maior = inicio;

    for (int *p = inicio; p < fim; p++) {
        if (*p > *p_maior) {
            p_maior = p;
        }
    }
    int k = (int) (p_maior - inicio);

    printf("Maior venda: %d\n", *p_maior);
    printf("Posição no bloco: %d\n", k);
    printf("Vendedor (linha): %d\n", k / 4);
    printf("Semana (coluna): %d\n", k % 4);
    return 0;
}

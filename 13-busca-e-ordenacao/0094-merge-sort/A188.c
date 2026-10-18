// A188 · Os pedidos das duas lojas numa fila só

#include <stdio.h>

// junta a[0..na-1] e b[0..nb-1], já ordenados, em c; devolve as comparações
int intercala(const int a[], int na, const int b[], int nb, int c[]) {
    int i = 0, j = 0, k = 0, comparacoes = 0;
    while (i < na && j < nb) {
        comparacoes++;
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < na) c[k++] = a[i++];   // uma das duas acabou:
    while (j < nb) c[k++] = b[j++];   // o resto da outra vem direto
    return comparacoes;
}

int main(void) {
    // horários dos pedidos (hhmm), cada loja já em ordem
    int loja_a[] = {812, 905, 1047, 1320};
    int loja_b[] = {750, 930, 1015, 1100, 1405};
    int todos[9];

    int c = intercala(loja_a, 4, loja_b, 5, todos);
    for (int k = 0; k < 9; k++) {
        printf("%s%02d:%02d", k > 0 ? " " : "", todos[k] / 100, todos[k] % 100);
    }
    printf("\n%d comparações para juntar 9 pedidos\n", c);
    return 0;
}
// Saída:
// 07:50 08:12 09:05 09:30 10:15 10:47 11:00 13:20 14:05
// 8 comparações para juntar 9 pedidos

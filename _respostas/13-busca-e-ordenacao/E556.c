// 0093 · Insertion sort
// Exercício E556 · ★★☆

#include <stdio.h>
#include <stdbool.h>

// ordena v e devolve o total de deslocamentos; com maior_ou_igual, usa >=
int ordena(int v[], int n, bool maior_ou_igual, bool mostrar) {
    int total = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];
        int i = j - 1;
        int d = 0;
        while (i >= 0 && (maior_ou_igual ? v[i] >= x : v[i] > x)) {
            v[i + 1] = v[i];
            i--;
            d++;
        }
        v[i + 1] = x;
        total += d;
        if (mostrar) {
            printf("j = %d (x = %d entrou na posição %d):", j, x, i + 1);
            for (int k = 0; k < n; k++) {
                printf(" %d", v[k]);
            }
            printf(" (deslocou %d)\n", d);
        }
    }
    return total;
}

int main(void) {
    int preparo[] = {6, 3, 8, 3, 1};
    int copia[] = {6, 3, 8, 3, 1};
    int n = 5;

    printf("total com >: %d\n", ordena(preparo, n, false, true));
    printf("total com >=: %d\n", ordena(copia, n, true, false));
    return 0;
}

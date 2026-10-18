// 0093 · Insertion sort
// Exercício E558 · ★★★
//
// A busca binária derruba as comparações, mas os deslocamentos continuam os
// mesmos: cada elemento ainda anda casa por casa. Dobrando n, os deslocamentos
// quase quadruplicam (120 -> 496): continua O(n²).

#include <stdio.h>

void insertion(int v[], int n, int *comp, int *desl) {
    *comp = 0;
    *desl = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];
        int i = j - 1;
        while (i >= 0) {
            (*comp)++;
            if (v[i] <= x) {
                break;
            }
            v[i + 1] = v[i];
            (*desl)++;
            i--;
        }
        v[i + 1] = x;
    }
}

void insertion_binaria(int v[], int n, int *comp, int *desl) {
    *comp = 0;
    *desl = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];
        // primeira posição de v[0..j-1] com valor > x (mantém a estabilidade)
        int ini = 0, fim = j;
        while (ini < fim) {
            int meio = ini + (fim - ini) / 2;
            (*comp)++;
            if (v[meio] <= x) {
                ini = meio + 1;
            } else {
                fim = meio;
            }
        }
        for (int i = j; i > ini; i--) {   // abre o buraco em v[ini]
            v[i] = v[i - 1];
            (*desl)++;
        }
        v[ini] = x;
    }
}

void testa(int n) {
    int a[32], b[32];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = 10 * (n - i);   // invertido: 10n, ..., 20, 10
    }
    int c1, d1, c2, d2;
    insertion(a, n, &c1, &d1);
    insertion_binaria(b, n, &c2, &d2);
    printf("n = %d\n", n);
    printf("normal:  %3d comparações, %3d deslocamentos\n", c1, d1);
    printf("binária: %3d comparações, %3d deslocamentos\n", c2, d2);
    printf("ordenado? %s\n", b[0] == 10 && b[n - 1] == 10 * n ? "sim" : "não");
}

int main(void) {
    testa(16);
    testa(32);
    return 0;
}

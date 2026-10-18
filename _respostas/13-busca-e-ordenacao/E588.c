// 0098 · Insertion sort
// Exercício E588 · ★★★
//
// Conclusão: a busca binária derruba as comparações (de 120 para 49 no vetor
// invertido), mas os deslocamentos continuam 120: cada elemento ainda precisa
// andar até o seu lugar, uma casa por vez. Como o custo dominante passa a ser
// mover memória, o algoritmo continua O(n²).

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

int main(void) {
    int a[16], b[16];
    for (int i = 0; i < 16; i++) {
        a[i] = b[i] = 160 - 10 * i;   // 160, 150, ..., 10
    }
    int c1, d1, c2, d2;
    insertion(a, 16, &c1, &d1);
    insertion_binaria(b, 16, &c2, &d2);
    printf("normal:  %3d comparações, %3d deslocamentos\n", c1, d1);
    printf("binária: %3d comparações, %3d deslocamentos\n", c2, d2);
    printf("ordenado? %s\n", b[0] == 10 && b[15] == 160 ? "sim" : "não");
    return 0;
}

// 0100 · Quick sort
// Exercício E596 · ★☆☆

#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// mesma ideia do separa: v[0..j-1] guarda os negativos
int separa_negativos(int v[], int n) {
    int j = 0;
    for (int k = 0; k < n; k++) {
        if (v[k] < 0) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    return j;
}

int main(void) {
    int saldos[] = {120, -45, 300, -10, 0, -80, 55};
    int n = 7;

    int neg = separa_negativos(saldos, n);
    for (int i = 0; i < n; i++) {
        printf("%s%d", i > 0 ? " " : "", saldos[i]);
    }
    printf("\n%d contas no vermelho\n", neg);
    return 0;
}

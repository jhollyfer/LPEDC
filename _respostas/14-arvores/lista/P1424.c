// Lista · Módulo 14 · Árvores
// Exercício P1424 · ★★★ · O heap que escolhia o filho errado
//
// Resposta: o if que escolhe o filho comparava o filho DIREITO com o PAI
// (v[f + 1] > v[i]) em vez de com o irmão esquerdo (v[f + 1] > v[f]). Quando
// os dois filhos são maiores que o pai, o direito era escolhido mesmo sendo
// o menor dos dois, e o menor subia acima do irmão maior.

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

int main(void) {
    int bonus[] = {300, 1500, 800, 1200, 900, 400, 1100, 700};
    int n = 8;

    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(bonus, n, i);
    }
    printf("ordem de pagamento:");
    while (n > 0) {
        printf(" %d", bonus[0]);
        bonus[0] = bonus[--n];
        desce(bonus, n, 0);
    }
    printf("\n");
    return 0;
}

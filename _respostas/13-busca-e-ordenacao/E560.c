// 0094 · Merge sort
// Exercício E560 · ★☆☆

#include <stdio.h>

static int chamadas = 0, folhas = 0;

void ordena(int p, int r, int nivel) {
    chamadas++;
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("[%d, %d)", p, r);
    if (r - p < 2) {
        folhas++;
        printf(" folha\n");
        return;
    }
    printf("\n");
    int q = p + (r - p) / 2;
    ordena(p, q, nivel + 1);
    ordena(q, r, nivel + 1);
}

int main(void) {
    ordena(0, 5, 0);
    printf("%d chamadas, %d folhas, %d intercalações\n",
           chamadas, folhas, chamadas - folhas);
    return 0;
}

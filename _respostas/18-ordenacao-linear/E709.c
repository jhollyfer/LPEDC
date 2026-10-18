// 0119 · Shell sort
// Exercício E709 · ★☆☆

#include <stdio.h>

// mostra os saltos de Knuth que o shell sort usa para n elementos
void mostra_saltos(int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    printf("n = %d:", n);
    for (; h >= 1; h /= 3) {
        printf(" %d", h);
    }
    printf("\n");
}

int main(void) {
    int tamanhos[] = {10, 100, 1000, 1000000};
    for (int i = 0; i < 4; i++) {
        mostra_saltos(tamanhos[i]);
    }
    return 0;
}

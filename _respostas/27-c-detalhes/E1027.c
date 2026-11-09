// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1027 · ★☆☆

#include <stdio.h>

void multiplos(int base, int n) {
    int t[n];
    for (int i = 0; i < n; i++) {
        t[i] = base * (i + 1);
    }
    printf("%d:", base);
    for (int i = 0; i < n; i++) {
        printf(" %d", t[i]);
    }
    printf(" (%zu bytes)\n", sizeof t);
}

int main(void) {
    multiplos(7, 3);
    multiplos(9, 5);
    return 0;
}

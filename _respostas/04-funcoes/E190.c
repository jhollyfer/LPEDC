// 0032 · Recursão
// Exercício E190 · ★★☆

#include <stdio.h>

void binario(int n) {
    if (n < 2) {
        printf("%d", n);
        return;
    }
    binario(n / 2);
    printf("%d", n % 2);
}

int main(void) {
    printf("13 = ");
    binario(13);
    printf("\n255 = ");
    binario(255);
    printf("\n2026 = ");
    binario(2026);
    printf("\n");
    return 0;
}

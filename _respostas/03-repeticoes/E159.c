// 0027 · Juntando tudo
// Exercício E159 · ★★☆

#include <stdio.h>

int main(void) {
    int encontrados = 0;

    for (int n = 100; n <= 999; n++) {
        int a = n / 100;
        int b = n / 10 % 10;
        int c = n % 10;
        if (a * a * a + b * b * b + c * c * c == n) {
            printf("%d ", n);
            encontrados++;
        }
    }
    printf("\nEncontrados: %d\n", encontrados);
    return 0;
}

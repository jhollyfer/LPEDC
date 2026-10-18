// 0028 · Break e continue
// Exercício E167 · ★★★

#include <stdio.h>

int main(void) {
    int testados = 0;

    for (int n = 1000; n <= 9999; n++) {
        if (n % 7 != 0) {
            continue;
        }
        testados++;
        int a = n / 1000;
        int b = n / 100 % 10;
        int c = n / 10 % 10;
        int d = n % 10;
        if (a + b + c + d == 20) {
            printf("Achei: %d (%d + %d + %d + %d = 20)\n", n, a, b, c, d);
            break;
        }
    }
    printf("Múltiplos de 7 testados: %d\n", testados);
    return 0;
}

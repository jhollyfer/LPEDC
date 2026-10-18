// 0020 · While
// Exercício E120 · ★★★

#include <stdio.h>

int main(void) {
    // trecho A
    int i = 0;
    int voltas_a = 0;
    printf("A: ");
    while (i++ < 5) {
        printf("%d ", i);
        voltas_a++;
    }
    printf("| voltas %d, i final %d\n", voltas_a, i);

    // trecho B
    int n = 100;
    int voltas_b = 0;
    printf("B: ");
    while (n > 1) {
        n = n / 3;
        printf("%d ", n);
        voltas_b++;
    }
    printf("| voltas %d, n final %d\n", voltas_b, n);

    // trecho C
    int k = 10;
    int voltas_c = 0;
    printf("C: ");
    while (k < 10) {
        k++;
        voltas_c++;
    }
    printf("| voltas %d, k final %d\n", voltas_c, k);
    return 0;
}

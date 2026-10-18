// 0021 · Do-while
// Exercício E122 · ★☆☆

#include <stdio.h>

int main(void) {
    // trecho A
    int n = 10;
    while (n < 5) {
        printf("%d ", n);
        n++;
    }
    printf("| A terminou com n = %d\n", n);

    // trecho B
    int m = 10;
    do {
        printf("%d ", m);
        m++;
    } while (m < 5);
    printf("| B terminou com m = %d\n", m);

    // trecho C: o corpo uma vez antes, depois o while
    int k = 10;
    printf("%d ", k);
    k++;
    while (k < 5) {
        printf("%d ", k);
        k++;
    }
    printf("| C terminou com k = %d\n", k);
    return 0;
}

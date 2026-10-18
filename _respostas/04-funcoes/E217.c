// 0037 · Recursão
// Exercício E217 · ★☆☆

#include <stdio.h>

int soma_ate(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + soma_ate(n - 1);
}

int main(void) {
    printf("soma_ate(4) = %d\n", soma_ate(4));
    printf("soma_ate(100) = %d\n", soma_ate(100));
    printf("Cumprimentos com 12 duplas: %d\n", soma_ate(11));
    return 0;
}

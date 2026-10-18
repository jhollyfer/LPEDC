// 0020 · While
// Exercício E119 · ★★★

#include <stdio.h>

int main(void) {
    long n;

    printf("Digite n: ");
    if (scanf("%ld", &n) != 1 || n < 1) {
        printf("Preciso de um inteiro positivo.\n");
        return 1;
    }

    long maior = n;
    int passos = 0;
    printf("%ld", n);
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        passos++;
        if (n > maior) {
            maior = n;
        }
        printf(" %ld", n);
    }
    printf("\nPassos: %d\n", passos);
    printf("Maior valor: %ld\n", maior);
    return 0;
}

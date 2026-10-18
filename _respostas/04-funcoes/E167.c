// 0028 · Funções
// Exercício E167 · ★★★

#include <stdio.h>

int dobro(int n) {
    return 2 * n;
    printf("nunca aparece\n");
}

int ajusta(int n) {
    if (n > 10) {
        return n - 10;
    }
    if (n % 2 == 0) {
        return n / 2;
    }
    return n + 1;
}

int passos(int n) {
    int contador = 0;
    while (n != 1) {
        n = ajusta(n);
        printf("%d ", n);
        contador++;
    }
    return contador;
}

int main(void) {
    int total;

    printf("7: ");
    total = passos(7);
    printf("(%d passos)\n", total);

    printf("14: ");
    total = passos(14);
    printf("(%d passos)\n", total);

    printf("30: ");
    total = passos(30);
    printf("(%d passos)\n", total);

    printf("ajusta(dobro(7)) = %d\n", ajusta(dobro(7)));
    return 0;
}

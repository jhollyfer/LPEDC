// 0028 · Funções
// Exercício E167 · ★★★
//
// Resposta: 8, 4, 11 e 5. ajusta(7) = 8 (ímpar, soma 1); dobro(7) = 14 e
// ajusta(14) = 4; ajusta(8) = 4, dobro(4) = 8, dobro(3) = 6, ajusta(6) = 3,
// 8 + 3 = 11; ajusta(30) = 20, ajusta(20) = 10, ajusta(10) = 5. O printf
// depois do return em dobro nunca roda (o compilador nem gera código para ele).

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

int main(void) {
    printf("%d\n", ajusta(7));
    printf("%d\n", ajusta(dobro(7)));
    printf("%d\n", dobro(ajusta(8)) + ajusta(dobro(3)));
    printf("%d\n", ajusta(ajusta(ajusta(30))));
    return 0;
}

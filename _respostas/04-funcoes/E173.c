// 0029 · Parâmetros e passagem por valor
// Exercício E173 · ★★★
//
// Resposta: 3, 7.0, 7.5 e 8. O 7.9 vira 7 ao entrar no parâmetro int, e 7 / 2
// é 3. Em media, (7 + 8) / 2 é divisão inteira: 7; só depois vira 7.0. Em
// media_certa, 7 e 8 viram 7.0 e 8.0 ao entrar, e a conta dá 7.5.
// metade(31) = 15, 15 + 1 = 16, metade(16) = 8.

#include <stdio.h>

int metade(int x) {
    return x / 2;
}

double media(int a, int b) {
    return (a + b) / 2;
}

double media_certa(double a, double b) {
    return (a + b) / 2;
}

int main(void) {
    printf("%d\n", metade(7.9));
    printf("%.1f\n", media(7, 8));
    printf("%.1f\n", media_certa(7, 8));
    printf("%d\n", metade(metade(31) + 1));
    return 0;
}

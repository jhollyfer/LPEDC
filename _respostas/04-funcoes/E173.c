// 0029 · Parâmetros e passagem por valor
// Exercício E173 · ★★★

#include <stdio.h>

int metade(int x) {
    return x / 2;
}

double media(int a, int b) {
    return (a + b) / 2.0; // 2.0 é double: a divisão deixa de ser inteira
}

int arredondar(double x) {
    return x + 0.5; // o return converte para int, cortando a parte decimal
}

int main(void) {
    printf("metade(7.9) = %d\n", metade(7.9));
    printf("media(7, 8) = %.1f\n", media(7, 8));
    printf("media(9, 10) = %.1f\n", media(9, 10));
    printf("arredondar(7.5) = %d\n", arredondar(7.5));
    printf("arredondar(media(6, 7)) = %d\n", arredondar(media(6, 7)));
    return 0;
}

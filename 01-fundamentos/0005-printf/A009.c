// A009 · O extrato que corta o nome comprido

#include <stdio.h>

int main(void) {
    // zeros à esquerda: o número da conta tem sempre 6 dígitos
    printf("Conta %06d-%d\n", 4521, 7);

    // %-14.14s: coluna de 14 casas e, se o texto for maior, corta em 14
    // %+9.2f: sinal sempre, para entrada e saída ficarem claras
    printf("%-14.14s %+9.2f\n", "Pix recebido de Mariana", 250.00);
    printf("%-14.14s %+9.2f\n", "Mercado", -87.35);
    printf("%-14.14s %+9.2f\n", "Conta de luz da casa", -142.10);
    printf("%-14s %9.2f\n", "Saldo", 20.55);

    // o mesmo valor com precisões diferentes: só a tela muda
    double juros = 0.0875;
    printf("Juros: %.1f%% ou %.3f%%\n", juros * 100, juros * 100);
    return 0;
}
// Saída:
// Conta 004521-7
// Pix recebido d   +250.00
// Mercado           -87.35
// Conta de luz d   -142.10
// Saldo              20.55
// Juros: 8.8% ou 8.750%

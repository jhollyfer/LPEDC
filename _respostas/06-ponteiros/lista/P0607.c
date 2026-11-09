// Lista · Módulo 06 · Ponteiros
// Exercício P0607 · ★☆☆ · A regra de desconto como parâmetro

#include <stdio.h>

double nenhuma(double p) { return p; }
double black_friday(double p) { return p * 0.70; }
double cupom10(double p) { return p > 10 ? p - 10 : 0; }
double leve_mais(double p) { return p > 100 ? p * 0.95 : p; }

double total_com(const double *precos, int n, double (*regra)(double)) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += regra(precos[i]); // a regra que quem chamou escolheu
    }
    return soma;
}

int main(void) {
    double carrinho[4] = {129.90, 8.50, 45.00, 210.00};
    double (*regras[4])(double) = {nenhuma, black_friday, cupom10, leve_mais};
    const char *nomes[4] = {"Sem desconto", "Black Friday", "Cupom R$ 10", "Leve mais"};

    for (int r = 0; r < 4; r++) {
        printf("%-13s R$ %7.2f\n", nomes[r], total_com(carrinho, 4, regras[r]));
    }
    return 0;
}

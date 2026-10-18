// A180 · Em qual faixa de frete cai o pacote?

#include <stdio.h>

// devolve a primeira posição com limite[i] >= peso (ou n, se nenhuma serve).
// Intervalo semiaberto [ini, fim): fim aponta uma gaveta DEPOIS do fim.
int primeira_faixa(const double limite[], int n, double peso, int *voltas) {
    int ini = 0, fim = n;
    *voltas = 0;
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        (*voltas)++;
        if (limite[meio] < peso) {
            ini = meio + 1;   // essa faixa é pequena demais
        } else {
            fim = meio;       // essa serve; talvez uma anterior também sirva
        }
    }
    return ini;
}

int main(void) {
    double limite[] = {1, 2, 5, 10, 20, 30};                    // até X kg
    double preco[] = {12.90, 18.50, 27.00, 39.90, 59.90, 84.00};
    int n = 6;
    double pesos[] = {7.5, 2.0, 0.3, 31.0};
    int voltas;

    for (int k = 0; k < 4; k++) {
        int f = primeira_faixa(limite, n, pesos[k], &voltas);
        if (f < n) {
            printf("%4.1f kg: faixa até %2.0f kg, R$ %5.2f (%d voltas)\n",
                   pesos[k], limite[f], preco[f], voltas);
        } else {
            printf("%4.1f kg: acima do limite (%d voltas)\n", pesos[k], voltas);
        }
    }
    return 0;
}
// Saída:
//  7.5 kg: faixa até 10 kg, R$ 39.90 (3 voltas)
//  2.0 kg: faixa até  2 kg, R$ 18.50 (3 voltas)
//  0.3 kg: faixa até  1 kg, R$ 12.90 (3 voltas)
// 31.0 kg: acima do limite (2 voltas)

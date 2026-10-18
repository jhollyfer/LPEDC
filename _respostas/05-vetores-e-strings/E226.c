// 0038 · Vetores e funções
// Exercício E226 · ★★☆

#include <stdio.h>

#define MESES 12

int indice_do_maior(const double v[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[pos]) {
            pos = i;
        }
    }
    return pos;
}

double media(const double v[], int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

int contar_acima(const double v[], int n, double limite) {
    int quantos = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > limite) {
            quantos++;
        }
    }
    return quantos;
}

int main(void) {
    double contas[MESES] = {182.40, 175.10, 190.75, 168.30, 150.20, 141.90,
                            139.60, 144.80, 158.25, 171.40, 189.90, 205.35};

    int pos = indice_do_maior(contas, MESES);
    double m = media(contas, MESES);

    printf("Mês mais caro: %d (R$ %.2f)\n", pos + 1, contas[pos]);
    printf("Média mensal: R$ %.2f\n", m);
    printf("Meses acima da média: %d\n", contar_acima(contas, MESES, m));
    return 0;
}

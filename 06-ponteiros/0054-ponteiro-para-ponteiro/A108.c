// A108 · O posto mais barato

#include <stdio.h>

// precisa MUDAR o ponteiro de quem chamou: recebe o endereço dele (double **)
void mais_barato(double *precos, int n, double **escolhido) {
    *escolhido = &precos[0];
    for (int i = 1; i < n; i++) {
        if (precos[i] < **escolhido) {
            *escolhido = &precos[i]; // o ponteiro do main passa a apontar aqui
        }
    }
}

int main(void) {
    double precos[4] = {5.89, 5.74, 5.92, 5.79}; // gasolina em 4 postos
    double *posto = NULL;

    mais_barato(precos, 4, &posto);  // &posto: o endereço do ponteiro
    if (posto != NULL) {
        printf("Mais barato: posto %td, R$ %.2f\n", posto - precos, *posto);
        *posto -= 0.10;              // cupom do app: 10 centavos a menos
    }
    for (int i = 0; i < 4; i++) {
        printf("%.2f ", precos[i]);
    }
    printf("\n");
    return 0;
}
// Saída:
// Mais barato: posto 1, R$ 5.74
// 5.89 5.64 5.92 5.79

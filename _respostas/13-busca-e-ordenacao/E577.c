// 0097 · Selection sort
// Exercício E577 · ★☆☆

#include <stdio.h>

int main(void) {
    int precos[] = {89, 45, 120, 30, 75, 60};
    int n = 6;

    // a parte pronta cresce pela DIREITA: v[fim+1..n-1]
    for (int fim = n - 1; fim > 0; fim--) {
        int maior = 0;
        for (int j = 1; j <= fim; j++) {
            if (precos[j] > precos[maior]) {
                maior = j;
            }
        }
        int aux = precos[fim];
        precos[fim] = precos[maior];
        precos[maior] = aux;

        printf("fim = %d:", fim);
        for (int i = 0; i < n; i++) {
            printf(" %d", precos[i]);
        }
        printf("\n");
    }
    return 0;
}

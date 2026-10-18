// 0071 · Eficiência: contar passos
// Exercício E422 · ★☆☆
//
// Resposta: Maior: 36, Comparações: 9, Trocas: 3.

#include <stdio.h>

int comparacoes = 0;
int trocas = 0;

int maior_temperatura(const int t[], int n) {
    int maior = t[0];
    for (int i = 1; i < n; i++) {
        comparacoes++;
        if (t[i] > maior) {
            maior = t[i];
            trocas++;
        }
    }
    return maior;
}

int main(void) {
    int temps[10] = {28, 31, 27, 35, 33, 30, 29, 36, 34, 32};

    printf("Maior: %d\n", maior_temperatura(temps, 10));
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    return 0;
}

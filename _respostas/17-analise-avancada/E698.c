// 0117 · Limite inferior da ordenação
// Exercício E698 · ★☆☆

#include <stdio.h>

int comparacoes = 0;

int maior(int a, int b) {
    comparacoes++;
    return a > b;
}

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j = i - 1;
        while (j >= 0 && maior(v[j], x)) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main(void) {
    int precos[4] = {10, 20, 30, 40};
    int melhor = 100, pior = 0, total = 0, quantas = 0, no_pior = 0;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    if (a == b || a == c || a == d || b == c || b == d || c == d) {
                        continue;
                    }
                    int v[4] = {precos[a], precos[b], precos[c], precos[d]};
                    comparacoes = 0;
                    insertion(v, 4);
                    total += comparacoes;
                    quantas++;
                    if (comparacoes < melhor) {
                        melhor = comparacoes;
                    }
                    if (comparacoes > pior) {
                        pior = comparacoes;
                        no_pior = 0;               // pior novo: recomeça a contagem
                    }
                    if (comparacoes == pior) {
                        no_pior++;
                    }
                }
            }
        }
    }
    printf("%d ordens testadas\n", quantas);
    printf("melhor: %d, pior: %d (em %d ordens), média: %.2f\n", melhor, pior, no_pior, (double)total / quantas);
    printf("limite inferior: 5\n");
    return 0;
}

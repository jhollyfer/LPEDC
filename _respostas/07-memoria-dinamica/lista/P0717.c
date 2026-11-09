// Lista · Módulo 07 · Memória dinâmica
// Exercício P0717 · ★★☆ · A média móvel do sensor

#include <stdio.h>
#include <stdlib.h>

#define K 4

int main(void) {
    double leituras[9] = {4.0, 4.5, 5.0, 6.5, 8.0, 7.5, 5.0, 4.0, 3.5};
    double *janela = malloc(K * sizeof *janela);
    if (janela == NULL) {
        return 1;
    }
    int pos = 0, usados = 0;
    double soma = 0;

    for (int m = 0; m < 9; m++) {
        if (usados == K) {
            soma -= janela[pos]; // a leitura mais velha sai
        } else {
            usados++;
        }
        janela[pos] = leituras[m];
        soma += leituras[m];
        pos = (pos + 1) % K;
        printf("Min %d: leitura %.1f, média das últimas %d = %.2f\n",
               m + 1, leituras[m], usados, soma / usados);
    }
    free(janela);
    return 0;
}

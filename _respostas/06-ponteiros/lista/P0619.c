// Lista · Módulo 06 · Ponteiros
// Exercício P0619 · ★★☆ · Média e desvio de uma vez

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool estatisticas(const double *v, int n, double *media, double *desvio) {
    if (n < 1) {
        return false;
    }
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    *media = soma / n;

    double quad = 0;
    for (int i = 0; i < n; i++) {
        double d = v[i] - *media;
        quad += d * d;
    }
    *desvio = sqrt(quad / n);
    return true;
}

int main(void) {
    double tempos[6] = {28.5, 27.9, 30.2, 26.8, 29.1, 27.5};
    double media, desvio;

    if (!estatisticas(tempos, 6, &media, &desvio)) {
        return 1;
    }
    printf("Média: %.2f min\n", media);
    printf("Desvio: %.2f min\n", desvio);
    printf("Abaixo da média:");
    for (int i = 0; i < 6; i++) {
        if (tempos[i] < media) {
            printf(" treino %d (%.1f)", i + 1, tempos[i]);
        }
    }
    printf("\n");
    return 0;
}

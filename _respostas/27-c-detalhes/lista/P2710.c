// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2710 · ★☆☆ · A semana mais quente

#include <stdio.h>

int main(void) {
    int v[] = {28, 31, 33, 29, 35, 30, 27};
    int n = sizeof v / sizeof v[0];
    int soma = 0, dia_max = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
        if (v[i] > v[dia_max]) {
            dia_max = i;
        }
    }
    double media = (double)soma / n;
    int acima = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > media) {
            acima++;
        }
    }
    printf("média = %.2f\n", media);
    printf("acima da média: %d dias\n", acima);
    printf("mais quente: %d no dia %d\n", v[dia_max], dia_max);
    return 0;
}

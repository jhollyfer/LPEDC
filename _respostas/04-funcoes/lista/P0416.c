// Lista · Módulo 04 · Funções e modularização
// Exercício P0416 · ★★☆ · A média da temperatura ao longo do dia

#include <stdio.h>

double media_ate_agora(double leitura) {
    static double soma = 0.0;
    static int quantas = 0;

    soma += leitura;
    quantas++;
    return soma / quantas;
}

int main(void) {
    printf("Leitura 30.0 -> média %.1f\n", media_ate_agora(30.0));
    printf("Leitura 32.0 -> média %.1f\n", media_ate_agora(32.0));
    printf("Leitura 28.0 -> média %.1f\n", media_ate_agora(28.0));
    printf("Leitura 34.0 -> média %.1f\n", media_ate_agora(34.0));
    return 0;
}

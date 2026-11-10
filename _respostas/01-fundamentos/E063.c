// 0011 · Juntando tudo
// Exercício E063 · ★★☆

#include <stdio.h>
#include <math.h>

int main(void) {
    double tamanho_gb, velocidade_mbps;
    scanf("%lf", &tamanho_gb);
    scanf("%lf", &velocidade_mbps);

    double megabits = tamanho_gb * 1000 * 8;      // GB -> MB -> megabits
    int segundos = (int) round(megabits / velocidade_mbps);

    printf("Tempo: %d s = %d min %d s\n", segundos, segundos / 60, segundos % 60);
    return 0;
}

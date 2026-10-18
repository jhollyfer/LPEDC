// 0031 · Aleatórios
// Exercício E186 · ★★★

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int experimentos = 10000;
    long total_lancamentos = 0;
    int recorde = 0;

    srand(2026);
    for (int e = 1; e <= experimentos; e++) {
        int seguidos = 0;
        int lancamentos = 0;
        while (seguidos < 3) {
            lancamentos++;
            if (1 + rand() % 6 == 6) {
                seguidos++;
            } else {
                seguidos = 0;
            }
        }
        total_lancamentos += lancamentos;
        if (lancamentos > recorde) {
            recorde = lancamentos;
        }
    }
    printf("Média: %.1f lançamentos\n", (double) total_lancamentos / experimentos);
    printf("Pior caso: %d lançamentos\n", recorde);
    return 0;
}

// 0042 · Vetores
// Exercício E250 · ★★☆

#include <stdio.h>

int main(void) {
    int avaliacoes[] = {5, 4, 5, 3, 5, 1, 4, 5, 2, 4, 5, 3, 4, 5, 5};
    int n = sizeof(avaliacoes) / sizeof(avaliacoes[0]);
    int contagem[6] = {0}; // contagem[0] fica sem uso

    for (int i = 0; i < n; i++) {
        contagem[avaliacoes[i]]++;
    }

    for (int nota = 5; nota >= 1; nota--) {
        printf("Nota %d: ", nota);
        for (int k = 0; k < contagem[nota]; k++) {
            printf("*");
        }
        printf(" (%d)\n", contagem[nota]);
    }
    return 0;
}

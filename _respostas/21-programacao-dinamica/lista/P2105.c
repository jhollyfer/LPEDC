// Lista · Módulo 21 · Programação dinâmica
// Exercício P2105 · ★☆☆ · As fatias do bolo de rolo

#include <stdio.h>

#define TAM 10
#define MAXF 6

int main(void) {
    const int preco[MAXF + 1] = {0, 3, 7, 11, 13, 16, 20};
    int melhor[TAM + 1], corte[TAM + 1];
    melhor[0] = 0;
    corte[0] = 0;
    for (int j = 1; j <= TAM; j++) {
        melhor[j] = 0;
        corte[j] = 0;
        for (int i = 1; i <= j && i <= MAXF; i++) {
            if (preco[i] + melhor[j - i] > melhor[j]) {
                melhor[j] = preco[i] + melhor[j - i];
                corte[j] = i;
            }
        }
    }
    for (int j = 1; j <= TAM; j++) {
        printf("%2d cm: R$ %d\n", j, melhor[j]);
    }
    printf("Fatias:");
    for (int j = TAM; j > 0 && corte[j] > 0; j -= corte[j]) {
        printf(" %d", corte[j]);
    }
    printf("\n");
    return 0;
}

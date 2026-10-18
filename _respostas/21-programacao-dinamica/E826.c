// 0138 · Memoização
// Exercício E826 · ★★☆

#include <stdio.h>

#define N 8

int main(void) {
    int lucro[N] = {40, 25, 60, 30, 10, 55, 35, 20};
    int melhor[N]; // melhor[i] = maior lucro usando só as barracas 0..i

    melhor[0] = lucro[0];
    melhor[1] = lucro[0] > lucro[1] ? lucro[0] : lucro[1];
    for (int i = 2; i < N; i++) {
        int sem_i = melhor[i - 1];            // não monta na barraca i
        int com_i = melhor[i - 2] + lucro[i]; // monta em i: a i - 1 fica vazia
        melhor[i] = com_i > sem_i ? com_i : sem_i;
    }

    printf("melhor:");
    for (int i = 0; i < N; i++) {
        printf(" %d", melhor[i]);
    }
    printf("\nLucro máximo: R$ %d\n", melhor[N - 1]);

    // de trás para a frente: se melhor[i] mudou em relação a melhor[i - 1],
    // a barraca i foi usada (e a i - 1 não pode ser)
    int usadas[N], n = 0;
    int i = N - 1;
    while (i >= 0) {
        if (i == 0 || melhor[i] != melhor[i - 1]) {
            usadas[n++] = i;
            i -= 2;
        } else {
            i--;
        }
    }
    printf("Barracas:");
    for (int k = n - 1; k >= 0; k--) {
        printf(" %d", usadas[k]);
    }
    printf("\n");
    return 0;
}

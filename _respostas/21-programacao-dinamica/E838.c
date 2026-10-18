// 0140 · Mochila 0/1
// Exercício E838 · ★★☆

#include <stdio.h>

#define N 8
#define ALVO 30

int main(void) {
    int nota[N] = {2, 5, 5, 10, 10, 20, 20, 50};

    // jeitos[s] = quantos subconjuntos das notas já vistas somam s.
    // Laço de s DESCENDO: cada nota entra no máximo uma vez.
    long long jeitos[ALVO + 1] = {0};
    jeitos[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int s = ALVO; s >= nota[i]; s--) {
            jeitos[s] += jeitos[s - nota[i]];
        }
    }
    printf("PD: %lld jeitos de separar R$ %d\n", jeitos[ALVO], ALVO);

    // conferência pela força bruta: cada número de 0 a 2^N - 1 é um subconjunto
    int conta = 0;
    for (int mascara = 0; mascara < (1 << N); mascara++) {
        int soma = 0;
        for (int i = 0; i < N; i++) {
            if (mascara & (1 << i)) {
                soma += nota[i];
            }
        }
        if (soma == ALVO) {
            conta++;
        }
    }
    printf("força bruta: %d jeitos (%d subconjuntos testados)\n", conta, 1 << N);
    return 0;
}

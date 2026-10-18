// 0127 · Backtracking
// Exercício E760 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define N 7
#define ALVO 60

const int pacotes[N] = {25, 20, 15, 12, 10, 8, 5};
bool leva[N];
bool melhor[N];
int melhor_k = N + 1; // nenhuma solução ainda

void mostra(const bool escolha[], int ate) {
    int primeiro = 1;
    for (int j = 0; j < ate; j++) {
        if (escolha[j]) {
            printf(primeiro ? "%d" : " %d", pacotes[j]);
            primeiro = 0;
        }
    }
}

void tenta(int i, int soma, int k) {
    if (soma > ALVO) {
        return;
    }
    if (soma == ALVO) {
        mostra(leva, i);
        printf("\n");
        if (k < melhor_k) {            // estritamente menor: o 1º empate fica
            melhor_k = k;
            for (int j = 0; j < N; j++) {
                melhor[j] = j < i && leva[j];
            }
        }
        return;
    }
    if (i == N) {
        return;
    }
    leva[i] = true;
    tenta(i + 1, soma + pacotes[i], k + 1);
    leva[i] = false;
    tenta(i + 1, soma, k);
}

int main(void) {
    tenta(0, 0, 0);
    printf("menos pacotes: ");
    mostra(melhor, N);
    printf(" (%d pacotes)\n", melhor_k);
    return 0;
}

// 0132 · Inversões e subvetor de soma máxima
// Exercício E789 · ★★☆

#include <stdio.h>
#include <string.h>

#define N 6

// posição de nome na lista (busca sequencial); -1 se não achar
int posicao(const char *lista[], int n, const char *nome) {
    for (int i = 0; i < n; i++) {
        if (strcmp(lista[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    const char *meu[N] = {"Feijoada", "Moqueca", "Coxinha", "Acarajé", "Pastel", "Pão de queijo"};
    const char *dela[N] = {"Moqueca", "Coxinha", "Feijoada", "Pão de queijo", "Acarajé", "Pastel"};

    // v[i] = posição, no ranking dela, do meu i-ésimo prato
    int v[N];
    for (int i = 0; i < N; i++) {
        v[i] = posicao(dela, N, meu[i]);
    }

    int desacordo = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i] > v[j]) {
                printf("%s x %s\n", meu[i], meu[j]);
                desacordo++;
            }
        }
    }
    printf("Pares em desacordo: %d de %d\n", desacordo, N * (N - 1) / 2);
    return 0;
}

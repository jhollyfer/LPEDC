// Lista · Módulo 21 · Programação dinâmica
// Exercício P2123 · ★★★ · A árvore de busca ótima do dicionário

#include <stdio.h>

#define N 5

const char *chave[N + 1] = {"", "açaí", "boto", "cuia", "jambu", "tacacá"};
const int busca[N + 1] = {0, 15, 10, 5, 40, 30};
int c[N + 2][N + 1], raiz[N + 2][N + 1];

int soma(int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += busca[k];
    }
    return s;
}

void pre(int i, int j, int prof) {
    if (i > j) {
        return;
    }
    int r = raiz[i][j];
    printf("  %s (nível %d)\n", chave[r], prof);
    pre(i, r - 1, prof + 1);
    pre(r + 1, j, prof + 1);
}

int main(void) {
    for (int i = 1; i <= N + 1; i++) {
        c[i][i - 1] = 0;
    }
    for (int tam = 1; tam <= N; tam++) {
        for (int i = 1; i + tam - 1 <= N; i++) {
            int j = i + tam - 1;
            c[i][j] = -1;
            for (int r = i; r <= j; r++) {
                int custo = c[i][r - 1] + c[r + 1][j] + soma(i, j);
                if (c[i][j] < 0 || custo < c[i][j]) {
                    c[i][j] = custo;
                    raiz[i][j] = r;
                }
            }
        }
    }
    printf("Custo ótimo: %d comparações\n", c[1][N]);
    pre(1, N, 1);
    // raiz cuia (3); açaí (1) com boto (2) à direita; jambu (4) com tacacá (5) à direita
    int equilibrada = busca[3] * 1 + busca[1] * 2 + busca[4] * 2 + busca[2] * 3 + busca[5] * 3;
    printf("Raiz cuia: %d comparações\n", equilibrada);
    return 0;
}

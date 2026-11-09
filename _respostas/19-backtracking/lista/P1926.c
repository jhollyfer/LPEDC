// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1926 · ★★★ · O roteiro turístico de Manaus

#include <stdbool.h>
#include <stdio.h>

#define N 6

const char *ponto[N] = {"Teatro", "Mercado", "Palácio", "MUSA", "Ponta Negra", "Encontro"};
const int liga[N][N] = {
    // Te Me Pa MU PN En
    {0, 1, 1, 1, 0, 0}, // Teatro
    {1, 0, 1, 0, 0, 1}, // Mercado
    {1, 1, 0, 1, 1, 0}, // Palácio
    {1, 0, 1, 0, 1, 1}, // MUSA
    {0, 0, 1, 1, 0, 1}, // Ponta Negra
    {0, 1, 0, 1, 1, 0}, // Encontro
};
bool visitado[N];
int rota[N];
int roteiros = 0, ciclos = 0;

void roteiro(int v, int k) {
    if (k == N) {
        roteiros++;
        for (int i = 0; i < N; i++) {
            printf("%s%s", i ? " > " : "", ponto[rota[i]]);
        }
        if (liga[v][0]) {
            ciclos++;
            printf(" (fecha)");
        }
        printf("\n");
        return;
    }
    for (int w = 0; w < N; w++) {
        if (liga[v][w] && !visitado[w]) {
            visitado[w] = true;
            rota[k] = w;
            roteiro(w, k + 1);
            visitado[w] = false;
        }
    }
}

int main(void) {
    visitado[0] = true;
    rota[0] = 0;
    roteiro(0, 1);
    printf("Roteiros: %d, ciclos: %d\n", roteiros, ciclos);
    return 0;
}

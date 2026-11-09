// 0189 · Juntando tudo
// Exercício E1131 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8

const int px[N] = {0, 1, 4, 6, 7, 5, 2, 3};
const int py[N] = {0, 3, 4, 3, 0, 1, 6, 1};
int d[N][N];
int rota[N];
bool usado[N];
long rotas_completas = 0, chamadas = 0;
int melhor = 1 << 30;

void permuta(int pos, int acum, bool poda) {
    chamadas++;
    if (poda && acum >= melhor) return; // já passou do melhor: não adianta continuar
    if (pos == N) {
        rotas_completas++;
        int total = acum + d[rota[N - 1]][0];
        if (total < melhor) melhor = total;
        return;
    }
    for (int v = 1; v < N; v++) {
        if (usado[v]) continue;
        usado[v] = true;
        rota[pos] = v;
        permuta(pos + 1, acum + d[rota[pos - 1]][v], poda);
        usado[v] = false;
    }
}

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);
    rota[0] = 0;
    usado[0] = true;

    permuta(1, 0, false);
    printf("Sem poda: ótimo %d, %ld rotas completas, %ld chamadas\n", melhor, rotas_completas, chamadas);

    melhor = 1 << 30, rotas_completas = 0, chamadas = 0;
    permuta(1, 0, true);
    printf("Com poda: ótimo %d, %ld rotas completas, %ld chamadas\n", melhor, rotas_completas, chamadas);
    return 0;
}

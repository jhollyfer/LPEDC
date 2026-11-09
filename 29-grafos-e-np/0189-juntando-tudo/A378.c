// A378 · 2-opt: desfazendo os cruzamentos da rota aproximada

#include <stdio.h>
#include <stdlib.h>

#define N 8

const char *pontos[N] = {"Farmácia", "Ana", "Bruno", "Clara", "Dênis", "Edna", "Fábio", "Gil"};
const int px[N] = {0, 1, 4, 6, 7, 5, 2, 3};
const int py[N] = {0, 3, 4, 3, 0, 1, 6, 1};
int d[N][N];

int custo(const int r[]) {
    int c = 0;
    for (int i = 0; i < N; i++) c += d[r[i]][r[(i + 1) % N]];
    return c;
}

void inverte(int r[], int i, int j) { // inverte o trecho r[i..j]
    while (i < j) {
        int t = r[i];
        r[i++] = r[j];
        r[j--] = t;
    }
}

int main(void) {
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++) d[a][b] = abs(px[a] - px[b]) + abs(py[a] - py[b]);

    int rota[N] = {0, 1, 2, 3, 5, 4, 7, 6}; // a rota da árvore mínima do texto
    printf("Início: %d quarteirões\n", custo(rota));

    // 2-opt: troca as arestas (a, b) e (c, e) por (a, c) e (b, e) se encurtar
    int melhorou = 1;
    while (melhorou) {
        melhorou = 0;
        for (int i = 1; i < N - 1 && !melhorou; i++)
            for (int j = i + 1; j < N && !melhorou; j++) {
                int a = rota[i - 1], b = rota[i], c = rota[j], e = rota[(j + 1) % N];
                int ganho = d[a][b] + d[c][e] - d[a][c] - d[b][e];
                if (ganho > 0) {
                    inverte(rota, i, j);
                    printf("  inverte %s..%s: -%d -> %d\n", pontos[b], pontos[c], ganho, custo(rota));
                    melhorou = 1;
                }
            }
    }
    printf("Final:");
    for (int i = 0; i < N; i++) printf(" %s", pontos[rota[i]]);
    printf(" %s = %d quarteirões\n", pontos[0], custo(rota));
    return 0;
}
// Saída:
// Início: 36 quarteirões
//   inverte Ana..Gil: -2 -> 34
//   inverte Dênis..Edna: -2 -> 32
//   inverte Ana..Fábio: -4 -> 28
// Final: Farmácia Gil Edna Dênis Clara Bruno Fábio Ana Farmácia = 28 quarteirões
//
// Inverter um trecho da rota troca duas arestas por outras duas; quando a
// soma das novas é menor, a rota encurta. Aqui, três inversões levaram a
// rota da árvore (36) até o ótimo do Held-Karp (28), com algumas
// centenas de contas. Nem sempre o 2-opt chega ao ótimo: ele para num
// ótimo LOCAL, onde nenhuma troca de duas arestas ajuda. Mas cada volta é
// O(n²), e na prática ele costuma ficar a poucos por cento do ótimo.

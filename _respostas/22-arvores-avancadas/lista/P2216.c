// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2216 · ★★☆ · As ilhas que surgem na vazante

#include <stdbool.h>
#include <stdio.h>

#define L 4
#define C 5

int pai[L * C], posto[L * C];

int acha(int x) {
    if (pai[x] != x) {
        pai[x] = acha(pai[x]);
    }
    return pai[x];
}

int une(int a, int b) {
    int ra = acha(a), rb = acha(b);
    if (ra == rb) {
        return 0;
    }
    if (posto[ra] < posto[rb]) {
        int t = ra;
        ra = rb;
        rb = t;
    }
    pai[rb] = ra;
    if (posto[ra] == posto[rb]) {
        posto[ra]++;
    }
    return 1;
}

int main(void) {
    const int dia[10][2] = {{0, 0}, {0, 1}, {2, 2}, {1, 4}, {2, 1}, {1, 1}, {3, 4}, {2, 4}, {0, 3}, {1, 3}};
    const int dl[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
    bool areia[L * C] = {false};
    for (int i = 0; i < L * C; i++) {
        pai[i] = i;
        posto[i] = 0;
    }
    int ilhas = 0;
    for (int d = 0; d < 10; d++) {
        int l = dia[d][0], c = dia[d][1], x = l * C + c;
        areia[x] = true;
        ilhas++;
        for (int k = 0; k < 4; k++) {
            int nl = l + dl[k], nc = c + dc[k];
            if (nl >= 0 && nl < L && nc >= 0 && nc < C && areia[nl * C + nc]) {
                ilhas -= une(x, nl * C + nc);
            }
        }
        printf("Dia %2d, areia em (%d,%d): %d ilha(s)\n", d + 1, l, c, ilhas);
    }
    return 0;
}

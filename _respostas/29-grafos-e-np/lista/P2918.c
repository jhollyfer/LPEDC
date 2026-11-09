// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2918 · ★★☆ · Clique pelo resolvedor de independente

#include <stdbool.h>
#include <stdio.h>

#define V 7

int g[V][V], comp[V][V];

// caixa-preta: maior conjunto independente por força bruta (máscara)
int maior_independente(int h[V][V]) {
    int melhor = 0, tam_melhor = 0;
    for (int m = 1; m < (1 << V); m++) {
        bool ok = true;
        int tam = 0;
        for (int a = 0; a < V; a++) {
            if (!(m >> a & 1)) continue;
            tam++;
            for (int b = a + 1; b < V; b++)
                if ((m >> b & 1) && h[a][b]) ok = false;
        }
        if (ok && tam > tam_melhor) melhor = m, tam_melhor = tam;
    }
    return melhor;
}

void mostra(const char *rotulo, int m) {
    int tam = 0;
    printf("%s:", rotulo);
    for (int v = 0; v < V; v++)
        if (m >> v & 1) printf(" %d", v), tam++;
    printf(" (%d)\n", tam);
}

int main(void) {
    int e[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {4, 6}};
    for (int k = 0; k < 11; k++) g[e[k][0]][e[k][1]] = g[e[k][1]][e[k][0]] = 1;

    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) comp[a][b] = a != b && !g[a][b];
    int s = maior_independente(comp);
    mostra("Maior clique", s);
    mostra("Cobertura do complemento", ((1 << V) - 1) & ~s);
    return 0;
}

// 0187 · Reduções
// Exercício E1119 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *lojas[V] = {"Açaí", "Bazar", "Café", "Doces", "Ervas", "Farmácia", "Gelato"};
int concorre[V][V]; // 1 = as duas vendem algo em comum
int g2[V][V];

// caixa-preta: maior clique por força bruta (máscara de bits)
int maior_clique(int g[V][V]) {
    int melhor = 0, tam_melhor = 0;
    for (int m = 1; m < (1 << V); m++) {
        bool ok = true;
        int tam = 0;
        for (int a = 0; a < V && ok; a++) {
            if (!(m >> a & 1)) continue;
            tam++;
            for (int b = a + 1; b < V; b++)
                if ((m >> b & 1) && !g[a][b]) ok = false;
        }
        if (ok && tam > tam_melhor) melhor = m, tam_melhor = tam;
    }
    return melhor;
}

int main(void) {
    int pares[][2] = {{0, 2}, {0, 3}, {0, 6}, {1, 4}, {2, 6}, {3, 6}, {4, 5}, {5, 6}};
    for (int k = 0; k < 8; k++) concorre[pares[k][0]][pares[k][1]] = concorre[pares[k][1]][pares[k][0]] = 1;

    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) g2[a][b] = a != b && !concorre[a][b];

    int s = maior_clique(g2);
    int tam = 0;
    printf("Lojas no corredor:");
    for (int v = 0; v < V; v++)
        if (s >> v & 1) printf(" %s", lojas[v]), tam++;
    printf(" (%d)\n", tam);
    return 0;
}

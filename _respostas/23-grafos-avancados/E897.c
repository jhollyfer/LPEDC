// 0150 · Componentes e ciclos
// Exercício E897 · ★★☆

#include <stdio.h>

#define V 9

const char *bairros[V] = {"Centro", "Prainha", "Jardim", "Lagoa", "Industrial",
                          "Vila Nova", "Alto", "Porto", "Mangue"};
int ciclovia[V][V];
int grupo[V];

int marca(int u, int g) { // devolve quantos bairros entraram no grupo
    grupo[u] = g;
    int total = 1;
    for (int v = 0; v < V; v++)
        if (ciclovia[u][v] && grupo[v] == 0) total += marca(v, g);
    return total;
}

int main(void) {
    int trechos[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 6}, {0, 7}, {6, 5}};
    for (int k = 0; k < 6; k++) {
        ciclovia[trechos[k][0]][trechos[k][1]] = 1;
        ciclovia[trechos[k][1]][trechos[k][0]] = 1;
    }

    int grupos = 0, maior = 0, g_maior = 0;
    for (int u = 0; u < V; u++) {
        if (grupo[u] != 0) continue;
        int t = marca(u, ++grupos);
        if (t > maior) {
            maior = t;
            g_maior = grupos;
        }
    }

    printf("Maior grupo: %d bairros (", maior);
    int primeiro = 1;
    for (int v = 0; v < V; v++)
        if (grupo[v] == g_maior) {
            printf("%s%s", primeiro ? "" : ", ", bairros[v]);
            primeiro = 0;
        }
    printf(")\n");

    printf("Sem ciclovia:");
    for (int u = 0; u < V; u++) {
        int grau = 0;
        for (int v = 0; v < V; v++) grau += ciclovia[u][v];
        if (grau == 0) printf(" %s", bairros[u]);
    }
    printf("\n");
    printf("Ciclovias novas para ligar tudo: %d\n", grupos - 1);
    return 0;
}

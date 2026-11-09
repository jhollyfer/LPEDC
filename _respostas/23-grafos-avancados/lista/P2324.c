// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2324 · ★★★ · A carreta mais pesada

#include <stdio.h>

#define V 6

const char *cidades[V] = {"Manaus", "Itacoatiara", "Humaitá", "Porto Velho", "Lábrea", "Tefé"};
const char *siglas[V] = {"MAO", "ITA", "HUM", "PVH", "LAB", "TEF"};

int main(void) {
    int cap[V][V] = {{0}}; // toneladas que a estrada aguenta; 0 = não tem estrada
    int estradas[][3] = {{0, 1, 40}, {0, 2, 18}, {1, 2, 25}, {2, 3, 30}, {1, 3, 12},
                         {2, 4, 22}, {3, 4, 35}, {0, 5, 15}, {5, 4, 28}};
    for (int k = 0; k < 9; k++) {
        int a = estradas[k][0], b = estradas[k][1];
        cap[a][b] = cap[b][a] = estradas[k][2];
    }
    // Floyd-Warshall do gargalo: um caminho vale o seu trecho mais fraco,
    // e queremos o caminho de MAIOR valor
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                if (i == j) continue;
                int passando = cap[i][k] < cap[k][j] ? cap[i][k] : cap[k][j];
                if (passando > cap[i][j]) cap[i][j] = passando;
            }

    printf("    ");
    for (int j = 0; j < V; j++) printf(" %s", siglas[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%s ", siglas[i]);
        for (int j = 0; j < V; j++) {
            if (i == j) printf("   -");
            else printf(" %3d", cap[i][j]);
        }
        printf("\n");
    }
    printf("%s -> %s: até %d t\n", cidades[0], cidades[3], cap[0][3]);
    printf("%s -> %s: até %d t\n", cidades[5], cidades[4], cap[5][4]);
    return 0;
}

// 0155 · Floyd-Warshall: todos os pares
// Exercício E928 · ★★☆

#include <stdio.h>

#define V 4
#define INFINITO 1000000000

const char *moedas[V] = {"Real", "Dólar", "Euro", "Cripto"};

void analisa(const char *semana, int custo[][3], int n) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    for (int e = 0; e < n; e++) d[custo[e][0]][custo[e][1]] = custo[e][2];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] != INFINITO && d[k][j] != INFINITO && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    int achou = 0;
    for (int i = 0; i < V; i++)
        if (d[i][i] < 0) achou = 1; // dá para sair de i e voltar a i ganhando
    if (!achou) {
        printf("%s: sem ciclo negativo\n", semana);
        return;
    }
    printf("%s: ciclo negativo passando por", semana);
    for (int i = 0; i < V; i++)
        if (d[i][i] < 0) printf(" %s", moedas[i]);
    printf("\n");
}

int main(void) {
    int semana1[][3] = {{0, 1, 30}, {1, 2, 20}, {2, 0, 25}, {0, 3, 50},
                        {3, 1, -10}, {1, 0, 35}, {2, 3, 15}};
    int semana2[][3] = {{0, 1, 30}, {1, 2, 20}, {2, 0, 25}, {0, 3, 50},
                        {3, 1, -40}, {1, 0, 35}, {2, 3, 15}};
    analisa("Semana 1", semana1, 7);
    analisa("Semana 2", semana2, 7);
    return 0;
}

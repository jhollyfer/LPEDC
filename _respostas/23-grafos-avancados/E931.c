// 0156 · Juntando tudo: o assistente do calouro
// Exercício E931 · ★☆☆

#include <stdio.h>

#define MAX 8
#define INFINITO 1000000000

typedef struct {
    int n;
    const char *nomes[MAX];
    int peso[MAX][MAX];
} Grafo;

void liga(Grafo *g, int a, int b, int peso) {
    g->peso[a][b] = peso;
    g->peso[b][a] = peso;
}

void todas_as_distancias(const Grafo *g, int d[][MAX]) {
    for (int i = 0; i < g->n; i++)
        for (int j = 0; j < g->n; j++) d[i][j] = (i == j) ? 0 : (g->peso[i][j] ? g->peso[i][j] : INFINITO);
    for (int k = 0; k < g->n; k++)
        for (int i = 0; i < g->n; i++)
            for (int j = 0; j < g->n; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

int main(void) {
    Grafo campus = {.n = 6, .nomes = {"Portaria", "Biblioteca", "Lab", "Bandejão", "Ginásio", "Reitoria"}};
    liga(&campus, 0, 1, 4);
    liga(&campus, 0, 3, 7);
    liga(&campus, 1, 2, 3);
    liga(&campus, 1, 3, 2);
    liga(&campus, 3, 4, 5);
    liga(&campus, 2, 5, 6);
    liga(&campus, 4, 5, 2);
    int d[MAX][MAX];
    todas_as_distancias(&campus, d);

    int a = 0, b = 0;
    for (int i = 0; i < campus.n; i++) {
        printf("%d:", i);
        for (int j = 0; j < campus.n; j++) {
            printf("%3d", d[i][j]);
            if (d[i][j] > d[a][b]) {
                a = i;
                b = j;
            }
        }
        printf("\n");
    }
    printf("Mais longe: %s e %s, %d min\n", campus.nomes[a], campus.nomes[b], d[a][b]);
    return 0;
}

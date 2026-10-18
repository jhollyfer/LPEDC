// 0155 · Floyd-Warshall: todos os pares
// Exercício E930 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO 1000000000

const char *bairros[V] = {"Centro", "Porto", "Vila", "Alto", "Feira"};

void floyd(int d[V][V]) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

void monta(int d[V][V], int ruas[][3], int n) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    for (int r = 0; r < n; r++) d[ruas[r][0]][ruas[r][1]] = ruas[r][2];
}

// rua nova a -> b com w minutos: todo caminho novo é (i até a) + w + (b até j)
void nova_rua(int d[V][V], int a, int b, int w) {
    int da[V], db[V]; // cópias da coluna a e da linha b, antes de mexer
    for (int i = 0; i < V; i++) {
        da[i] = d[i][a];
        db[i] = d[b][i];
    }
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (da[i] + w + db[j] < d[i][j]) d[i][j] = da[i] + w + db[j];
}

int main(void) {
    int ruas[][3] = {{0, 2, 2}, {2, 1, 3}, {0, 1, 6}, {1, 3, 4},
                     {3, 0, 5}, {2, 4, 7}, {4, 3, 1}, {1, 4, 2}, {4, 2, 1}};
    int d[V][V], conferencia[V][V];
    monta(d, ruas, 8); // a cidade de antes: sem a rua 9
    floyd(d);

    nova_rua(d, 4, 2, 1); // abriu a rua Feira -> Vila, 1 minuto: O(V²)

    monta(conferencia, ruas, 9); // refaz tudo do zero, com a rua nova: O(V³)
    floyd(conferencia);

    bool igual = true;
    for (int i = 0; i < V; i++) {
        printf("%-7s", bairros[i]);
        for (int j = 0; j < V; j++) {
            printf("%4d", d[i][j]);
            if (d[i][j] != conferencia[i][j]) igual = false;
        }
        printf("\n");
    }
    printf("Confere com o Floyd completo: %s\n", igual ? "sim" : "não");
    return 0;
}

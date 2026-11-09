// A373 · De 3-SAT para clique: a construção em C

#include <stdbool.h>
#include <stdio.h>

#define M 3      // cláusulas
#define NV 3     // variáveis
#define V (3 * M) // um vértice por literal

// (x1 ou não x2 ou x3) e (não x1 ou x2 ou x3) e (x1 ou x2 ou não x3)
const int formula[M][3] = {{1, -2, 3}, {-1, 2, 3}, {1, 2, -3}};
int lit[V];   // o literal de cada vértice
int adj[V][V];

void mostra_lit(int l) {
    printf("%sx%d", l < 0 ? "não " : "", l < 0 ? -l : l);
}

int main(void) {
    // a redução: O(m²) vértices e arestas, polinomial
    for (int c = 0; c < M; c++)
        for (int i = 0; i < 3; i++) lit[3 * c + i] = formula[c][i];
    int arestas = 0;
    for (int a = 0; a < V; a++)
        for (int b = a + 1; b < V; b++) {
            bool outra_clausula = a / 3 != b / 3;
            bool compativel = lit[a] != -lit[b]; // x e não x nunca se ligam
            if (outra_clausula && compativel) adj[a][b] = adj[b][a] = 1, arestas++;
        }
    printf("Grafo: %d vértices, %d arestas\n", V, arestas);

    // clique de tamanho M: no máximo um vértice por cláusula, então basta
    // escolher um literal de cada uma (3^M escolhas)
    for (int esc = 0; esc < 27; esc++) {
        int v[M], r = esc;
        for (int c = 0; c < M; c++) v[c] = 3 * c + r % 3, r /= 3;
        bool clique = true;
        for (int i = 0; i < M; i++)
            for (int j = i + 1; j < M; j++)
                if (!adj[v[i]][v[j]]) clique = false;
        if (!clique) continue;

        printf("Clique:");
        for (int c = 0; c < M; c++) printf(" v%d(", v[c]), mostra_lit(lit[v[c]]), printf(")");
        bool valor[NV + 1] = {false}; // variável não citada fica falsa
        for (int c = 0; c < M; c++)
            if (lit[v[c]] > 0) valor[lit[v[c]]] = true;
        printf("\nAtribuição:");
        for (int x = 1; x <= NV; x++) printf(" x%d=%s", x, valor[x] ? "V" : "F");
        printf("\n");
        return 0;
    }
    printf("Sem clique de tamanho %d: fórmula insatisfatível\n", M);
    return 0;
}
// Saída:
// Grafo: 9 vértices, 21 arestas
// Clique: v0(x1) v4(x2) v6(x1)
// Atribuição: x1=V x2=V x3=F
//
// Dos 27 pares entre cláusulas diferentes, só 6 são contraditórios (x e
// não x) e ficam de fora: sobram 21 arestas. A clique escolhe um literal
// por cláusula sem contradição; tornar esses literais verdadeiros satisfaz
// as três cláusulas. A volta também vale: de uma atribuição que satisfaz,
// pegue um literal verdadeiro por cláusula e eles formam uma clique. Por
// isso "a fórmula é satisfatível" e "o grafo tem clique de tamanho m" têm
// sempre a mesma resposta.

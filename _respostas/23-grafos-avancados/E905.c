// 0151 · Ordenação topológica
// Exercício E905 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *etapas[V] = {"sistema", "aplicação", "banco", "usuário", "firewall", "certificado"};
int antes[V][V];
bool visitado[V];
int ordem[V], n = 0;

// o bug: a etapa entrava no vetor quando a chamada COMEÇAVA (pré-ordem).
// A pré-ordem não respeita as setas: sistema -> aplicação foi explorada
// antes de banco -> usuário -> aplicação.
void dfs(int u) {
    visitado[u] = true;
    for (int v = 0; v < V; v++)
        if (antes[u][v] && !visitado[v]) dfs(v);
    ordem[n++] = u; // pós-ordem: tudo que vem depois de u já entrou
}

int main(void) {
    int regras[][2] = {{0, 1}, {0, 2}, {2, 3}, {3, 1}, {0, 4}, {4, 5}, {5, 1}};
    for (int k = 0; k < 7; k++) antes[regras[k][0]][regras[k][1]] = 1;

    for (int u = 0; u < V; u++)
        if (!visitado[u]) dfs(u);

    for (int i = n - 1; i >= 0; i--) printf("%s%s", i < n - 1 ? " " : "", etapas[ordem[i]]); // de trás para frente
    printf("\n");
    return 0;
}

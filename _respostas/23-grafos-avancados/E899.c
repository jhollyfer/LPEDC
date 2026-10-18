// 0150 · Componentes e ciclos
// Exercício E899 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 7
enum { BRANCO, CINZA, PRETO };

const char *disciplinas[V] = {"Lógica", "C", "Estruturas", "Arquivos", "Grafos", "Cálculo", "Discreta"};
int antes[V][V]; // antes[a][b] = 1: a é pré-requisito de b
int cor[V];

// o bug: "visitado" não distingue quem está na pilha (cinza) de quem já
// terminou (preto). Lógica -> Estruturas chega num preto e não é ciclo.
bool dfs(int u) {
    cor[u] = CINZA;
    for (int v = 0; v < V; v++) {
        if (!antes[u][v]) continue;
        if (cor[v] == CINZA) return true; // voltou para a pilha: ciclo
        if (cor[v] == BRANCO && dfs(v)) return true;
    }
    cor[u] = PRETO;
    return false;
}

bool tem_ciclo(void) {
    for (int u = 0; u < V; u++) cor[u] = BRANCO;
    for (int u = 0; u < V; u++)
        if (cor[u] == BRANCO && dfs(u)) return true;
    return false;
}

int main(void) {
    int grade[][2] = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {0, 2}, {5, 6}, {6, 4}};
    for (int k = 0; k < 7; k++) antes[grade[k][0]][grade[k][1]] = 1;
    printf("Grade 2024: %s\n", tem_ciclo() ? "pré-requisito circular" : "sem ciclo");

    antes[4][5] = 1; // Grafos -> Cálculo
    printf("Grade 2025: %s\n", tem_ciclo() ? "pré-requisito circular" : "sem ciclo");
    return 0;
}

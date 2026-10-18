// 0116 · DFS: busca em profundidade
// Exercício E695 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define V 6

typedef enum { BRANCO, CINZA, PRETO } Cor;

const char *nomes[V] = {"app", "api", "auth", "db", "log", "utils"};
int adj[V][V];
Cor cor[V];
int pai[V];

// devolve true se achou um ciclo (e já imprimiu)
bool dfs(int u) {
    cor[u] = CINZA; // a chamada de u está aberta
    for (int v = 0; v < V; v++) {
        if (!adj[u][v]) continue;
        if (cor[v] == CINZA) { // seta para quem está na pilha: ciclo
            int ciclo[V], n = 0;
            for (int x = u; x != v; x = pai[x]) ciclo[n++] = x;
            printf("ciclo %s", nomes[v]);
            for (int i = n - 1; i >= 0; i--) printf(" -> %s", nomes[ciclo[i]]);
            printf(" -> %s\n", nomes[v]);
            return true;
        }
        if (cor[v] == BRANCO) {
            pai[v] = u;
            if (dfs(v)) return true;
        }
        // PRETO: já terminou; não é ciclo
    }
    cor[u] = PRETO;
    return false;
}

void testar(const char *rotulo) {
    for (int v = 0; v < V; v++) {
        cor[v] = BRANCO;
        pai[v] = -1;
    }
    printf("%s: ", rotulo);
    bool achou = false;
    for (int s = 0; s < V && !achou; s++)
        if (cor[s] == BRANCO) achou = dfs(s);
    if (!achou) printf("sem ciclo\n");
}

int main(void) {
    int deps[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 5}, {5, 4}, {4, 2}};
    for (int k = 0; k < 8; k++) adj[deps[k][0]][deps[k][1]] = 1;

    testar("Com log -> auth");
    adj[4][2] = 0; // remove log -> auth
    testar("Sem log -> auth");
    return 0;
}

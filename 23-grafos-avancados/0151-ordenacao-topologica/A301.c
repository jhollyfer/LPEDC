// A301 · Ordem de compilação pela DFS

#include <stdbool.h>
#include <stdio.h>

#define V 7
enum { BRANCO, CINZA, PRETO };

const char *modulos[V] = {"main", "menu", "estoque", "banco", "relatorio", "util", "log"};
int usa[V][V]; // usa[a][b] = 1: a.c faz #include "b.h" (b precisa estar pronto antes)
int cor[V];
int pos_ordem[V], n_pos; // a ordem em que as chamadas da DFS terminam

bool dfs(int u) {
    cor[u] = CINZA;
    for (int v = 0; v < V; v++) {
        if (!usa[u][v]) continue;
        if (cor[v] == CINZA) {
            printf("Include circular: %s -> %s\n", modulos[u], modulos[v]);
            return false;
        }
        if (cor[v] == BRANCO && !dfs(v)) return false;
    }
    cor[u] = PRETO;
    pos_ordem[n_pos++] = u; // u termina depois de tudo de que ele depende
    return true;
}

void ordem_de_compilacao(void) {
    for (int v = 0; v < V; v++) cor[v] = BRANCO;
    n_pos = 0;
    for (int u = 0; u < V; u++)
        if (cor[u] == BRANCO && !dfs(u)) return;
    printf("Compilar:");
    for (int i = 0; i < n_pos; i++) printf(" %s", modulos[pos_ordem[i]]);
    printf("\n");
}

int main(void) {
    int includes[][2] = {{0, 1}, {0, 4}, {1, 2}, {2, 3}, {4, 2},
                         {4, 5}, {3, 6}, {5, 6}, {2, 5}};
    for (int k = 0; k < 9; k++) usa[includes[k][0]][includes[k][1]] = 1;
    ordem_de_compilacao();

    usa[6][1] = 1; // alguém fez o log incluir o menu
    ordem_de_compilacao();
    return 0;
}
// Saída:
// Compilar: log banco util estoque menu relatorio main
// Include circular: log -> menu
//
// Aqui as setas apontam para quem precisa vir ANTES (a usa b). Por isso a
// própria pós-ordem já é a resposta. Com setas no sentido "a antes de b",
// como na obra do texto, a resposta é a pós-ordem lida de trás para frente.

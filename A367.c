// A367 · A raiz da DFS é um caso à parte

#include <stdbool.h>
#include <stdio.h>

#define V 5

// linhas de ônibus: Terminal, Bosque e Campus em triângulo; Terminal segue
// sozinho até a Vila, e a Vila até o Sítio
const char *pontos[V] = {"Terminal", "Bosque", "Campus", "Vila", "Sítio"};
int linha[V][V];
int tin[V], low[V], relogio;
bool certo[V], ingenuo[V]; // com e sem o caso especial da raiz

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    int filhos = 0;
    for (int v = 0; v < V; v++) {
        if (!linha[u][v] || v == pai) continue;
        if (tin[v] != 0) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        filhos++;
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] >= tin[u]) {
            ingenuo[u] = true;               // aplica a regra a todo mundo
            if (pai != -1) certo[u] = true;  // fora a raiz
        }
    }
    if (pai == -1 && filhos >= 2) certo[u] = true;
}

void roda(int raiz) {
    relogio = 0;
    for (int u = 0; u < V; u++) tin[u] = 0, certo[u] = ingenuo[u] = false;
    dfs(raiz, -1);
    printf("Raiz %s\n  regra certa:", pontos[raiz]);
    for (int u = 0; u < V; u++)
        if (certo[u]) printf(" %s", pontos[u]);
    printf("\n  sem caso da raiz:");
    for (int u = 0; u < V; u++)
        if (ingenuo[u]) printf(" %s", pontos[u]);
    printf("\n");
}

int main(void) {
    int trechos[][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}};
    for (int k = 0; k < 5; k++) linha[trechos[k][0]][trechos[k][1]] = linha[trechos[k][1]][trechos[k][0]] = 1;
    roda(0);
    roda(1);
    return 0;
}
// Saída:
// Raiz Terminal
//   regra certa: Terminal Vila
//   sem caso da raiz: Terminal Vila
// Raiz Bosque
//   regra certa: Terminal Vila
//   sem caso da raiz: Terminal Bosque Vila
//
// Com raiz no Terminal, ele tem dois filhos na árvore (Bosque e Vila) e é
// articulação de verdade: as duas regras concordam. Com raiz no Bosque, a
// DFS desce Bosque -> Terminal -> Campus e volta ao Bosque pelo Campus: um
// filho só. Sem o caso especial, o Bosque aparece como articulação, mas
// tire o Bosque e o resto continua ligado. A resposta certa não pode
// depender de onde a DFS começa, e com o caso especial não depende.

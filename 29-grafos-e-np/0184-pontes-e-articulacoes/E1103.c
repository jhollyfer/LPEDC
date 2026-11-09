// 0184 · Pontes e articulações
// Exercício E1103 · ★★★
//
// Ache o bug. A rede de energia do E1102 tem três linhas críticas (pontes):
// Sul-Porto, Porto-Vila e Porto-Serra. Mas o programa abaixo acusa mais
// duas, que estão dentro de triângulos e têm caminho alternativo:
//
//   Saída que aparece:
//   Linha crítica: Porto - Vila
//   Linha crítica: Porto - Serra
//   Linha crítica: Sul - Porto
//   Linha crítica: Norte - Leste
//   Linha crítica: Usina - Norte
//
//   Saída esperada:
//   Linha crítica: Porto - Vila
//   Linha crítica: Porto - Serra
//   Linha crítica: Sul - Porto
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte-o.
//
// Dicas:
// 1. Mostre tin e low de Norte e Leste. Leste e Oeste formam triângulo com
//    o Norte: o Oeste volta ao Norte, e low[Leste] fica igual a tin[Norte].
// 2. "Voltar ao próprio u" basta para u - v não ser ponte: existe outro
//    caminho entre u e v. A regra com igualdade é a da articulação.
// 3. Resposta esperada: a saída esperada acima. Troque um >= por >.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define V 8

const char *subestacoes[V] = {"Usina", "Norte", "Sul", "Leste", "Oeste", "Porto", "Vila", "Serra"};
int linha[V][V];
int tin[V], low[V], relogio = 0;

void dfs(int u, int pai) {
    tin[u] = low[u] = ++relogio;
    for (int v = 0; v < V; v++) {
        if (!linha[u][v] || v == pai) continue;
        if (tin[v] != 0) {
            if (tin[v] < low[u]) low[u] = tin[v];
            continue;
        }
        dfs(v, u);
        if (low[v] < low[u]) low[u] = low[v];
        if (low[v] >= tin[u]) printf("Linha crítica: %s - %s\n", subestacoes[u], subestacoes[v]);
    }
}

int main(void) {
    int linhas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {3, 4}, {2, 5}, {5, 6}, {5, 7}};
    for (int k = 0; k < 9; k++) linha[linhas[k][0]][linhas[k][1]] = linha[linhas[k][1]][linhas[k][0]] = 1;
    dfs(0, -1);
    return 0;
}

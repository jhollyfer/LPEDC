// 0151 · Ordenação topológica
// Exercício E904 · ★★☆

#include <stdio.h>

#define V 8

int main(void) {
    const char *tarefas[V] = {"Elétrica", "Fundação", "Hidráulica", "Paredes",
                              "Piso", "Pintura", "Reboco", "Telhado"};
    int dias[V] = {5, 10, 6, 15, 4, 6, 8, 7};
    int antes[V][V] = {0};
    int regras[][2] = {{1, 3}, {3, 7}, {3, 0}, {3, 2}, {7, 6},
                       {0, 6}, {2, 6}, {2, 4}, {6, 5}, {4, 5}};
    for (int k = 0; k < 10; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int grau[V] = {0};
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];

    int fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++)
        if (grau[v] == 0) fila[fim++] = v;

    int comeca[V] = {0}, quem[V]; // dia de início e quem segurou a tarefa
    for (int v = 0; v < V; v++) quem[v] = -1;

    int ultima = -1, total = 0;
    while (inicio < fim) {
        int u = fila[inicio++];
        int termina = comeca[u] + dias[u];
        printf("%s: dia %d ao %d\n", tarefas[u], comeca[u], termina);
        if (termina > total) {
            total = termina;
            ultima = u;
        }
        for (int v = 0; v < V; v++) {
            if (!antes[u][v]) continue;
            if (termina > comeca[v]) { // v só começa quando o último anterior termina
                comeca[v] = termina;
                quem[v] = u;
            }
            if (--grau[v] == 0) fila[fim++] = v;
        }
    }
    printf("Obra pronta em %d dias\n", total);

    int caminho[V], n = 0;
    for (int v = ultima; v != -1; v = quem[v]) caminho[n++] = v;
    printf("Caminho crítico:");
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", tarefas[caminho[i]], i > 0 ? " ->" : "");
    printf("\n");
    return 0;
}

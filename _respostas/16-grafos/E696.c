// 0116 · DFS: busca em profundidade
// Exercício E696 · ★★★
//
// Resposta: (1) o true devolvido pela chamada recursiva era descartado, e a
// função sempre caía no "return false" do fim; o certo é propagar:
// "if (existe_caminho(v, destino)) return true;". (2) visitado[] é global e
// não era zerado: a segunda pergunta começava com as salas 1 e 2 marcadas
// e não conseguia passar por elas. Zerar antes de cada consulta resolve.

#include <stdbool.h>
#include <stdio.h>

#define V 5

int porta[V][V] = {
    {0, 1, 0, 1, 0}, // 0 -> 1, 0 -> 3
    {0, 0, 1, 0, 0}, // 1 -> 2
    {0, 0, 0, 0, 1}, // 2 -> 4
    {0, 1, 0, 0, 0}, // 3 -> 1
    {0, 0, 0, 0, 0}, // da 4 não sai nada
};
bool visitado[V];

bool existe_caminho(int u, int destino) {
    if (u == destino) return true;
    visitado[u] = true;
    for (int v = 0; v < V; v++)
        if (porta[u][v] && !visitado[v])
            if (existe_caminho(v, destino)) return true; // conserto 1
    return false;
}

int main(void) {
    int perguntas[][2] = {{0, 4}, {3, 4}, {4, 0}};
    for (int k = 0; k < 3; k++) {
        int de = perguntas[k][0], para = perguntas[k][1];
        for (int v = 0; v < V; v++) visitado[v] = false; // conserto 2
        printf("Sala %d -> Sala %d: %s\n", de, para, existe_caminho(de, para) ? "sim" : "não");
    }
    return 0;
}

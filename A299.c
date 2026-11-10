// A299 · O laço de cabos na rede do escritório

#include <stdbool.h>
#include <stdio.h>

#define V 7

// grafo NÃO dirigido: cabo de rede entre os switches de cada sala
const char *salas[V] = {"TI", "Recepcao", "RH", "Financeiro", "Diretoria", "Deposito", "Copa"};
int cabo[V][V];
bool visitado[V];
int pai[V];       // de onde a DFS chegou em cada sala
bool laco = false;

void explora(int u) {
    visitado[u] = true;
    for (int v = 0; v < V; v++) {
        if (!cabo[u][v] || v == pai[u]) continue; // o cabo por onde cheguei não conta
        if (!visitado[v]) {
            pai[v] = u;
            explora(v);
        } else if (!laco) { // vizinho já visto que não é o pai: fecha um laço
            laco = true;
            printf("Laço de cabos: %s", salas[v]);
            for (int w = u; w != v; w = pai[w]) printf(" - %s", salas[w]);
            printf(" - %s\n", salas[v]);
        }
    }
}

int main(void) {
    int cabos[][2] = {{0, 1}, {0, 2}, {2, 3}, {3, 4}, {4, 2}, {5, 6}};
    for (int k = 0; k < 6; k++) {
        cabo[cabos[k][0]][cabos[k][1]] = 1;
        cabo[cabos[k][1]][cabos[k][0]] = 1; // mão dupla
    }

    int redes = 0;
    for (int u = 0; u < V; u++) {
        if (visitado[u]) continue;
        redes++; // cada recomeço é uma rede separada
        pai[u] = -1;
        explora(u);
    }
    printf("Redes separadas: %d\n", redes);
    printf("%s\n", laco ? "Desligue um cabo do laço" : "Rede sem laços");
    return 0;
}
// Saída:
// Laço de cabos: RH - Diretoria - Financeiro - RH
// Redes separadas: 2
// Desligue um cabo do laço
//
// Um laço de cabos entre switches faz os pacotes de broadcast girarem sem
// parar e derruba a rede. Por isso o teste ignora só o PAI: num grafo não
// dirigido, o cabo de volta para quem chamou sempre aparece.

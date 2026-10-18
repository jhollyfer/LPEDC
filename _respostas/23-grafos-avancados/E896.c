// 0150 · Componentes e ciclos
// Exercício E896 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6
enum { BRANCO, CINZA, PRETO };

const char *pacotes[V] = {"app", "rede", "json", "log", "cripto", "util"};
int depende[V][V]; // depende[a][b] = 1: a precisa de b instalado antes
int cor[V];

bool visita(int u) {
    cor[u] = CINZA;
    for (int v = 0; v < V; v++) {
        if (!depende[u][v]) continue;
        if (cor[v] == CINZA) return true;
        if (cor[v] == BRANCO && visita(v)) return true;
    }
    cor[u] = PRETO;
    return false;
}

bool tem_ciclo(void) {
    for (int u = 0; u < V; u++) cor[u] = BRANCO;
    for (int u = 0; u < V; u++)
        if (cor[u] == BRANCO && visita(u)) return true;
    return false;
}

int main(void) {
    int versao1[][2] = {{0, 1}, {0, 2}, {1, 4}, {1, 3}, {2, 5}, {3, 5}, {4, 5}};
    for (int k = 0; k < 7; k++) depende[versao1[k][0]][versao1[k][1]] = 1;
    printf("Versão 1: %s\n", tem_ciclo() ? "dependência circular" : "pode instalar");

    depende[5][1] = 1; // a versão 2 fez o util depender da rede
    printf("Versão 2: %s\n", tem_ciclo() ? "dependência circular" : "pode instalar");
    return 0;
}

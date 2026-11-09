// Lista · Módulo 16 · Grafos
// Exercício P1619 · ★★☆ · Instrumente: a BFS na matriz e na lista
//
// A BFS custa O(V²) com matriz e O(V + E) com lista de adjacência. Confira
// isso contando operações. O esqueleto tem uma BFS na matriz. Faça três
// coisas:
//
// 1. Acrescente um contador global consultas que soma 1 a cada vez que a BFS
// OLHA uma posição adj[u][v] da matriz.
// 2. Escreva bfs_lista(), a mesma BFS sobre uma lista de adjacência com
// malloc, contando 1 a cada nó de lista visitado.
// 3. Rode as duas num "grafo caminho" (a linha de ônibus que vai parando:
// 0-1, 1-2, ..., (n-2)-(n-1)) com n = 10, 100 e 1000, conferindo que as
// duas BFS dão o mesmo d[n - 1].
//
//   Saída esperada:
//   n =   10: matriz d =   9,     100 consultas | lista d =   9,   18 consultas
//   n =  100: matriz d =  99,   10000 consultas | lista d =  99,  198 consultas
//   n = 1000: matriz d = 999, 1000000 consultas | lista d = 999, 1998 consultas
//
// Dicas:
// 1. Na matriz, cada vértice que sai da fila varre a linha inteira: V
//    consultas por vértice, V² no total, tenha o grafo muitas arestas ou não.
// 2. Na lista, cada vértice percorre só os seus vizinhos: a soma dos graus,
//    que é 2E. No grafo caminho, E = n - 1.
// 3. A matriz de 1000 × 1000 pode ser global e de char (1 MB); a lista cabe
//    em 2E nós. Libere a lista no fim de cada rodada.
// 4. Resposta esperada: com n = 1000, a matriz faz 1000000 consultas e a
//    lista 1998, e as duas dão d = 999.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

unsigned char adj[MAX][MAX];

int bfs_matriz(int n, int s, int t) {
    static int d[MAX], fila[MAX];
    int ini = 0, fim = 0;
    for (int v = 0; v < n; v++) d[v] = -1;
    d[s] = 0;
    fila[fim++] = s;
    while (ini < fim) {
        int u = fila[ini++];
        for (int v = 0; v < n; v++)
            if (adj[u][v] && d[v] == -1) {
                d[v] = d[u] + 1;
                fila[fim++] = v;
            }
    }
    return d[t];
}

int main(void) {
    int tamanhos[] = {10, 100, 1000};
    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) adj[i][j] = 0;
        for (int i = 0; i + 1 < n; i++) adj[i][i + 1] = adj[i + 1][i] = 1;
        printf("n = %d: d = %d\n", n, bfs_matriz(n, 0, n - 1));
    }
    return 0;
}

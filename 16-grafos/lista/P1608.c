// Lista · Módulo 16 · Grafos
// Exercício P1608 · ★☆☆ · Conserte a BFS das trilhas do bosque
//
// Conserte o programa. Ele deveria mostrar a quantos trechos de trilha cada
// ponto do bosque fica da Entrada (grafo não dirigido) e por onde se chega,
// mas o colega deixou DOIS erros de propósito. Não há erro de memória: o
// programa roda até o fim, só que as distâncias e os predecessores saem
// errados.
//
//   Saída que aparece:
//   Entrada    d=0  pi=NIL
//   Lago       d=1  pi=Lago
//   Viveiro    d=1  pi=Viveiro
//   Mirante    d=2  pi=Mirante
//   Orquidario d=2  pi=Orquidario
//   Torre      d=3  pi=Torre
//   Cafe       d=3  pi=Cafe
//
//   Saída esperada:
//   Entrada    d=0  pi=NIL
//   Lago       d=1  pi=Entrada
//   Viveiro    d=1  pi=Entrada
//   Mirante    d=2  pi=Lago
//   Orquidario d=2  pi=Viveiro
//   Torre      d=3  pi=Mirante
//   Cafe       d=2  pi=Lago
//
// Dicas:
// 1. Uma fila tira do COMEÇO (ini++) e põe no FIM (fim++). Tirar do fim
//    transforma a fila em pilha, e a "BFS" deixa de andar por camadas.
// 2. O predecessor de v é quem o descobriu: o u que acabou de sair da fila.
// 3. Confira à mão: Lago e Viveiro são vizinhos da Entrada, então têm d = 1.
// 4. Resposta esperada: a segunda saída acima; a Torre fica a 3 trechos, pelo
//    Mirante.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 7

const char *nomes[V] = {"Entrada", "Lago", "Viveiro", "Mirante", "Orquidario", "Torre", "Cafe"};
int adj[V][V] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
};

int main(void) {
    int d[V], pi[V], fila[V], ini = 0, fim = 0;
    for (int v = 0; v < V; v++) d[v] = pi[v] = -1;
    d[0] = 0;
    fila[fim++] = 0;
    while (ini < fim) {
        int u = fila[--fim];
        for (int v = 0; v < V; v++)
            if (adj[u][v] && d[v] == -1) {
                d[v] = d[u] + 1;
                pi[v] = v;
                fila[fim++] = v;
            }
    }
    for (int v = 0; v < V; v++)
        printf("%-10s d=%d  pi=%s\n", nomes[v], d[v], pi[v] == -1 ? "NIL" : nomes[pi[v]]);
    return 0;
}

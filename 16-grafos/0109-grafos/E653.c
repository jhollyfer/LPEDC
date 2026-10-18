// 0109 · Grafos
// Exercício E653 · ★★★
//
// Pegue a matriz das ciclovias do exemplo A217 (já está no esqueleto) e
// converta para LISTA de adjacência alocada com malloc: um vetor de 5
// ponteiros, cada um apontando para a lista encadeada dos vizinhos daquele
// ponto. Regras:
//
// - os vizinhos de cada lista aparecem em ordem crescente de índice;
// - cada nó custa O(1) para inserir (nada de percorrer a lista até o fim);
// - conte quantos nós foram alocados;
// - libere tudo no final (o rodar não pode acusar vazamento).
//
//   Saída esperada:
//   Centro  -> Praia Feira
//   Praia   -> Centro Feira
//   Feira   -> Centro Praia Parque
//   Parque  -> Feira Estadio
//   Estadio -> Parque
//   Nós alocados: 10
//
// Dicas:
// 1. typedef struct No { int destino; struct No *prox; } No; e
//    No *lista[V] = {NULL};
// 2. Inserir no início é O(1), mas inverte a ordem. Truque: percorra as
//    colunas de trás para frente (j de V-1 até 0); a última inserida, a menor,
//    fica na frente.
// 3. Para liberar, guarde p->prox numa variável antes do free(p).
// 4. Resposta esperada: a saída acima; 10 nós porque são 5 arestas, cada uma
//    guardada nos dois sentidos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 5

const char *nomes[V] = {"Centro", "Praia", "Feira", "Parque", "Estadio"};
int adj[V][V] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0},
};

int main(void) {

    return 0;
}

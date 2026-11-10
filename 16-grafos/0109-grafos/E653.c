// 0109 · Grafos
// Exercício E653 · ★★★
//
// Converta a matriz das ciclovias (no esqueleto) para uma LISTA de adjacência
// com malloc: um vetor de 5 ponteiros, cada um para a lista encadeada dos
// vizinhos do ponto. Regras: os vizinhos de cada lista saem em ordem crescente
// de índice; inserir um nó custa O(1) (sem percorrer a lista até o fim); conte
// os nós alocados; libere tudo no final, sem vazamento.
//
//   Saída esperada:
//   Centro  -> Praia Feira
//   Praia   -> Centro Feira
//   Feira   -> Centro Praia Parque
//   Parque  -> Feira Estadio
//   Estadio -> Parque
//   Nós alocados: 10
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

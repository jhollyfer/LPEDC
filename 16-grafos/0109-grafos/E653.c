// 0109 · Grafos
// Exercício E653 · ★★★
//
// Pegue a matriz das ciclovias do texto do assunto (já está no esqueleto) e
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

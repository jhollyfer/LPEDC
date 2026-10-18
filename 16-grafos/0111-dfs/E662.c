// 0111 · DFS: busca em profundidade
// Exercício E662 · ★☆☆
//
// No centro da cidade todas as ruas são de mão única (grafo DIRIGIDO). As
// ligações diretas são:
//
//   Casa -> Mercado, Mercado -> Escola, Escola -> Casa,
//   Escola -> Praça, Hospital -> Mercado
//
// Com os índices Casa 0, Mercado 1, Escola 2, Hospital 3 e Praça 4, escreva
// uma DFS recursiva que lista todos os lugares alcançáveis a partir de uma
// origem, na ordem da visita. Rode para a Casa e para o Hospital (zere o
// visitado entre uma busca e outra) e diga se a Casa alcança o Hospital.
//
//   Saída esperada:
//   De Casa: Casa Mercado Escola Praça
//   De Hospital: Hospital Mercado Escola Casa Praça
//   Casa chega no Hospital? não
//
// Dicas:
// 1. Em grafo dirigido, adj[u][v] = 1 só no sentido da seta.
// 2. A função é a mesma do texto, sem o recuo. Para zerar entre as buscas,
//    um laço com visitado[v] = false.
// 3. Resposta esperada: a saída acima. O Hospital alcança todo mundo, mas
//    ninguém chega nele: nenhuma seta entra no Hospital.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

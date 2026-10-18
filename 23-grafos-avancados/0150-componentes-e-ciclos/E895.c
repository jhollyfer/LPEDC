// 0150 · Componentes e ciclos
// Exercício E895 · ★☆☆
//
// Um arquipélago tem sete ilhas: Norte, Sul, Leste, Oeste, Coral, Farol e
// Gaivota (índices 0 a 6). As pontes, todas de mão dupla, são:
//
//   Norte-Farol, Farol-Coral, Sul-Leste, Oeste-Sul
//
// Escreva o programa do zero: monte a matriz de adjacência, descubra os
// grupos de ilhas ligadas por ponte (os componentes) com uma DFS e um laço
// externo, mostre cada grupo e quantas pontes novas, no mínimo, ligariam o
// arquipélago inteiro.
//
//   Saída esperada:
//   Grupos de ilhas: 3
//     grupo 1: Norte Coral Farol
//     grupo 2: Sul Leste Oeste
//     grupo 3: Gaivota
//   Pontes novas para ligar tudo: 2
//
// Dicas:
// 1. Use um vetor grupo[V] zerado: 0 quer dizer "sem grupo ainda". A DFS
//    marca(u, g) põe g em u e chama a si mesma nos vizinhos com grupo 0.
// 2. O laço externo chama marca(u, ++grupos) para cada ilha ainda sem
//    grupo. Para listar o grupo g, percorra as ilhas em ordem de índice.
// 3. Resposta esperada: a saída acima. Com g grupos, g - 1 pontes bastam:
//    cada ponte nova entre grupos diferentes junta dois deles.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

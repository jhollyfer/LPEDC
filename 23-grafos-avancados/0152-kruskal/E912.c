// 0152 · Kruskal: árvore geradora mínima
// Exercício E912 · ★★★
//
// Uma ciclista quer ir de Casa até a Escola. Ela não se importa com a
// distância: quer a rota cuja PIOR subida seja a menor possível. O
// desnível de cada rua (mão dupla), em metros:
//
//   Casa-Morro 30, Morro-Escola 25, Casa-Praça 8, Praça-Feira 12,
//   Praça-Igreja 15, Igreja-Escola 18, Feira-Parque 10, Parque-Escola 14,
//   Feira-Igreja 9, Casa-Igreja 20
//
// Existe um fato bonito: na árvore geradora mínima, o caminho entre dois
// vértices é justamente o que minimiza a maior aresta. Escreva o programa:
// monte a MST com Kruskal, guarde as arestas dela numa matriz, ache o
// caminho de Casa até a Escola na árvore com uma DFS (com anterior[]) e
// mostre a rota e a maior subida dela.
//
//   Saída esperada:
//   Rota: Casa -> Praça -> Feira -> Parque -> Escola
//   Maior subida: 14 m
//
// Dicas:
// 1. Ao aceitar uma aresta no Kruskal, grave
//    arvore[a][b] = arvore[b][a] = subida. Depois, a DFS só anda por
//    arvore[u][v] != 0.
// 2. Numa árvore só existe um caminho entre dois vértices: a DFS a partir
//    de Casa preenche anterior[], e a rota sai seguindo anterior[] a partir
//    da Escola. Pegue o máximo das arestas no caminho.
// 3. Resposta esperada: a saída acima. Pela Igreja direto, a pior subida
//    seria 20; por Praça, Igreja, Escola, 18. Pelo Morro, 30.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 7
#define E 10

typedef struct {
    int a, b, subida; // desnível da rua, em metros
} Rua;

const char *lugares[V] = {"Casa", "Praça", "Igreja", "Feira", "Morro", "Parque", "Escola"};

int main(void) {
    Rua ruas[E] = {{0, 4, 30}, {4, 6, 25}, {0, 1, 8}, {1, 3, 12}, {1, 2, 15},
                   {2, 6, 18}, {3, 5, 10}, {5, 6, 14}, {3, 2, 9}, {0, 2, 20}};
    (void)ruas; // apague esta linha

    return 0;
}

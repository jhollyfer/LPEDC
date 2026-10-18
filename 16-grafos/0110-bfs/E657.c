// 0110 · BFS: busca em largura
// Exercício E657 · ★★☆
//
// Mesmo mapa de ônibus do E655 (já está no esqueleto). Você mora na Lapa e
// precisa ir à Saude pegando o menor número de ônibus. Rode uma BFS a partir
// da Lapa guardando pai[] e escreva uma função RECURSIVA que imprime o
// caminho na ordem certa, da origem ao destino:
//
//   void imprimir_caminho(const int pai[], int v);
//
//   Saída esperada:
//   Lapa -> Centro -> Moema -> Saude
//   Ônibus: 3
//
// Existe outro caminho com 3 ônibus (Lapa, Penha, Tatuape, Saude). Explique,
// num comentário, por que a sua BFS escolheu o que passa pelo Centro.
//
// Dicas:
// 1. pai[origem] = -1. Na função: se pai[v] != -1, imprima primeiro o
//    caminho até pai[v] (chamada recursiva) e depois " -> " e o nome de v.
// 2. A recursão desfaz a inversão: o pai é impresso antes do filho, igual a
//    uma pilha (assunto 0084).
// 3. Resposta esperada: a saída acima. O Centro (índice 0) é examinado antes
//    da Penha (3) como vizinho da Lapa; por isso Moema é descoberta pelo
//    Centro, e a Saude por Moema, antes que o ramo da Penha chegue lá.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Centro", "Lapa", "Moema", "Penha", "Saude", "Tatuape"};
int adj[V][V] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0},
};

int main(void) {

    return 0;
}

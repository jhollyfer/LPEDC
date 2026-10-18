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
// Existe outro caminho com 3 ônibus (Lapa, Penha, Tatuape, Saude). Para ver
// quem decide o empate, rode a BFS uma segunda vez examinando os vizinhos
// de trás para frente (v de V-1 até 0) e mostre o caminho que ela acha.
//
//   Saída esperada:
//   Lapa -> Centro -> Moema -> Saude
//   Ônibus: 3
//   Ao contrário: Lapa -> Penha -> Tatuape -> Saude
//   Ônibus: 3
//
// Dicas:
// 1. pai[origem] = -1. Na função: se pai[v] != -1, imprima primeiro o
//    caminho até pai[v] (chamada recursiva) e depois " -> " e o nome de v.
// 2. A recursão desfaz a inversão: o pai é impresso antes do filho, igual a
//    uma pilha (assunto 0084).
// 3. Para não escrever a BFS duas vezes, ponha-a numa função com um
//    parâmetro bool crescente e use v = crescente ? k : V - 1 - k.
// 4. Resposta esperada: a saída acima. Os dois caminhos são mínimos; quem
//    entra primeiro na fila descobre os vizinhos primeiro.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
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

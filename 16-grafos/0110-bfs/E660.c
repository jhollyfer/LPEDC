// 0110 · BFS: busca em largura
// Exercício E660 · ★★★
//
// Este programa tem um erro de propósito. Ele deveria mostrar a ordem em que
// uma corrente de WhatsApp chega em cada pessoa, a partir da Ana. Rode com o
// rodar: o AddressSanitizer acusa um estouro do vetor fila. Responda num
// comentário: por que a fila de V posições, que deveria bastar, estourou?
// Quem entrou nela duas vezes? Depois conserte mexendo no MOMENTO em que o
// vértice é marcado.
//
//   Saída esperada depois do conserto:
//   Ana Bia Cadu Dani
//
// Dicas:
// 1. Simule a fila no papel. Quando Bia sai, Dani entra. Quando Cadu sai,
//    Dani já foi marcada?
// 2. A marcação só acontece quando o vértice SAI da fila. Entre entrar e
//    sair, ele pode ser colocado de novo por outro vizinho.
// 3. Resposta esperada: Dani entra duas vezes (por Bia e por Cadu), então a
//    fila precisaria de 5 posições e tem 4. O conserto é marcar visitado[v]
//    no momento em que v entra na fila (e marcar a origem antes do laço).
//    Assim cada pessoa entra uma vez só e a saída é "Ana Bia Cadu Dani".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 4

int main(void) {
    const char *nomes[V] = {"Ana", "Bia", "Cadu", "Dani"};
    int adj[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
    };
    bool visitado[V] = {false};
    int fila[V], inicio = 0, fim = 0;

    fila[fim++] = 0;
    while (inicio < fim) {
        int u = fila[inicio++];
        visitado[u] = true;
        printf("%s ", nomes[u]);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visitado[v]) fila[fim++] = v;
        }
    }
    printf("\n");
    return 0;
}

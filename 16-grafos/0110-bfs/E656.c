// 0110 · BFS: busca em largura
// Exercício E656 · ★☆☆
//
// A Vó mandou um áudio no grupo da família, e cada pessoa só encaminha para
// quem tem contato direto (grafo não dirigido). Em que "rodada" o áudio chega
// em cada um? Rodada 0 é a própria Vó, rodada 1 são os contatos dela, e assim
// por diante: é a distância da BFS.
//
// O programa está quase pronto. Falta o miolo da BFS, no lugar marcado com
// "COMPLETE AQUI": anotar a rodada do vizinho e colocá-lo na fila. Hoje ele
// compila, mas só mostra a Vó.
//
//   Saída esperada:
//   Vó: rodada 0
//   Tia: rodada 1
//   Pai: rodada 1
//   Primo: rodada 2
//   Mãe: rodada 2
//   Eu: rodada 3
//   Rodadas até todos ouvirem: 3
//
// Dicas:
// 1. São duas linhas: rodada[v] = rodada[u] + 1; e fila[fim++] = v;
// 2. Por que dá para marcar a rodada já aqui, antes de o vizinho sair da
//    fila? Porque é isso que impede que ele entre duas vezes.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define V 6

int main(void) {
    const char *nomes[V] = {"Vó", "Tia", "Pai", "Mãe", "Primo", "Eu"};
    int adj[V][V] = {0};
    int contatos[][2] = {{0, 1}, {0, 2}, {1, 4}, {2, 3}, {3, 5}, {4, 5}};
    for (int k = 0; k < 6; k++) {
        adj[contatos[k][0]][contatos[k][1]] = 1;
        adj[contatos[k][1]][contatos[k][0]] = 1;
    }

    int rodada[V], fila[V], inicio = 0, fim = 0, maior = 0;
    for (int v = 0; v < V; v++) rodada[v] = -1;
    rodada[0] = 0;
    fila[fim++] = 0;

    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%s: rodada %d\n", nomes[u], rodada[u]);
        if (rodada[u] > maior) maior = rodada[u];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && rodada[v] == -1) {
                // COMPLETE AQUI
            }
        }
    }
    printf("Rodadas até todos ouvirem: %d\n", maior);
    return 0;
}

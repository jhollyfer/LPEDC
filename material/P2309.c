// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2309 · ★☆☆ · Floyd-Warshall quadro a quadro
//
// Os tempos de ônibus (minutos, mão única) entre quatro bairros:
//
//   Centro -> Adrianópolis 10, Adrianópolis -> Ponta Negra 25,
//   Centro -> Ponta Negra 40, Ponta Negra -> Cidade Nova 15,
//   Cidade Nova -> Centro 20, Adrianópolis -> Cidade Nova 30
//
// Complete floyd(d): o Floyd-Warshall com o k no laço de fora e, depois de
// cada k, a linha "Depois de k = SIGLA:" e a matriz (a função mostra está
// pronta). É assim que a prova cobra: a matriz D(k) de cada rodada.
//
//   Saída esperada:
//   Início:
//          CEN  ADR  PNE  CNO
//   CEN      0   10   40    -
//   ADR      -    0   25   30
//   PNE      -    -    0   15
//   CNO     20    -    -    0
//   Depois de k = CEN:
//          CEN  ADR  PNE  CNO
//   CEN      0   10   40    -
//   ADR      -    0   25   30
//   PNE      -    -    0   15
//   CNO     20   30   60    0
//   Depois de k = ADR:
//          CEN  ADR  PNE  CNO
//   CEN      0   10   35   40
//   ADR      -    0   25   30
//   PNE      -    -    0   15
//   CNO     20   30   55    0
//   Depois de k = PNE:
//          CEN  ADR  PNE  CNO
//   CEN      0   10   35   40
//   ADR      -    0   25   30
//   PNE      -    -    0   15
//   CNO     20   30   55    0
//   Depois de k = CNO:
//          CEN  ADR  PNE  CNO
//   CEN      0   10   35   40
//   ADR     50    0   25   30
//   PNE     35   45    0   15
//   CNO     20   30   55    0
//
// Dicas:
// 1. INF vale 1000000: a soma de dois INF ainda cabe num int, então dá
//    para comparar d[i][k] + d[k][j] < d[i][j] direto.
// 2. Na rodada k só mudam casas cujo melhor caminho passa por k, e nunca a
//    linha k nem a coluna k.
// 3. Resposta esperada: k = PNE não muda nada; na rodada CNO, Ponta Negra
//    chega no Centro em 35 (15 + 20).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 4
#define INF 1000000

const char *siglas[V] = {"CEN", "ADR", "PNE", "CNO"};

void mostra(int d[V][V]) {
    printf("     ");
    for (int j = 0; j < V; j++) printf(" %4s", siglas[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%-5s", siglas[i]);
        for (int j = 0; j < V; j++) {
            if (d[i][j] >= INF) printf("    -");
            else printf(" %4d", d[i][j]);
        }
        printf("\n");
    }
}

void floyd(int d[V][V]) {
    (void)d; // apague esta linha e escreva o algoritmo

}

int main(void) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = i == j ? 0 : INF;
    int ruas[][3] = {{0, 1, 10}, {1, 2, 25}, {0, 2, 40}, {2, 3, 15}, {3, 0, 20}, {1, 3, 30}};
    for (int k = 0; k < 6; k++) d[ruas[k][0]][ruas[k][1]] = ruas[k][2];

    printf("Início:\n");
    mostra(d);
    floyd(d);
    return 0;
}

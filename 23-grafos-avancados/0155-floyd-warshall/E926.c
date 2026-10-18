// 0155 · Floyd-Warshall: todos os pares
// Exercício E926 · ★☆☆
//
// O malote interno de uma empresa leva dias entre as filiais (mão única).
// A filial de Recife ainda não entrou na rota de malotes. Complete a função
// floyd(d). Aqui o INFINITO é INT_MAX, então a soma d[i][k] + d[k][j] só
// pode ser feita depois de conferir que nenhum dos dois é INFINITO. O main
// já imprime "-" onde não há caminho.
//
//   Saída esperada:
//          SP  RJ  BH POA REC
//   SP      0   1   3   3   -
//   RJ      4   0   2   6   -
//   BH      2   3   0   4   -
//   POA     4   5   7   0   -
//   REC     -   -   -   -   0
//
// Dicas:
// 1. A condição completa do miolo é: d[i][k] != INFINITO e
//    d[k][j] != INFINITO e d[i][k] + d[k][j] < d[i][j].
// 2. Por causa do curto-circuito do && (assunto 0013), a soma nem chega a
//    ser calculada quando um dos lados é INFINITO.
// 3. Resposta esperada: a saída acima. Sem os testes, INT_MAX + 1 estoura
//    e o sanitizer acusa "signed integer overflow".
//
// Escreva sua resposta abaixo (complete floyd):

#include <limits.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX

const char *filiais[V] = {"SP", "RJ", "BH", "POA", "REC"};

void floyd(int d[V][V]) {
    (void)d; // apague esta linha
}

int main(void) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    int malotes[][3] = {{0, 1, 1}, {1, 2, 2}, {2, 0, 2}, {0, 3, 3}, {3, 0, 4}, {2, 3, 4}};
    for (int m = 0; m < 6; m++) d[malotes[m][0]][malotes[m][1]] = malotes[m][2];

    floyd(d);

    printf("     ");
    for (int j = 0; j < V; j++) printf("%4s", filiais[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%-5s", filiais[i]);
        for (int j = 0; j < V; j++) {
            if (d[i][j] == INFINITO) printf("%4s", "-");
            else printf("%4d", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}

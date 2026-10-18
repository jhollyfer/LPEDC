// 0114 · Grafos
// Exercício E680 · ★☆☆
//
// Depois do churrasco, a turma anotou quem ficou devendo Pix para quem num
// grafo DIRIGIDO: deve[i][j] == 1 quer dizer que i deve para j. Sem rodar,
// preveja o que o programa abaixo mostra. Só depois rode e confira.
//
// Dicas:
// 1. Somar a LINHA i conta as setas que saem de i: para quantos i deve.
// 2. Somar a COLUNA i conta as setas que chegam em i: de quantos i recebe.
// 3. Resposta esperada:
//    Leo deve para 2 e recebe de 1
//    Mia deve para 1 e recebe de 2
//    Rui deve para 0 e recebe de 3
//    Sol deve para 3 e recebe de 0
//    Sem dívidas: Rui
//
// Escreva sua resposta abaixo (a saída prevista, como comentário):

#include <stdio.h>

#define V 4

int main(void) {
    const char *nomes[V] = {"Leo", "Mia", "Rui", "Sol"};
    int deve[V][V] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0},
    };

    for (int i = 0; i < V; i++) {
        int saida = 0, entrada = 0;
        for (int j = 0; j < V; j++) {
            saida += deve[i][j];
            entrada += deve[j][i];
        }
        printf("%s deve para %d e recebe de %d\n", nomes[i], saida, entrada);
    }

    printf("Sem dívidas:");
    for (int i = 0; i < V; i++) {
        int saida = 0;
        for (int j = 0; j < V; j++) saida += deve[i][j];
        if (saida == 0) printf(" %s", nomes[i]);
    }
    printf("\n");
    return 0;
}

// 0155 · Floyd-Warshall: todos os pares
// Exercício E929 · ★★★
//
// Ache o bug. Este programa monta a tabela de tempos (minutos) entre cinco
// pontos ligados por ciclovias de mão única. Ele compila, roda, não dá erro
// nenhum, e a tabela está errada: diz que do Parque não se chega na Escola,
// mas Parque -> Estação -> Museu -> Escola existe (2 + 1 + 4 = 7).
//
//   Saída que aparece:
//   0.    0   5  15   2   7   (Escola)
//   1.    -   0   3   -   2   (Parque)
//   2.    4   9   0   6  11   (Museu)
//   3.    -   3   6   0   5   (Praça)
//   4.    5  10   1   7   0   (Estação)
//
//   Saída esperada:
//   0.    0   5   8   2   7   (Escola)
//   1.    7   0   3   9   2   (Parque)
//   2.    4   9   0   6  11   (Museu)
//   3.   10   3   6   0   5   (Praça)
//   4.    5  10   1   7   0   (Estação)
//
// Ache o erro, conserte e confira.
//
// Dicas:
// 1. Quando o programa calcula d[1][0] (Parque -> Escola), quais casas ele
//    usa? d[1][4] + d[4][0] (Estação -> Escola) já está pronta nessa hora?
// 2. Cada par (i, j) só é examinado uma vez, numa passada pelos k. Se o
//    pedaço d[k][j] ainda vai melhorar depois, o par (i, j) não fica
//    sabendo. A ordem dos laços é a ideia do algoritmo, não um detalhe.
// 3. Resposta esperada: o k precisa ser o laço de FORA (for k, for i, for
//    j). Consertado, mostra a saída esperada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define V 5
#define INFINITO 1000000000

int main(void) {
    const char *pontos[V] = {"Escola", "Parque", "Museu", "Praça", "Estação"};
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO;
    int ciclovias[][3] = {{0, 3, 2}, {3, 1, 3}, {1, 4, 2}, {4, 2, 1}, {0, 2, 15}, {2, 0, 4}, {0, 1, 9}};
    for (int c = 0; c < 7; c++) d[ciclovias[c][0]][ciclovias[c][1]] = ciclovias[c][2];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            for (int k = 0; k < V; k++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];

    for (int i = 0; i < V; i++) {
        printf("%d. ", i);
        for (int j = 0; j < V; j++) {
            if (d[i][j] >= INFINITO) printf("%4s", "-");
            else printf("%4d", d[i][j]);
        }
        printf("   (%s)\n", pontos[i]);
    }
    return 0;
}

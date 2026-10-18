// 0156 · Juntando tudo: o assistente do calouro
// Exercício E931 · ★☆☆
//
// O mapa do campus do texto, com uma função que já preenche a tabela de
// distâncias pelo Floyd-Warshall. Estenda o main: mostre a tabela (uma
// linha por prédio, com o índice e cada número em %3d) e o par de prédios
// mais distante um do outro, o "diâmetro" do campus (o primeiro par com a
// maior distância, percorrendo a tabela linha por linha).
//
//   Saída esperada:
//   0:  0  4  7  6 11 13
//   1:  4  0  3  2  7  9
//   2:  7  3  0  5  8  6
//   3:  6  2  5  0  5  7
//   4: 11  7  8  5  0  2
//   5: 13  9  6  7  2  0
//   Mais longe: Portaria e Reitoria, 13 min
//
// Dicas:
// 1. Dois laços sobre d[i][j]: imprima e, no mesmo passo, guarde o par
//    (a, b) com o maior valor visto até agora (troque só se for MAIOR,
//    para ficar com o primeiro).
// 2. A tabela é simétrica porque o campus é de mão dupla: d[i][j] ==
//    d[j][i]. Por isso o par (Reitoria, Portaria) também tem 13, mas vem
//    depois.
// 3. Resposta esperada: a saída acima. Portaria -> Reitoria: Portaria,
//    Biblioteca, Lab, Reitoria (4 + 3 + 6 = 13).
//
// Escreva sua resposta abaixo (estenda o main):

#include <stdio.h>

#define MAX 8
#define INFINITO 1000000000

typedef struct {
    int n;
    const char *nomes[MAX];
    int peso[MAX][MAX];
} Grafo;

void liga(Grafo *g, int a, int b, int peso) {
    g->peso[a][b] = peso;
    g->peso[b][a] = peso;
}

void todas_as_distancias(const Grafo *g, int d[][MAX]) {
    for (int i = 0; i < g->n; i++)
        for (int j = 0; j < g->n; j++) d[i][j] = (i == j) ? 0 : (g->peso[i][j] ? g->peso[i][j] : INFINITO);
    for (int k = 0; k < g->n; k++)
        for (int i = 0; i < g->n; i++)
            for (int j = 0; j < g->n; j++)
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
}

int main(void) {
    Grafo campus = {.n = 6, .nomes = {"Portaria", "Biblioteca", "Lab", "Bandejão", "Ginásio", "Reitoria"}};
    liga(&campus, 0, 1, 4);
    liga(&campus, 0, 3, 7);
    liga(&campus, 1, 2, 3);
    liga(&campus, 1, 3, 2);
    liga(&campus, 3, 4, 5);
    liga(&campus, 2, 5, 6);
    liga(&campus, 4, 5, 2);
    int d[MAX][MAX];
    todas_as_distancias(&campus, d);

    // mostre a tabela e o par mais distante
    (void)d; // apague esta linha
    return 0;
}

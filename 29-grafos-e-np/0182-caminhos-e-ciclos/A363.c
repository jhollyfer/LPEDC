// A363 · Seguidores: grau de entrada e de saída

#include <stdio.h>

#define V 5

// grafo DIRIGIDO: segue[a][b] = 1 quer dizer "a segue b"
const char *perfis[V] = {"Ana", "Beto", "Caio", "Duda", "Elis"};
int segue[V][V];

int main(void) {
    int setas[][2] = {{0, 1}, {0, 3}, {1, 3}, {2, 3}, {4, 3}, {3, 0}, {2, 0}, {4, 2}};
    int e = 8;
    for (int k = 0; k < e; k++) segue[setas[k][0]][setas[k][1]] = 1;

    int soma_entrada = 0, soma_saida = 0, famoso = 0, maior = -1;
    printf("perfil  segue (saída)  seguidores (entrada)\n");
    for (int u = 0; u < V; u++) {
        int saida = 0, entrada = 0;
        for (int v = 0; v < V; v++) {
            saida += segue[u][v];   // linha u: setas que saem de u
            entrada += segue[v][u]; // coluna u: setas que chegam em u
        }
        printf("%-6s  %13d  %20d\n", perfis[u], saida, entrada);
        soma_saida += saida;
        soma_entrada += entrada;
        if (entrada > maior) maior = entrada, famoso = u;
    }
    printf("Soma das saídas: %d; soma das entradas: %d; setas: %d\n", soma_saida, soma_entrada, e);
    printf("Mais seguido: %s, com %d seguidores\n", perfis[famoso], maior);
    return 0;
}
// Saída:
// perfil  segue (saída)  seguidores (entrada)
// Ana                 2                     2
// Beto                1                     1
// Caio                2                     1
// Duda                1                     4
// Elis                2                     0
// Soma das saídas: 8; soma das entradas: 8; setas: 8
// Mais seguido: Duda, com 4 seguidores
//
// No dirigido, cada seta conta uma vez na saída de quem segue e uma vez na
// entrada de quem é seguido. As duas somas dão E, e juntas dão 2E: é o
// mesmo aperto de mãos, dividido em dois. Grau de entrada é a coluna da
// matriz; grau de saída é a linha.

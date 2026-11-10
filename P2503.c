// Lista · Módulo 25 · Estruturas especiais
// Exercício P2503 · ★☆☆ · Busca binária nas triplas
//
// O condomínio guarda o consumo de luz (kWh) só dos apartamentos que
// tiveram leitura, como triplas (andar, número, kWh) em ordem. Como estão
// em ordem de (lin, col), dá para procurar com busca binária em vez de
// varrer tudo. Complete valor(t, n, i, j, &comparacoes): devolve o kWh do
// apartamento (i, j), ou 0 se não houver leitura, e conta as triplas
// examinadas.
//
//   Saída esperada:
//   (2, 3): 150 kWh, 1 comparação(ões)
//   (0, 1): 120 kWh, 3 comparação(ões)
//   (7, 3): 105 kWh, 4 comparação(ões)
//   (4, 2):   0 kWh, 4 comparação(ões)
//   (5, 2): 190 kWh, 2 comparação(ões)
//
// Dicas:
// 1. A tripla do meio vem "antes" de (i, j) quando lin < i, ou lin == i e
//    col < j: aí ini = meio + 1.
// 2. Com 10 triplas, a busca binária examina no máximo 4.
// 3. Resposta esperada: (4, 2) não tem leitura (0 kWh, 4 comparações);
//    (2, 3) é achado logo na primeira.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int lin, col, valor;
} Tripla;

int valor(const Tripla t[], int n, int i, int j, int *comparacoes) {
    (void)t; // apague estas linhas e escreva a busca binária
    (void)n;
    (void)i;
    (void)j;
    *comparacoes = 0;
    return 0;
}

int main(void) {
    Tripla leituras[] = {{0, 1, 120}, {0, 4, 95}, {1, 2, 210}, {2, 0, 80}, {2, 3, 150},
                         {3, 1, 175}, {4, 4, 60}, {5, 2, 190}, {6, 0, 130}, {7, 3, 105}};
    int n = 10;
    int perguntas[][2] = {{2, 3}, {0, 1}, {7, 3}, {4, 2}, {5, 2}};
    for (int k = 0; k < 5; k++) {
        int c;
        int v = valor(leituras, n, perguntas[k][0], perguntas[k][1], &c);
        printf("(%d, %d): %3d kWh, %d comparação(ões)\n", perguntas[k][0], perguntas[k][1], v, c);
    }
    return 0;
}

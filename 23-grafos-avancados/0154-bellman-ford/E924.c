// 0154 · Bellman-Ford: pesos negativos
// Exercício E924 · ★★★
//
// Você quer voar de Recife (0) a Curitiba (4), mas odeia conexões. Os voos
// (mão única, preço em R$):
//
//   Recife -> Curitiba 900     Recife -> Salvador 200    Salvador -> Brasília 250
//   Brasília -> Curitiba 300   Recife -> Brasília 500    Salvador -> São Paulo 350
//   São Paulo -> Curitiba 150  Brasília -> São Paulo 120
//
// Escreva mais_barato(origem, destino, k): o menor preço usando NO MÁXIMO
// k voos. Use o Bellman-Ford com k rodadas, mas com um cuidado: em cada
// rodada, relaxe lendo uma CÓPIA da dist da rodada anterior. Assim, a
// rodada r acrescenta no máximo um voo a cada caminho.
//
//   Saída esperada:
//   Até 1 trecho: R$ 900
//   Até 2 trechos: R$ 800
//   Até 3 trechos: R$ 700
//
// Dicas:
// 1. No começo de cada rodada: antes[v] = dist[v] para todo v. No laço das
//    arestas, teste e some com antes[u], mas compare e grave em dist[v].
// 2. Sem a cópia, uma rodada pode encadear vários voos (se a lista estiver
//    na ordem do caminho), e a resposta de k = 1 já sairia 700.
// 3. Resposta esperada: a saída acima. Com 2 voos: Recife, Brasília,
//    Curitiba. Com 3: Recife, Salvador, São Paulo, Curitiba.
//
// Escreva sua resposta abaixo (escreva mais_barato):

#include <stdio.h>

#define V 5
#define E 8
#define INFINITO 1000000000

typedef struct {
    int de, para, preco;
} Voo;

Voo voos[E] = {{0, 4, 900}, {0, 1, 200}, {1, 2, 250}, {2, 4, 300},
               {0, 2, 500}, {1, 3, 350}, {3, 4, 150}, {2, 3, 120}};

int mais_barato(int origem, int destino, int k) {
    (void)origem; // apague estas três linhas
    (void)destino;
    (void)k;
    return 0;
}

int main(void) {
    for (int k = 1; k <= 3; k++) printf("Até %d trecho%s: R$ %d\n", k, k > 1 ? "s" : "", mais_barato(0, 4, k));
    return 0;
}

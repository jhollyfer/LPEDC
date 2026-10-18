// 0154 · Bellman-Ford: pesos negativos
// Exercício E923 · ★★★
//
// Ache o bug. O cartão de transporte da cidade dá R$ 1 de volta na
// integração Lapa -> Barra (custo -1). Não existe nenhuma volta que dê
// lucro, mas o programa acusa ciclo negativo:
//
//   Saída que aparece:
//   Ciclo negativo!
//
//   Saída esperada:
//   Centro: R$ 0
//   Lapa: R$ 4
//   Barra: R$ 3
//   Pituba: R$ 6
//   Itapuã: R$ 8
//
// O erro é de uma linha. Ache, conserte e confira a saída.
//
// Dicas:
// 1. Acrescente um printf dentro do laço das rodadas mostrando o número da
//    rodada e a dist do Itapuã. Quantas rodadas acontecem? Quantas deveriam
//    acontecer com V = 5?
// 2. A lista está na pior ordem possível: cada rodada só avança uma
//    aresta do caminho Centro -> Lapa -> Barra -> Pituba -> Itapuã, que tem
//    4 arestas. Com uma rodada a menos, o Itapuã fica com 10, e a "rodada
//    extra" ainda consegue melhorar: alarme falso.
// 3. Resposta esperada: o laço faz V - 2 rodadas. Troque
//    "rodada < V - 1" por "rodada <= V - 1". Consertado, mostra a saída
//    esperada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define V 5
#define E 5
#define INFINITO 1000000000

typedef struct {
    int de, para, tarifa;
} Trecho;

int main(void) {
    const char *estacoes[V] = {"Centro", "Lapa", "Barra", "Pituba", "Itapuã"};
    Trecho t[E] = {{3, 4, 2}, {2, 3, 3}, {1, 2, -1}, {0, 2, 5}, {0, 1, 4}};
    int dist[V];
    for (int v = 0; v < V; v++) dist[v] = INFINITO;
    dist[0] = 0;

    for (int rodada = 1; rodada < V - 1; rodada++)
        for (int k = 0; k < E; k++)
            if (dist[t[k].de] != INFINITO && dist[t[k].de] + t[k].tarifa < dist[t[k].para])
                dist[t[k].para] = dist[t[k].de] + t[k].tarifa;

    for (int k = 0; k < E; k++)
        if (dist[t[k].de] != INFINITO && dist[t[k].de] + t[k].tarifa < dist[t[k].para]) {
            printf("Ciclo negativo!\n");
            return 0;
        }
    for (int v = 0; v < V; v++) printf("%s: R$ %d\n", estacoes[v], dist[v]);
    return 0;
}

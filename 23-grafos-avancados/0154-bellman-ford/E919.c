// 0154 · Bellman-Ford: pesos negativos
// Exercício E919 · ★☆☆
//
// Viagem de carro da Garagem até o Sítio. Cada trecho tem um custo em R$
// (gasolina e pedágio), mas o aplicativo do Posto A dá cashback para quem
// abastece lá e segue para o Posto B: esse trecho custa R$ -10. Os trechos
// são de mão única:
//
//   Garagem -> Posto A 30    Garagem -> Posto B 45    Posto A -> Posto B -10
//   Posto A -> Pedágio 25    Posto B -> Pedágio 12    Pedágio -> Sítio 8
//   Posto B -> Sítio 40
//
// Escreva o Bellman-Ford do zero, com a lista de arestas já declarada, e
// mostre o menor custo da Garagem até cada lugar.
//
//   Saída esperada:
//   Garagem: R$ 0
//   Posto A: R$ 30
//   Posto B: R$ 20
//   Pedágio: R$ 32
//   Sítio: R$ 40
//
// Dicas:
// 1. dist[] com INFINITO (o 1000000000 já definido) e dist[0] = 0. Faça
//    V - 1 rodadas; em cada uma, passe por todas as E arestas.
// 2. Só relaxe a partir de quem já tem distância: dist[de] != INFINITO.
// 3. Resposta esperada: a saída acima. O Posto B sai mais barato passando
//    pelo Posto A (30 - 10 = 20) do que direto (45).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 5
#define E 7
#define INFINITO 1000000000

typedef struct {
    int de, para, custo;
} Trecho;

int main(void) {
    const char *lugares[V] = {"Garagem", "Posto A", "Posto B", "Pedágio", "Sítio"};
    Trecho t[E] = {{0, 1, 30}, {0, 2, 45}, {1, 2, -10}, {1, 3, 25},
                   {2, 3, 12}, {3, 4, 8}, {2, 4, 40}};
    (void)lugares; // apague estas duas linhas
    (void)t;

    return 0;
}

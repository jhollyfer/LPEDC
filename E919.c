// 0154 · Bellman-Ford: pesos negativos
// Exercício E919 · ★☆☆
//
// Viagem de carro da Garagem até o Sítio. Cada trecho tem um custo em R$
// (gasolina e pedágio), mas o aplicativo do Posto A dá cashback para quem
// abastece lá e segue para o Posto B: esse trecho custa R$ -10. Os trechos são
// de mão única (lugares de 0 a 4: Garagem, Posto A, Posto B, Pedágio, Sítio):
//
//   Garagem -> Posto A 30    Garagem -> Posto B 45    Posto A -> Posto B -10
//   Posto A -> Pedágio 25    Posto B -> Pedágio 12    Pedágio -> Sítio 8
//   Posto B -> Sítio 40
//
// Escreva o Bellman-Ford do zero, com os trechos numa lista de arestas, e
// mostre o menor custo da Garagem até cada lugar.
//
//   Saída esperada:
//   Garagem: R$ 0
//   Posto A: R$ 30
//   Posto B: R$ 20
//   Pedágio: R$ 32
//   Sítio: R$ 40
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}

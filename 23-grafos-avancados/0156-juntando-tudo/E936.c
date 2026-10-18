// 0156 · Juntando tudo: o assistente do calouro
// Exercício E936 · ★★★
//
// O entregador sai da Loja, visita os três clientes do dia (Ana, Bruno e
// Carla) em alguma ordem e volta para a Loja. Os outros pontos do mapa
// (Praça e Ponte) servem só de passagem. As ruas, de mão dupla, em minutos:
//
//   Loja-Praça 4, Loja-Ponte 6, Praça-Ana 3, Praça-Bruno 5, Ponte-Carla 2,
//   Ana-Bruno 4, Bruno-Carla 3, Ana-Ponte 7, Loja-Carla 12
//
// Escreva o programa: rode o Floyd-Warshall para ter o tempo entre
// quaisquer dois pontos e depois teste TODAS as ordens de visita (as
// permutações por troca do assunto 0126), mostrando cada roteiro com o
// tempo total e, no fim, o melhor (o primeiro de menor tempo).
//
//   Saída esperada:
//   Loja -> Ana -> Bruno -> Carla -> Loja: 22 min
//   Loja -> Ana -> Carla -> Bruno -> Loja: 26 min
//   Loja -> Bruno -> Ana -> Carla -> Loja: 28 min
//   Loja -> Bruno -> Carla -> Ana -> Loja: 26 min
//   Loja -> Carla -> Bruno -> Ana -> Loja: 22 min
//   Loja -> Carla -> Ana -> Bruno -> Loja: 28 min
//   Melhor roteiro (22 min): Loja -> Ana -> Bruno -> Carla -> Loja
//
// Dicas:
// 1. Guarde os clientes num vetor {1, 2, 3}. A recursão tenta(pos) troca
//    clientes[pos] com cada clientes[i] (i de pos em diante), chama
//    tenta(pos + 1) e desfaz a troca. Com pos == 3, a ordem está completa.
// 2. O tempo do roteiro é d[Loja][1º] + d[1º][2º] + d[2º][3º] + d[3º][Loja],
//    com d já calculada pelo Floyd-Warshall (ela embute as passagens por
//    Praça e Ponte).
// 3. Resposta esperada: a saída acima. Com k clientes são k! roteiros: com
//    3, seis; com 12, quase meio bilhão. É o problema do caixeiro-viajante,
//    e para ele ninguém conhece algoritmo rápido.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6
#define K 3 // clientes do dia
#define INFINITO 1000000000

const char *lugares[V] = {"Loja", "Ana", "Bruno", "Carla", "Praça", "Ponte"};

int main(void) {
    int ruas[][3] = {{0, 4, 4}, {0, 5, 6}, {4, 1, 3}, {4, 2, 5}, {5, 3, 2},
                     {1, 2, 4}, {2, 3, 3}, {1, 5, 7}, {0, 3, 12}};
    (void)ruas; // apague esta linha

    return 0;
}

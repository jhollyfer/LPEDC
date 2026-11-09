// Lista · Módulo 16 · Grafos
// Exercício P1602 · ★☆☆ · Voos diretos: graus de entrada e de saída
//
// Uma companhia aérea tem voos diretos entre seis capitais. Voo é de mão
// única: o voo Manaus -> Belém não garante o voo Belém -> Manaus (grafo
// DIRIGIDO). O esqueleto traz o vetor voos[], um par {origem, destino} por voo.
//
// Escreva o programa que:
//
// - monte a matriz de adjacência m[V][V] a partir de voos[];
// - mostre, para cada capital, o grau de SAÍDA (voos que partem) e o grau de
//   ENTRADA (voos que chegam);
// - confira que as duas somas dão o número de voos;
// - mostre o "hub" (a capital com o maior grau de entrada);
// - conte os pares de capitais com voo nos DOIS sentidos.
//
//   Saída esperada:
//   Manaus     saída 3  entrada 2
//   Belem      saída 1  entrada 1
//   Brasilia   saída 3  entrada 3
//   Sao Paulo  saída 2  entrada 2
//   Recife     saída 1  entrada 2
//   Boa Vista  saída 1  entrada 1
//   Voos: 11 | soma das saídas 11 | soma das entradas 11
//   Hub: Brasilia (3 chegadas)
//   Ida e volta: Manaus <-> Brasilia
//   Ida e volta: Manaus <-> Boa Vista
//   Ida e volta: Brasilia <-> Sao Paulo
//   Ida e volta: Sao Paulo <-> Recife
//   Pares com ida e volta: 4
//
// Dicas:
// 1. Num grafo dirigido, a saída de i é a soma da LINHA i, e a entrada de j é
//    a soma da COLUNA j.
// 2. Cada voo soma 1 em uma saída e 1 em uma entrada: as duas somas são
//    iguais ao número de arestas (e não ao dobro, como no não dirigido).
// 3. Para os pares de ida e volta, olhe só i < j e teste m[i][j] && m[j][i]:
//    assim cada par conta uma vez.
// 4. Resposta esperada: 11 voos nas duas somas, hub Brasilia (3 chegadas) e
//    4 pares com ida e volta.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Manaus", "Belem", "Brasilia", "Sao Paulo", "Recife", "Boa Vista"};
int voos[][2] = {
    {0, 1}, {0, 2}, {0, 5}, {1, 2}, {2, 3}, {2, 4},
    {2, 0}, {3, 2}, {3, 4}, {4, 3}, {5, 0},
};

int main(void) {
    int total = (int)(sizeof voos / sizeof voos[0]);

    (void)total; // apague esta linha quando usar total
    return 0;
}

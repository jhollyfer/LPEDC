// 0154 · Bellman-Ford: pesos negativos
// Exercício E921 · ★★☆
//
// Um drone de entregas sai da Base. Cada voo gasta uma porcentagem da
// bateria; o voo da Torre até a Praia é uma descida planando com o painel
// solar ligado, e RECARREGA 5% (gasto -5). Os voos são de mão única e já
// estão na lista. Escreva o Bellman-Ford com o vetor anterior[] e mostre,
// para cada ponto, o gasto mínimo e a rota completa, ou "inalcançável" se
// nenhum voo chega lá (é o caso da Mata: ela só tem voo de saída).
//
//   Saída esperada:
//   Ponte (10%): Base -> Ponte
//   Torre (18%): Base -> Ponte -> Torre
//   Praia (13%): Base -> Ponte -> Torre -> Praia
//   Farol (20%): Base -> Ponte -> Torre -> Praia -> Farol
//   Ilha (32%): Base -> Ponte -> Torre -> Praia -> Farol -> Ilha
//   Mata: inalcançável
//
// Dicas:
// 1. Ao relaxar a aresta u -> v, grave anterior[v] = u. A rota de v é a
//    rota até anterior[v] seguida de v: uma função recursiva rota(v)
//    imprime na ordem certa sem precisar de vetor auxiliar.
// 2. Para mostrar o símbolo de porcentagem no printf, use "%%".
// 3. Resposta esperada: a saída acima. A Praia (13%) gasta menos que a
//    Torre (18%), mesmo vindo depois dela: é o efeito da aresta negativa.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define V 7
#define E 10
#define INFINITO 1000000000

typedef struct {
    int de, para, gasto;
} Voo;

const char *pontos[V] = {"Base", "Ponte", "Torre", "Praia", "Farol", "Ilha", "Mata"};

int main(void) {
    Voo voos[E] = {{0, 1, 10}, {0, 2, 25}, {1, 2, 8}, {2, 3, -5}, {1, 3, 20},
                   {3, 4, 7}, {4, 5, 12}, {2, 5, 30}, {6, 4, 3}, {5, 3, 4}};
    (void)voos; // apague esta linha

    return 0;
}

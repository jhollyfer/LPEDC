// 0154 · Bellman-Ford: pesos negativos
// Exercício E921 · ★★☆
//
// Um drone de entregas sai da Base. Cada voo gasta uma porcentagem da bateria;
// o voo da Torre até a Praia é uma descida planando com o painel solar ligado e
// RECARREGA 5% (gasto -5). Os pontos (índices 0 a 6) são Base, Ponte, Torre,
// Praia, Farol, Ilha e Mata. Os voos, de mão única, são:
//
//   Base -> Ponte 10   Base -> Torre 25   Ponte -> Torre 8   Torre -> Praia -5
//   Ponte -> Praia 20  Praia -> Farol 7   Farol -> Ilha 12   Torre -> Ilha 30
//   Mata -> Farol 3    Ilha -> Praia 4
//
// Escreva o Bellman-Ford com o vetor anterior[] e mostre, para cada ponto, o
// gasto mínimo e a rota completa, ou "inalcançável" se nenhum voo chega lá (é o
// caso da Mata, que só tem voo de saída).
//
//   Saída esperada:
//   Ponte (10%): Base -> Ponte
//   Torre (18%): Base -> Ponte -> Torre
//   Praia (13%): Base -> Ponte -> Torre -> Praia
//   Farol (20%): Base -> Ponte -> Torre -> Praia -> Farol
//   Ilha (32%): Base -> Ponte -> Torre -> Praia -> Farol -> Ilha
//   Mata: inalcançável
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define INFINITO 1000000000

int main(void) {

    return 0;
}

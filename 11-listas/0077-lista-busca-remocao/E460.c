// 0077 · Busca e remoção
// Exercício E460 · ★★☆
//
// Num leilão online, a cada rodada o MENOR lance sai da disputa. Os lances
// estão numa lista de structs Lance (declarada abaixo). Escreva
//
//   Lance *lance_insere(Lance *inicio, const char *nome, int valor)  no início
//   void lance_imprime(const Lance *inicio)  formato do exemplo
//   void lance_libera(Lance *inicio)
//   bool remove_menor(Lance **inicio, Lance *saiu)
//
// remove_menor acha o nó de menor valor, copia os dados dele para *saiu, tira
// o nó da lista e devolve true (ou false se a lista estiver vazia). Insira
// Ana 150, Bruno 90, Carla 210 e Davi 175 (nesta ordem), mostre a lista e
// rode duas rodadas.
//
//   Saída esperada:
//   Davi R$ 175 -> Carla R$ 210 -> Bruno R$ 90 -> Ana R$ 150 -> NULL
//   saiu Bruno (R$ 90)
//   Davi R$ 175 -> Carla R$ 210 -> Ana R$ 150 -> NULL
//   saiu Ana (R$ 150)
//   Davi R$ 175 -> Carla R$ 210 -> NULL
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct lance {
    char nome[20];
    int valor;
    struct lance *prox;
} Lance;

int main(void) {

    return 0;
}

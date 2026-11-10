// Lista · Módulo 11 · Listas
// Exercício P1106 · ★☆☆ · O metrô nos dois sentidos
//
// Uma linha de metrô vai e volta pelas mesmas estações: é uma lista dupla.
// Escreva insere_fim para a lista dupla com início e fim, e duas funções de
// impressão: uma do início para o fim (seguindo prox) e outra do fim para o
// início (seguindo ant). Cadastre as estações Sé, Luz, Tiradentes e
// Armênia (nesta ordem) e mostre a ida e a volta. Libere tudo no fim.
//
//   Saída esperada:
//   Ida:   Sé -> Luz -> Tiradentes -> Armênia
//   Volta: Armênia -> Tiradentes -> Luz -> Sé
//
// Dicas:
// 1. Cada nó tem ant e prox. No insere_fim: novo->ant = l->fim; novo->prox
//    = NULL; se a lista não estava vazia, l->fim->prox = novo; senão,
//    l->inicio = novo. No fim, l->fim = novo.
// 2. A volta começa em l->fim e anda com p = p->ant: O(n), sem pilha e sem
//    recursão, que é o que a seta extra compra.
// 3. Para não sobrar " -> " no fim, imprima a seta ANTES de cada estação,
//    menos da primeira.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estacao {
    char nome[24];
    struct estacao *ant, *prox;
} Estacao;

typedef struct {
    Estacao *inicio, *fim;
} Linha;

int main(void) {

    return 0;
}

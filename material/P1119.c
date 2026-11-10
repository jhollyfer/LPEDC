// Lista · Módulo 11 · Listas
// Exercício P1119 · ★★☆ · O ranking da corrida em lista dupla
//
// Os tempos da corrida de 5 km (em minutos) chegam fora de ordem: 58, 61,
// 55, 70 e 60. Guarde-os numa lista DUPLA com início e fim, sempre em ordem
// crescente. Escreva
//
//   void insere_ordenado(Ranking *r, int tempo)
//
// tratando os quatro casos: lista vazia, novo antes do primeiro, novo
// depois do último e novo no meio. Mostre o ranking depois de cada
// inserção, do início para o fim, e no final mostre também do fim para o
// início (o que confere se todas as setas ant ficaram certas).
//
//   Saída esperada:
//   58
//   58 61
//   55 58 61
//   55 58 61 70
//   55 58 60 61 70
//   De trás para frente: 70 61 60 58 55
//
// Dicas:
// 1. Ache o primeiro nó p com p->tempo > tempo (ou p == NULL). O novo entra
//    ANTES de p: novo->prox = p e novo->ant = (p ? p->ant : r->fim).
// 2. Depois acerte os vizinhos: se novo->ant existe, novo->ant->prox =
//    novo, senão r->inicio = novo; se p existe, p->ant = novo, senão
//    r->fim = novo. Assim os quatro casos saem do mesmo código.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int tempo;
    struct no *ant, *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Ranking;

int main(void) {

    return 0;
}

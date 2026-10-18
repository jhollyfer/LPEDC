// 0091 · Fila encadeada
// Exercício E541 · ★☆☆
//
// Sem rodar, desenhe a lista da fila depois de cada operação do main, no
// formato inicio -> ... -> NULL, marcando onde está o fim. Preveja a saída.
// Depois responda: em quais momentos inicio e fim apontam para o MESMO nó?
//
// Dicas:
// 1. Insere pendura no fim; retira tira do início.
// 2. inicio == fim (sem ser NULL) quer dizer fila com um só nó.
// 3. Resposta esperada: mostra "7 4 9 " e depois "sobrou 1 (1 na fila)".
//    A sequência é [7], [7, 4], [4], [4, 9], [9], [9, 1], [1]. inicio e
//    fim apontam para o mesmo nó quando a fila tem um nó só: depois de
//    inserir o 7 e depois de cada retirada.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *f = fila_cria();
    if (f == NULL) {
        return 1;
    }
    int x;

    fila_insere(f, 7);
    fila_insere(f, 4);
    fila_retira(f, &x);
    printf("%d ", x);
    fila_insere(f, 9);
    fila_retira(f, &x);
    printf("%d ", x);
    fila_insere(f, 1);
    fila_retira(f, &x);
    printf("%d \n", x);

    fila_primeiro(f, &x);
    printf("sobrou %d (%d na fila)\n", x, fila_tamanho(f));
    fila_libera(f);
    return 0;
}

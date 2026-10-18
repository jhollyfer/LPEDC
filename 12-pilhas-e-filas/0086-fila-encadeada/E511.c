// 0086 · Fila encadeada
// Exercício E511 · ★☆☆
//
// Os nós da fila ficam escondidos no fila.c, mas dá para mostrar a fila
// inteira só com o fila.h: retire o primeiro, mostre e insira de novo no
// fim, fila_tamanho vezes. No fim da volta, a fila está igual. Escreva a
// função mostra assim, do início para o fim (7 -> 4), e acrescente
// "(um nó só: início e fim apontam para ele)" quando a fila tiver 1 item.
// O main já chama mostra depois de cada operação.
//
//   Saída esperada:
//   insere 7: 7 (um nó só: início e fim apontam para ele)
//   insere 4: 7 -> 4
//   retira 7: 4 (um nó só: início e fim apontam para ele)
//   insere 9: 4 -> 9
//   retira 4: 9 (um nó só: início e fim apontam para ele)
//   insere 1: 9 -> 1
//   retira 9: 1 (um nó só: início e fim apontam para ele)
//   retira 1: vazia
//
// Dicas:
// 1. Guarde fila_tamanho num int antes do laço e faça o for até ele.
// 2. Mostre " -> " antes de cada item, menos do primeiro.
// 3. Cada volta faz um free (retira) e um malloc (insere): a fila é a
//    mesma, mas os nós são novos.
// 4. Resposta esperada: as oito linhas acima, sem vazamento.
//
// Escreva sua resposta abaixo (escreva mostra):

#include <stdio.h>
#include "fila.h"

void mostra(Fila *f) {
    (void)f; // apague esta linha quando usar f
    printf("\n");
}

int main(void) {
    Fila *f = fila_cria();
    if (f == NULL) {
        return 1;
    }
    int entram[] = {7, 4, 9, 1};
    int x;

    for (int i = 0; i < 4; i++) {
        fila_insere(f, entram[i]);
        printf("insere %d: ", entram[i]);
        mostra(f);
        if (i > 0 && fila_retira(f, &x)) { // a partir do segundo, sai um
            printf("retira %d: ", x);
            mostra(f);
        }
    }
    if (fila_retira(f, &x)) {
        printf("retira %d: ", x);
        mostra(f);
    }
    fila_libera(f);
    return 0;
}

// 0085 · Lista circular
// Exercício E506 · ★☆☆
//
// Sem rodar, preveja as seis linhas deste programa. Lembre: a lista é
// guardada pelo ponteiro para o ÚLTIMO nó. Depois rode e confira.
//
// O código está no arquivo, logo abaixo deste enunciado.
//
// Dicas:
// 1. Depois das quatro inserções: 5 10 20 30, com u no 30.
// 2. O for anda 6 vezes a partir do 10: ele passa do fim e continua.
// 3. "u = u->prox->prox" não muda nenhuma seta: só muda QUEM é o último.
//    É girar a roda em O(1).
// 4. Resposta esperada:
//    5 -> 10 -> 20 -> 30 -> (volta ao 5)
//    30 5
//    10 20 30 5 10 20
//    20 -> 30 -> 5 -> 10 -> (volta ao 20)
//    20 -> 30 -> 5 -> (volta ao 20)
//    3
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "lista.h"

int main(void) {
    No *u = NULL;
    u = lista_insere_fim(u, 10);
    u = lista_insere_fim(u, 20);
    u = lista_insere_inicio(u, 5);
    u = lista_insere_fim(u, 30);
    lista_imprime(u);
    printf("%d %d\n", u->valor, u->prox->valor);

    const No *p = u->prox->prox;
    for (int i = 0; i < 6; i++) {
        printf(i == 0 ? "%d" : " %d", p->valor);
        p = p->prox;
    }
    printf("\n");

    u = u->prox->prox;
    lista_imprime(u);
    lista_remove(&u, 10);
    lista_imprime(u);
    printf("%d\n", lista_tamanho(u));

    lista_libera(u);
    return 0;
}

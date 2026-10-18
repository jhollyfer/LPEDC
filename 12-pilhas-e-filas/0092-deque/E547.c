// 0092 · Deque
// Exercício E547 · ★☆☆
//
// Sem rodar, preveja a saída. Desenhe o deque como uma fileira, com a
// frente à esquerda, e atualize a cada operação.
//
// Dicas:
// 1. insere_inicio põe à esquerda; insere_fim, à direita.
// 2. primeiro e ultimo só olham.
// 3. Resposta esperada: a ordem depois das quatro inserções é 4 2 1 3. A
//    saída é "saiu do fim: 3", "saiu da frente: 4" e "frente 2, fundo 1,
//    tamanho 2".
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "deque.h"

int main(void) {
    Deque *d = deque_cria();
    if (d == NULL) {
        return 1;
    }
    int x, y;

    deque_insere_fim(d, 1);
    deque_insere_inicio(d, 2);
    deque_insere_fim(d, 3);
    deque_insere_inicio(d, 4);

    deque_retira_fim(d, &x);
    printf("saiu do fim: %d\n", x);
    deque_retira_inicio(d, &x);
    printf("saiu da frente: %d\n", x);

    deque_primeiro(d, &x);
    deque_ultimo(d, &y);
    printf("frente %d, fundo %d, tamanho %d\n", x, y, deque_tamanho(d));

    deque_libera(d);
    return 0;
}

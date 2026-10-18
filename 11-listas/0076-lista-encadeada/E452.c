// 0076 · Lista encadeada
// Exercício E452 · ★☆☆
//
// O laço do programa abaixo já monta uma lista inserindo 3, 6, 9 e 12 no
// início. Complete o main para mostrar a lista e mais três linhas:
//
//   o primeiro valor da lista;
//   o terceiro, seguindo duas setas a partir do início (l->prox->prox);
//   o último, andando com um ponteiro p até o nó cujo prox é NULL.
//
//   Saída esperada:
//   12 -> 9 -> 6 -> 3 -> NULL
//   primeiro: 12
//   terceiro: 6
//   último: 3
//
// Dicas:
// 1. Desenhe os nós e as setas no papel antes: quem ficou na frente?
// 2. l->prox->prox anda dois nós a partir do primeiro.
// 3. Para o último: No *p = l; while (p->prox != NULL) p = p->prox;
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o main):

#include <stdio.h>
#include "lista.h"

int main(void) {
    No *l = NULL;
    for (int i = 1; i <= 4; i++) {
        l = lista_insere_inicio(l, i * 3);
    }

    // escreva aqui, antes de liberar

    lista_libera(l);
    return 0;
}

// 0079 · Lista dupla
// Exercício E470 · ★☆☆
//
// Sem rodar, preveja as sete linhas que este programa mostra. Desenhe os nós
// com as duas setas de cada um. Depois rode e confira.
//
// O código está no arquivo, logo abaixo deste enunciado.
//
// Dicas:
// 1. Depois das quatro inserções, a lista é 4 2 1 3.
// 2. l.fim->ant->ant anda duas casas para trás a partir do último.
// 3. Tirar l.inicio e l.fim usa os dois casos de borda da remoção.
// 4. Resposta esperada:
//    4 <-> 2 <-> 1 <-> 3
//    3 <-> 1 <-> 2 <-> 4
//    2 2
//    2 3
//    2: 2 <-> 1
//    1 <-> 2
//    1
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista l;
    lista_inicia(&l);
    lista_insere_fim(&l, 1);
    lista_insere_inicio(&l, 2);
    lista_insere_fim(&l, 3);
    lista_insere_inicio(&l, 4);
    lista_imprime(&l);
    lista_imprime_reverso(&l);

    printf("%d %d\n", l.inicio->prox->valor, l.fim->ant->ant->valor);
    No *p = lista_busca(&l, 1);
    printf("%d %d\n", p->ant->valor, p->prox->valor);

    lista_remove_no(&l, l.inicio);
    lista_remove_no(&l, l.fim);
    printf("%d: ", l.tamanho);
    lista_imprime(&l);
    lista_imprime_reverso(&l);
    printf("%d\n", l.inicio->ant == NULL && l.fim->prox == NULL);

    lista_libera(&l);
    return 0;
}

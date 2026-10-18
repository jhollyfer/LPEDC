// 0077 · Busca e remoção
// Exercício E458 · ★☆☆
//
// Sem rodar, preveja tudo o que este programa mostra. A lista tem valores
// repetidos, e é aí que mora a graça. Depois rode e confira.
//
// O código está no arquivo, logo abaixo deste enunciado.
//
// Dicas:
// 1. A lista começa como 5 -> 2 -> 5 -> 9 -> 5.
// 2. lista_remove tira só o PRIMEIRO nó que tem o valor.
// 3. lista_busca devolve o endereço do nó: mudar p->valor muda a lista.
// 4. Resposta esperada:
//    1
//    2 -> 5 -> 9 -> 5 -> NULL
//    0
//    2 -> 5 -> 4 -> 5 -> NULL
//    1
//    2 -> 4 -> NULL
//    2
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "lista.h"

int main(void) {
    No *l = NULL;
    int v[] = {5, 9, 5, 2, 5};
    for (int i = 0; i < 5; i++) l = lista_insere_inicio(l, v[i]);

    printf("%d\n", lista_remove(&l, 5));
    lista_imprime(l);
    printf("%d\n", lista_remove(&l, 7));

    No *p = lista_busca(l, 9);
    p->valor = 4;
    lista_imprime(l);
    printf("%d\n", lista_busca(l, 9) == NULL);

    lista_remove(&l, 5);
    lista_remove(&l, 5);
    lista_imprime(l);
    printf("%d\n", lista_tamanho(l));

    lista_libera(l);
    return 0;
}

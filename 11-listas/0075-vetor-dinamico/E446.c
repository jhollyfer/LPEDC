// 0075 · Vetor dinâmico
// Exercício E446 · ★☆☆
//
// Sem rodar, preveja as linhas que este programa mostra. Anote em cada
// passo como está o vetor por dentro (itens, tam e cap). Depois rode e
// confira.
//
// O código está no arquivo, logo abaixo deste enunciado.
//
// Dicas:
// 1. lista_cria(1) começa com cap 1. Cada vez que enche, a capacidade dobra.
// 2. Inserir na posição igual ao tamanho é o mesmo que inserir no fim.
// 3. Remover numa posição que não existe devolve false e não mexe em x.
// 4. Resposta esperada:
//    A: tam 2, cap 2
//    B: tam 4, cap 4
//    [3, 5, 9, 7]
//    C: x = 5, tam 4, cap 4
//    [3, 9, 7, 10]
//    D: falhou, x continua 5
//    E: tam 5, cap 8
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista *l = lista_cria(1);
    if (l == NULL) return 1;

    lista_insere_fim(l, 5);
    lista_insere_fim(l, 9);
    printf("A: tam %d, cap %d\n", lista_tamanho(l), lista_capacidade(l));

    lista_insere_em(l, 0, 3);
    lista_insere_fim(l, 7);
    printf("B: tam %d, cap %d\n", lista_tamanho(l), lista_capacidade(l));
    lista_imprime(l);

    int x = 0;
    lista_remove_em(l, 1, &x);
    lista_insere_em(l, 3, x * 2);
    printf("C: x = %d, tam %d, cap %d\n", x, lista_tamanho(l), lista_capacidade(l));
    lista_imprime(l);

    if (!lista_remove_em(l, 4, &x)) {
        printf("D: falhou, x continua %d\n", x);
    }

    lista_insere_fim(l, 1);
    printf("E: tam %d, cap %d\n", lista_tamanho(l), lista_capacidade(l));

    lista_libera(l);
    return 0;
}

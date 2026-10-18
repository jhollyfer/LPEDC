// 0076 · Lista encadeada
// Exercício E452 · ★☆☆
//
// Sem rodar, preveja as cinco linhas que este programa mostra. Desenhe os
// nós e as setas no papel: é o jeito certo de pensar em lista. Depois
// responda: por que o fim do programa usa free(outra) e não
// lista_libera(outra)?
//
// O código está no arquivo, logo abaixo deste enunciado.
//
// Dicas:
// 1. O laço insere 3, 6, 9 e 12 no início: quem fica na frente?
// 2. l->prox->prox anda dois nós a partir do primeiro.
// 3. "outra" ganha um nó novo cujo prox é l->prox: as duas listas passam a
//    COMPARTILHAR a mesma cauda.
// 4. Resposta esperada:
//    12
//    6
//    3
//    99 -> 9 -> 6 -> 3 -> NULL
//    12 -> 9 -> 6 -> 3 -> NULL
//    Como a cauda 9 -> 6 -> 3 é das duas, lista_libera(outra) liberaria esses
//    nós, e depois lista_libera(l) daria free neles de novo (free duplo).
//    Por isso só o nó 99 sai com free(outra).
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
    No *l = NULL;
    for (int i = 1; i <= 4; i++) {
        l = lista_insere_inicio(l, i * 3);
    }
    printf("%d\n", l->valor);
    printf("%d\n", l->prox->prox->valor);

    No *p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    printf("%d\n", p->valor);

    No *outra = lista_insere_inicio(l->prox, 99);
    lista_imprime(outra);
    lista_imprime(l);

    free(outra);
    lista_libera(l);
    return 0;
}

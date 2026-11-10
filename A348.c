// A348 · Juntar duas filas em O(1)

#include <stdio.h>
#include "0174-sentinela.h"

// o caixa b fecha: a fila dele vai inteira para o fim da fila a.
// Quatro ponteiros, não importa o tamanho das filas.
void concatena(ListaS *a, ListaS *b) {
    if (b->n == 0) {
        return; // b vazia: a sentinela de b não pode entrar em a
    }
    NoS *ultimo_a = a->nil.ant;
    NoS *primeiro_b = b->nil.prox;
    NoS *ultimo_b = b->nil.ant;

    ultimo_a->prox = primeiro_b; // costura o fim de a no começo de b
    primeiro_b->ant = ultimo_a;
    ultimo_b->prox = &a->nil;    // o fim de b passa a fechar o anel de a
    a->nil.ant = ultimo_b;
    a->n += b->n;

    b->nil.prox = &b->nil; // b fica vazia, pronta para outro uso
    b->nil.ant = &b->nil;
    b->n = 0;
}

int main(void) {
    ListaS *caixa1 = sent_cria();
    ListaS *caixa2 = sent_cria();
    if (caixa1 == NULL || caixa2 == NULL) {
        sent_libera(caixa1 != NULL ? caixa1 : caixa2);
        return 1;
    }
    int f1[] = {101, 102, 103};
    int f2[] = {201, 202, 203, 204};
    for (int i = 0; i < 3; i++) {
        sent_insere_fim(caixa1, f1[i]);
    }
    for (int i = 0; i < 4; i++) {
        sent_insere_fim(caixa2, f2[i]);
    }
    printf("Caixa 1: ");
    sent_mostra(caixa1);
    printf("Caixa 2: ");
    sent_mostra(caixa2);

    concatena(caixa1, caixa2);
    printf("O caixa 2 fechou.\n");
    printf("Caixa 1: ");
    sent_mostra(caixa1);
    printf("Ao contrário: ");
    sent_mostra_inverso(caixa1);
    printf("Caixa 2: ");
    sent_mostra(caixa2);
    printf("Tamanhos: %d e %d\n", caixa1->n, caixa2->n);

    sent_libera(caixa1);
    sent_libera(caixa2);
    return 0;
}
// Saída:
// Caixa 1: [ 101 102 103 ]
// Caixa 2: [ 201 202 203 204 ]
// O caixa 2 fechou.
// Caixa 1: [ 101 102 103 201 202 203 204 ]
// Ao contrário: [ 204 203 202 201 103 102 101 ]
// Caixa 2: [ ]
// Tamanhos: 7 e 0

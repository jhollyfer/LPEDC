// 0080 · Lista circular
// Exercício E480 · ★★★
//
// A escala de plantão do hospital é circular: depois do último enfermeiro,
// volta o primeiro. As duas funções deste programa têm erros de propósito.
// Rode, compare com a saída esperada e leia o relatório do AddressSanitizer.
// Conserte as duas funções e responda: por que um laço "while (p != NULL)"
// nunca termina sozinho numa lista circular?
//
//   Saída esperada depois do conserto:
//   escala: 101 102 103 104
//   4 enfermeiros
//
// Dicas:
// 1. A escala sai sem o 104. O while de mostra_escala para quando p chega
//    no último, antes de imprimir ele. Uma volta completa se faz com
//    do-while, parando quando p volta ao primeiro.
// 2. O ASan acusa "heap-use-after-free" em libera_escala: depois de liberar
//    o último, o "seguinte" dele é o primeiro, que já foi liberado. Nenhum
//    prox é NULL! Corte o círculo antes (ultimo->prox = NULL).
// 3. Resposta esperada: a saída acima. Na circular, todo nó tem um próximo
//    de verdade: p nunca vira NULL, e o laço daria voltas para sempre (ou,
//    como aqui, andaria por memória já liberada).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static void mostra_escala(const No *ultimo) {
    printf("escala:");
    const No *p = ultimo->prox;
    while (p != ultimo) {
        printf(" %d", p->valor);
        p = p->prox;
    }
    printf("\n");
}

static void libera_escala(No *ultimo) {
    No *p = ultimo->prox;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
}

int main(void) {
    No *escala = NULL;
    for (int m = 101; m <= 104; m++) escala = lista_insere_fim(escala, m);
    mostra_escala(escala);
    printf("%d enfermeiros\n", lista_tamanho(escala));
    libera_escala(escala);
    return 0;
}

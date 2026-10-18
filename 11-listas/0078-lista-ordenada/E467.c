// 0078 · Lista ordenada
// Exercício E467 · ★★★
//
// O ranking da corrida de 5 km guarda os tempos em segundos, do mais rápido
// para o mais lento. A função insere_ordem e o main têm TRÊS erros de
// propósito. Rode, leia os relatórios do AddressSanitizer e conserte até
// sair:
//
//   Saída esperada depois do conserto:
//   1290 -> 1385 -> 1520 -> 1610 -> NULL
//
// Dicas:
// 1. O primeiro relatório é um SEGV logo na primeira inserção, com a lista
//    vazia. Leia o while: quem é testado primeiro?
// 2. O segundo aparece quando o laço nem anda (lista vazia, ou o novo tempo
//    é o MENOR de todos): ant continua NULL e a função faz ant->prox.
// 3. O terceiro não quebra nada, mas a lista mostra "NULL" e o ASan acusa
//    vazamento: olhe como o main chama insere_ordem.
// 4. Resposta esperada: "while (p != NULL && p->valor < valor)"; "if (ant ==
//    NULL) return novo;" antes do ant->prox = novo; e no main,
//    "ranking = insere_ordem(ranking, tempos[i]);".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static No *insere_ordem(No *inicio, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->valor = valor;

    No *ant = NULL;
    No *p = inicio;
    while (p->valor < valor && p != NULL) {
        ant = p;
        p = p->prox;
    }
    novo->prox = p;
    ant->prox = novo;
    return inicio;
}

int main(void) {
    int tempos[] = {1520, 1385, 1610, 1290};
    No *ranking = NULL;
    for (int i = 0; i < 4; i++) {
        insere_ordem(ranking, tempos[i]);
    }
    lista_imprime(ranking);
    lista_libera(ranking);
    return 0;
}

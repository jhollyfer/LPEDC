// 0082 · Busca e remoção
// Exercício E491 · ★★★
//
// A lista de presentes do chá de bebê guarda o código de cada presente. A
// função "tira" deveria remover um código, mas tem QUATRO erros de
// propósito. Rode, leia o aviso do gcc e os relatórios do AddressSanitizer
// e conserte um por um até sair:
//
//   Saída esperada depois do conserto:
//   14 -> 3 -> 27 -> 9 -> NULL
//   3 -> 9 -> NULL
//   50 não estava na lista
//
// Dicas:
// 1. O gcc já avisa o primeiro ("pointer 'p' used after 'free'") e o ASan
//    confirma com "heap-use-after-free". Olhe a ordem das duas linhas depois
//    do laço: depois do free, p->prox não é mais seu.
// 2. Segundo: tirar o 14 (o primeiro) faz ant->prox com ant == NULL.
// 3. Mesmo tratando o primeiro, o main não fica sabendo do novo início:
//    "inicio" chegou por valor. A função precisa receber No **.
// 4. Terceiro relatório: procurar o 50 cai num p NULL. Veja a ordem do &&.
// 5. Resposta esperada: assinatura bool tira(No **inicio, int valor); laço
//    "while (p != NULL && p->valor != valor)"; "if (ant == NULL) *inicio =
//    p->prox; else ant->prox = p->prox;" e só então free(p). No main,
//    chame tira(&lista, ...).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

static bool tira(No *inicio, int valor) {
    No *ant = NULL;
    No *p = inicio;
    while (p->valor != valor && p != NULL) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return false;
    free(p);
    ant->prox = p->prox;
    return true;
}

int main(void) {
    No *lista = NULL;
    int codigos[] = {9, 27, 3, 14};
    for (int i = 0; i < 4; i++) lista = lista_insere_inicio(lista, codigos[i]);
    lista_imprime(lista);

    tira(lista, 27);
    tira(lista, 14);
    lista_imprime(lista);
    if (!tira(lista, 50)) printf("50 não estava na lista\n");

    lista_libera(lista);
    return 0;
}

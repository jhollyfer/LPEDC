// 0082 · Busca e remoção
// Exercício E489 · ★★☆
//
// O sensor de temperatura da estufa grava 0 quando falha. Escreva
//
//   int remove_todos(No **inicio, int valor)
//
// que tira TODOS os nós com o valor numa passada só (sem chamar
// lista_remove em laço, que recomeçaria do início a cada vez) e devolve
// quantos tirou. Teste com as duas listas do main.
//
//   Saída esperada:
//   antes:  0 -> 0 -> 21 -> 0 -> 19 -> 0 -> NULL
//   depois: 21 -> 19 -> NULL
//   4 leituras removidas
//   só falhas: NULL (2 removidas)
//
// Dicas:
// 1. Ande com ant e p. Quando p->valor for o valor, religue (o início ou
//    ant->prox), guarde p->prox, dê free(p) e continue a partir do guardado,
//    SEM mexer no ant.
// 2. Quando não remover, aí sim: ant = p e p anda.
// 3. Os 0 do começo são o caso traiçoeiro: o início muda duas vezes seguidas.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (troque o corpo de remove_todos):

#include <stdio.h>
#include "lista.h"

int remove_todos(No **inicio, int valor) {
    (void)inicio; // apague estas duas linhas
    (void)valor;  // quando escrever a função
    return 0;
}

int main(void) {
    int leituras[] = {0, 19, 0, 21, 0, 0}; // inseridas no início: ficam ao contrário
    No *l = NULL;
    for (int i = 0; i < 6; i++) l = lista_insere_inicio(l, leituras[i]);
    printf("antes:  ");
    lista_imprime(l);
    int n = remove_todos(&l, 0);
    printf("depois: ");
    lista_imprime(l);
    printf("%d leituras removidas\n", n);

    No *falhas = lista_insere_inicio(lista_insere_inicio(NULL, 0), 0);
    n = remove_todos(&falhas, 0);
    printf("só falhas: ");
    if (falhas == NULL) printf("NULL");
    printf(" (%d removidas)\n", n);

    lista_libera(l);
    lista_libera(falhas);
    return 0;
}

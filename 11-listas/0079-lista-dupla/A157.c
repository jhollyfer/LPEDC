// A157 · Mexendo nas duas pontas: a fila do pronto-socorro

#include <stdio.h>
#include "lista.h"

static void mostra(const Lista *l) {
    printf("(%d) ", l->tamanho);
    lista_imprime(l);
}

int main(void) {
    Lista fila;
    lista_inicia(&fila);

    // fichas de atendimento: normais entram atrás, urgente entra na frente
    lista_insere_fim(&fila, 31);
    lista_insere_fim(&fila, 32);
    lista_insere_fim(&fila, 33);
    lista_insere_inicio(&fila, 90); // caso urgente: passa na frente
    mostra(&fila);

    // atender o primeiro: remover o início é O(1)
    printf("atende %d\n", fila.inicio->valor);
    lista_remove_no(&fila, fila.inicio);

    // o último desistiu: com o ponteiro fim, tirar o último também é O(1)
    printf("desistiu %d\n", fila.fim->valor);
    lista_remove_no(&fila, fila.fim);
    mostra(&fila);

    // esvaziando pela frente: no fim, as DUAS pontas voltam a NULL
    while (fila.inicio != NULL) lista_remove_no(&fila, fila.inicio);
    printf("vazia: inicio %s, fim %s, tamanho %d\n",
           fila.inicio == NULL ? "NULL" : "?",
           fila.fim == NULL ? "NULL" : "?", fila.tamanho);

    // e a lista vazia continua pronta para uso
    lista_insere_inicio(&fila, 34);
    printf("um só: início e fim são o mesmo nó? %s\n",
           fila.inicio == fila.fim ? "sim" : "não");

    lista_libera(&fila);
    return 0;
}
// Saída:
// (4) 90 <-> 31 <-> 32 <-> 33
// atende 90
// desistiu 33
// (2) 31 <-> 32
// vazia: inicio NULL, fim NULL, tamanho 0
// um só: início e fim são o mesmo nó? sim

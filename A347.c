// A347 · Vazia, um nó, vários: o mesmo código

#include <stdio.h>
#include "0174-sentinela.h"

// mostra a lista e para onde a sentinela aponta
void raio_x(const char *passo, const ListaS *L) {
    printf("%s ", passo);
    sent_mostra(L);
    printf("    nil.prox é %s | nil.ant é %s | n = %d\n",
           L->nil.prox == &L->nil ? "a própria nil" : "um nó",
           L->nil.ant == &L->nil ? "a própria nil" : "um nó", L->n);
}

int main(void) {
    ListaS *L = sent_cria();
    if (L == NULL) {
        return 1;
    }
    raio_x("criada:", L);

    NoS *a = sent_insere_fim(L, 50); // lista vazia: nenhum if especial
    raio_x("insere 50 no fim:", L);

    sent_remove(L, a); // remove o único nó: o mesmo código de sempre
    raio_x("remove o 50:", L);

    sent_insere_fim(L, 10);
    sent_insere_fim(L, 20);
    sent_insere_fim(L, 30);
    raio_x("insere 10, 20, 30:", L);

    sent_remove(L, L->nil.prox); // o primeiro
    sent_remove(L, L->nil.ant);  // o último
    raio_x("tira o primeiro e o último:", L);

    sent_libera(L);
    return 0;
}
// Saída:
// criada: [ ]
//     nil.prox é a própria nil | nil.ant é a própria nil | n = 0
// insere 50 no fim: [ 50 ]
//     nil.prox é um nó | nil.ant é um nó | n = 1
// remove o 50: [ ]
//     nil.prox é a própria nil | nil.ant é a própria nil | n = 0
// insere 10, 20, 30: [ 10 20 30 ]
//     nil.prox é um nó | nil.ant é um nó | n = 3
// tira o primeiro e o último: [ 20 ]
//     nil.prox é um nó | nil.ant é um nó | n = 1

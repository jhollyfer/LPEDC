## 0174 · Lista com sentinela

- **Nó sentinela** (`L.nil`): um nó falso, sem dado, entre o último e o
  primeiro. A lista vira **dupla e circular**, e nenhum `NULL` sobra dentro
  dela (CORMEN et al., 2024, cap. 10).
- **Por que existe**: na lista dupla comum, o primeiro e o último têm `NULL` de
  um lado, e cada `NULL` é um caso especial na remoção (TENENBAUM; LANGSAM;
  AUGENSTEIN, 1995).
- **Lista vazia**: a sentinela aponta para si (`nil.prox == &nil`);
  `nil.prox` é o primeiro e `nil.ant` é o último (CORMEN et al., 2024, cap. 10).
- **Inserir depois de `y`**: quatro ponteiros, sempre os mesmos, com `y`
  podendo ser a sentinela (começo) ou o último (fim).
- **Remover `x`**: `x->ant->prox = x->prox` e `x->prox->ant = x->ant`. Duas
  linhas, sem `if` (CELES; CERQUEIRA; RANGEL, 2016).
- **Buscar com a chave na sentinela**: guarde a chave procurada em `nil`
  antes do laço; ele sempre para e faz um teste por volta em vez de dois. Se
  parar na sentinela, não achou (CORMEN et al., 2024, cap. 10).
- **Custo**: um nó a mais por lista. Como a sentinela fica dentro da `ListaS`,
  `&L->nil` é fixo e os laços sabem onde parar.

> [!WARNING]
> A sentinela **não é um dado**: o laço para quando volta a ela e começa em
> `L->nil.prox`. Nunca passe `&L->nil` para `sent_remove`: ela não veio do
> `malloc`, e o `free` derruba o programa.

{{exemplo}}

Uma barbearia guarda as fichas de espera. Chegam 12, 25 e 7; a 25 desiste e
sai. A busca pela 40, que não existe, para na sentinela (o nó cinza):

{{ideia}}

As três funções centrais do `sentinela.c`; o `n` conta só os nós reais:

```c
NoS *sent_insere_apos(ListaS *L, NoS *y, int chave) {
    NoS *x = malloc(sizeof(NoS));
    if (x == NULL) {
        return NULL;
    }
    x->chave = chave;
    x->prox = y->prox; // y sempre tem vizinho: no mínimo, a sentinela
    x->ant = y;
    y->prox->ant = x;
    y->prox = x;
    L->n++;
    return x;
}

NoS *sent_busca(ListaS *L, int chave) {
    L->nil.chave = chave; // a sentinela guarda a chave: o laço sempre para
    NoS *x = L->nil.prox;
    while (x->chave != chave) {
        x = x->prox;
    }
    return x; // se for &L->nil, a chave não estava na lista
}

void sent_remove(ListaS *L, NoS *x) {
    x->ant->prox = x->prox;
    x->prox->ant = x->ant;
    free(x);
    L->n--;
}
```

O programa da barbearia:

```c
#include <stdio.h>
#include "sentinela.h"

int main(void) {
    ListaS *fila = sent_cria();
    if (fila == NULL) {
        return 1;
    }
    sent_insere_fim(fila, 12); // fichas na ordem de chegada
    sent_insere_fim(fila, 25);
    sent_insere_fim(fila, 7);
    printf("Fila: ");
    sent_mostra(fila);

    NoS *x = sent_busca(fila, 25); // a ficha 25 desistiu
    if (x != &fila->nil) {
        sent_remove(fila, x);
    }
    printf("Sem a 25: ");
    sent_mostra(fila);
    printf("De trás para a frente: ");
    sent_mostra_inverso(fila);

    x = sent_busca(fila, 40);
    printf("Ficha 40: %s\n", x == &fila->nil ? "não está na fila" : "na fila");
    printf("Na fila: %d\n", fila->n);

    sent_libera(fila);
    return 0;
}
// Saída:
// Fila: [ 12 25 7 ]
// Sem a 25: [ 12 7 ]
// De trás para a frente: [ 7 12 ]
// Ficha 40: não está na fila
// Na fila: 2
```

A busca da ficha 40 passa pelo 12 e pelo 7 e para na sentinela, que guarda
40. "Parou na sentinela?" separa "achou" de "não está":

{{fluxograma}}

## 0174 · Lista com sentinela

Na barbearia do bairro, quem chega pega uma ficha e espera, e às vezes
desiste no meio da fila. O barbeiro usa uma lista dupla (a do 0079), mas a
remoção tem `if` para todo lado: e se for o primeiro? O último? O único?

Os `if` existem porque o primeiro nó tem `NULL` à esquerda e o último, à
direita: cada `NULL` é um caso especial, e é neles que o bug mora.

A saída clássica é um **nó sentinela** (o Cormen chama de `L.nil`): um nó
falso, sem dado, **entre o último e o primeiro**. A lista vira **dupla e
circular**: `nil.prox` é o primeiro, `nil.ant` é o último. Não sobra `NULL`
dentro da lista.

A lista vazia é a sentinela apontando para si (`nil.prox == &nil`). **Todo nó
real tem vizinho dos dois lados**, nem que seja a sentinela, e os casos
especiais somem:

- **inserir depois de `y`**: quatro ponteiros, sempre os mesmos, com `y`
  podendo ser a sentinela (começo) ou o último (fim);
- **remover `x`**: `x->ant->prox = x->prox` e `x->prox->ant = x->ant`. Duas
  linhas, sem `if`;
- **buscar**: anda de `nil.prox` até achar a chave. Se voltar à sentinela,
  não achou.

Na busca, o Cormen **guarda a chave procurada dentro da sentinela** antes do
laço. Assim o laço sempre para (no pior caso, na sentinela) e faz um teste por
volta, `x->chave != chave`, em vez de dois.

Chegam as fichas 12, 25 e 7. A 25 desiste e sai. A busca pela 40, que não
existe, para na sentinela (o nó cinza do desenho, sem valor):

{{ideia}}

No `sentinela.h`, a sentinela fica **dentro** da struct da lista, e o `n`
conta só os nós reais. As três funções centrais do `sentinela.c`:

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

No fluxograma, a busca da ficha 40 passa pelo 12 e pelo 7 e para na
sentinela, que guarda 40. "Parou na sentinela?" separa "achou" de "não está":

{{fluxograma}}

> [!WARNING]
> A sentinela **não é um dado**. Todo laço para quando volta a ela (`x !=
> &L->nil`) e nunca começa por ela: o primeiro nó real é `L->nil.prox`.
> Nunca passe `&L->nil` para `sent_remove`: ela não veio do `malloc`, e o
> `free` derruba o programa.

> [!TIP]
> A sentinela custa um nó a mais por lista (24 bytes em 64 bits). Como ela
> está **dentro** da `ListaS`, `&L->nil` é fixo e os laços sabem onde parar.

> [!NOTE]
> **Pergunta para você:** depois de `sent_busca(fila, 40)`, qual valor fica
> guardado em `fila->nil.chave`? E se a sua lista tivesse a chave 40 de
> verdade, a busca acharia o nó certo ou pararia na sentinela?

{{pratique}}

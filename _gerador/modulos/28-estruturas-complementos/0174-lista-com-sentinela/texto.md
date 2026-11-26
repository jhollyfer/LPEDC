## 0174 · Lista com sentinela

A lista duplamente encadeada do 0079 funciona, mas a remoção dela é cheia de
`if`. Antes de mexer nos ponteiros, o código pergunta: o nó é o primeiro? É o
último? É o único? Cada pergunta existe por um motivo só: o primeiro nó tem
`NULL` à esquerda e o último tem `NULL` à direita. Quem segue `x->ant->prox`
num nó sem vizinho à esquerda tenta ler um campo de `NULL`, e o programa cai.
Esses casos especiais são o lugar preferido dos bugs em listas (TENENBAUM;
LANGSAM; AUGENSTEIN, 1995).

Pense numa mesa redonda com uma cadeira vazia reservada. Ninguém senta nela,
mas ela está ali, entre o último e o primeiro convidado. Todo convidado tem
vizinho dos dois lados, nem que seja a cadeira vazia. Na lista, essa cadeira é
o **nó sentinela**: um nó falso, sem dado, colocado entre o último e o
primeiro, que transforma a lista em **duplamente encadeada e circular**. O
Cormen o chama de `L.nil` (CORMEN et al., 2024, cap. 10).

Com a sentinela no lugar, os dois extremos da lista ficam guardados nela
mesma: `nil.prox` é o primeiro nó real e `nil.ant` é o último. A lista vazia
é a sentinela sozinha, apontando para si dos dois lados (`nil.prox == &nil` e
`nil.ant == &nil`). Repare que nenhum ponteiro dentro da lista vale `NULL`. É
isso que elimina os casos especiais (CORMEN et al., 2024, cap. 10).

```c
typedef struct NoS {
    int chave;
    struct NoS *ant, *prox;
} NoS;

typedef struct {
    NoS nil; // a sentinela mora dentro da lista, não vem do malloc
    int n;   // conta só os nós reais
} ListaS;
```

Veja a inserção de um nó `x` logo depois de um nó `y`. São sempre os mesmos
quatro ponteiros: `x` aponta para `y` e para o antigo vizinho de `y`, e esses
dois passam a apontar para `x`. Se `y` for a sentinela, o novo nó entra no
começo; se `y` for o último, entra no fim. O código é o mesmo nos dois casos,
porque `y` sempre tem vizinho à direita.

A remoção de `x` fica em duas linhas, sem nenhum `if`: o vizinho da esquerda
passa a apontar para o da direita (`x->ant->prox = x->prox`), e o da direita
passa a apontar para o da esquerda (`x->prox->ant = x->ant`). Funciona para o
primeiro, para o último e para o único, porque os dois vizinhos sempre
existem (CELES; CERQUEIRA; RANGEL, 2016).

A busca anda de `nil.prox` em diante até achar a chave. Numa lista comum o
laço testa duas coisas a cada volta: se a lista acabou e se achou a chave. O
Cormen usa um truque: antes do laço, ele **guarda a chave procurada dentro da
sentinela**. Assim o laço sempre para, no pior caso ao voltar à sentinela, e
basta um teste por volta, `x->chave != chave`. Quando o laço termina, você
olha onde parou: se foi em `&L->nil`, a chave não estava na lista (CORMEN et
al., 2024, cap. 10).

O preço é um nó a mais por lista, 24 bytes numa máquina de 64 bits (um `int`,
o alinhamento e dois ponteiros). Como a sentinela fica dentro da struct
`ListaS`, o endereço `&L->nil` não muda nunca, e todo laço sabe onde parar:
começa em `L->nil.prox` e segue enquanto `x != &L->nil`.

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

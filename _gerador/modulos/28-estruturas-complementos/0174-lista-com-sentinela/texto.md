## 0174 · Lista com sentinela

Na barbearia do bairro, quem chega pega uma ficha e espera. Às vezes alguém
desiste no meio da fila e vai embora. O barbeiro anota tudo numa lista dupla
(a do 0079): entra no fim, sai de qualquer lugar. Funciona, mas o código da
remoção tem `if` para todo lado: e se for o primeiro? E se for o último? E se
for o único?

Esses `if` existem porque as pontas da lista são diferentes do meio. O nó do
meio tem vizinho dos dois lados; o primeiro tem `NULL` à esquerda e o último
tem `NULL` à direita. Cada `NULL` é um caso especial, e é nos casos especiais
que o bug mora.

A saída clássica é um **nó sentinela** (o Cormen chama de `L.nil`): um nó
falso, sem dado, que fica **entre o último e o primeiro**. A lista
vira **dupla e circular**: `nil.prox` é o primeiro, `nil.ant` é o último, e o
último aponta de volta para a sentinela. Não existe mais `NULL` dentro da
lista.

A lista vazia é a sentinela apontando para ela mesma: `nil.prox == &nil` e
`nil.ant == &nil`. A partir daí, **todo nó real tem vizinho dos dois
lados**, nem que o vizinho seja a sentinela, e os casos especiais somem:

- **inserir depois de `y`**: quatro ponteiros, sempre os mesmos, com `y`
  podendo ser a própria sentinela (inserir no começo) ou o último (no fim);
- **remover `x`**: `x->ant->prox = x->prox` e `x->prox->ant = x->ant`. Duas
  linhas, sem `if`;
- **buscar**: anda a partir de `nil.prox` até achar a chave. Se voltar à
  sentinela, não achou.

Na busca, o Cormen usa um truque a mais: antes do laço, ele **guarda a chave
procurada dentro da sentinela**. Assim o laço sempre para (no pior caso, na
sentinela) e só precisa de um teste por volta, `x->chave != chave`, em vez de
dois.

Chegam as fichas 12, 25 e 7, nessa ordem. A ficha 25
desiste: o barbeiro busca a 25 e remove o nó. Depois alguém pergunta pela ficha
40, que não existe, e a busca para na sentinela. No desenho, a sentinela é o
nó cinza, sem valor:

{{ideia}}

O TAD é o `sentinela.h`. A sentinela fica **dentro** da struct da lista (não
é alocada à parte), e o `n` conta só os nós reais. As três funções centrais
do `sentinela.c`:

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

E a barbearia:

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

O fluxograma da busca tem uma pergunta só por volta. Para a ficha 40, o laço
passa pelo 12 e pelo 7 e para na sentinela, que estava com 40 guardado. A
última pergunta, "parou na sentinela?", separa "achou" de "não está":

{{fluxograma}}

> [!WARNING]
> A sentinela **não é um dado**. Todo laço que percorre a lista para quando
> volta a ela (`x != &L->nil`), e nunca começa por ela: o primeiro nó real
> é `L->nil.prox`.
 Se você escrever `for (x = &L->nil; ...)`, mostra um valor
> lixo (ou a última chave buscada, por causa do truque da busca). E nunca
> passe `&L->nil` para `sent_remove`: ela não foi alocada com `malloc`, e o
> `free` derruba o programa.

> [!TIP]
> **Por dentro do C:** a sentinela custa um nó a mais por lista: 24 bytes
> num sistema de 64 bits (4 da chave, 4 de enchimento, 8 de `ant`, 8 de
> `prox`). Em troca, cada operação perde os desvios dos casos especiais, e
> desvio que o processador erra de previsão custa caro. Como ela está
> **dentro** da `ListaS`, o endereço `&L->nil` é fixo enquanto a lista
> existir: é por ele que os laços sabem onde parar. No livro, uma árvore usa
> a mesma ideia (`T.nil` na rubro-negra, no 0177). Quando você tem milhares
> de listas pequenas e quase sempre vazias, como os baldes de uma tabela
> hash, o Cormen avisa: a sentinela de cada uma pode gastar memória demais.

> [!NOTE]
> **Pergunta para você:** depois de `sent_busca(fila, 40)`, qual valor fica
> guardado em `fila->nil.chave`? E se a sua lista tivesse a chave 40 de
> verdade, a busca acharia o nó certo ou pararia na sentinela?

{{pratique}}

## 0145 · Rubro-negra esquerdista (LLRB): inserção

O síndico cadastra as tags da cancela do condomínio a qualquer hora. Uma BST
degenera se as tags chegarem em ordem; a AVL resolve, mas guarda alturas e tem
quatro casos de rotação. A **rubro-negra** é mais simples.

Ela se apoia na **árvore 2-3**: um nó tem **uma chave** (2 filhos) ou **duas**
(3 filhos). Toda chave entra numa folha; com três chaves, a folha estoura: a do
meio sobe e as outras duas viram nós separados. A árvore só cresce quando a raiz
estoura, então **todas as folhas ficam no mesmo nível**.

A **rubro-negra esquerdista** (*left-leaning red-black*, LLRB) guarda a árvore
2-3 em nós binários. Um nó `[a b]` vira o `b` com o `a` pendurado à esquerda por
um **link vermelho**; os outros links são **pretos**. Cada nó guarda a cor do
link que chega nele (`bool vermelho`).

As regras da LLRB são a árvore 2-3 escrita em cores:

1. link vermelho **só à esquerda**;
2. nunca **dois vermelhos seguidos** (nó de três chaves não existe na 2-3);
3. todo caminho da raiz até um `NULL` passa pelo **mesmo número de nós pretos**
   (a **altura preta**), porque na 2-3 todas as folhas estão no mesmo nível.

A raiz é sempre preta. O caminho mais longo tem no máximo o dobro do mais curto,
e a altura fica abaixo de 2 · log₂(n + 1).

> [!NOTE]
> Esta é a de Sedgewick. A rubro-negra **clássica** do Cormen (a da
> prova do PPGI) põe a cor no **nó**, aceita vermelho dos dois lados (equivale à
> árvore 2-3-4), usa folhas `NIL` pretas e conserta a inserção pelos casos do
> **tio**, com no máximo duas rotações. Veja o assunto 0177.

A inserção pendura um nó **vermelho**, como na BST. Na volta da recursão, cada
ancestral aplica três consertos, **nesta ordem**:

| Situação em `h` | Conserto | Na árvore 2-3 |
| --- | --- | --- |
| filho direito vermelho, esquerdo preto | rotação à esquerda | deita o nó de 2 chaves para a esquerda |
| filho esquerdo e neto esquerdo vermelhos | rotação à direita | arruma um nó de 3 chaves temporário |
| os dois filhos vermelhos | inverte as cores | o nó de 3 chaves estoura e a do meio sobe |

A **inversão de cores** pinta os dois filhos de preto e `h` de vermelho: a chave
do meio sobe para o pai, onde pode disparar os consertos de novo.

No desenho, as tags 30, 10 e 20 formam um zigue-zague e disparam os três
consertos. Com as tags 50 e 40, o 20 vermelho fica colado no 40, o nó 2-3
`[20 40]`:

{{ideia}}

A inserção de `rubronegra.c`. A rotação é a da AVL, e a cor do link sobe junto:

```c
static NoRN *gira_esquerda(NoRN *h) {
    NoRN *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho; // x herda a cor do link que chegava em h
    h->vermelho = true;
    rotacoes++;
    return x;
}

static NoRN *insere(NoRN *h, int chave) {
    if (h == NULL) {
        return novo_no(chave); // todo nó novo chega vermelho
    }
    if (chave < h->chave) {
        h->esq = insere(h->esq, chave);
    } else if (chave > h->chave) {
        h->dir = insere(h->dir, chave);
    }
    // na volta, os três consertos, nesta ordem
    if (eh_vermelho(h->dir) && !eh_vermelho(h->esq)) {
        h = gira_esquerda(h);      // 1. vermelho à direita
    }
    if (eh_vermelho(h->esq) && eh_vermelho(h->esq->esq)) {
        h = gira_direita(h);       // 2. dois vermelhos seguidos
    }
    if (eh_vermelho(h->esq) && eh_vermelho(h->dir)) {
        inverte_cores(h);          // 3. dois filhos vermelhos
    }
    return h;
}

NoRN *rn_insere(NoRN *raiz, int chave) {
    raiz = insere(raiz, chave);
    raiz->vermelho = false; // a raiz é sempre preta
    return raiz;
}
```

`eh_vermelho(NULL)` devolve `false`: `NULL` conta como preto. O cliente
cadastra as tags e mostra a árvore em pré-ordem, com `*` nos vermelhos:

```c
#include <stdio.h>
#include "rubronegra.h"

int main(void) {
    int tags[] = {30, 10, 20, 50, 40};
    NoRN *raiz = NULL;

    for (int i = 0; i < 5; i++) {
        raiz = rn_insere(raiz, tags[i]);
        printf("Insere %d: pré", tags[i]);
        rn_pre_ordem(raiz);
        printf(" | rotações %d | inversões %d\n", rn_rotacoes(), rn_inversoes());
    }
    printf("Altura %d, altura preta %d\n", rn_altura(raiz), rn_altura_preta(raiz));

    raiz = rn_libera(raiz);
    return 0;
}
// Saída:
// Insere 30: pré 30 | rotações 0 | inversões 0
// Insere 10: pré 30 10* | rotações 0 | inversões 0
// Insere 20: pré 20 10 30 | rotações 2 | inversões 1
// Insere 50: pré 20 10 50 30* | rotações 3 | inversões 1
// Insere 40: pré 40 20* 10 30 50 | rotações 6 | inversões 2
// Altura 2, altura preta 2
```

O fluxograma mostra os três `if` da volta. O caminho verde é o do nó 30 quando
a tag 20 chega: o 10 já fez o primeiro conserto, e o 30 faz o segundo e o
terceiro:

{{fluxograma}}

### Passo a passo

A tag 40 desce 20, 50, 30 e vira filha direita vermelha do 30, que também é
vermelho:

| Nó na volta | O que encontra | Conserto | Como fica a subárvore |
| --- | --- | --- | --- |
| 30 | filho direito 40 vermelho | rotação à esquerda | 40* com 30* à esquerda |
| 50 | 40* e 30* seguidos à esquerda | rotação à direita | 40 com 30* e 50* |
| 40 | dois filhos vermelhos | inverte as cores | 40* com 30 e 50 pretos |
| 20 | filho direito 40 vermelho | rotação à esquerda | 40 com 20* (10, 30) e 50 |

Três rotações e uma inversão neste exemplo.

> [!WARNING]
> Na rotação, quem sobe herda a cor de quem desce (`x->vermelho = h->vermelho`);
> sem essa linha, a altura preta se desencontra. Outro erro: a raiz fica
> vermelha após uma inversão no topo, por isso `rn_insere` a pinta de preto em
> **toda** inserção.

> [!TIP]
> O `NoRN` tem 24 bytes, como o da AVL.

> [!NOTE]
> **Pergunta para você:** com as tags 10, 20, 30, 40, 50, 60 e 70, nesta ordem,
> qual fica na raiz e quantos nós vermelhos sobram? Desenhe a árvore 2-3 de cada
> passo e confira com o `rn_pre_ordem`.

{{pratique}}

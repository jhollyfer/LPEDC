## 0145 · Rubro-negra esquerdista (LLRB): inserção

O síndico cadastra as tags da cancela do condomínio a qualquer hora, e o
sistema precisa achar uma tag rápido quando o carro chega. Uma árvore
binária de busca (BST) degenera numa lista se as tags chegarem em ordem
crescente, e a busca vira O(n). A AVL resolve, mas guarda alturas em cada
nó e tem quatro casos de rotação. A **rubro-negra** chega ao mesmo
equilíbrio com regras mais curtas, e a versão esquerdista de Sedgewick é a
mais fácil de programar.

Para entendê-la, comece por outra árvore. Na **árvore 2-3**, cada nó tem
**uma chave** e 2 filhos, ou **duas chaves** e 3 filhos (SEDGEWICK; WAYNE,
2011). Toda chave nova entra numa folha. Se a folha tinha uma chave, passa a
ter duas, e acabou. Se já tinha duas, fica com três por um instante e
**estoura**: a chave do meio sobe para o pai, e as outras duas viram nós
separados. Se o pai também estourar, o processo se repete para cima. A
árvore só ganha altura quando a raiz estoura, e aí todos os caminhos crescem
juntos. Por isso **todas as folhas ficam no mesmo nível**, sempre.

A 2-3 é equilibrada, mas nós de tamanhos diferentes são chatos de programar.
A **rubro-negra esquerdista** (*left-leaning red-black*, LLRB) guarda a
mesma árvore 2-3 usando só nós binários (SEDGEWICK, 2008). Um nó de duas
chaves `[a b]` vira dois nós binários: o `b`, com o `a` pendurado à esquerda
por um **link vermelho**. Os outros links, que ligam nós de verdade da 2-3,
são **pretos**. Como cada nó tem um único pai, ele guarda a cor do link que
chega nele, num `bool vermelho` (SEDGEWICK, 2008).

As regras da LLRB são a árvore 2-3 escrita em cores. Link vermelho **só à
esquerda**, porque é assim que se escolheu desenhar o nó de duas chaves.
Nunca **dois vermelhos seguidos**, porque isso seria um nó de três chaves,
que na 2-3 não existe. E todo caminho da raiz até um `NULL` passa pelo mesmo
número de links pretos, a **altura preta**, porque na 2-3 todas as folhas
estão no mesmo nível. A raiz é sempre preta (SEDGEWICK, 2008).

Dessas regras sai a garantia de altura. O caminho mais curto possível só
tem pretos; o mais longo alterna preto e vermelho, sem dois vermelhos
juntos. Então o mais longo tem no máximo o dobro do mais curto, e a altura
fica abaixo de 2 · log₂(n + 1). Busca, inserção e remoção custam O(log n)
(CORMEN et al., 2024, cap. 13).

A inserção começa como na BST: desce comparando e pendura um nó novo, sempre
**vermelho**, porque a chave nova se junta a um nó da 2-3 que já existe. Isso
pode quebrar uma regra. Na volta da recursão, cada ancestral `h` confere três
situações e aplica o conserto de cada uma, **nesta ordem**. A tabela mostra
cada conserto e o que ele faz na árvore 2-3 por trás:

| Situação em `h` | Conserto | Na árvore 2-3 |
| --- | --- | --- |
| filho direito vermelho, esquerdo preto | rotação à esquerda | deita o nó de 2 chaves para a esquerda |
| filho esquerdo e neto esquerdo vermelhos | rotação à direita | arruma um nó de 3 chaves temporário |
| os dois filhos vermelhos | inverte as cores | o nó de 3 chaves estoura e a do meio sobe |

O último conserto merece atenção. A **inversão de cores** pinta os dois
filhos de `h` de preto e o próprio `h` de vermelho. Na 2-3, é o estouro: as
chaves dos lados viram nós separados, e a do meio, `h`, passa a fazer parte
do nó do pai. Lá em cima, esse vermelho novo pode disparar os consertos de
novo, como o estouro que sobe na 2-3.

A LLRB é a variante de Sedgewick. A **rubro-negra clássica** do Cormen, que
é a cobrada na prova do PPGI, põe a cor no **nó**, aceita filho vermelho dos
dois lados (o que equivale a uma árvore 2-3-4), usa folhas `NIL` pretas e
conserta a inserção pelos casos do **tio**, com no máximo duas rotações. O
assunto 0177 trata dela (CORMEN et al., 2024, cap. 13).

> [!WARNING]
> Na rotação, quem sobe herda a cor de quem desce (`x->vermelho = h->vermelho`);
> sem isso, a altura preta se desencontra. E a raiz pode ficar vermelha após
> uma inversão no topo: `rn_insere` a pinta de preto em **toda** inserção.

{{exemplo}}

As tags da cancela de um condomínio: 30, 10 e 20 formam um zigue-zague e
disparam os três consertos. Com 50 e 40, o 20 vermelho fica colado no 40, o nó
2-3 `[20 40]`:

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
a tag 20 chega: ele faz o segundo e o terceiro conserto:

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

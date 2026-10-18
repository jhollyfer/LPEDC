## 0145 · Rubro-negra esquerdista (LLRB): inserção

A cancela do condomínio abre pela tag do carro. O síndico cadastra tags novas a
qualquer hora (morador novo, carro trocado, visita frequente), e a consulta tem
que ser instantânea quando o carro encosta. Uma BST comum degenera se as tags
chegarem em ordem. A AVL resolve, mas guarda a altura em cada nó e tem quatro
casos de rotação para lembrar. Existe uma árvore equilibrada mais enxuta: a
**rubro-negra**, a que mais aparece em sistemas reais (o escalonador de
processos do Linux usa uma).

A ideia por trás dela é outra árvore, a **árvore 2-3**. Nela, um nó guarda **uma
chave** (e tem 2 filhos) ou **duas chaves** (e tem 3 filhos). Toda chave nova
entra numa folha; se a folha ficar com três chaves, ela estoura: a do meio sobe
para o pai e as outras duas viram nós separados. Como a árvore só cresce quando
a raiz estoura, **todas as folhas ficam sempre no mesmo nível**. Equilíbrio
perfeito, mas nós de dois tamanhos são chatos de programar.

A **rubro-negra esquerdista** (em inglês, *left-leaning red-black*, LLRB) guarda
a árvore 2-3 em nós binários comuns. Um nó de duas chaves `[a b]` vira o `b`
com o `a` pendurado à esquerda por um **link vermelho**. Os outros links são
**pretos**. Cada nó guarda a cor do link que chega nele: um `bool vermelho`, um
bit de informação.

As regras da LLRB são a árvore 2-3 escrita em cores:

1. link vermelho **só à esquerda**;
2. nunca **dois vermelhos seguidos** (um nó de três chaves não existe na 2-3);
3. todo caminho da raiz até um `NULL` passa pelo **mesmo número de nós pretos**
   (a **altura preta**), porque na 2-3 todas as folhas estão no mesmo nível.

A raiz é sempre preta. Com essas regras, o caminho mais longo é no máximo o
dobro do mais curto (preto, vermelho, preto, vermelho...), e a altura fica
abaixo de 2 · log₂(n + 1).

A inserção começa como na BST e pendura um nó **vermelho** (a chave nova se
cola num nó 2-3 que já existe). Isso pode quebrar uma regra. Na volta da
recursão, cada ancestral aplica três consertos, **nesta ordem**:

| Situação em `h` | Conserto | Na árvore 2-3 |
| --- | --- | --- |
| filho direito vermelho, esquerdo preto | rotação à esquerda | deita o nó de 2 chaves para a esquerda |
| filho esquerdo e neto esquerdo vermelhos | rotação à direita | arruma um nó de 3 chaves temporário |
| os dois filhos vermelhos | inverte as cores | o nó de 3 chaves estoura e a do meio sobe |

A **inversão de cores** pinta os dois filhos de preto e `h` de vermelho: o
vermelho que sobe é a chave do meio indo para o pai. Lá em cima, ele pode
disparar os consertos de novo, como a divisão que sobe na 2-3.

Vamos ver na prática. O síndico cadastra as tags 30, 10 e 20. A 20 entra à
direita do 10 e forma um zigue-zague: os três consertos acontecem um atrás do
outro. Depois, com as tags 50 e 40, a árvore fica com o 20 vermelho colado no
40, que é exatamente o nó 2-3 `[20 40]`:

{{ideia}}

A inserção do `rubronegra.c`. A rotação é a mesma da AVL, com uma novidade: a
cor do link vai junto com quem sobe:

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

`eh_vermelho(NULL)` devolve `false`: o `NULL` conta como preto. O cliente
cadastra as tags e mostra a árvore em pré-ordem, com `*` nos nós vermelhos:

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

Repara no fluxograma: são os três `if` da volta, em sequência, e não um
`else if`. O caminho verde é o do nó 30 quando a tag 20 chega: o primeiro
conserto já foi feito lá embaixo, no 10; no 30 entram o segundo e o terceiro:

{{fluxograma}}

### Passo a passo

A tag 40 mostra o vermelho subindo. Ela desce 20, 50, 30 e vira filha direita
(vermelha) do 30, que também é vermelho:

| Nó na volta | O que encontra | Conserto | Como fica a subárvore |
| --- | --- | --- | --- |
| 30 | filho direito 40 vermelho | rotação à esquerda | 40* com 30* à esquerda |
| 50 | 40* e 30* seguidos à esquerda | rotação à direita | 40 com 30* e 50* |
| 40 | dois filhos vermelhos | inverte as cores | 40* com 30 e 50 pretos |
| 20 | filho direito 40 vermelho | rotação à esquerda | 40 com 20* (10, 30) e 50 |

Três rotações e uma inversão para uma inserção: é o pior caso deste exemplo. Na
média, a LLRB faz bem menos trabalho, e a árvore 2-3 por trás dela continua com
todas as folhas no mesmo nível.

> [!WARNING]
> A cor é do **link**, não do nó em si. Na rotação, quem sobe ocupa o lugar de
> quem desce e tem que herdar a cor dele (`x->vermelho = h->vermelho`). Sem
> essa linha, um nó vermelho vira raiz de subárvore no lugar de um preto, a
> altura preta se desencontra e a árvore volta a crescer torta (é o bug do
> E869). O outro esquecimento clássico é a raiz: depois de uma inversão de
> cores no topo, ela fica vermelha. Por isso `rn_insere` pinta a raiz de preto
> no fim de **toda** inserção.

> [!TIP]
> **Por dentro do C:** um `bool` ocupa 1 byte, mas o `NoRN` tem 24 bytes, os
> mesmos da AVL: 4 da chave, 1 da cor, 3 de enchimento e dois ponteiros de 8.
> A cor só precisa de 1 bit, e o kernel do Linux aproveita isso: como todo nó
> começa num endereço múltiplo de 4, os dois bits mais baixos de um ponteiro
> para nó são sempre 0, e ele guarda a cor no bit mais baixo do ponteiro para o
> pai. Em C dá para fazer isso convertendo o ponteiro para `uintptr_t`, mas é
> um truque de sistema operacional, não de curso. A grande vantagem prática é
> outra: a inserção faz no máximo um punhado de trocas de ponteiros por nível
> e não recalcula alturas.

> [!NOTE]
> **Pergunta para você:** se o síndico cadastrar as tags 10, 20, 30, 40, 50, 60
> e 70, nesta ordem, qual tag fica na raiz e quantos nós vermelhos sobram no
> fim? Desenhe a árvore 2-3 de cada passo e confira com o `rn_pre_ordem`.

{{pratique}}

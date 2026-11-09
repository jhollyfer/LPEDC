## 0176 · AVL: remoção

A lanchonete do bairro guarda os pedidos em preparo numa AVL, pelo número do
pedido: o painel da cozinha consulta, insere e mostra em ordem, sempre em
O(log n). No 0101 você viu a AVL crescer. Só que pedido também **sai**: o
motoboy levou o 30, e o nó tem que sumir da árvore sem que ela perca o
equilíbrio.

A remoção começa igual à da BST (0100), em três casos:

- o nó é **folha**: some;
- tem **um filho**: o filho ocupa o lugar dele;
- tem **dois filhos**: a chave do **sucessor** (o menor da subárvore direita,
  o do 0175) é copiada para o nó, e o sucessor é removido lá embaixo, onde
  ele tem no máximo um filho.

Tirar um nó **encurta** um caminho, e algum ancestral pode ficar com fator 2
ou -2. O conserto é o mesmo da inserção: na **volta da recursão**, cada
ancestral recalcula a altura, confere o fator e, se precisar, faz a rotação
simples ou a dupla. As rotações são as do 0101.

Duas coisas mudam, e a prova cobra as duas:

1. O filho do lado pesado pode ter **fator 0**. Na inserção isso nunca
   acontece. Na remoção acontece, e a regra é: fator 0 ou do mesmo sinal,
   **rotação simples**; sinal contrário, **dupla**. Com fator 0, a subárvore
   mantém a altura depois da rotação, e o conserto para ali.
2. A rotação pode **não devolver a altura antiga**. Na inserção, uma rotação
   devolve a subárvore à altura de antes, e o resto da árvore não percebe. Na
   remoção, a subárvore consertada pode ficar um nível mais baixa, e o
   desequilíbrio **sobe** para o avô. Por isso uma remoção pode fazer
   **várias rotações**, até a raiz: no pior caso, uma a cada dois níveis,
   O(log n) rotações.

A cozinha tem 16 pedidos, numa árvore de altura 4. O pedido 30 sai.
O 28 fica pesado à esquerda, com o filho 25 pendendo para a direita: rotação
dupla, o 26 sobe. A subárvore do 28 cai de altura 2 para 1, e agora quem
desequilibra é a raiz, o 20: rotação simples, e o 12 vira a raiz. No desenho,
a árvore antes, o conserto no 28 e a árvore no fim:

{{ideia}}

O TAD é o `avlrem.h`. A remoção do `avlrem.c`, com o `rebalanceia` que serve
para as duas operações:

```c
static NoA *rebalanceia(NoA *r) {
    atualiza(r);
    int fb = avr_fator(r);
    if (fb > 1) {
        if (avr_fator(r->esq) < 0) { // só -1 pede a dupla; 0 e 1, a simples
            r->esq = rot_esquerda(r->esq);
        }
        return rot_direita(r);
    }
    if (fb < -1) {
        if (avr_fator(r->dir) > 0) {
            r->dir = rot_direita(r->dir);
        }
        return rot_esquerda(r);
    }
    return r;
}

NoA *avr_remove(NoA *r, int chave) {
    if (r == NULL) {
        return NULL; // não estava na árvore
    }
    if (chave < r->chave) {
        r->esq = avr_remove(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = avr_remove(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        NoA *filho = r->esq != NULL ? r->esq : r->dir; // 0 ou 1 filho
        free(r);
        return filho; // o filho (já AVL) ocupa o lugar; o pai confere
    } else {
        NoA *s = r->dir; // 2 filhos: copia o sucessor e remove ele
        while (s->esq != NULL) {
            s = s->esq;
        }
        r->chave = s->chave;
        r->dir = avr_remove(r->dir, s->chave);
    }
    return rebalanceia(r); // na volta, cada ancestral se confere
}
```

E o painel da cozinha:

```c
#include <stdio.h>
#include "avlrem.h"

int main(void) {
    int pedidos[] = {20, 12, 28, 6, 16, 25, 30, 3, 9, 14, 18, 26, 1, 4, 10, 8};
    NoA *raiz = NULL;
    for (int i = 0; i < 16; i++) {
        raiz = avr_insere(raiz, pedidos[i]);
    }
    printf("Antes:  pré");
    avr_pre_ordem(raiz);
    printf(" | altura %d\n", avr_altura(raiz));

    int antes = avr_rotacoes();
    raiz = avr_remove(raiz, 30); // o pedido 30 foi entregue
    printf("Depois: pré");
    avr_pre_ordem(raiz);
    printf(" | altura %d\n", avr_altura(raiz));
    printf("Rotações nesta remoção: %d | fator da raiz: %d\n",
           avr_rotacoes() - antes, avr_fator(raiz));

    raiz = avr_libera(raiz);
    return 0;
}
// Saída:
// Antes:  pré 20 12 6 3 1 4 9 8 10 16 14 18 28 25 26 30 | altura 4
// Depois: pré 12 6 3 1 4 9 8 10 20 16 14 18 26 25 28 | altura 3
// Rotações nesta remoção: 3 | fator da raiz: 0
```

São 3 rotações simples: a dupla no 28 conta 2, a simples no 20 conta 1.

O fluxograma mostra o `rebalanceia` no 28, logo depois de o 30 sair. O
fator é 2 (pesado à esquerda), o filho 25 tem fator -1 (pende para dentro), e
o caminho verde passa pelas duas rotações. No 20, o mesmo fluxograma pega o
outro ramo: filho 12 com fator 1, só a rotação à direita:

{{fluxograma}}

### Passo a passo

O 30 é folha: a chamada que chegou nele devolve `NULL` para o 28. Daí para
cima, cada nó da volta confere a si mesmo:

| Nó na volta | Altura esq / dir | Fator | Filho pesado | Conserto | Altura da subárvore |
| --- | --- | --- | --- | --- | --- |
| 28 | 1 / -1 | 2 | 25, fator -1 | dupla: esquerda no 25, direita no 28 | era 2, fica 1 (o 26 sobe) |
| 20 | 3 / 1 | 2 | 12, fator 1 | simples: direita no 20 | era 4, fica 3 (o 12 sobe) |

Na última coluna, o conserto no 28 **encurtou** a subárvore, e isso levou o
desequilíbrio para o 20. Se o 28 tivesse voltado à altura 2, a
remoção pararia ali. O 20 desce para a direita do 12 e leva junto o 16 (que
era filho direito do 12) como filho esquerdo.

> [!WARNING]
> A pegadinha é a condição da rotação dupla. Copiar da inserção um teste como
> `if (avr_fator(r->esq) <= 0)` (menor **ou igual**) faz a dupla quando o
> filho tem fator 0, e a árvore sai desequilibrada (é o bug do E1055). Só o
> fator **de sinal contrário** pede a dupla. O outro esquecimento é parar
> cedo: na remoção, não existe "fiz uma rotação, acabou". Todo ancestral, até
> a raiz, tem que passar pelo `rebalanceia`, e a recursão garante isso.

> [!TIP]
> **Por dentro do C:** a remoção recursiva empilha uma chamada por nível,
> cerca de 1,44 · log₂ n quadros no pior caso da AVL: para um milhão de chaves,
> menos de 30 quadros, nada perto de estourar a pilha. No caso dos dois
> filhos,
 o código **copia a chave** do sucessor e libera o nó
> dele, em vez de religar ponteiros: é mais simples, mas qualquer ponteiro
> que alguém guardava para o nó do sucessor fica apontando para memória
> liberada. Se o seu programa guarda `NoA *` fora da árvore, troque a cópia
> por uma religação dos nós.

> [!NOTE]
> **Pergunta para você:** na árvore do fim (raiz 12), o pedido 1 sai. Quantas
> rotações acontecem e qual é a nova raiz? E se, em seguida, sair o 3?
> Desenhe as alturas antes de rodar.

{{pratique}}

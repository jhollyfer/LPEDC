## 0176 · AVL: remoção

A lanchonete guarda os pedidos em preparo numa AVL, pelo número. Mas pedido
também **sai**: o motoboy levou o 30, e o nó precisa sumir sem a árvore perder
o equilíbrio.

A remoção começa como a da BST (0100), em três casos:

- **folha**: some;
- **um filho**: o filho ocupa o lugar;
- **dois filhos**: a chave do **sucessor** (0175) é copiada para o nó, e o
  sucessor é removido lá embaixo, onde tem no máximo um filho.

Tirar um nó **encurta** um caminho, e um ancestral pode ficar com fator 2 ou
-2. Como na inserção, na **volta da recursão** cada ancestral recalcula a
altura, confere o fator e, se preciso, faz a rotação do 0101. Duas coisas
mudam, e a prova cobra as duas:

1. O filho do lado pesado pode ter **fator 0**, o que na inserção nunca
   ocorre. Fator 0 ou do mesmo sinal: **rotação simples**; sinal contrário:
   **dupla**. Com fator 0, a subárvore mantém a altura e o conserto para.
2. A rotação pode **não devolver a altura antiga**: a subárvore fica um nível
   mais baixa, e o desequilíbrio **sobe** para o avô. Por isso uma remoção
   pode fazer **várias rotações**, até a raiz: O(log n) no pior caso.

A cozinha tem 16 pedidos (altura 4), e o 30 sai. O 28 fica pesado à esquerda,
com o filho 25 pendendo para a direita: rotação dupla, e o 26 sobe. A
subárvore do 28 cai de altura 2 para 1, e a raiz 20 desequilibra: rotação
simples, e o 12 vira a raiz. No desenho, a árvore antes, o conserto no 28 e o
fim:

{{ideia}}

A remoção do `avlrem.c`, com o `rebalanceia` das duas operações:

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

O painel da cozinha:

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

O fluxograma mostra o `rebalanceia` no 28 (fator 2, filho 25 com fator -1:
duas rotações). No 20, pega o outro ramo: filho 12 com fator 1, só a rotação
à direita:

{{fluxograma}}

### Passo a passo

O 30 é folha e devolve `NULL` ao 28. Daí para cima, cada nó confere a si
mesmo:

| Nó na volta | Altura esq / dir | Fator | Filho pesado | Conserto | Altura da subárvore |
| --- | --- | --- | --- | --- | --- |
| 28 | 1 / -1 | 2 | 25, fator -1 | dupla: esquerda no 25, direita no 28 | era 2, fica 1 (o 26 sobe) |
| 20 | 3 / 1 | 2 | 12, fator 1 | simples: direita no 20 | era 4, fica 3 (o 12 sobe) |

O conserto no 28 **encurtou** a subárvore e levou o desequilíbrio ao 20. Se o
28 tivesse voltado à altura 2, a remoção pararia ali.

> [!WARNING]
> Copiar da inserção o teste `if (avr_fator(r->esq) <= 0)` (menor **ou
> igual**) faz a dupla com fator 0, e a árvore sai desequilibrada. Só o fator
> **de sinal contrário** pede a dupla. Na remoção também não existe "fiz uma
> rotação, acabou": todo ancestral passa pelo `rebalanceia`.

> [!TIP]
> Com dois filhos, o código **copia a chave** do sucessor e libera o nó dele:
> um `NoA *` guardado fora da árvore para o sucessor fica pendurado.

> [!NOTE]
> **Pergunta para você:** na árvore do fim (raiz 12), o pedido 1 sai. Quantas
> rotações acontecem e qual é a nova raiz? E se, em seguida, sair o 3?

{{pratique}}

## 0176 · AVL: remoção

- **Remoção na AVL**: começa como a da BST (0100). Folha some; com um filho,
  o filho ocupa o lugar; com dois, a chave do **sucessor** é copiada e o
  sucessor é removido lá embaixo (SZWARCFITER; MARKENZON, 2010).
- **Conserto na volta**: tirar um nó encurta um caminho. Na volta da
  recursão, cada ancestral recalcula a altura, confere o fator e, se passar
  de 1 ou -1, faz a rotação do 0101 (ADELSON-VELSKY; LANDIS, 1962).
- **Filho com fator 0**: na remoção, o filho do lado pesado pode ter fator 0,
  o que nunca ocorre na inserção. Fator 0 ou de mesmo sinal: **rotação
  simples**; sinal contrário: **dupla** (SZWARCFITER; MARKENZON, 2010).
- **Várias rotações**: a rotação pode deixar a subárvore um nível mais baixa,
  e o desequilíbrio sobe para o avô. Uma remoção pode rodar até a raiz:
  O(log n) rotações no pior caso (ZIVIANI, 2010).
- **Cópia da chave**: com dois filhos, o código copia a chave do sucessor e
  libera o nó dele; um ponteiro guardado para esse nó fica pendurado.

> [!WARNING]
> Copiar da inserção o teste `avr_fator(r->esq) <= 0` faz a dupla com fator 0
> e deixa a árvore torta. Só o sinal **contrário** pede a dupla. E não existe
> "fiz uma rotação, acabou": todo ancestral passa pelo `rebalanceia`.

{{exemplo}}

Uma lanchonete guarda 16 pedidos numa AVL de altura 4, e o 30 sai. O 28 fica
pesado à esquerda com o filho 25 pendendo para a direita: rotação dupla. A
subárvore cai de altura e a raiz 20 desequilibra: rotação simples, e o 12 vira
a raiz:

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

São 3 rotações simples: a dupla no 28 conta 2, a simples no 20 conta 1. O
fluxograma mostra o `rebalanceia` no 28 (fator 2, filho com fator -1) e, no 20,
o outro ramo (filho com fator 1, só a rotação à direita):

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

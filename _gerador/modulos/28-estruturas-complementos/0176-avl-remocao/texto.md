## 0176 · AVL: remoção

A AVL do 0101 sabe receber chaves sem perder o equilíbrio. Só que dado também
sai: o pedido entregue deixa a fila da cozinha, o cliente cancela a conta. Se
a remoção for a da BST comum, um lado da árvore pode encolher até o fator de
algum nó chegar a 2 ou -2, e a garantia de altura O(log n) se perde. Este
assunto mostra como tirar um nó e consertar a árvore no caminho de volta.

A primeira parte é igual à remoção da BST do 0100, com três casos. Se o nó é
folha, ele some. Se tem um filho só, esse filho ocupa o lugar dele, e a
subárvore do filho já é AVL. Se tem dois filhos, o nó não pode sumir sem
deixar dois órfãos; então você copia para ele a chave do **sucessor** (o
mínimo da subárvore direita, visto no 0175) e remove o sucessor lá embaixo,
onde ele tem no máximo um filho (SZWARCFITER; MARKENZON, 2010).

Tirar um nó **encurta** um caminho da árvore. Os ancestrais do nó removido
podem ter perdido um nível de um lado, e o fator deles muda. O conserto segue
a ideia da inserção: na **volta da recursão**, cada ancestral recalcula a
própria altura, confere o fator e, se ele passou de 1 ou de -1, faz uma das
rotações do 0101 (ADELSON-VELSKY; LANDIS, 1962). Como a remoção é recursiva,
a volta passa por todos os ancestrais, um por um, até a raiz.

Duas coisas mudam em relação à inserção, e a prova cobra as duas. A primeira é
o fator do filho do lado pesado. Na inserção, o nó novo acabou de entrar por
um lado, e esse filho sempre pende para algum lado: fator 1 ou -1. Na
remoção, o lado pesado não recebeu nada; ele só ficou mais alto que o outro,
e o filho dele pode estar equilibrado, com **fator 0** (SZWARCFITER;
MARKENZON, 2010).

A regra para escolher a rotação fica assim. Se o filho do lado pesado tem
fator 0 ou o mesmo sinal do pai, basta uma **rotação simples**. Se tem sinal
contrário, o peso está "no meio", e só a **rotação dupla** resolve. Exemplo:
um nó com fator 2 (esquerda pesada) e filho esquerdo com fator 0 pede uma
rotação simples à direita; com filho esquerdo de fator -1, pede a dupla
(esquerda no filho, depois direita no nó). No caso do fator 0, a subárvore
mantém a altura de antes depois da rotação, e o conserto para ali.

A segunda diferença é o que acontece depois da rotação. Na inserção, uma
rotação devolve a subárvore à altura que ela tinha antes, e o resto da árvore
nem percebe. Na remoção, a rotação pode deixar a subárvore **um nível mais
baixa** que antes. Para o avô, é como se outra remoção tivesse acontecido, e
o desequilíbrio sobe. Por isso uma remoção pode fazer **várias rotações**, uma
em cada nível, até a raiz: O(log n) rotações no pior caso (ZIVIANI, 2010). O
custo total continua O(log n), porque cada rotação mexe em poucos ponteiros.

Um último detalhe vem do caso de dois filhos. O código não move o nó do
sucessor para cima: ele copia a chave e libera o nó do sucessor lá embaixo.
Se outra parte do programa guardava um ponteiro para o nó do sucessor, esse
ponteiro passa a apontar para memória liberada, e usá-lo é comportamento
indefinido.

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

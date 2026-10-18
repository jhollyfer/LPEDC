## 0101 · AVL: balanceamento e rotações

A lanchonete numera os pedidos: 10, 20, 30, 40... Eles chegam **sempre em ordem
crescente**. Se você guardar os pedidos numa BST comum, cada pedido novo vira
filho direito do anterior, e a árvore vira uma lista com altura n - 1. Com mil
pedidos, achar o último custa mil comparações. A BST é ótima até receber dados
ordenados, que é justamente o que mais acontece na vida real.

A saída é uma BST que se **conserta sozinha** a cada inserção. A mais antiga
delas é a **AVL** (das iniciais de Adelson-Velsky e Landis, que a publicaram em
1962). A regra: em **todo** nó, as alturas das duas subárvores diferem de no
máximo 1.

Para conferir a regra, cada nó guarda a própria altura e calcula o **fator de
balanceamento**: `fb = altura(esq) - altura(dir)`. Na AVL, todo nó tem fator
-1, 0 ou 1. Fator 2 quer dizer "pesado à esquerda"; -2, "pesado à direita".

Com essa regra, a altura de uma AVL nunca passa de uns 1,44 · log₂ n. Mil
pedidos cabem em altura 9, e não 999.

A inserção começa igual à da BST: desce e pendura uma folha. A diferença está
na **volta** da recursão. Cada ancestral do nó novo, de baixo para cima,
atualiza a altura e confere o fator. Se achar um 2 ou um -2, conserta ali mesmo
com uma **rotação**.

Uma **rotação** é uma troca de dois ponteiros que faz um filho subir e o pai
descer, **sem quebrar a ordem da BST**. Na rotação à esquerda no nó `r`, o filho
direito `d` sobe, `r` vira filho esquerdo de `d`, e a antiga subárvore esquerda
de `d` (chaves entre `r` e `d`) passa a ser a direita de `r`. A em ordem
continua igual; só a forma muda.

Qual rotação usar depende de onde o peso está:

| Caso | Fator do nó | Fator do filho pesado | Conserto |
| --- | --- | --- | --- |
| esquerda-esquerda | +2 | +1 ou 0 (esquerdo) | rotação à direita no nó |
| direita-direita | -2 | -1 ou 0 (direito) | rotação à esquerda no nó |
| esquerda-direita | +2 | -1 (esquerdo) | à esquerda no filho, depois à direita no nó |
| direita-esquerda | -2 | +1 (direito) | à direita no filho, depois à esquerda no nó |

Os dois últimos são a **rotação dupla**: o caminho até o nó novo faz um
"zigue-zague", e uma rotação só não resolve. A primeira rotação endireita o
zigue-zague; a segunda equilibra.

Vamos ver na prática. Inserir 10, 20 e 30 deixa o 10 com fator -2 e o filho com
-1: direita-direita, uma rotação à esquerda no 10 e o 20 sobe. Mais adiante,
com a árvore 20 (10, 40 (30, 50)), inserir o 25 deixa o 20 com -2 e o filho 40
com +1: zigue-zague, rotação dupla. O 30 acaba na raiz:

{{ideia}}

As rotações e o rebalanceamento, no `avl.c`:

```c
static No *rot_esquerda(No *r) {
    No *d = r->dir;
    r->dir = d->esq; // a subárvore do meio muda de pai
    d->esq = r;
    atualiza(r);     // r agora está embaixo: primeiro ele
    atualiza(d);
    return d;        // d é a nova raiz desta subárvore
}

static No *rebalanceia(No *r) {
    atualiza(r);
    int fb = avl_fator(r);
    if (fb > 1) {                    // pesado à esquerda
        if (avl_fator(r->esq) < 0) { // zigue-zague: dupla
            r->esq = rot_esquerda(r->esq);
        }
        return rot_direita(r);
    }
    if (fb < -1) {                   // pesado à direita
        if (avl_fator(r->dir) > 0) { // zigue-zague: dupla
            r->dir = rot_direita(r->dir);
        }
        return rot_esquerda(r);
    }
    return r;
}
```

A `avl_insere` é a `bst_insere` com uma linha trocada: em vez de `return r`, ela
termina com `return rebalanceia(r)`. O cliente insere os pedidos e acompanha a
forma da árvore pela pré-ordem:

```c
#include <stdio.h>
#include "avl.h"

int main(void) {
    int pedidos[] = {10, 20, 30, 40, 50, 25};
    No *raiz = NULL;

    for (int i = 0; i < 6; i++) {
        raiz = avl_insere(raiz, pedidos[i]);
        printf("Insere %d: pré", pedidos[i]);
        avl_pre_ordem(raiz);
        printf(" | altura %d | rotações %d\n", avl_altura(raiz), avl_rotacoes());
    }

    raiz = avl_libera(raiz);
    return 0;
}
// Saída:
// Insere 10: pré 10 | altura 0 | rotações 0
// Insere 20: pré 10 20 | altura 1 | rotações 0
// Insere 30: pré 20 10 30 | altura 1 | rotações 1
// Insere 40: pré 20 10 30 40 | altura 2 | rotações 1
// Insere 50: pré 20 10 40 30 50 | altura 2 | rotações 2
// Insere 25: pré 30 20 10 25 40 50 | altura 2 | rotações 4
```

Repara no fluxograma: é o que cada ancestral faz na volta. O caminho verde é o
do nó 20 quando o 25 chega: fator -2, filho direito com fator +1, então duas
rotações:

{{fluxograma}}

### Passo a passo

| Insere | Quem fica desequilibrado | Caso | Rotação | Raiz depois |
| --- | --- | --- | --- | --- |
| 10, 20 | ninguém | | | 10 |
| 30 | 10 (fb -2; filho 20 com -1) | direita-direita | esquerda no 10 | 20 |
| 40 | ninguém (20 fica com -1) | | | 20 |
| 50 | 30 (fb -2; filho 40 com -1) | direita-direita | esquerda no 30 | 20 |
| 25 | 20 (fb -2; filho 40 com +1) | direita-esquerda | direita no 40, esquerda no 20 | 30 |

Sem a AVL, a mesma sequência daria uma BST de altura 4 (10, 20, 30, 40, 50 em
fila, com o 25 pendurado no 30).

> [!WARNING]
> No zigue-zague, a rotação simples **não conserta**: ela só espelha o
> problema. Na árvore 20 (10, 40 (30 (25), 50)), girar à esquerda no 20 faz o 40
> subir com fator +2 do outro lado. Por isso o código olha o fator do **filho**
> antes de girar. Outro erro comum: girar e não ligar o resultado de volta no
> pai. A rotação devolve a nova raiz da subárvore; sem `r->dir = rot_direita(r->dir)`
> ou `return rot_esquerda(r)`, o pai continua apontando para o nó que desceu.

> [!TIP]
> **Por dentro do C:** a AVL guarda um `int altura` a mais em cada nó, e mesmo
> assim o nó continua com 24 bytes: os 4 bytes de enchimento que a BST
> desperdiçava entre o `int chave` e os ponteiros agora guardam a altura. Uma
> rotação mexe em 3 ponteiros e 2 alturas, custo O(1). Cada inserção faz no
> máximo uma rotação (simples ou dupla) e sobe O(log n) níveis atualizando
> alturas. O exemplo A202 insere mil pedidos em ordem: a BST comum fica com
> altura 999, a AVL com 9.

> [!NOTE]
> **Pergunta para você:** insira 1, 2, 3, 4, 5, 6 e 7, nesta ordem, numa AVL
> vazia. Quantas rotações acontecem e qual é a árvore final? Desenhe antes de
> conferir no exercício E602.

{{pratique}}

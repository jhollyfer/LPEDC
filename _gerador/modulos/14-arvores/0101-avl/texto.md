## 0101 · AVL: balanceamento e rotações

- **AVL**: BST que se conserta a cada inserção. Em **todo** nó, as alturas
  das duas subárvores diferem de no máximo 1 (ADELSON-VELSKY; LANDIS, 1962).
- **Fator de balanceamento**: `fb = altura(esq) - altura(dir)`. Na AVL vale
  -1, 0 ou 1; 2 é "pesado à esquerda" e -2, "pesado à direita". Há livros que
  invertem a conta: o sinal troca, a regra não
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Altura garantida**: no máximo uns 1,44 · log₂ n. Mil chaves cabem em
  altura 9, e não 999 (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Inserção**: pendura a folha como na BST. Na **volta** da recursão, cada
  ancestral atualiza a altura e confere o fator (CORMEN et al., 2024).
- **Rotação**: um filho sobe e o pai desce, sem quebrar a ordem da BST. Na
  rotação à esquerda em `r`, o filho direito `d` sobe e a antiga subárvore
  esquerda de `d` vira a direita de `r`. Custa O(1) (CORMEN et al., 2024,
  cap. 13).
- **Rotação dupla**: para o "zigue-zague". A primeira rotação, no filho,
  endireita; a segunda, no nó, equilibra. Cada inserção faz no máximo uma
  rotação, simples ou dupla (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Outras árvores equilibradas**: a **rubro-negra** (0177) e a **árvore B**
  (0146) também garantem O(log n) (CORMEN et al., 2024, caps. 13 e 18).

| Caso | Fator do nó | Fator do filho pesado | Conserto |
| --- | --- | --- | --- |
| esquerda-esquerda | +2 | +1 ou 0 (esquerdo) | rotação à direita no nó |
| direita-direita | -2 | -1 ou 0 (direito) | rotação à esquerda no nó |
| esquerda-direita | +2 | -1 (esquerdo) | à esquerda no filho, depois à direita no nó |
| direita-esquerda | -2 | +1 (direito) | à direita no filho, depois à esquerda no nó |

> [!WARNING]
> No zigue-zague, a rotação simples **não conserta**: só espelha o problema.
> Por isso o código olha o fator do **filho**. E ligue a nova raiz de volta no
> pai (`return rot_esquerda(r)`); senão o pai aponta para o nó que desceu.

{{exemplo}}

A lanchonete numera os pedidos em ordem crescente, e a BST comum viraria uma
lista. Na AVL, inserir 10, 20 e 30 gira o 10 à esquerda e o 20 sobe. Depois,
com 20 (10, 40 (30, 50)), o 25 pede rotação dupla e o 30 vai para a raiz:

{{ideia}}

Rotações e rebalanceamento, no `avl.c`:

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

A `avl_insere` é a `bst_insere` terminando em `return rebalanceia(r)`. O
cliente insere os pedidos e mostra a pré-ordem:

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

O caminho verde é o do nó 20 quando o 25 chega: fator -2, filho direito com
fator +1, então duas rotações:

{{fluxograma}}

### Passo a passo

| Insere | Quem fica desequilibrado | Caso | Rotação | Raiz depois |
| --- | --- | --- | --- | --- |
| 10, 20 | ninguém | | | 10 |
| 30 | 10 (fb -2; filho 20 com -1) | direita-direita | esquerda no 10 | 20 |
| 40 | ninguém (20 fica com -1) | | | 20 |
| 50 | 30 (fb -2; filho 40 com -1) | direita-direita | esquerda no 30 | 20 |
| 25 | 20 (fb -2; filho 40 com +1) | direita-esquerda | direita no 40, esquerda no 20 | 30 |

Sem a AVL, a sequência daria uma BST de altura 4.

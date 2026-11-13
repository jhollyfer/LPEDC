## 0175 · Conceitos e sucessor

- **Grau**: quantos filhos o nó tem; grau 0 é **folha**. O grau da árvore é o
  maior grau entre os nós (SZWARCFITER; MARKENZON, 2010).
- **Profundidade** e **nível**: arestas do nó até a raiz, que tem
  profundidade 0. Alguns livros contam o nível a partir de 1: confira o
  enunciado (CORMEN et al., 2024, cap. 12).
- **Altura**: o maior número de arestas do nó até uma folha abaixo. Folha tem
  altura 0 e árvore vazia, -1 (CORMEN et al., 2024, cap. 12).
- **Fator de balanceamento**: `altura(esq) - altura(dir)`, que a AVL mantém
  em -1, 0 ou 1 (ADELSON-VELSKY; LANDIS, 1962).
- **Sucessor** de `x`: a menor chave maior que `x`. Com subárvore direita, é o
  **mínimo** dela; sem ela, sobe enquanto vier de um filho direito, e o
  primeiro ancestral alcançado por um filho esquerdo é a resposta
  (CORMEN et al., 2024, cap. 12).
- **Ponteiro `pai`** (`x.p` no Cormen): permite a subida, sem pilha nem
  recursão; custa 8 bytes por nó. O **antecessor** é o espelho, e os dois
  custam O(h) (CORMEN et al., 2024, cap. 12).

> [!WARNING]
> Trocar o lado na subida (`x == y->esq` no lugar de `x == y->dir`) dá um
> "sucessor" **menor** que `x`. Toda inserção, remoção ou rotação também tem
> que acertar o `pai` (o da raiz fica `NULL`).

{{exemplo}}

Os horários de ônibus de uma rodoviária entram numa BST na ordem 8h00, 6h15,
10h30, 7h00, 6h50, 9h20, 12h00, 7h30. O sucessor das 8h00 é caso 1 (10h30 e
depois à esquerda, 9h20); o das 7h30 é caso 2 e sobe até o 8h00. Ao lado de
cada nó, a profundidade e a altura:

{{ideia}}

O sucessor no `arvpai.c`:

```c
NoP *ap_sucessor(NoP *x) {
    if (x->dir != NULL) {
        return ap_minimo(x->dir); // caso 1: o menor da subárvore direita
    }
    NoP *y = x->pai; // caso 2: sobe até chegar por um filho esquerdo
    while (y != NULL && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}
```

O painel mostra os conceitos de três nós e as perguntas de horário:

```c
#include <stdio.h>
#include "arvpai.h"

void hora(const NoP *x) {
    if (x == NULL) {
        printf("nenhum");
    } else {
        printf("%dh%02d", x->chave / 100, x->chave % 100);
    }
}

int main(void) {
    int saidas[] = {800, 615, 1030, 700, 650, 920, 1200, 730};
    NoP *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = ap_insere(raiz, saidas[i]);
    }
    int olhar[] = {800, 615, 730};
    for (int i = 0; i < 3; i++) {
        NoP *x = ap_busca(raiz, olhar[i]);
        printf("%4d: grau %d | nível %d | altura %d | fator %2d\n", x->chave,
               ap_grau(x), ap_profundidade(x), ap_altura(x), ap_fator(x));
    }
    printf("Altura da árvore: %d\n", ap_altura(raiz));

    int perguntas[] = {730, 800};
    for (int i = 0; i < 2; i++) {
        NoP *x = ap_busca(raiz, perguntas[i]);
        printf("Depois das ");
        hora(x);
        printf(" sai o das ");
        hora(ap_sucessor(x));
        printf("; antes, o das ");
        hora(ap_antecessor(x));
        printf("\n");
    }
    raiz = ap_libera(raiz);
    return 0;
}
// Saída:
//  800: grau 2 | nível 0 | altura 3 | fator  1
//  615: grau 1 | nível 1 | altura 2 | fator -2
//  730: grau 0 | nível 3 | altura 0 | fator  0
// Altura da árvore: 3
// Depois das 7h30 sai o das 8h00; antes, o das 7h00
// Depois das 8h00 sai o das 9h20; antes, o das 7h30
```

O fluxograma segue o sucessor das 7h30: sobe duas vezes vindo da direita; na
terceira, o 6h15 é filho esquerdo do 8h00 e o laço para:

{{fluxograma}}

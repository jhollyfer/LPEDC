## 0175 · Conceitos e sucessor

No painel da rodoviária, qual ônibus sai logo depois do seu? E qual saiu
logo antes? Os horários (6h15, 6h50, 7h00, 7h30, 8h00, 9h20, 10h30, 12h00)
estão numa BST, e a resposta é o **sucessor** e o **antecessor** da chave.

Primeiro o vocabulário, na convenção do Cormen e do módulo 14 (altura conta
**arestas**):

- **grau de um nó**: quantos filhos ele tem. Grau 0 é **folha**. O **grau da
  árvore** é o maior grau entre os nós;
- **profundidade** de um nó: arestas até a raiz, que tem profundidade 0;
- **nível**: os nós de mesma profundidade. A raiz está no nível 0, mas alguns
  livros contam **a partir de 1**: confira o enunciado;
- **altura** de um nó: o maior número de arestas até uma folha abaixo. Folha
  tem altura 0, árvore vazia tem -1. A altura da árvore é a da raiz;
- **fator de balanceamento**: `altura(esq) - altura(dir)`, mantido em -1, 0
  ou 1 pela AVL do 0101.

O sucessor de `x` em ordem é a menor chave maior que `x`. Há dois casos:

1. `x` tem **subárvore direita**: o sucessor é o **mínimo** dela (desce uma
   vez à direita e depois tudo à esquerda);
2. `x` **não tem** subárvore direita: o sucessor é um **ancestral**. Sobe
   enquanto vier de um filho direito (esses ancestrais são menores). O
   primeiro ancestral alcançado **por um filho esquerdo** é a resposta. Se a
   subida passar da raiz, `x` é o maior e não tem sucessor.

O caso 2 precisa subir, por isso o nó ganha o ponteiro **`pai`** (`x.p` no
Cormen). O antecessor é o espelho (esquerda por direita, mínimo por máximo).
Os dois custam O(h).

Os horários entram na ordem 8h00, 6h15, 10h30, 7h00, 6h50, 9h20, 12h00, 7h30
(chaves `800`, `615`...). O sucessor das 8h00 é caso 1: 10h30 e depois à
esquerda, 9h20. O das 7h30 é caso 2: ela é filha direita do 7h00, que é filho
direito do 6h15, que é filho **esquerdo** do 8h00, a resposta. No desenho, os
números ao lado de cada nó são a profundidade e a altura:

{{ideia}}

No `arvpai.c`, a inserção é a iterativa do Cormen (desce lembrando o pai).
O sucessor:

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

O painel mostra também os conceitos de três nós:

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

O fluxograma segue o sucessor das 7h30: sem filho direito, vai ao caso 2 e
sobe duas vezes, sempre vindo da direita. Na terceira, o 6h15 é filho esquerdo
do 8h00: o laço para:

{{fluxograma}}

> [!WARNING]
> Trocar o lado na subida (`x == y->esq` no lugar de `x == y->dir`) faz o
> sucessor das 7h30 virar 7h00, que é **menor**. Toda inserção, remoção ou
> rotação também tem que acertar o `pai` (o da raiz fica `NULL`).

> [!TIP]
> O `pai` custa 8 bytes por nó (32 no `NoP`, contra 24 da BST do 0099), mas o
> sucessor dispensa pilha e recursão.

> [!NOTE]
> **Pergunta para você:** qual é o antecessor das 6h50? E o sucessor das
> 12h00? Depois insira 7h45 e
> diga, sem rodar, qual será o grau do 7h30 e a nova altura da árvore.

{{pratique}}

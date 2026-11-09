## 0175 · Conceitos e sucessor

No painel da rodoviária, você olha a hora do seu ônibus e pergunta: qual sai
logo depois deste? E qual saiu logo antes? Os horários do dia (6h15, 6h50,
7h00, 7h30, 8h00, 9h20, 10h30, 12h00) estão numa BST, e a resposta é o
**sucessor** e o **antecessor** da chave, sem percorrer a árvore inteira.

Antes do algoritmo, o vocabulário. A prova cobra cada palavra, e os livros não
contam tudo do mesmo jeito. Aqui vale a convenção do Cormen, a mesma do
módulo 14 (altura conta **arestas**):

- **grau de um nó**: quantos filhos ele tem. Numa árvore binária, 0, 1 ou 2.
  Nó de grau 0 é **folha**;
- **grau da árvore**: o maior grau entre os nós dela;
- **profundidade** de um nó: quantas arestas há entre ele e a raiz. A raiz tem
  profundidade 0;
- **nível**: todos os nós com a mesma profundidade formam um nível. A raiz
  está no nível 0. Alguns livros brasileiros contam o nível **a partir de 1**:
  confira a convenção do enunciado;
- **altura** de um nó: o maior número de arestas dele até uma folha abaixo.
  Folha tem altura 0, árvore vazia tem altura -1. A altura da árvore é a da
  raiz, que é também a maior profundidade;
- **fator de balanceamento**: `altura(esq) - altura(dir)`, o número que a AVL
  do 0101 mantém em -1, 0 ou 1. Alguns autores fazem a conta ao contrário
  (direita menos esquerda); o módulo do valor é o mesmo.

Agora o sucessor. Em ordem, a próxima chave depois de `x` é a menor chave
maior que `x`. Há dois casos, e os dois só precisam de ponteiros:

1. `x` tem **subárvore direita**: o sucessor é o **mínimo** dela (desce uma
   vez à direita e depois tudo à esquerda);
2. `x` **não tem** subárvore direita: o sucessor é um **ancestral**. Sobe
   enquanto estiver vindo de um filho direito (esses ancestrais são menores
   que `x`). O primeiro ancestral alcançado **por um filho esquerdo** é a
   resposta. Se a subida passar da raiz, `x` é o maior e não tem sucessor.

O caso 2 precisa subir, e é por isso que o nó ganha um quarto campo: o
ponteiro **`pai`** (o Cormen chama de `x.p`). O antecessor é o espelho: troque
esquerda por direita e mínimo por máximo. Os dois custam O(h), a altura da
árvore.

Vamos ver na prática. Os horários entram na ordem 8h00, 6h15, 10h30, 7h00,
6h50, 9h20, 12h00, 7h30 (as chaves são `800`, `615`, e assim por diante). O
sucessor das 8h00 é caso 1: desce para 10h30 e depois à esquerda, 9h20. O das
7h30 é caso 2: ela é filha direita do 7h00, que é filho direito do 6h15, que é
filho **esquerdo** do 8h00. Resposta: 8h00. No desenho, os números ao lado de
cada nó são a profundidade e a altura:

{{ideia}}

O TAD é o `arvpai.h`. A inserção é a iterativa do Cormen (desce lembrando o
pai e pendura o nó novo nele). O sucessor, no `arvpai.c`:

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

E o painel da rodoviária, que também mostra os conceitos de três nós:

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

Repara no fluxograma: é o sucessor das 7h30. Sem filho direito, ele vai para
o caso 2 e o laço roda duas vezes (sobe para 7h00 e para 6h15, sempre vindo da
direita). Na terceira pergunta, o 6h15 é filho esquerdo do 8h00: o laço para e
o 8h00 é a resposta:

{{fluxograma}}

> [!WARNING]
> O erro clássico é trocar o lado na subida: `x == y->esq` no lugar de
> `x == y->dir`. Com ele, o sucessor das 7h30 vira 7h00, que é **menor**. Pense
> assim: subir vindo da direita é voltar para alguém menor que você, então não
> serve, continue subindo. O outro cuidado é manter o `pai` em dia: toda
> inserção, remoção e rotação que mexe em `esq` ou `dir` tem que acertar o
> `pai` do nó que mudou de lugar (e o da raiz fica `NULL`).

> [!TIP]
> **Por dentro do C:** o ponteiro `pai` custa 8 bytes por nó: o `NoP` tem 32
> bytes (4 da chave, 4 de enchimento e três ponteiros), contra 24 da BST do
> 0099. Em troca, o sucessor não precisa de pilha nem de recursão, e dá para
> percorrer a árvore em ordem com um `for` (mínimo, sucessor, sucessor...).
> Um sucessor sozinho pode custar a altura, mas o passeio inteiro custa O(n):
> cada aresta é descida uma vez e subida uma vez (o A349 conta os
> ponteiros). As árvores balanceadas de verdade, como a rubro-negra do
> 0177, guardam o `pai` justamente para consertar a árvore subindo.

> [!NOTE]
> **Pergunta para você:** qual é o antecessor das 6h50? E o sucessor das
> 12h00? Siga os dois casos no desenho antes de rodar. Depois insira 7h45 e
> diga, sem rodar, qual será o grau do 7h30 e a nova altura da árvore.

{{pratique}}

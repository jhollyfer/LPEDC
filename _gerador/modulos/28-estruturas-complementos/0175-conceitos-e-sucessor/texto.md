## 0175 · Conceitos e sucessor

Questão de prova sobre árvore quase sempre começa com vocabulário: "qual a
altura do nó 7?", "quantas folhas há no nível 2?". Se você conta altura por
nós e o enunciado conta por arestas, erra a questão sabendo o assunto. Por
isso este assunto fixa os termos antes de chegar à pergunta que dá o nome a
ele: numa árvore binária de busca, qual chave vem logo depois de uma chave
dada?

Comece pelo **grau** de um nó, que é quantos filhos ele tem. Numa árvore
binária o grau vai de 0 a 2. Nó de grau 0 é uma **folha**: não tem ninguém
abaixo. O **grau da árvore** é o maior grau entre todos os nós (SZWARCFITER;
MARKENZON, 2010). Uma árvore binária com pelo menos um nó de dois filhos tem
grau 2.

Depois vêm as medidas de posição. A **profundidade** de um nó é o número de
arestas no caminho dele até a raiz; a raiz tem profundidade 0, os filhos dela
têm 1, os netos, 2. O **nível** agrupa os nós de mesma profundidade, e a raiz
fica no nível 0 (CORMEN et al., 2024, cap. 12). Aqui mora a primeira
armadilha: alguns livros contam o nível a partir de 1, com a raiz no nível 1.
Antes de responder, confira qual convenção o enunciado usa.

A **altura** olha para baixo: é o maior número de arestas do nó até uma folha
abaixo dele. Folha tem altura 0, porque não desce nada. A altura da árvore é
a altura da raiz, e a árvore vazia tem altura -1 por convenção, o que faz a
conta `1 + max(altura(esq), altura(dir))` funcionar até no nó sem filhos
(CORMEN et al., 2024, cap. 12). Profundidade conta para cima, altura conta
para baixo; o curso segue o Cormen e conta as duas em arestas, como no módulo
14.

Com a altura em mãos sai o **fator de balanceamento** de um nó:
`altura(esq) - altura(dir)`. Fator positivo quer dizer que a esquerda pesa
mais; negativo, a direita. A AVL do 0101 mantém o fator de todo nó em -1, 0
ou 1, e essa regra garante altura O(log n) (ADELSON-VELSKY; LANDIS, 1962).

Agora a pergunta do sucessor. Pense no painel de uma rodoviária com os
horários guardados numa BST: qual ônibus sai logo depois do seu? Em ordem
crescente, o **sucessor** de um nó `x` é o nó com a menor chave maior que a
de `x`. O **antecessor** é o espelho, a maior chave menor que a de `x`
(CORMEN et al., 2024, cap. 12). Há dois casos.

No caso 1, `x` tem subárvore direita. Tudo o que é maior que `x` e está
abaixo dele mora ali, e o menor desses é o **mínimo** da subárvore direita:
você desce uma vez à direita e depois vai sempre à esquerda até não poder
mais. Numa árvore com 8 na raiz, 10 à direita e 9 à esquerda do 10, o
sucessor do 8 é o 9.

No caso 2, `x` não tem subárvore direita, e o sucessor é um ancestral. Para
achá-lo, você sobe. Enquanto sobe vindo de um filho direito, o ancestral é
menor que `x` e não serve. O primeiro ancestral alcançado vindo de um filho
**esquerdo** é a resposta, porque `x` está à esquerda dele e, portanto, ele
é maior. Se a subida passar da raiz sem achar esse ancestral, `x` é a maior
chave da árvore e não tem sucessor (CORMEN et al., 2024, cap. 12).

O caso 2 precisa subir, e o nó de uma BST comum só aponta para baixo. Por isso
cada nó ganha um ponteiro **`pai`** (o `x.p` do Cormen), que vale `NULL` na
raiz. Com ele, a subida dispensa pilha e recursão. O custo é de 8 bytes a mais
por nó numa máquina de 64 bits. Sucessor e antecessor percorrem no máximo um
caminho da raiz até uma folha, então custam O(h), com h a altura da árvore
(CORMEN et al., 2024, cap. 12).

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

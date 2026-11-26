## 0099 · BST: busca e inserção

A catraca da academia precisa achar a matrícula na hora, e alunos novos se
matriculam todo dia. No vetor ordenado, a busca binária do 0090 é rápida, mas
cada aluno novo obriga a empurrar metade do vetor para abrir espaço. Na lista
encadeada, inserir é barato, mas a busca anda nó a nó, em O(n). Você quer a
busca do vetor ordenado com a inserção da lista. A árvore binária do 0098,
com uma regra a mais, entrega as duas coisas.

A **árvore binária de busca**, ou **BST** (do inglês *binary search tree*), é
uma árvore binária em que vale uma regra em **todo** nó: as chaves da
subárvore esquerda são todas **menores** que a chave do nó, e as da subárvore
direita são todas **maiores** (CORMEN et al., 2024, cap. 12). A regra vale
para a subárvore inteira, não só para os filhos: se a raiz é 50, nenhum nó em
qualquer ponto da esquerda pode passar de 50.

Buscar é a busca binária feita na árvore. Você compara a chave com a raiz. Se
é igual, achou. Se é menor, ela só pode estar na subárvore esquerda, e a
direita inteira fica para trás; se é maior, vale o contrário. Você repete a
comparação no nó seguinte até achar a chave ou chegar a um `NULL`, e chegar
ao `NULL` quer dizer que a chave não existe (FEOFILOFF, 2009). Cada
comparação desce um nível e descarta uma subárvore.

**Inserir** é a mesma descida. Você procura a chave nova como se ela já
existisse; no `NULL` em que a busca falharia, pendura um nó novo. Por isso o
nó novo sempre entra como **folha**, e nenhum nó antigo muda de lugar. A
versão recursiva devolve a raiz da subárvore em que inseriu, e quem chamou
guarda o retorno: o pai faz `r->esq = bst_insere(r->esq, chave)`. Quando a
descida chega ao `NULL`, a função devolve o nó novo, e essa atribuição faz o
ponteiro do pai passar a apontar para ele. Uma chave repetida é ignorada, e a
árvore não guarda duplicatas (FEOFILOFF, 2009). A outra forma de escrever é
passar o endereço do ponteiro, um `No **`, como você faz com o `scanf`.

A regra da BST tem um efeito bonito no percurso **em ordem** do 0098: ele
visita a esquerda (os menores), depois o nó, depois a direita (os maiores), e
por isso lista as chaves em ordem **crescente**. O nó que vem logo depois de
outro na em ordem é o seu **sucessor**; o que vem logo antes é o seu
**antecessor**. O menor nó da árvore é o que fica mais à esquerda, e o maior,
o que fica mais à direita (CORMEN et al., 2024, cap. 12).

O custo da busca e da inserção é o tamanho do caminho percorrido: no máximo
**altura** + 1 comparações. Numa árvore cheia, em que todos os níveis estão
completos, a altura fica perto de log₂ n. Com 7 chaves são 3 níveis; com um
milhão de chaves, uns 20 (ZIVIANI, 2010, cap. 5). O problema é que nada
garante a árvore cheia. A forma da BST depende da ordem em que as chaves
chegam, e o assunto 0101 trata de corrigir isso.

> [!WARNING]
> A forma da BST depende da **ordem de chegada**. As sete matrículas em ordem
> crescente formam uma lista disfarçada de altura 6 (exemplo A198). E sem
> `raiz = bst_insere(raiz, ...)` o nó criado se perde.

{{exemplo}}

A catraca da academia procura matrículas. Sete alunos chegaram na ordem 50,
30, 70, 20, 40, 60 e 80. A busca do 60 passa por 50 e 70; a do 45 desce 50,
30, 40 e cai no `NULL` à direita do 40:

{{ideia}}

O TAD fica em `bst.h` e `bst.c`. As duas funções principais:

```c
No *bst_insere(No *r, int chave) {
    if (r == NULL) {
        return novo_no(chave); // achou o lugar vazio: vira folha
    }
    if (chave < r->chave) {
        r->esq = bst_insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = bst_insere(r->dir, chave);
    }
    return r; // igual: já existe, não insere de novo
}

No *bst_busca(No *r, int chave) {
    while (r != NULL && r->chave != chave) {
        r = chave < r->chave ? r->esq : r->dir;
    }
    return r;
}
```

A busca dispensa recursão: um laço desce um nível por volta. O exemplo mostra
o caminho:

```c
#include <stdio.h>
#include "bst.h"

void procura(const No *r, int chave) {
    printf("Busca %d:", chave);
    while (r != NULL) {
        printf(" %d", r->chave);
        if (chave == r->chave) {
            printf(" -> achou\n");
            return;
        }
        r = chave < r->chave ? r->esq : r->dir;
    }
    printf(" -> NULL, não existe\n");
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80};
    No *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\n");
    procura(raiz, 60);
    procura(raiz, 45);
    printf("Altura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
// Saída:
// Em ordem: 20 30 40 50 60 70 80
// Busca 60: 50 70 60 -> achou
// Busca 45: 50 30 40 -> NULL, não existe
// Altura: 2
```

Cada volta faz no máximo duas perguntas e desce um nível. O caminho verde é a
busca do 60:

{{fluxograma}}

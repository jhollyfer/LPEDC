## 0104 · BST: busca e inserção

A academia do bairro guarda os alunos pela matrícula. Na catraca, o sistema
precisa achar a matrícula na hora. Num vetor ordenado, a busca binária
(assunto 0095) acha rápido, mas cada aluno novo obriga a empurrar metade do
vetor para abrir espaço. Numa lista encadeada, inserir é barato, mas a busca
passa por um nó de cada vez. Dá para ter as duas coisas?

Dá: a **árvore binária de busca**, ou **BST** (*binary search tree*). É uma
árvore binária com uma regra que vale em **todo** nó: as chaves da subárvore
esquerda são **menores** que a do nó, e as da subárvore direita são **maiores**.

Com essa regra, buscar vira a busca binária andando pela árvore. Compare a chave
procurada com a raiz. Igual? Achou. Menor? Tudo que interessa está à esquerda,
então a metade da direita fica para trás. Maior? Vá para a direita. Se chegar
num `NULL`, a chave não existe.

**Inserir** é a mesma descida: procure a chave e, no `NULL` onde a busca
falharia, pendure um nó novo. Todo nó entra como **folha**; ninguém sai do lugar.
Por isso a inserção recursiva devolve a raiz da subárvore e o pai faz
`r->esq = bst_insere(r->esq, chave)`: na maioria das chamadas nada muda, e no
`NULL` o ponteiro do pai passa a apontar para o nó novo. Chave repetida é
ignorada neste TAD.

E o bônus: a **em ordem** de uma BST sai em ordem crescente. Esquerda (todos
menores), raiz, direita (todos maiores). Você ganha uma ordenação de graça.

O custo da busca é o número de níveis que ela desce: no máximo a **altura** + 1
comparações. Numa árvore cheinha, cada nível dobra o número de nós, e a altura
fica perto de log₂ n. Com 7 chaves são 3 níveis; com um milhão, uns 20.

Vamos ver na prática. Sete alunos chegaram nesta ordem: 50, 30, 70, 20, 40, 60
e 80. A busca pelo 60 compara com 50 (vai para a direita), com 70 (vai para a
esquerda) e acha. A busca pelo 45 desce 50, 30, 40 e cai no `NULL` à direita do
40: é ali que o 45 entraria se fosse inserido:

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

A busca nem precisa de recursão: é um laço que desce um nível por volta. No
exemplo, uma versão que mostra o caminho:

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

Repara no fluxograma: cada volta do laço faz no máximo duas perguntas sobre o
nó atual e desce um nível. O caminho verde é a busca do 60: direita no 50,
esquerda no 70, achou:

{{fluxograma}}

> [!WARNING]
> A forma da BST depende da **ordem de chegada**. As mesmas sete matrículas
> inseridas em ordem crescente (20, 30, ..., 80) formam uma "árvore" em que todo
> nó só tem filho direito: uma lista encadeada disfarçada, com altura 6. A busca
> pelo 80 passa pelos 7 nós, e a promessa do log₂ n vai embora. O exemplo A208
> mostra isso, e o assunto 0106 resolve.

> [!TIP]
> **Por dentro do C:** repare no `raiz = bst_insere(raiz, ...)`. A árvore começa
> como `NULL` e só o primeiro `insere` muda a raiz. Se você esquecer a
> atribuição, o nó criado se perde: a variável `raiz` continua `NULL` e o
> AddressSanitizer acusa vazamento no fim. Outra saída é passar o endereço da
> raiz (`No **`), como no `scanf`. O exercício E622 faz assim. Cada nó ocupa 24
> bytes (4 do `int`, 4 de enchimento, 16 dos ponteiros), contra 4 bytes por
> chave num vetor: a BST troca memória por inserção barata.

> [!NOTE]
> **Pergunta para você:** em que ordem você inseriria as chaves 10, 20, 30, 40,
> 50, 60 e 70 para a árvore ficar com altura 2? Existe mais de uma resposta?

{{pratique}}

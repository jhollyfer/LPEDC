## 0100 · BST: remoção

Três alunos cancelaram o plano, e as matrículas 30, 40 e 20 precisam sair da
árvore. Inserir foi fácil porque todo nó novo entra como folha e ninguém muda
de lugar. Remover é mais delicado: o nó que sai pode ter filhos, e depois da
remoção a regra da BST do 0099 precisa continuar valendo em todo nó.

O primeiro passo é a busca de sempre, que acha o nó. O que fazer com ele
depende de **quantos filhos** ele tem, e são três casos (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 7). Se o nó é uma **folha**, você libera o nó e o pai
passa a apontar para `NULL`. Se o nó tem **um filho**, esse filho sobe para o
lugar dele: o avô passa a apontar direto para o neto e "pula" o nó removido.
A regra continua valendo, porque o filho e tudo abaixo dele já estavam do
lado certo do avô.

Os dois primeiros casos cabem num código só. A regra é "o filho que existe
sobe", e na folha esse filho é `NULL`, então o pai passa a apontar para
`NULL` sem nenhum teste extra (CORMEN et al., 2024, cap. 12).

O caso difícil é o nó com **dois filhos**. Não dá para subir os dois, porque o
pai só tem um ponteiro para aquele lugar. A saída é procurar outro nó que
possa ocupar a posição: alguém maior que tudo à esquerda e menor que tudo à
direita. O candidato natural é o **sucessor**, a menor chave da subárvore
direita, que o 0099 definiu como o nó logo depois na em ordem (CORMEN et al.,
2024, cap. 12). Para achá-lo, desça **uma vez à direita** e depois **à
esquerda até não dar mais**.

O sucessor tem uma propriedade que salva a remoção: ele **não tem filho
esquerdo**, porque se tivesse, esse filho seria menor e o sucessor seria ele.
Então você copia a chave do sucessor para o nó que ia sair e remove o
sucessor da subárvore direita, e essa segunda remoção sempre cai num dos
casos fáceis. Usar o **antecessor**, a maior chave da subárvore esquerda,
funciona do mesmo jeito, mas a árvore final sai diferente; este TAD usa o
sucessor, como o Cormen (FEOFILOFF, 2009).

| Caso | O que fazer | No exemplo |
| --- | --- | --- |
| **folha** | dá `free` e o pai passa a apontar para `NULL` | remover o 20 |
| **um filho** | o filho sobe para o lugar dele; o avô "pula" o nó | remover o 40: o 45 sobe |
| **dois filhos** | troca pelo **sucessor** e remove o sucessor | remover o 30: o 35 assume |

O código segue o molde da inserção: a função devolve a raiz da subárvore
depois da remoção, o pai faz `r->esq = bst_remove(r->esq, chave)` e o cliente
faz `raiz = bst_remove(raiz, ...)`, porque a própria raiz pode sair. O custo é
o da descida, **O(altura)** (CELES; RANGEL, 2002). Copiar só a chave basta
quando o nó guarda um `int`. Com uma `struct` grande, compensa religar os
ponteiros em vez de copiar dados, e é isso que o procedimento `TRANSPLANT` do
Cormen faz.

> [!WARNING]
> `bst_remove(raiz->esq, 20);` sem atribuir o retorno dá `free` no 20 mas deixa
> o pai apontando para o endereço antigo: **ponteiro solto**, que o
> AddressSanitizer acusa como `heap-use-after-free`. Vale também para `raiz`.

{{exemplo}}

Três alunos cancelaram o plano, e as matrículas 30, 40 e 20 saem. O 30 tem
dois filhos: o sucessor fica à direita (40) e depois à esquerda (35). O 35
ocupa o lugar do 30, e o 35 de baixo, que era folha, sai:

{{ideia}}

A função completa, no `bst.c`. Ela copia **só a chave**; com uma struct
grande, compensa religar ponteiros:

```c
No *bst_remove(No *r, int chave) {
    if (r == NULL) {
        return NULL; // não achou: nada a remover
    }
    if (chave < r->chave) {
        r->esq = bst_remove(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = bst_remove(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        // folha ou um filho: o filho (ou NULL) sobe para o lugar do nó
        No *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        // dois filhos: copia o sucessor (o menor da direita) e remove ele lá
        No *suc = r->dir;
        while (suc->esq != NULL) {
            suc = suc->esq;
        }
        r->chave = suc->chave;
        r->dir = bst_remove(r->dir, suc->chave);
    }
    return r;
}
```

O cliente remove as três matrículas e mostra a pré-ordem, que revela a
**forma** da árvore (a em ordem sairia sempre crescente):

```c
#include <stdio.h>
#include "bst.h"

void pre(const No *r) {
    if (r == NULL) {
        return;
    }
    printf(" %d", r->chave);
    pre(r->esq);
    pre(r->dir);
}

void mostra(const char *rotulo, const No *r) {
    printf("%-11s pré:", rotulo);
    pre(r);
    printf("\n");
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }
    mostra("Antes", raiz);

    raiz = bst_remove(raiz, 30); // dois filhos: o sucessor 35 assume
    mostra("Remove 30", raiz);
    raiz = bst_remove(raiz, 40); // um filho: o 45 sobe
    mostra("Remove 40", raiz);
    raiz = bst_remove(raiz, 20); // folha: só sai
    mostra("Remove 20", raiz);
    raiz = bst_remove(raiz, 99); // não existe: nada muda
    mostra("Remove 99", raiz);

    raiz = bst_libera(raiz);
    return 0;
}
// Saída:
// Antes       pré: 50 30 20 40 35 45 70 60 80
// Remove 30   pré: 50 35 20 40 45 70 60 80
// Remove 40   pré: 50 35 20 45 70 60 80
// Remove 20   pré: 50 35 45 70 60 80
// Remove 99   pré: 50 35 45 70 60 80
```

O caminho verde é a chamada que encontra o 30: cai no caso de dois filhos,
copia o 35 e faz uma **segunda remoção**, do 35, que termina no caso fácil:

{{fluxograma}}

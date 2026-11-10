## 0146 · Árvore B: busca, divisão e inserção

O acervo de uma biblioteca tem milhões de fichas no disco. Um HD leva uns 10
milissegundos por bloco. Numa AVL com 2 milhões de livros, a busca desce uns 21
nós, e cada nó pode ser uma ida ao disco. Importa **ler poucos nós**.

A **árvore B** usa nós gordos. Cada nó guarda **várias chaves em ordem** e tem
um filho a mais do que chaves: com `[40 70]`, o filho 0 tem as chaves menores
que 40, o filho 1 as entre 40 e 70, e o filho 2 as maiores que 70. Num banco de
dados, um nó ocupa um bloco do disco.

O **grau mínimo** `t` define o tamanho do nó:

- todo nó, menos a raiz, tem de `t - 1` a `2t - 1` chaves (a raiz pode ter 1);
- um nó com `k` chaves que não é folha tem `k + 1` filhos;
- **todas as folhas ficam no mesmo nível**.

O TAD usa `t = 2`: de 1 a 3 chaves por nó, de 2 a 4 filhos (a árvore 2-3-4).
Como cada nó abaixo da raiz tem pelo menos `t` filhos, a altura de uma árvore B
com `n` chaves é `h ≤ log_t((n + 1) / 2)` (Cormen).

A **busca** é a da BST com um laço dentro do nó: ande até achar uma chave maior
ou igual. Se for igual, achou; senão, desça pelo filho daquela posição. Lê um nó
por nível: altura + 1 nós.

A **inserção** põe a chave numa folha. Se a folha está cheia, ocorre a
**divisão**: o nó com `2t - 1` chaves vira dois nós de `t - 1` chaves, e a
**chave do meio sobe** para o pai. Para o pai nunca estar cheio, o TAD divide
**na descida** todo nó cheio do caminho; a raiz cheia se divide e a chave do
meio vira a raiz nova. A árvore cresce por cima, e as folhas ficam no mesmo
nível.

Exemplo: 11 livros, na ordem 40, 10, 70, 20, 50, 80, 30, 60, 90, 25 e 85. O 25
encontra a folha `[10 20 30]` cheia: ela se divide e o 20 sobe. O 85 encontra a
raiz `[20 40 70]` cheia: ela se divide e o 40 vira a raiz nova. A busca pelo 60
lê três nós:

{{ideia}}

A divisão e a inserção na raiz, em `arvoreb.c` (`AB_T` é o `t`; `AB_MAX`, `2t - 1`):

```c
static void divide(NoB *pai, int i) {
    NoB *y = pai->filho[i];         // o filho cheio
    NoB *z = novo_no(y->folha);     // a metade da direita
    z->n = AB_T - 1;
    for (int j = 0; j < AB_T - 1; j++) {
        z->chave[j] = y->chave[j + AB_T]; // as chaves depois do meio
    }
    if (!y->folha) {
        for (int j = 0; j < AB_T; j++) {
            z->filho[j] = y->filho[j + AB_T]; // e os filhos delas
        }
    }
    y->n = AB_T - 1; // y fica com as chaves antes do meio

    for (int j = pai->n; j > i; j--) { // abre espaço no pai
        pai->filho[j + 1] = pai->filho[j];
    }
    pai->filho[i + 1] = z;
    for (int j = pai->n - 1; j >= i; j--) {
        pai->chave[j + 1] = pai->chave[j];
    }
    pai->chave[i] = y->chave[AB_T - 1]; // a chave do meio sobe
    pai->n++;
}

NoB *ab_insere(NoB *raiz, int chave) {
    if (ab_busca(raiz, chave, NULL)) {
        return raiz; // repetida
    }
    if (raiz == NULL) {
        raiz = novo_no(true);
    }
    if (raiz->n == AB_MAX) { // raiz cheia: a árvore cresce por cima
        NoB *s = novo_no(false);
        s->filho[0] = raiz;
        divide(s, 0);
        raiz = s;
    }
    insere_nao_cheio(raiz, chave);
    return raiz;
}
```

A `divide` só diminui `y->n`: as chaves do fim ficam no vetor, fora da parte em uso.
O cliente:

```c
#include <stdio.h>
#include "arvoreb.h"

int main(void) {
    int livros[] = {40, 10, 70, 20, 50, 80, 30, 60, 90, 25, 85};
    NoB *acervo = NULL;
    for (int i = 0; i < 11; i++) {
        acervo = ab_insere(acervo, livros[i]);
    }

    printf("Árvore B com 11 livros (altura %d, %d divisões):\n",
           ab_altura(acervo), ab_divisoes());
    ab_mostra(acervo);

    int procura[] = {60, 65};
    for (int i = 0; i < 2; i++) {
        int lidos;
        bool achou = ab_busca(acervo, procura[i], &lidos);
        printf("Livro %d: %s, %d nós lidos\n", procura[i],
               achou ? "achou" : "não tem", lidos);
    }

    acervo = ab_libera(acervo);
    return 0;
}
// Saída:
// Árvore B com 11 livros (altura 2, 4 divisões):
//   nível 0: [40]
//   nível 1: [20] [70]
//   nível 2: [10] [25 30] [50 60] [80 85 90]
// Livro 60: achou, 3 nós lidos
// Livro 65: não tem, 3 nós lidos
```

O fluxograma segue `insere_nao_cheio` na raiz `[40 70]` quando o 25 chega. O
filho 0, cheio, se divide e o 20 sobe. Como 25 > 20, o `i++` leva a chave à
metade nova, folha `[30]`:

{{fluxograma}}

> [!WARNING]
> Depois de `divide(x, i)`, a chave que subiu está em `x->chave[i]`. Sem
> `if (chave > x->chave[i]) i++;`, chaves grandes vão para a metade da esquerda
> e a busca não as acha. Cuidado também com "ordem m": são **m filhos no
> máximo** em alguns livros (Knuth) e **de m a 2m registros** no Ziviani. O curso
> usa o grau mínimo `t` do Cormen.

> [!TIP]
> Com chaves `int` e ponteiros de 8 bytes, `t = 170` (nó de `24t` bytes) cabe num
> bloco de 4096 bytes: um bilhão de chaves em altura 3, 4 blocos lidos por busca.

> [!NOTE]
> **Pergunta para você:** na árvore final, insira o 87. Qual nó se divide, qual
> chave sobe e como fica o nível 1? Depois insira o 95: a raiz muda? Confira
> acrescentando as chaves no vetor do exemplo.

{{pratique}}

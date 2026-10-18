## 0146 · Árvore B: busca, divisão e inserção

A biblioteca municipal pôs o acervo inteiro no computador: milhões de fichas,
guardadas no disco, porque não cabem na memória. Ler do disco é lento: um HD
leva uns 10 milissegundos para buscar um bloco, tempo em que o processador faz
milhões de comparações. Numa AVL com 2 milhões de livros, a busca desce uns 21
nós, e se cada nó estiver num bloco diferente são 21 idas ao disco. Para o
disco, o que importa não é comparar pouco: é **ler poucos nós**.

A **árvore B** resolve isso com nós gordos. Cada nó guarda **várias chaves em
ordem** e tem um filho a mais do que chaves: com as chaves `[40 70]`, o filho
0 tem as menores que 40, o filho 1 as que ficam entre 40 e 70, e o filho 2 as
maiores que 70. É uma BST em que cada nó decide entre muitos caminhos de uma
vez. Num banco de dados, um nó ocupa um bloco do disco e guarda centenas de
chaves; a árvore fica com altura 3 ou 4 mesmo com bilhões de registros.

O tamanho do nó é dado pelo **grau mínimo** `t`:

- todo nó, menos a raiz, tem de `t - 1` a `2t - 1` chaves (a raiz pode ter 1);
- um nó com `k` chaves que não é folha tem `k + 1` filhos;
- **todas as folhas ficam no mesmo nível**.

O TAD do curso usa `t = 2`: de 1 a 3 chaves por nó, de 2 a 4 filhos (é a
chamada árvore 2-3-4). Na vida real, `t` passa de 100.

A **busca** é a da BST com um laço dentro do nó: ande pelas chaves até achar
uma maior ou igual. Se for igual, achou; senão, desça pelo filho daquela
posição. Lê um nó por nível: altura + 1 nós no total.

A **inserção** sempre põe a chave numa folha. O problema é a folha cheia. A
solução é a **divisão**: um nó com `2t - 1` chaves se parte em dois nós de
`t - 1` chaves, e a **chave do meio sobe** para o pai. Para o pai nunca estar
cheio nessa hora, o TAD divide **na descida**: todo nó cheio que aparece no
caminho é dividido antes de a chave descer por ele. Quando a raiz está cheia,
ela se divide e a chave do meio vira uma raiz nova. A árvore B cresce por
cima, nunca por baixo: é por isso que as folhas continuam todas no mesmo nível.

Vamos ver na prática. O bibliotecário cadastra 11 livros, nesta ordem: 40, 10,
70, 20, 50, 80, 30, 60, 90, 25 e 85. Quando o 25 chega, a raiz é `[40 70]` e a
folha do caminho, `[10 20 30]`, está cheia: ela se divide, o 20 sobe e o 25
entra na metade da direita. Quando o 85 chega, a raiz `[20 40 70]` é que está
cheia: ela se divide, o 40 vira raiz nova e a árvore ganha um nível. No fim, a
busca pelo 60 lê três nós:

{{ideia}}

A divisão e a inserção na raiz, no `arvoreb.c` (`AB_T` é o `t`, e `AB_MAX`,
`2t - 1`):

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

Repare que `divide` não apaga nada de `y`: só diminui `y->n`. As chaves do fim
continuam no vetor, mas ficam fora da parte em uso. O cliente:

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

Repara no fluxograma: é o `insere_nao_cheio` chamado na raiz `[40 70]` quando
o 25 chega. A raiz não é folha; o 25 desce pelo filho 0, que está cheio; o
filho se divide e o 20 sobe. Como 25 é maior que o 20, o `i++` manda a chave
para a metade nova, e a chamada recursiva a põe na folha `[30]`:

{{fluxograma}}

> [!WARNING]
> Depois de `divide(x, i)`, o nó por onde a chave ia descer virou **dois**, e
> a chave que subiu está em `x->chave[i]`. Se a chave nova for maior que ela,
> o caminho certo é o filho `i + 1`, a metade nova. Esquecer o
> `if (chave > x->chave[i]) i++;` põe chaves grandes na metade da esquerda: a
> árvore perde a ordem e a busca deixa de achar chaves que estão lá dentro (é o
> bug do E875). Outra confusão comum é de vocabulário: "árvore B de ordem m"
> costuma querer dizer **m filhos no máximo**, e não o grau mínimo `t`. Confira
> qual dos dois o material usa.

> [!TIP]
> **Por dentro do C:** o `NoB` do TAD tem 56 bytes: 4 do `n`, 12 das três
> chaves, 32 dos quatro ponteiros, 1 do `bool` e 7 de enchimento. Num banco de
> dados, o nó é dimensionado para caber num bloco do disco, por exemplo 4096
> bytes. Com chaves `int` e ponteiros de 8 bytes, `24t` bytes ficam por volta de
> 4096, o que dá `t = 170`: até 339 chaves por nó, e um bilhão de chaves em
> altura 3 (4 blocos lidos por busca). Dentro do nó, as chaves estão num vetor
> ordenado e contíguo: dá para usar até busca binária ali, e a leitura
> sequencial aproveita bem o cache do processador.

> [!NOTE]
> **Pergunta para você:** na árvore final, insira o 87. Qual nó se divide,
> qual chave sobe e como fica o nível 1? Depois insira o 95 e veja se a raiz
> muda. Confira acrescentando as duas chaves no vetor do exemplo.

{{pratique}}

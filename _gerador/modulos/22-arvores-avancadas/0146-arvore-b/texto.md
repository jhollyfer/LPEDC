## 0146 · Árvore B: busca, divisão e inserção

O acervo de uma biblioteca tem milhões de fichas guardadas no disco. Ler
algo da memória leva nanossegundos; ler um bloco de um HD leva uns 10
milissegundos, um milhão de vezes mais. Numa AVL com 2 milhões de livros, a
busca desce uns 21 nós, e cada nó pode estar num bloco diferente: 21 idas ao
disco, um quinto de segundo por busca (ZIVIANI, 2010, cap. 6). Quando os
dados moram no disco, o que importa é **ler poucos nós**, e para isso cada
nó precisa decidir muito mais que "esquerda ou direita".

A **árvore B** é uma árvore de busca com nós gordos, feita para disco. Cada
nó guarda **várias chaves em ordem** e tem um filho a mais do que chaves.
Num banco de dados, um nó costuma ocupar exatamente um bloco do disco, e
uma leitura traz o nó inteiro (BAYER; McCREIGHT, 1972). As chaves do nó
separam os filhos: num nó `[40 70]`, o filho 0 guarda as chaves menores que
40, o filho 1 as que ficam entre 40 e 70, e o filho 2 as maiores que 70. É a
mesma regra da BST, generalizada para várias chaves.

O tamanho dos nós é controlado pelo **grau mínimo** `t`, um número fixo da
árvore. Todo nó, menos a raiz, tem de `t - 1` a `2t - 1` chaves; a raiz pode
ter só uma. Um nó interno, que não é folha, com `k` chaves tem `k + 1`
filhos. E **todas as folhas ficam no mesmo nível** (CORMEN et al., 2024, cap.
18). O mínimo de `t - 1` chaves impede nós quase vazios, que fariam a árvore
crescer em altura à toa.

O TAD deste assunto usa `t = 2`: cada nó tem de 1 a 3 chaves e de 2 a 4
filhos. Essa árvore B pequena tem nome próprio, árvore 2-3-4, e é a prima da
2-3 que você viu na rubro-negra (0145). Com `t` pequeno, os desenhos cabem na
página; num banco de dados de verdade, `t` passa de cem.

Como cada nó abaixo da raiz tem pelo menos `t` filhos, a árvore se alarga
muito a cada nível e a altura fica pequena: com `n` chaves, `h ≤
log_t((n + 1) / 2)` (CORMEN et al., 2024, cap. 18). Com chaves `int` e
ponteiros de 8 bytes, `t = 170` faz um nó caber num bloco de 4096 bytes, e um
bilhão de chaves fica em altura 3. São 4 blocos lidos por busca, contra uns
30 de uma árvore binária.

A **busca** é a da BST com um laço dentro do nó. Ande pelas chaves do nó
até achar uma maior ou igual à procurada. Se for igual, achou. Se não, desça
pelo filho daquela posição e repita. Ela lê um nó por nível, altura + 1 nós
no total (CORMEN et al., 2024, cap. 18).

A **inserção** sempre põe a chave nova numa folha. Se a folha tem espaço,
basta encaixar a chave em ordem. Se está cheia, com `2t - 1` chaves,
acontece a **divisão**: o nó vira dois nós de `t - 1` chaves cada, e a
**chave do meio sobe** para o pai, entre os dois (CORMEN et al., 2024, cap.
18). Com `t = 2`, a folha `[10 20 30]` vira `[10]` e `[30]`, e o 20 sobe.

E se o pai também estiver cheio? A chave que sobe não teria onde ficar. O
TAD evita isso dividindo **na descida**: a caminho da folha, todo nó cheio
encontrado é dividido antes de entrar nele. Assim o pai de quem se divide
sempre tem espaço. Se a própria raiz está cheia, ela se divide e a chave do
meio vira uma raiz nova, acima das duas metades (CORMEN et al., 2024, cap.
18). A árvore B só cresce **por cima**, pela raiz, e é por isso que as
folhas continuam todas no mesmo nível.

> [!WARNING]
> Depois de `divide(x, i)`, a chave que subiu está em `x->chave[i]`. Sem
> `if (chave > x->chave[i]) i++;`, chaves grandes vão para a metade errada. E
> "ordem m" muda de livro para livro (m filhos no Knuth, de m a 2m registros no
> Ziviani); o curso usa o `t` do Cormen.

{{exemplo}}

O acervo de uma biblioteca recebe 11 livros: 40, 10, 70, 20, 50, 80, 30, 60, 90,
25 e 85. O 25 divide a folha `[10 20 30]` e o 20 sobe; o 85 divide a raiz
`[20 40 70]` e o 40 vira a raiz nova. A busca pelo 60 lê três nós:

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

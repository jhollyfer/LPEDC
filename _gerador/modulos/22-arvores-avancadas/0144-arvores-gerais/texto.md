## 0144 · Árvores gerais: primeiro filho, próximo irmão

O empreiteiro mandou o orçamento da reforma em tópicos. A reforma tem
cozinha, banheiro e pintura; a cozinha tem piso e pia; o banheiro tem box e
louças; as louças têm vaso e cuba. O total de cada tópico é a soma do que
está embaixo dele. Você quer guardar isso na memória e calcular os totais.

A forma é uma árvore, mas não binária: a reforma tem três filhos, a cozinha
tem dois, e nada impede um tópico de ter dez. Uma **árvore geral**, também
chamada **n-ária**, é uma árvore em que cada nó pode ter qualquer número de
filhos (SZWARCFITER; MARKENZON, 2010). Pastas e arquivos de um disco, o
organograma de uma empresa e o sumário de um livro são árvores gerais.

O primeiro impulso é dar a cada nó um vetor de ponteiros para os filhos,
como o `filhos[4]` do A193, no módulo 14. Isso trava no quinto filho: o
tópico com cinco subitens não cabe. E desperdiça memória, porque a maioria
dos nós de uma árvore são folhas e carregam quatro ponteiros `NULL` sem uso.
Aumentar o vetor piora o desperdício; diminuir piora a trava.

A saída é a representação **primeiro filho, próximo irmão** (*left-child,
right-sibling*). Cada nó guarda só dois ponteiros, qualquer que seja o
número de filhos: `filho` aponta para o primeiro filho do nó, e `irmao`
aponta para o próximo filho do mesmo pai (CORMEN et al., 2024, cap. 10). Na
reforma, `filho` aponta para a cozinha; a cozinha aponta, por `irmao`, para
o banheiro; o banheiro, para a pintura; e o `irmao` da pintura é `NULL`.

Repare no que isso forma: os filhos de um nó viram uma **lista encadeada**,
que começa em `filho` e segue pelos `irmao` até o `NULL`. Visitar todos os
filhos é percorrer essa lista, com o mesmo laço de sempre:

```c
for (const NoG *p = r->filho; p != NULL; p = p->irmao) { ... }
```

Há um efeito curioso. Com dois ponteiros por nó, a estrutura na memória é
uma **árvore binária**: `filho` faz o papel do ponteiro esquerdo e `irmao`,
do direito (CELES; RANGEL, 2002). Toda árvore geral pode ser guardada como
binária. Mas o significado muda: na binária, descer pela direita é descer um
nível; aqui, andar pelo `irmao` é andar para o lado, no mesmo nível.

As funções sobre a árvore seguem um molde recursivo: resolvem o nó, pedem a
resposta de cada filho percorrendo a lista e juntam tudo. O total de um
tópico é o valor dele mais o total de cada filho. Essa ordem, em que os
filhos ficam prontos antes do pai, é a **pós-ordem** (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 5). No banheiro, a função soma o box (900) e as
louças (700, que por sua vez já somaram vaso e cuba) e devolve 1600.

O preço da economia está no acesso. Cada nó tem tamanho fixo, 40 bytes no
TAD deste assunto, tenha ele um filho ou cem. Mas, para chegar ao k-ésimo
filho, é preciso andar k passos pela lista de irmãos, enquanto o vetor
chegava lá direto pelo índice. Para percorrer todos os filhos, que é o caso
comum, a diferença some.

> [!WARNING]
> O irmão está no **mesmo nível**. A altura escrita como na binária,
> `1 + maior(altura(r->filho), altura(r->irmao))`, conta cada irmão como um
> andar: no orçamento dá 6 em vez de 3. Só `filho` desce um nível.

{{exemplo}}

O orçamento de uma reforma em tópicos, com 10 nós; os tópicos que só agrupam
valem 0. Em cima a árvore, embaixo a memória: setas verdes para o primeiro
filho, roxas para o irmão:

{{ideia}}

O TAD está em `arvgen.h` e `arvgen.c`. O nó e as funções recursivas:

```c
typedef struct NoG {
    char nome[20];
    int valor;          // o valor do próprio nó (um grupo pode ter 0)
    struct NoG *filho;  // o primeiro filho
    struct NoG *irmao;  // o próximo irmão (mesmo pai)
} NoG;

int ag_total(const NoG *r) {
    int soma = r->valor;
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        soma += ag_total(p); // cada filho traz o total da sua subárvore
    }
    return soma;
}

static void mostra(const NoG *r, int nivel) {
    printf("%*s%s: %d\n", 2 * nivel, "", r->nome, ag_total(r));
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        mostra(p, nivel + 1);
    }
}
```

`ag_adiciona(pai, nome, valor)` pendura o filho novo no fim da fila de
irmãos e devolve o ponteiro dele:

```c
#include <stdio.h>
#include "arvgen.h"

int main(void) {
    NoG *reforma = ag_cria("reforma", 0);
    NoG *cozinha = ag_adiciona(reforma, "cozinha", 0);
    ag_adiciona(cozinha, "piso", 1800);
    ag_adiciona(cozinha, "pia", 650);
    NoG *banheiro = ag_adiciona(reforma, "banheiro", 0);
    ag_adiciona(banheiro, "box", 900);
    NoG *loucas = ag_adiciona(banheiro, "loucas", 0);
    ag_adiciona(loucas, "vaso", 420);
    ag_adiciona(loucas, "cuba", 280);
    ag_adiciona(reforma, "pintura", 1200);

    ag_mostra(reforma);
    printf("Itens: %d | altura: %d | grau da raiz: %d\n",
           ag_conta(reforma), ag_altura(reforma), ag_grau(reforma));

    ag_libera(reforma);
    return 0;
}
// Saída:
// reforma: 5250
//   cozinha: 2450
//     piso: 1800
//     pia: 650
//   banheiro: 1600
//     box: 900
//     loucas: 700
//       vaso: 420
//       cuba: 280
//   pintura: 1200
// Itens: 10 | altura: 3 | grau da raiz: 3
```

O fluxograma segue `ag_total` no banheiro: soma o box (900) e as louças (700)
e para quando `p` chega a `NULL`, devolvendo 1600:

{{fluxograma}}

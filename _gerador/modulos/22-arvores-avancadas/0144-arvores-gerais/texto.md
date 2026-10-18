## 0144 · Árvores gerais: primeiro filho, próximo irmão

Você vai reformar o apartamento e o empreiteiro mandou o orçamento em tópicos:
a reforma tem cozinha, banheiro e pintura; a cozinha tem piso e pia; o banheiro
tem box e louças; as louças têm vaso e cuba. Quanto custa o banheiro? E a obra
toda? Cada tópico tem quantos subtópicos quiser, e o total de um tópico é a soma
do que está embaixo dele.

Isso é uma **árvore geral** (ou n-ária): cada nó pode ter qualquer número de
filhos. No módulo 14, o A193 guardou as pastas num vetor fixo de filhos
(`filhos[4]`). Funciona até a pasta ganhar o quinto filho, e cada folha carrega
quatro ponteiros que nunca usa.

A saída clássica é a representação **primeiro filho / próximo irmão** (em
inglês, *left-child right-sibling*). Cada nó guarda só dois ponteiros: `filho`
aponta para o primeiro filho, e `irmao` aponta para o próximo filho do mesmo
pai. Os filhos de um nó formam uma **lista encadeada** que começa em `filho` e
segue pelos `irmao`.

Repare no que isso quer dizer: com dois ponteiros por nó, é uma **árvore
binária** disfarçada. Leia `filho` como "esquerdo" e `irmao` como "direito" e
qualquer árvore geral vira uma binária, sem perder nada. O nó tem o mesmo
tamanho tenha ele zero ou cinquenta filhos.

Visitar os filhos de um nó vira o laço de sempre da lista:

```c
for (const NoG *p = r->filho; p != NULL; p = p->irmao) { ... }
```

E as funções recursivas seguem o molde da árvore: resolva o próprio nó, peça a
resposta de cada filho e junte. O total do orçamento é o valor do nó mais o
total de cada filho, uma **pós-ordem**: os filhos ficam prontos antes do pai.

Vamos ver na prática. O orçamento da reforma tem 10 nós. Os tópicos que só
agrupam (reforma, cozinha, banheiro, louças) têm valor 0; os itens têm preço.
No desenho, em cima a árvore como você pensa nela; embaixo, como ela fica na
memória, com as setas verdes descendo para o primeiro filho e as roxas andando
para o irmão:

{{ideia}}

O TAD fica em `arvgen.h` e `arvgen.c`. O nó e as duas funções recursivas que
interessam aqui:

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

O cliente monta o orçamento com `ag_adiciona(pai, nome, valor)`, que pendura o
filho novo no fim da fila de irmãos e devolve o ponteiro dele:

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

Repara no fluxograma: é o `ag_total` chamado no banheiro. A soma começa no
valor próprio (0), o laço visita o box (900) e as louças (que devolvem 700 depois
de somar vaso e cuba) e para quando `p` chega em `NULL`, no fim da fila de
irmãos. O banheiro devolve 1600:

{{fluxograma}}

> [!WARNING]
> O irmão está no **mesmo nível**, não embaixo. Quem escreve a altura no
> estilo da árvore binária, `1 + maior(altura(r->filho), altura(r->irmao))`,
> conta cada irmão como mais um andar. No orçamento, o caminho reforma,
> cozinha, banheiro, box, louças, vaso, cuba vira uma escada de 6 degraus, e a
> resposta sai 6 em vez de 3. Na árvore geral, só o `filho` desce um nível; o
> `irmao` anda para o lado. O mesmo
> cuidado vale para o total: `total(p->filho) + total(p->irmao)` soma também os
> irmãos de `p`, que não são da subárvore dele.

> [!TIP]
> **Por dentro do C:** o `NoG` tem 40 bytes: 20 do nome, 4 do `int` e dois
> ponteiros de 8 bytes (os 20 + 4 = 24 já caem num múltiplo de 8, então não
> sobra enchimento). A reforma inteira cabe em 400 bytes, e uma pasta com 50
> filhos usaria os mesmos 40. Com um vetor fixo de 10 filhos, cada nó teria 104
> bytes e travaria no 11º filho. O preço dos dois ponteiros é o acesso: achar o
> k-ésimo filho custa k passos pela lista de irmãos, e `ag_adiciona` anda até o
> último irmão antes de pendurar o novo (inserir no começo seria O(1), mas
> inverteria a ordem dos filhos).

> [!NOTE]
> **Pergunta para você:** se o empreiteiro acrescentar `ag_adiciona(loucas,
> "torneira", 150)`, quais linhas da saída mudam? E se a torneira for
> pendurada na `pintura`? Pense na altura e no grau da raiz nos dois casos.

{{pratique}}

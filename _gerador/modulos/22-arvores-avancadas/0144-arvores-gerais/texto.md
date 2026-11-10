## 0144 · Árvores gerais: primeiro filho, próximo irmão

O empreiteiro mandou o orçamento da reforma em tópicos: a reforma tem
cozinha, banheiro e pintura; a cozinha tem piso e pia; o banheiro tem box e
louças; as louças têm vaso e cuba. O total de um tópico é a soma do que está
embaixo dele.

Isso é uma **árvore geral** (ou n-ária): cada nó pode ter qualquer número de
filhos. No módulo 14, o A193 usou um vetor fixo (`filhos[4]`), que trava no
quinto filho e desperdiça ponteiros nas folhas.

A saída é a representação **primeiro filho / próximo irmão** (*left-child
right-sibling*). Cada nó guarda dois ponteiros: `filho`, para o primeiro filho,
e `irmao`, para o próximo filho do mesmo pai. Os filhos formam uma **lista
encadeada** que começa em `filho` e segue pelos `irmao`.

Com dois ponteiros por nó, é uma **árvore binária**: `filho` faz o papel do
esquerdo e `irmao`, do direito. Visitar os filhos é o laço da lista:

```c
for (const NoG *p = r->filho; p != NULL; p = p->irmao) { ... }
```

As funções recursivas resolvem o nó, pedem a resposta de cada filho e juntam. O
total do orçamento é o valor do nó mais o total de cada filho: uma
**pós-ordem**, porque os filhos ficam prontos antes do pai.

O orçamento tem 10 nós; os tópicos que só agrupam valem 0. No desenho, em cima a
árvore e embaixo a memória: setas verdes para o primeiro filho, roxas para o
irmão:

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

O fluxograma acompanha `ag_total` no banheiro. A soma começa em 0, o laço
visita o box (900) e as louças (700) e para quando `p` chega a `NULL`. O
banheiro devolve 1600:

{{fluxograma}}

> [!WARNING]
> O irmão está no **mesmo nível**. Na altura escrita como na binária,
> `1 + maior(altura(r->filho), altura(r->irmao))`, cada irmão conta como um
> andar: no orçamento, a resposta sai 6 em vez de 3. Só `filho` desce um nível.
> Do mesmo modo, `total(p->filho) + total(p->irmao)` soma irmãos que não são da
> subárvore de `p`.

> [!TIP]
> O `NoG` tem 40 bytes, com qualquer número de filhos. O preço é o acesso:
> achar o k-ésimo filho custa k passos pela lista de irmãos.

> [!NOTE]
> **Pergunta para você:** se o empreiteiro acrescentar `ag_adiciona(loucas,
> "torneira", 150)`, quais linhas da saída mudam? E se a torneira for pendurada
> na `pintura`? Pense na altura e no grau da raiz nos dois casos.

{{pratique}}

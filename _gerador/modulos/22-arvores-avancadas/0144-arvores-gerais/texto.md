## 0144 · Árvores gerais: primeiro filho, próximo irmão

- **Árvore geral** (ou n-ária): cada nó pode ter qualquer número de filhos
  (SZWARCFITER; MARKENZON, 2010).
- **Vetor fixo de filhos** (`filhos[4]`, A193 do módulo 14) trava no quinto
  filho e desperdiça ponteiros nas folhas.
- **Primeiro filho / próximo irmão** (*left-child right-sibling*): cada nó
  guarda `filho`, o primeiro filho, e `irmao`, o próximo filho do mesmo pai
  (CORMEN et al., 2024, cap. 10).
- **Filhos como lista**: começam em `filho` e seguem pelos `irmao`. Com dois
  ponteiros, a árvore geral vira uma **árvore binária** (CELES; RANGEL, 2002).
- **Recursão**: resolve o nó, pede a resposta de cada filho e junta. Somar a
  subárvore é **pós-ordem**: os filhos ficam prontos antes do pai
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 5).
- **Custo**: o nó tem tamanho fixo (40 bytes aqui), mas achar o k-ésimo filho
  custa k passos pela lista de irmãos.

Visitar os filhos é o laço da lista:

```c
for (const NoG *p = r->filho; p != NULL; p = p->irmao) { ... }
```

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

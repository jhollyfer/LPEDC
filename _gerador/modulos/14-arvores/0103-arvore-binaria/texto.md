## 0103 · Árvore binária e percursos

Churrasco no sábado: vão 8 pessoas, 3 não bebem, e quem bebe paga R$ 4 de
cerveja mais R$ 2 de gelo. Na planilha você digita `=(8-3)*(4+2)` e ela
responde 30. Como a planilha sabe que a subtração e a soma vêm antes da
multiplicação? Ela monta uma **árvore** com a fórmula.

Uma **árvore binária** é uma árvore em que cada nó tem **no máximo dois
filhos**, e cada filho tem lado: o da **esquerda** ou o da **direita**. A
definição recursiva é curta: uma árvore binária é **vazia** (`NULL`) ou é um nó
com uma **subárvore esquerda** e uma **subárvore direita**, que também são
árvores binárias.

Lado importa. Um nó `A` com filho `B` à esquerda e um nó `A` com filho `B` à
direita são árvores **diferentes**. Isso não existia nas pastas do assunto
anterior, onde só contava a ordem dos filhos.

Em C, o nó é uma struct com o dado e dois ponteiros. Aqui o dado é um `char`,
que guarda um dígito ou um operador:

```c
typedef struct No {
    char info;
    struct No *esq; // subárvore da esquerda
    struct No *dir; // subárvore da direita
} No;
```

O resto vira um **TAD**: `arvore.h` com os protótipos, `arvore.c` com a
implementação, como no assunto 0079. Diferente da pilha e da fila, a struct fica
à mostra no `.h`, porque os exercícios precisam andar pelos nós. A função
`arv_cria(info, esq, dir)` monta um nó com as duas subárvores prontas, então
dá para construir a árvore de baixo para cima.

Montada a árvore, como visitar todos os nós? Existem quatro ordens clássicas, os
**percursos**:

| Percurso | Ordem | Na fórmula |
| --- | --- | --- |
| **pré-ordem** | raiz, esquerda, direita | `* - 8 3 + 4 2` (notação prefixa) |
| **em ordem** | esquerda, raiz, direita | `8 - 3 * 4 + 2` (infixa, sem parênteses) |
| **pós-ordem** | esquerda, direita, raiz | `8 3 - 4 2 + *` (pós-fixa, a da calculadora HP) |
| **por nível** | linha por linha, de cima para baixo | `* - + 8 3 4 2` |

Os três primeiros são recursivos e mudam só a posição do `printf` em relação às
duas chamadas. O por nível não desce por um lado e depois pelo outro: ele usa
uma **fila** (assunto 0090). Tira um nó da frente, mostra, põe os filhos dele no
fim, e repete até a fila esvaziar.

A pós-ordem é a ordem natural para **calcular**: você só aplica o `*` depois de
saber quanto valem as duas subárvores. É o mesmo algoritmo da pilha com notação
pós-fixa do assunto 0089, só que agora a árvore está desenhada.

Vamos ver na prática. Os operadores ficam nos nós internos (roxo) e os números
nas folhas (azul). Cada percurso lê a mesma árvore numa ordem diferente:

{{ideia}}

O cliente do TAD monta a árvore de baixo para cima e chama os percursos:

```c
#include <stdio.h>
#include "arvore.h"

int main(void) {
    // (8 - 3) * (4 + 2): 8 pessoas, 3 não bebem; cerveja R$ 4 + gelo R$ 2
    No *menos = arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL));
    No *mais = arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL));
    No *raiz = arv_cria('*', menos, mais);

    printf("Pré-ordem:");
    arv_pre_ordem(raiz);
    printf("\nEm ordem: ");
    arv_em_ordem(raiz);
    printf("\nPós-ordem:");
    arv_pos_ordem(raiz);
    printf("\nPor nível:");
    arv_por_nivel(raiz);
    printf("\nNós: %d, altura: %d\n", arv_conta(raiz), arv_altura(raiz));

    raiz = arv_libera(raiz);
    return 0;
}
// Saída:
// Pré-ordem: * - 8 3 + 4 2
// Em ordem:  8 - 3 * 4 + 2
// Pós-ordem: 8 3 - 4 2 + *
// Por nível: * - + 8 3 4 2
// Nós: 7, altura: 2
```

Dentro do `arvore.c`, a em ordem tem três linhas de verdade:

```c
void arv_em_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    arv_em_ordem(r->esq);
    printf(" %c", r->info);
    arv_em_ordem(r->dir);
}
```

Repara no fluxograma: o caso base é a árvore vazia. Num nó de verdade, a função
resolve a esquerda inteira, mostra a raiz e só então resolve a direita. Troque a
caixa azul de lugar e você tem a pré-ordem (antes) ou a pós-ordem (depois):

{{fluxograma}}

### Passo a passo

A pilha de chamadas da em ordem, a partir da raiz `*`. Cada linha é o momento em
que um `printf` acontece:

| Pilha de chamadas (topo à direita) | Mostra | Na tela até aqui |
| --- | --- | --- |
| `*` → `-` → `8` | 8 | `8` |
| `*` → `-` | - | `8 -` |
| `*` → `-` → `3` | 3 | `8 - 3` |
| `*` | * | `8 - 3 *` |
| `*` → `+` → `4` | 4 | `8 - 3 * 4` |
| `*` → `+` | + | `8 - 3 * 4 +` |
| `*` → `+` → `2` | 2 | `8 - 3 * 4 + 2` |

> [!WARNING]
> A em ordem **perde os parênteses**. `8 - 3 * 4 + 2`, lido por uma pessoa (ou
> pelo C), dá `8 - 12 + 2 = -2`, e não 30. A árvore não precisa de parênteses
> porque a forma dela já diz o que vem primeiro. Para mostrar a fórmula certa,
> a em ordem precisa abrir um `(` antes de cada subárvore e fechar depois. O
> exemplo A206 faz isso e calcula o valor em pós-ordem.

> [!TIP]
> **Por dentro do C:** cada nó ocupa 24 bytes: 1 do `char`, 7 de enchimento para
> alinhar os ponteiros e 2 ponteiros de 8 bytes. Uma árvore com `n` nós tem
> `n + 1` ponteiros `NULL` (aqui, 7 nós e 8 `NULL`, todos nas folhas). A
> recursão usa a pilha de chamadas: a profundidade máxima é a altura + 1 frames.
> Numa árvore equilibrada de um milhão de nós são uns 20 frames; numa árvore
> "torta", em fila indiana, seria um milhão, e a pilha estoura.

> [!NOTE]
> **Pergunta para você:** se a em ordem de uma árvore é `B A C` e a pré-ordem é
> `A B C`, quem é a raiz? Quem fica à esquerda? Desenhe. E com em ordem `A B C`
> e pré-ordem `A B C`, como fica a árvore?

{{pratique}}

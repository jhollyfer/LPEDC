## 0102 · Árvores

Abra o gerenciador de arquivos. Dentro de `casa` tem `fotos`, `contas` e
`musica`. Dentro de `fotos` tem `praia` e `natal`. Dentro de `contas` tem `agua`
e `luz`, e dentro de `luz` tem a pasta `2025`, com os boletos do ano. Nenhuma
lista, pilha ou fila desenha isso direito: uma pasta tem **várias** subpastas,
e cada subpasta tem as suas.

Essa forma de "um em cima, vários embaixo" é uma **árvore**. Você convive com
ela o tempo todo: a árvore genealógica da família, o organograma da empresa, o
chaveamento da Copa, o sumário de um livro (capítulos, seções, subseções).

Na computação a árvore cresce de cabeça para baixo. O vocabulário:

| Termo | O que é | Nas pastas |
| --- | --- | --- |
| **nó** | cada elemento da árvore | cada pasta |
| **raiz** | o nó do topo, o único sem pai | `casa` |
| **pai** e **filho** | o nó de cima e os nós ligados logo abaixo | `contas` é pai de `luz` |
| **irmãos** | filhos do mesmo pai | `praia` e `natal` |
| **folha** | nó sem filhos | `praia`, `natal`, `agua`, `2025`, `musica` |
| **subárvore** | um nó com tudo que está embaixo dele | `contas` com `agua`, `luz` e `2025` |
| **grau** | quantos filhos o nó tem | `casa` tem grau 3 |

Duas medidas aparecem em tudo daqui para a frente. A **profundidade** de um nó
é quantas arestas (ligações) existem entre ele e a raiz: `casa` tem
profundidade 0, `luz` tem 2. A **altura** de um nó é o tamanho do caminho mais
longo dele até uma folha. A altura da árvore é a altura da raiz.

Neste curso, altura se mede em **arestas**: uma folha tem altura 0 e uma árvore
vazia tem altura -1. Tem livro que conta nós em vez de arestas (folha com
altura 1). Nenhum está errado; só não misture.

A definição mais útil de árvore é **recursiva**: uma árvore é um nó (a raiz)
com zero ou mais árvores penduradas embaixo. Por isso quase toda função de
árvore é recursiva: resolva para cada filho e combine as respostas. Contar
folhas? Some as folhas de cada filho. Altura? Pegue a maior altura entre os
filhos e some 1.

Vamos ver na prática. A árvore das pastas tem 9 nós, 5 folhas (em verde) e
altura 3: o caminho mais longo vai de `casa` até `2025`, passando por `contas` e
`luz`:

{{ideia}}

Em C, cada pasta vira um nó com um nome e um vetor de ponteiros para os filhos.
Cada nó é criado com `malloc`, igual aos nós da lista encadeada:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    struct No *filhos[MAX_FILHOS]; // ponteiros para as subpastas
    int qtd;                       // quantas subpastas tem
} No;

No *novo(const char *nome) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    strcpy(n->nome, nome);
    n->qtd = 0;
    return n;
}

No *adiciona(No *pai, const char *nome) {
    No *filho = novo(nome);
    pai->filhos[pai->qtd++] = filho;
    return filho;
}

void mostra(const No *n, int profundidade) {
    // %*s com "" imprime 2 * profundidade espaços: o recuo
    printf("%*s%s (%d)\n", 2 * profundidade, "", n->nome, profundidade);
    for (int i = 0; i < n->qtd; i++) {
        mostra(n->filhos[i], profundidade + 1);
    }
}

int conta_folhas(const No *n) {
    if (n->qtd == 0) {
        return 1; // sem filhos: é folha
    }
    int total = 0;
    for (int i = 0; i < n->qtd; i++) {
        total += conta_folhas(n->filhos[i]);
    }
    return total;
}

int altura(const No *n) {
    int maior = -1;
    for (int i = 0; i < n->qtd; i++) {
        int h = altura(n->filhos[i]);
        if (h > maior) {
            maior = h;
        }
    }
    return maior + 1; // folha: -1 + 1 = 0
}

void libera(No *n) {
    for (int i = 0; i < n->qtd; i++) {
        libera(n->filhos[i]); // os filhos primeiro
    }
    free(n);
}

int main(void) {
    No *casa = novo("casa");
    No *fotos = adiciona(casa, "fotos");
    No *contas = adiciona(casa, "contas");
    adiciona(casa, "musica");
    adiciona(fotos, "praia");
    adiciona(fotos, "natal");
    adiciona(contas, "agua");
    No *luz = adiciona(contas, "luz");
    adiciona(luz, "2025");

    mostra(casa, 0);
    printf("Folhas: %d\n", conta_folhas(casa));
    printf("Altura: %d\n", altura(casa));
    libera(casa);
    return 0;
}
// Saída:
// casa (0)
//   fotos (1)
//     praia (2)
//     natal (2)
//   contas (1)
//     agua (2)
//     luz (2)
//       2025 (3)
//   musica (1)
// Folhas: 5
// Altura: 3
```

Repara no fluxograma da `altura`: não existe um caso especial para a folha. Ela
não entra no laço, `maior` fica em -1 e a função devolve 0. Cada pasta pergunta
a altura dos filhos e soma 1 à maior resposta. Em `casa`, os filhos respondem 1
(`fotos`), 2 (`contas`) e 0 (`musica`), e ela devolve 2 + 1 = 3:

{{fluxograma}}

> [!WARNING]
> A ordem do `free` importa. Se `libera` fizer `free(n)` **antes** de visitar os
> filhos, o laço seguinte lê `n->qtd` e `n->filhos[i]` de memória já devolvida:
> é uso depois de liberar, e o AddressSanitizer acusa na hora. Numa árvore,
> libere de baixo para cima: primeiro as subárvores, por último o nó.

> [!TIP]
> **Por dentro do C:** este nó ocupa 56 bytes: 16 do nome, 4 ponteiros de 8
> bytes (32), 4 do `int` e mais 4 de enchimento (*padding*) para o tamanho ficar
> múltiplo de 8. Uma folha gasta os mesmos 56 bytes, com 4 ponteiros sem uso. O
> exemplo A204 mostra a saída clássica: **primeiro filho / próximo irmão**. Cada
> nó guarda só dois ponteiros, um para o primeiro filho e outro para o próximo
> irmão, e aceita qualquer número de filhos. Repare que isso é, na prática, uma
> árvore binária, o assunto seguinte.

> [!NOTE]
> **Pergunta para você:** se você criar a pasta `2026` dentro de `2025`, o que
> muda na saída? Quantas folhas e qual altura? E se criar `2026` dentro de
> `musica`? Responda antes de mudar o A203.

{{pratique}}

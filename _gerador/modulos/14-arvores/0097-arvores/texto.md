## 0097 · Árvores

No gerenciador de arquivos, `casa` tem `fotos`, `contas` e `musica`. `fotos`
tem `praia` e `natal`. `contas` tem `agua` e `luz`, e `luz` tem a pasta `2025`.
Nenhuma lista, pilha ou fila desenha isso: uma pasta tem **várias** subpastas.

Essa forma de "um em cima, vários embaixo" é uma **árvore**, como o
organograma e o sumário de um livro. Na computação ela cresce de cabeça para
baixo. O vocabulário:

| Termo | O que é | Nas pastas |
| --- | --- | --- |
| **nó** | cada elemento da árvore | cada pasta |
| **raiz** | o nó do topo, o único sem pai | `casa` |
| **pai** e **filho** | o nó de cima e os nós ligados logo abaixo | `contas` é pai de `luz` |
| **irmãos** | filhos do mesmo pai | `praia` e `natal` |
| **folha** | nó sem filhos | `praia`, `natal`, `agua`, `2025`, `musica` |
| **subárvore** | um nó com tudo que está embaixo dele | `contas` com `agua`, `luz` e `2025` |
| **grau** | quantos filhos o nó tem; o da árvore é o maior deles | `casa` tem grau 3 |

A **profundidade** de um nó é o número de arestas (ligações) até a raiz: `casa`
tem profundidade 0, `luz` tem 2. O **nível** é a profundidade. A **altura** de
um nó é o caminho mais longo dele até uma folha, e a altura da árvore é a da
raiz.

Aqui, altura se mede em **arestas**: folha tem altura 0 e árvore vazia tem
altura -1 (convenção do Cormen). Há livros que contam nós; não misture.

A definição mais útil é **recursiva**: uma árvore é um nó (a raiz) com zero ou
mais árvores penduradas embaixo. Por isso quase toda função de árvore é
recursiva: resolve cada filho e combina as respostas. Folhas: some as folhas
dos filhos. Altura: maior altura dos filhos, mais 1.

A árvore das pastas tem 9 nós, 5 folhas (em verde) e altura 3: o caminho mais
longo vai de `casa` até `2025`, por `contas` e `luz`:

{{ideia}}

Em C, cada pasta é um nó com um nome e um vetor de ponteiros para os filhos,
criado com `malloc` como os nós da lista encadeada:

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

A `altura` não trata a folha à parte: ela não entra no laço, `maior` fica em -1
e a função devolve 0. Em `casa`, os filhos respondem 1, 2 e 0, e ela devolve
2 + 1 = 3:

{{fluxograma}}

> [!WARNING]
> Libere de baixo para cima: primeiro as subárvores, por último o nó. Com
> `free(n)` **antes** dos filhos, o laço lê memória já devolvida.

> [!TIP]
> A alternativa **primeiro filho / próximo irmão** usa só dois ponteiros por nó
> e aceita qualquer número de filhos (exemplo A194).

> [!NOTE]
> **Pergunta para você:** se você criar a pasta `2026` dentro de `2025`, o que
> muda na saída? Quantas folhas e qual altura? E se criar `2026` dentro de
> `musica`?

{{pratique}}

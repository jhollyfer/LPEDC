## 0097 · Árvores

- **Árvore**: estrutura em que cada elemento tem um só "de cima" e pode ter
  vários "de baixo". Serve para pastas, organogramas e sumários
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 5).
- **Definição recursiva**: uma árvore é um nó, a **raiz**, com zero ou mais
  árvores penduradas embaixo. Por isso quase toda função de árvore resolve
  cada filho e junta as respostas (FEOFILOFF, 2009).
- **Profundidade** (ou **nível**): quantas arestas separam o nó da raiz. A
  raiz tem profundidade 0 (CELES; RANGEL, 2002).
- **Altura**: o caminho mais longo, em arestas, do nó até uma folha. A altura
  da árvore é a da raiz; folha tem altura 0 e árvore vazia, -1
  (FEOFILOFF, 2009).
- **Liberar**: cada nó vem de um `malloc`, como na lista encadeada; o `free`
  vem depois dos filhos (CELES; RANGEL, 2002).

| Termo | O que é | Nas pastas |
| --- | --- | --- |
| **nó** | cada elemento da árvore | cada pasta |
| **raiz** | o nó do topo, o único sem pai | `casa` |
| **pai** e **filho** | o nó de cima e os nós ligados logo abaixo | `contas` é pai de `luz` |
| **irmãos** | filhos do mesmo pai | `praia` e `natal` |
| **folha** | nó sem filhos | `praia`, `natal`, `agua`, `2025`, `musica` |
| **subárvore** | um nó com tudo que está embaixo dele | `contas` com `agua`, `luz` e `2025` |
| **grau** | quantos filhos o nó tem; o da árvore é o maior deles | `casa` tem grau 3 |

> [!WARNING]
> Aqui a altura conta **arestas**. Há livros que contam nós, e a mesma árvore
> ganha 1 a mais; não misture. Na hora de liberar, primeiro as subárvores: com
> `free(n)` **antes** dos filhos, o laço lê memória já devolvida.

{{exemplo}}

As pastas de um computador: `casa` tem `fotos`, `contas` e `musica`, e `luz`
fica dentro de `contas`. São 9 nós, 5 folhas (em verde) e altura 3, de `casa`
até `2025`:

{{ideia}}

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

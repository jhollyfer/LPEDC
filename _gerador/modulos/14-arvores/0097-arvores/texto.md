## 0097 · Árvores

No gerenciador de arquivos, a pasta `casa` tem `fotos`, `contas` e `musica`.
`fotos` tem `praia` e `natal`. `contas` tem `agua` e `luz`, e `luz` tem a
pasta `2025`. Tente guardar isso numa lista, numa pilha ou numa fila e você
esbarra no mesmo problema: todas elas põem um elemento depois do outro, numa
linha. Uma pasta tem **várias** subpastas, e cada subpasta pode ter as suas.
Falta uma estrutura que se ramifique.

Essa forma de "um em cima, vários embaixo" é a **árvore**: uma estrutura em
que cada elemento tem um único elemento acima dele, exceto o primeiro, e pode
ter vários abaixo (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 5). O
organograma de uma empresa e o sumário de um livro têm essa forma. Na
computação, a árvore se desenha de cabeça para baixo: a origem fica no alto e
os galhos descem.

O vocabulário vem dessa imagem e da árvore genealógica. Cada elemento é um
**nó**, e a ligação entre dois nós é uma **aresta**. O nó do topo, o único sem
ninguém acima, é a **raiz**; nas pastas, é `casa`. Um nó é **pai** dos nós
ligados logo abaixo dele, que são seus **filhos**, e filhos do mesmo pai são
**irmãos**. Um nó sem filhos é uma **folha**. Um nó junto com tudo que está
abaixo dele forma uma **subárvore**. O **grau** de um nó é quantos filhos ele
tem, e o grau da árvore é o maior grau entre os nós. A tabela aplica cada
termo às pastas:

| Termo | O que é | Nas pastas |
| --- | --- | --- |
| **nó** | cada elemento da árvore | cada pasta |
| **raiz** | o nó do topo, o único sem pai | `casa` |
| **pai** e **filho** | o nó de cima e os nós ligados logo abaixo | `contas` é pai de `luz` |
| **irmãos** | filhos do mesmo pai | `praia` e `natal` |
| **folha** | nó sem filhos | `praia`, `natal`, `agua`, `2025`, `musica` |
| **subárvore** | um nó com tudo que está embaixo dele | `contas` com `agua`, `luz` e `2025` |
| **grau** | quantos filhos o nó tem; o da árvore é o maior deles | `casa` tem grau 3 |

Duas medidas dizem onde um nó está. A **profundidade**, também chamada de
**nível**, é o número de arestas entre o nó e a raiz: `casa` tem profundidade
0, `contas` tem 1 e `luz` tem 2 (CELES; RANGEL, 2002). A **altura** olha para
baixo: é o número de arestas do caminho mais longo entre o nó e uma folha. A
altura da árvore é a altura da raiz. Nesta convenção, que conta arestas, a
folha tem altura 0 e a árvore vazia tem altura -1 (FEOFILOFF, 2009). A árvore
das pastas tem altura 3, pelo caminho `casa`, `contas`, `luz`, `2025`.

A definição que mais ajuda a programar é **recursiva**: uma árvore é um nó, a
raiz, com zero ou mais árvores penduradas embaixo dele (FEOFILOFF, 2009). Cada
filho da raiz é, ele mesmo, a raiz de uma árvore menor. Por isso quase toda
função de árvore é recursiva e segue o mesmo molde: resolve o problema em cada
filho e combina as respostas. Para contar folhas, você soma as folhas dos
filhos, e um nó sem filhos conta 1. Para a altura, você pega a maior altura
entre os filhos e soma 1.

Em C, cada nó vem de um `malloc`, como na lista encadeada do módulo 11, e por
isso precisa de um `free` no fim. A ordem importa: o nó só pode ser liberado
**depois** dos filhos, porque é ele que guarda os endereços deles (CELES;
RANGEL, 2002). Para guardar um número qualquer de filhos com só dois
ponteiros por nó, há a representação **primeiro filho, próximo irmão**: cada
nó aponta para o filho mais à esquerda e para o irmão seguinte.

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

## 0102 · Heap e fila de prioridade

- **Fila de prioridade**: cada item entra com uma prioridade e sai primeiro o
  de **maior** prioridade (CORMEN et al., 2024, cap. 6).
- **Heap de máximo**: árvore binária com duas regras. **Forma**: completa,
  todos os níveis cheios menos talvez o último, que enche da esquerda para a
  direita. **Ordem**: todo pai é maior ou igual aos filhos, e o máximo fica na
  raiz (CORMEN et al., 2024, cap. 6).
- **Regra mais fraca que a da BST**: esquerda e direita não se comparam. O
  heap só responde "quem é o maior?" (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
  cap. 6).
- **Heap em vetor**: a forma completa deixa guardar a árvore nível por nível,
  sem buracos e sem ponteiros (FEOFILOFF, 2009).
- **Inserir**: o novo entra no fim e **sobe**, trocando com o pai enquanto for
  maior. **Remover o máximo**: o último vai para a raiz e **desce**, trocando
  com o **maior** filho. As duas custam até a altura, ⌊log₂ n⌋; no Cormen a
  descida é a `MAX-HEAPIFY` (CORMEN et al., 2024, cap. 6).
- **Heap de mínimo**: as comparações invertidas; o menor fica na raiz
  (FEOFILOFF, 2009).
- **Dois heaps diferentes**: este heap (estrutura de dados) não tem relação
  com o heap do `malloc` (assunto 0053) (FEOFILOFF, 2009).

| Quem | Índice com `v[0]` na raiz | No Cormen (`A[1..n]`) |
| --- | --- | --- |
| pai de `i` | `(i - 1) / 2` (divisão inteira) | `⌊i/2⌋` |
| filho esquerdo | `2 * i + 1` | `2i` |
| filho direito | `2 * i + 2` | `2i + 1` |

| Onde guardar | Inserir | Tirar o máximo |
| --- | --- | --- |
| vetor solto | O(1) | O(n) |
| vetor ordenado | O(n) | O(1) |
| heap | O(log n) | O(log n) |

> [!WARNING]
> Na descida, troque com o **maior** dos filhos; trocar com o menor quebra o
> heap. Confira `f + 1 < h->n` antes de ler `v[f + 1]`, e numa questão veja em
> que índice o vetor começa.

{{exemplo}}

No pronto-socorro, chegam pacientes com gravidade 40, 70, 20, 90, 50 e 30. O
heap fica `[90 70 30 40 50 20]`. O 70 está no índice 1, e os filhos dele, nos
índices 3 e 4:

{{ideia}}

O TAD guarda o vetor, quantos elementos tem e quantos cabem. As duas peças do
`heap.c`:

```c
// o elemento em i sobe enquanto for maior que o pai
static void sobe(Heap *h, int i) {
    while (i > 0 && h->v[(i - 1) / 2] < h->v[i]) {
        troca(&h->v[(i - 1) / 2], &h->v[i]);
        i = (i - 1) / 2;
    }
}

// o elemento em i desce, trocando com o MAIOR dos filhos
static void desce(Heap *h, int i) {
    while (2 * i + 1 < h->n) {
        int f = 2 * i + 1;                       // filho esquerdo
        if (f + 1 < h->n && h->v[f + 1] > h->v[f]) {
            f++;                                 // o direito é maior
        }
        if (h->v[i] >= h->v[f]) {
            break;                               // já está no lugar
        }
        troca(&h->v[i], &h->v[f]);
        i = f;
    }
}
```

O cliente só vê `heap_insere` e `heap_remove`:

```c
#include <stdio.h>
#include "heap.h"

int main(void) {
    // gravidade de cada paciente, na ordem em que chegaram (maior = mais urgente)
    int chegada[] = {40, 70, 20, 90, 50, 30};
    Heap *fila = heap_cria(10);

    for (int i = 0; i < 6; i++) {
        heap_insere(fila, chegada[i]);
        printf("Chega %d: ", chegada[i]);
        heap_mostra(fila);
        printf("\n");
    }
    for (int i = 0; i < 2; i++) {
        int atendido = heap_remove(fila);
        printf("Atende %d: ", atendido);
        heap_mostra(fila);
        printf("\n");
    }

    heap_libera(fila);
    return 0;
}
// Saída:
// Chega 40: [40]
// Chega 70: [70 40]
// Chega 20: [70 40 20]
// Chega 90: [90 70 20 40]
// Chega 50: [90 70 20 40 50]
// Chega 30: [90 70 30 40 50 20]
// Atende 90: [70 50 30 40 20]
// Atende 70: [50 40 30 20]
```

O fluxograma segue a subida do 30: entra no índice 5, o pai (índice 2) é o 20,
menor, e eles trocam. O novo pai é o 90, e a subida para:

{{fluxograma}}

### Passo a passo

A remoção do 90. O último (20) vai para a raiz e desce pelo filho maior:

| Passo | Vetor | `i` | Filhos de `i` | Maior filho | Troca? |
| --- | --- | --- | --- | --- | --- |
| tira o 90, o 20 vai para `v[0]` | `[20 70 30 40 50]` | 0 | 70, 30 | 70 (índice 1) | sim |
| | `[70 20 30 40 50]` | 1 | 40, 50 | 50 (índice 4) | sim |
| | `[70 50 30 40 20]` | 4 | (nenhum) | | para |

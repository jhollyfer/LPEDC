## 0102 · Heap e fila de prioridade

No pronto-socorro, o próximo atendido é o **mais grave** de quem espera, não o
primeiro a chegar.

Isso é uma **fila de prioridade**: insere-se com uma prioridade e tira-se o de
**maior** prioridade. Num vetor solto, inserir é O(1) e achar o máximo é O(n).
Num vetor ordenado, tirar o máximo é O(1) e inserir é O(n). Numa BST, os dois
são O(log n) só se ela estiver equilibrada.

O **heap** (de máximo) faz as duas em O(log n), sempre, sem ponteiros. É uma
árvore binária com duas regras:

- **forma**: **completa**: todos os níveis cheios, menos talvez o último, que
  se enche da esquerda para a direita;
- **ordem**: todo pai é **maior ou igual** aos filhos. O máximo está na raiz.

A regra de ordem é mais fraca que a da BST: esquerda e direita não se
comparam. Por isso o heap só responde "quem é o maior?".

A regra de forma permite guardar o heap **num vetor**, nível por nível, sem
buracos. A raiz fica em `v[0]` e, para o índice `i`:

| Quem | Índice |
| --- | --- |
| pai de `i` | `(i - 1) / 2` (divisão inteira) |
| filho esquerdo | `2 * i + 1` |
| filho direito | `2 * i + 2` |

O Cormen usa `A[1..n]`, com `PARENT(i) = ⌊i/2⌋`, `LEFT(i) = 2i` e
`RIGHT(i) = 2i + 1`. Numa questão, confira em que índice o vetor começa.

As duas operações consertam o heap por um único caminho:

- **inserir**: o novo entra no fim do vetor e **sobe**, trocando com o pai
  enquanto for maior que ele;
- **remover o máximo**: a raiz sai, o último elemento vai para o lugar dela e
  **desce**, trocando com o **maior** dos filhos enquanto for menor que algum.

O custo máximo é a altura, ⌊log₂ n⌋. No Cormen, a descida é a `MAX-HEAPIFY`.
Invertendo as comparações, o **heap de mínimo** tem o menor na raiz.

Chegam pacientes com gravidade 40, 70, 20, 90, 50 e 30. O heap fica
`[90 70 30 40 50 20]`. Árvore e vetor são a mesma coisa: o 70 está no índice
1, e os filhos dele, nos índices 3 e 4:

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

> [!WARNING]
> Na descida, troque com o **maior** dos filhos. Trocar o 20 com o 30 o poria
> acima do 70
> e quebraria o heap. Confira `f + 1 < h->n` antes de ler `v[f + 1]`.

> [!TIP]
> Não confunda este heap (estrutura de dados) com o heap do `malloc` (assunto
> 0053, região de memória).

> [!NOTE]
> **Pergunta para você:** o vetor `[90 70 30 40 50 20]` é um heap. E
> `[90 30 70 40 50 20]`? Um vetor em ordem **decrescente** é sempre um
> heap?

{{pratique}}

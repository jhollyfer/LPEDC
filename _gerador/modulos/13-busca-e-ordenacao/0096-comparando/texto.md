## 0096 · Comparando: estabilidade, custo e qsort

A planilha de pedidos vem em ordem de horário, e a logística pede: "agrupa por
cidade, mas mantém a ordem de chegada dentro de cada cidade". Qual algoritmo
usar? Precisa escrever um?

Um algoritmo de ordenação é **estável** quando elementos com chave **igual**
saem na ordem relativa em que entraram. Se três pedidos de Recife chegaram como
R1, R3, R6, um algoritmo estável devolve R1, R3, R6; um instável pode
devolver R3, R1, R6. Com `int` isso não importa; com structs, importa.

Outros critérios:

- **custo** no melhor, no médio e no pior caso (o pior derruba o sistema);
- **memória extra**: **in-place** (O(1) a mais) ou rascunho O(n);
- **adaptativo**: fica mais rápido com o vetor quase em ordem.

Resumo do módulo:

| Algoritmo | Melhor | Médio | Pior | Memória extra | Estável |
| --- | --- | --- | --- | --- | --- |
| bubble (com bandeira) | O(n) | O(n²) | O(n²) | O(1) | sim |
| selection | O(n²) | O(n²) | O(n²) | O(1) | não |
| insertion | O(n) | O(n²) | O(n²) | O(1) | sim |
| merge | O(n log n) | O(n log n) | O(n log n) | O(n) | sim |
| quick | O(n log n) | O(n log n) | O(n²) | O(log n) a O(n) de pilha | não |
| heap (assunto 0103) | O(n log n) | O(n log n) | O(n log n) | O(1) | não |

Não existe o melhor de todos. O insertion ganha em vetores pequenos ou quase
ordenados. O merge garante n log n e estabilidade, ao custo de memória. O quick
é o mais rápido na média, mas tem pior caso O(n²) e não é estável. O selection
faz o mínimo de trocas.

Na prática, use o **`qsort`** da `stdlib.h`, genérico (assunto 0050, ponteiro
para função):

```text
void qsort(void *base, size_t n, size_t tamanho,
           int (*compara)(const void *, const void *));
```

O `qsort` não conhece o tipo dos elementos (por isso o `void *` e o
`tamanho`). A sua `compara` recebe dois ponteiros e devolve **negativo** se o
primeiro vem antes, **zero** se empatam e **positivo** se vem depois, como o
`strcmp`.

Por cidade, um algoritmo estável (insertion, merge) mantém R1, R3, R6. O
selection, com trocas de longa distância, entrega R3 antes de R1:

{{ideia}}

A norma **não promete** que o `qsort` é estável. Se a ordem dos empatados
importa, ponha o desempate na `compara`: cidade primeiro, horário depois. Isso
é uma **chave composta**; a **chave simples** é um campo só (assunto 0180).

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    int hora;          // hhmm
    char cidade[16];
} Pedido;

// contrato do qsort: negativo se a vem antes, 0 se empata, positivo se depois
int compara(const void *a, const void *b) {
    const Pedido *p = a;
    const Pedido *q = b;
    int c = strcmp(p->cidade, q->cidade);   // 1º critério: cidade
    if (c != 0) {
        return c;
    }
    return (p->hora > q->hora) - (p->hora < q->hora); // desempate: horário
}

int main(void) {
    Pedido pedidos[] = {           // chegaram nesta ordem (por horário)
        {101, 910, "Recife"},
        {102, 925, "Manaus"},
        {103, 1005, "Recife"},
        {104, 1040, "Natal"},
        {105, 1115, "Manaus"},
        {106, 1150, "Recife"},
    };
    size_t n = sizeof pedidos / sizeof pedidos[0];

    qsort(pedidos, n, sizeof pedidos[0], compara);

    for (size_t i = 0; i < n; i++) {
        printf("%-7s %02d:%02d  #%d\n", pedidos[i].cidade,
               pedidos[i].hora / 100, pedidos[i].hora % 100, pedidos[i].numero);
    }
    return 0;
}
// Saída:
// Manaus  09:25  #102
// Manaus  11:15  #105
// Natal   10:40  #104
// Recife  09:10  #101
// Recife  10:05  #103
// Recife  11:50  #106
```

### Passo a passo

O exemplo A192 roda os cinco algoritmos com 1000 números:

| n = 1000 | aleatório | ordenado | invertido |
| --- | --- | --- | --- |
| bubble | 499.122 | 999 | 499.500 |
| selection | 499.500 | 499.500 | 499.500 |
| insertion | 241.308 | 999 | 499.500 |
| merge | 8.696 | 4.932 | 5.044 |
| quick (pivô no fim) | 10.972 | 499.500 | 499.500 |

No aleatório, os O(n log n) fazem umas 50 vezes menos trabalho. No ordenado, o
bubble e o insertion fazem uma passada só e o quick com pivô no fim cai no pior
caso. O selection não percebe diferença.

O caminho marcado no fluxograma é o deste exemplo: a ordem de chegada cabe
como desempate na `compara`, então `qsort` resolve:

{{fluxograma}}

> [!WARNING]
> `return *(const int *) a - *(const int *) b;` passa nos testes pequenos, mas
> com sinais opostos e valores grandes (`INT_MAX` e `-5`) a subtração dá
> **overflow** e a ordem sai errada. Escreva `return (x > y) - (x < y);`.

> [!TIP]
> A norma não diz qual algoritmo o `qsort` usa: não conte com estabilidade. Para
> buscar num vetor ordenado pela `compara`, use a **`bsearch`**, da `stdlib.h`.

> [!NOTE]
> **Pergunta para você:** se a `compara` só comparasse a cidade, a saída seria
> sempre igual? Em que ordem você esperaria os três pedidos de Recife?

{{pratique}}

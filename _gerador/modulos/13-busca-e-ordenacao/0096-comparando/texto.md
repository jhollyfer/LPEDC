## 0096 · Comparando: estabilidade, custo e qsort

- **Estável**: elementos com chave **igual** saem na ordem relativa em que
  entraram. Com `int` não importa; com structs, sim (FEOFILOFF, 2009).
- **Outros critérios**: **custo** no melhor, médio e pior caso; **memória
  extra**, **in-place** (O(1)) ou rascunho O(n); **adaptativo**, mais rápido
  com o vetor quase em ordem (ZIVIANI, 2010, cap. 4).
- **Não há o melhor de todos**: insertion ganha em vetores pequenos ou quase
  ordenados; merge garante n log n e estabilidade, com memória; quick é o
  mais rápido na média, mas tem pior caso O(n²); selection faz o mínimo de
  trocas (FEOFILOFF, 2009).
- **`qsort`** da `stdlib.h`: ordenação genérica com ponteiro para função
  (0050). Não conhece o tipo, por isso o `void *` e o `tamanho`
  (KERNIGHAN; RITCHIE, 1989).

```text
void qsort(void *base, size_t n, size_t tamanho,
           int (*compara)(const void *, const void *));
```

- **Função de comparação**: devolve **negativo** se o primeiro vem antes,
  **zero** se empatam e **positivo** se vem depois, como o `strcmp`
  (CPPREFERENCE, s.d.).
- **Estabilidade do `qsort`**: a norma não promete. Se a ordem dos empatados
  importa, ponha o desempate na função: uma **chave composta** (0180)
  (LINUX MAN-PAGES, s.d.).
- **`bsearch`**: busca binária da `stdlib.h` num vetor ordenado pela mesma
  função de comparação (CELES; RANGEL, 2002).

| Algoritmo | Melhor | Médio | Pior | Memória extra | Estável |
| --- | --- | --- | --- | --- | --- |
| bubble (com bandeira) | O(n) | O(n²) | O(n²) | O(1) | sim |
| selection | O(n²) | O(n²) | O(n²) | O(1) | não |
| insertion | O(n) | O(n²) | O(n²) | O(1) | sim |
| merge | O(n log n) | O(n log n) | O(n log n) | O(n) | sim |
| quick | O(n log n) | O(n log n) | O(n²) | O(log n) a O(n) de pilha | não |
| heap (assunto 0103) | O(n log n) | O(n log n) | O(n log n) | O(1) | não |

> [!WARNING]
> `return *(const int *) a - *(const int *) b;` passa nos testes pequenos,
> mas com sinais opostos e valores grandes (`INT_MAX` e `-5`) a subtração dá
> **overflow**. Escreva `return (x > y) - (x < y);`.

{{exemplo}}

A planilha de pedidos vem em ordem de horário, e a logística quer agrupar por
cidade mantendo a ordem de chegada. Um algoritmo estável mantém R1, R3, R6; o
selection, com trocas de longa distância, entrega R3 antes de R1:

{{ideia}}

O desempate pelo horário vai na `compara`, e o `qsort` resolve:

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

No aleatório, os O(n log n) fazem umas 50 vezes menos trabalho. No ordenado,
bubble e insertion fazem uma passada e o quick com pivô no fim cai no pior
caso.

A ordem de chegada cabe como desempate na `compara`, então o caminho termina
no `qsort`:

{{fluxograma}}

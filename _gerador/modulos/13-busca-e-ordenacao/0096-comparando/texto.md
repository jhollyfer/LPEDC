## 0096 · Comparando: estabilidade, custo e qsort

A planilha de pedidos vem em ordem de horário, e a logística pede: "agrupa
por cidade, mas mantém a ordem de chegada dentro de cada cidade". Você já
conhece seis métodos de ordenação. Qual deles serve? E, num programa de
verdade, precisa escrever algum? Este assunto compara os métodos pelos
critérios que decidem a escolha e apresenta a ordenação que o C já traz
pronta.

O pedido da logística depende de **estabilidade**, que o 0092 apresentou: um
método é estável quando elementos com chave **igual** saem na mesma ordem
relativa em que entraram (FEOFILOFF, 2009). Se três pedidos de Recife chegaram
como R1, R3 e R6, um método estável que ordena por cidade devolve R1, R3, R6.
Um instável pode devolver R3, R1, R6. Num vetor de `int` isso não faz
diferença, porque dois 7 são indistinguíveis. Num vetor de `struct`, em que a
chave é só um dos campos, faz toda a diferença: os outros campos revelam a
troca.

Além da estabilidade, três critérios pesam (ZIVIANI, 2010, cap. 4). O
primeiro é o **custo** no melhor, no médio e no pior caso; o pior caso importa
porque é ele que trava um sistema no dia em que a entrada vem ruim. O segundo
é a **memória extra**: um método **in-place** usa só O(1) além do vetor,
enquanto o merge sort precisa de um rascunho O(n). O terceiro é ser
**adaptativo**, isto é, ficar mais rápido quando o vetor já está quase em
ordem, como o insertion sort e o bubble sort com bandeira. A tabela reúne o
módulo inteiro, e o heapsort, que entra no assunto 0103:

| Algoritmo | Melhor | Médio | Pior | Memória extra | Estável |
| --- | --- | --- | --- | --- | --- |
| bubble (com bandeira) | O(n) | O(n²) | O(n²) | O(1) | sim |
| selection | O(n²) | O(n²) | O(n²) | O(1) | não |
| insertion | O(n) | O(n²) | O(n²) | O(1) | sim |
| merge | O(n log n) | O(n log n) | O(n log n) | O(n) | sim |
| quick | O(n log n) | O(n log n) | O(n²) | O(log n) a O(n) de pilha | não |
| heap (assunto 0103) | O(n log n) | O(n log n) | O(n log n) | O(1) | não |

A tabela mostra que não existe um método melhor que todos. O insertion sort
ganha em vetores pequenos ou quase ordenados. O merge sort garante
O(n log n) e estabilidade, pagando com memória. O quick sort é o mais rápido
na média, mas tem pior caso O(n²) e não é estável. O selection sort faz o
mínimo de trocas, o que ajuda quando mover um elemento é caro (FEOFILOFF,
2009). Para a logística, servem o insertion e o merge, que são estáveis.

Num programa real, você não escreve a ordenação: usa a **`qsort`**, da
`stdlib.h`. Ela ordena um vetor de qualquer tipo, e o truque para isso é o
ponteiro para função do assunto 0050 (KERNIGHAN; RITCHIE, 1989):

```text
void qsort(void *base, size_t n, size_t tamanho,
           int (*compara)(const void *, const void *));
```

A `qsort` não sabe o tipo dos elementos. Por isso recebe o vetor como
`void *`, o endereço cru do primeiro byte, junto com o número de elementos e o
`tamanho` de cada um em bytes: com esses dados ela sabe onde começa cada
elemento e consegue copiá-los. O que ela não sabe é qual vem antes, e isso
você ensina com a **função de comparação**. Ela recebe os endereços de dois
elementos e devolve um número **negativo** se o primeiro deve vir antes,
**zero** se os dois empatam e **positivo** se o primeiro deve vir depois, a
mesma convenção do `strcmp` (CPPREFERENCE, s.d.).

A norma do C não diz qual algoritmo a `qsort` usa, e por isso não promete
estabilidade. Se a ordem dos empatados importa, ponha o desempate dentro da
própria função de comparação: compare a cidade e, se empatar, compare o
horário. Essa é uma **chave composta** (0180) (LINUX MAN-PAGES, s.d.). Para
buscar num vetor ordenado pela mesma função, a `stdlib.h` traz a **`bsearch`**,
uma busca binária genérica que recebe a mesma função de comparação (CELES;
RANGEL, 2002).

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

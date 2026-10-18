## 0096 · Comparando: estabilidade, custo e qsort

Você exporta a planilha de pedidos da loja virtual. Ela vem em ordem de
horário. O pessoal da logística pede: "agrupa por cidade, mas dentro de cada
cidade mantém a ordem em que chegaram". Qual dos cinco algoritmos você usa? E
precisa mesmo escrever um?

Primeiro, um conceito novo. Um algoritmo de ordenação é **estável** quando
elementos com a **mesma chave** saem na mesma ordem relativa em que entraram.
Se três pedidos de Recife chegaram como R1, R3, R6, um algoritmo estável
ordenando por cidade devolve R1, R3, R6, nessa ordem. Um instável pode
devolver R3, R1, R6. Com `int` isso não importa (um 7 é igual ao outro); com
structs, importa muito.

Os outros critérios para escolher:

- **custo** no melhor, no médio e no pior caso (o pior caso é o que derruba
  um sistema em produção);
- **memória extra**: ordenar **in-place** (O(1) a mais) ou precisar de um
  rascunho O(n);
- **adaptativo**: fica mais rápido quando o vetor já está quase em ordem.

O resumo do módulo inteiro:

| Algoritmo | Melhor | Médio | Pior | Memória extra | Estável |
| --- | --- | --- | --- | --- | --- |
| bubble (com bandeira) | O(n) | O(n²) | O(n²) | O(1) | sim |
| selection | O(n²) | O(n²) | O(n²) | O(1) | não |
| insertion | O(n) | O(n²) | O(n²) | O(1) | sim |
| merge | O(n log n) | O(n log n) | O(n log n) | O(n) | sim |
| quick | O(n log n) | O(n log n) | O(n²) | O(log n) a O(n) de pilha | não |

Não existe o melhor de todos. O insertion ganha em vetores pequenos ou quase
ordenados. O merge garante n log n e estabilidade, pagando memória. O quick é
o mais rápido na média e não usa rascunho, mas tem o pior caso O(n²) e não é
estável. O selection faz o mínimo de trocas. O bubble... ensina.

Na prática, você quase nunca escreve um desses: a `stdlib.h` traz o
**`qsort`**, genérico, que apareceu no assunto 0050 (ponteiro para função):

```text
void qsort(void *base, size_t n, size_t tamanho,
           int (*compara)(const void *, const void *));
```

Ele não sabe o tipo dos elementos (por isso o `void *` e o `tamanho`). Quem
sabe é a sua função `compara`, que recebe dois ponteiros e devolve
**negativo** se o primeiro vem antes, **zero** se empatam e **positivo** se
vem depois. É o mesmo contrato do `strcmp`.

Vamos ver na prática. Os pedidos chegam por horário. Ordenando por cidade, um
algoritmo estável (insertion, merge) mantém R1, R3, R6. O selection sort, com
as suas trocas de longa distância, entrega R3 antes de R1:

{{ideia}}

A norma do C **não promete** que o `qsort` é estável. Então, quando a ordem
dos empatados importa, ponha o desempate na própria `compara`. É o que o
código abaixo faz: cidade primeiro, horário depois.

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

Os números de verdade. O exemplo A192 roda os cinco algoritmos do módulo com
os mesmos 1000 números e conta as comparações:

| n = 1000 | aleatório | ordenado | invertido |
| --- | --- | --- | --- |
| bubble | 499.122 | 999 | 499.500 |
| selection | 499.500 | 499.500 | 499.500 |
| insertion | 241.308 | 999 | 499.500 |
| merge | 8.696 | 4.932 | 5.044 |
| quick (pivô no fim) | 10.972 | 499.500 | 499.500 |

Leia a tabela por coluna. No aleatório, os O(n log n) fazem umas 50 vezes
menos trabalho. No ordenado, o bubble e o insertion fazem uma passada só,
enquanto o quick com pivô no fim cai no pior caso. O selection nem percebe a
diferença entre as três colunas.

Repara no fluxograma: é um guia de decisão, não um algoritmo. O caminho
marcado é o deste exemplo: a ordem de chegada importa, mas cabe como
desempate na `compara` (o horário), então `qsort` resolve:

{{fluxograma}}

> [!WARNING]
> A `compara` preguiçosa `return *(const int *) a - *(const int *) b;`
> parece certa e passa nos testes com números pequenos. Com valores grandes de
> sinais opostos (por exemplo, `INT_MAX` e `-5`), a subtração dá **overflow**:
> o resultado vira negativo e a ordem sai errada. Escreva
> `return (x > y) - (x < y);`, que devolve -1, 0 ou 1 sem fazer conta.

> [!TIP]
> **Por dentro do C:** o `qsort` move os elementos byte a byte (ele só sabe o
> `tamanho`) e chama a sua `compara` por um **ponteiro para função** a cada
> comparação. Essa chamada indireta impede o compilador de colar a
> comparação dentro do laço, então, para `int`, um sort escrito à mão pode
> ser mais rápido. A norma também não diz qual algoritmo o `qsort` usa: as
> bibliotecas usam variações de quick sort (com proteção contra o pior caso)
> ou de merge sort. Por isso, nunca conte com estabilidade nem com um custo
> exato. Para buscar num vetor ordenado pelo mesmo critério, a mesma
> `stdlib.h` traz a **`bsearch`**, com a mesma `compara`.

> [!NOTE]
> **Pergunta para você:** se a `compara` do A191 só comparasse a cidade (sem o
> desempate por horário), a saída seria sempre a mesma? Em que ordem você
> esperaria os três pedidos de Recife? Rode algumas vezes, troque a ordem do
> vetor de entrada e veja.

{{pratique}}

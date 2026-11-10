## 0116 · Análise amortizada

Mudar de apartamento custa um dia carregando **todos** os móveis, mas é raro:
ninguém mede o custo de morar pela pior semana do ano.

No vetor que cresce (assunto 0075), inserir no fim custa uma escrita, até o
vetor encher: aí é preciso alocar um maior e **copiar tudo**. Isolada, a
inserção é O(n) no pior caso, e `n` inserções dariam O(n²). A conta é
pessimista: as caras não vêm em sequência.

A **análise amortizada** mede uma **sequência** de operações no pior caso e
divide pelo número de operações: o **custo amortizado** é uma garantia sobre o
total, sem sorteio.

No **método agregado**, some tudo. Com capacidade inicial 1, dobrando ao
encher, `n` inserções fazem `n` escritas mais as cópias `1 + 2 + 4 + ...`, que
somam menos de `2n`. O total fica abaixo de `3n`: **O(1) amortizado**.

No **método do banqueiro** (contábil), cada inserção paga **3 moedas**: 1 pela
escrita e 2 para um cofrinho. Quando a capacidade `c` enche e vira `2c`, os `c`
elementos mais novos guardaram 2 moedas cada: são as `c` cópias. Com o cofrinho
**sempre não negativo**, o custo amortizado é 3. O Cormen traz ainda o **potencial**: o
cofrinho vira uma função Φ do estado (aqui, Φ = 2 · n - capacidade).

O app do banco guarda o histórico de Pix num vetor de 1 posição que dobra ao
encher. Chegam 16 Pix; as inserções 2, 3, 5 e 9 são as mudanças, em vermelho, e
o cofrinho cai nelas e se recupera:

{{ideia}}

O `insere` devolve o custo real. O vetor cresce com `malloc`, cópia e `free`
à mão, para contar cada cópia:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int n;   // quantos tem
    int cap; // quantos cabem
} Vetor;

// insere no fim e devolve o custo: 1 escrita + as cópias, se precisou crescer
int insere(Vetor *v, int valor) {
    int custo = 1;
    if (v->n == v->cap) {
        int nova = v->cap * 2;                       // dobra
        int *maior = malloc(nova * sizeof *maior);
        if (maior == NULL) {
            exit(1);
        }
        for (int i = 0; i < v->n; i++) {
            maior[i] = v->dados[i];                  // a mudança: copia tudo
            custo++;
        }
        free(v->dados);
        v->dados = maior;
        v->cap = nova;
    }
    v->dados[v->n++] = valor;
    return custo;
}

int main(void) {
    Vetor v = {malloc(sizeof(int)), 0, 1};
    if (v.dados == NULL) {
        return 1;
    }
    int total = 0, cofrinho = 0;
    printf("Pix  custo  cofrinho\n");
    for (int i = 1; i <= 16; i++) {
        int custo = insere(&v, 100 * i);             // valor do Pix, tanto faz
        total += custo;
        cofrinho += 3 - custo;                       // cada inserção paga 3
        printf("%3d  %5d  %8d\n", i, custo, cofrinho);
    }
    printf("total: %d para 16 inserções (%.2f por inserção)\n", total, total / 16.0);
    free(v.dados);
    return 0;
}
// Saída:
// Pix  custo  cofrinho
//   1      1         2
//   2      2         3
//   3      3         3
//   4      1         5
//   5      5         3
//   6      1         5
//   7      1         7
//   8      1         9
//   9      9         3
//  10      1         5
//  11      1         7
//  12      1         9
//  13      1        11
//  14      1        13
//  15      1        15
//  16      1        17
// total: 31 para 16 inserções (1.94 por inserção)
```

As cópias somam `1 + 2 + 4 + 8 = 15`, mais 16 escritas: 31, menos de `2 · 16`.
O cofrinho nunca chega a zero.

O fluxograma segue o `insere` da 9ª inserção, a mais cara: o vetor tem 8 de 8
ocupados, então o caminho passa pela mudança inteira:

{{fluxograma}}

A mesma análise vale para o **contador binário** (somar 1 às vezes vira muitos
bits, em média menos de 2; exemplo A231) e para a **pilha com `multipop(k)`**,
que tira até `k` itens (cada item sai uma vez; exemplo A232).

Amortizado **não** é caso médio: o médio supõe entradas sorteadas; o
amortizado vale para a **pior** sequência. E não garante que cada operação é
rápida: a 1.048.577ª inserção copia mais de um milhão de elementos. Sistema que
não pode travar precisa de outra solução.

> [!WARNING]
> Crescer por **tamanho fixo** estraga tudo. Com `nova = cap + 10`, as mudanças
> copiam 10, 20, 30... elementos: para 100.000 inserções, quase **500 milhões**
> de cópias, contra 131.071 dobrando. É uma progressão aritmética, Θ(n²) no
> total e O(n) amortizado. Qualquer fator maior que 1 (1,5 ou 2) dá O(1)
> amortizado; somar uma constante, não.

> [!TIP]
> **Por dentro do C:** na prática se usa `realloc` (assunto 0055), que às vezes
> estica o bloco no lugar; a análise conta o pior caso, copiar tudo. O preço
> é memória: logo após dobrar, metade do vetor está vazia.
> Use o `realloc` seguro, com ponteiro à parte e `NULL` conferido.

> [!NOTE]
> **Pergunta para você:** e na volta? Suponha que o vetor **encolhe pela
> metade** quando fica com metade das posições ocupadas. Com 16 elementos e
> capacidade 16, quantas cópias cada operação faz se o programa alternar
> "insere, remove" mil vezes?

{{pratique}}

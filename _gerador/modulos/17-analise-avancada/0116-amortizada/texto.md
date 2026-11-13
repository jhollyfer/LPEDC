## 0116 · Análise amortizada

- **Análise amortizada**: mede uma **sequência** de operações no pior caso e
  divide pelo número de operações. O **custo amortizado** é uma garantia
  sobre o total, sem sorteio (CORMEN et al., 2024, cap. 16).
- **Vetor que dobra** (0075): inserir no fim custa uma escrita, até encher;
  aí aloca o dobro e **copia tudo**. Isolada, a inserção é O(n); em sequência,
  as caras são raras (ROVAI, 2018).
- **Método agregado**: some tudo. Com capacidade inicial 1, `n` inserções
  fazem `n` escritas mais cópias `1 + 2 + 4 + ...`, menos de `2n`. O total
  fica abaixo de `3n`: **O(1) amortizado** (CORMEN et al., 2024, cap. 16).
- **Método do banqueiro** (contábil): cada inserção paga **3 moedas**, 1 pela
  escrita e 2 para um cofrinho. Quando `c` vira `2c`, os `c` mais novos
  guardaram as `c` cópias. O cofrinho nunca fica negativo
  (SZWARCFITER; MARKENZON, 2010).
- **Método do potencial**: o cofrinho vira uma função Φ do estado (aqui,
  Φ = 2 · n - capacidade). Custo amortizado = real + Φ(depois) - Φ(antes)
  (CORMEN et al., 2024, cap. 16).
- **Não é caso médio**: o médio supõe entradas sorteadas; o amortizado vale
  para a **pior** sequência. E não promete que cada operação é rápida: um
  sistema que não pode travar precisa de outra solução
  (SZWARCFITER; MARKENZON, 2010).
- **Outros exemplos**: o **contador binário** troca menos de 2 bits por soma
  em média (A231) e a pilha com `multipop(k)` tira cada item uma vez (A232)
  (CORMEN et al., 2024, cap. 16).
- **Na prática**: usa-se `realloc` (0055), que às vezes estica no lugar; a
  análise conta o pior caso. O preço é memória: logo após dobrar, metade está
  vazia (CORTÉS, 2015).

> [!WARNING]
> Crescer por **tamanho fixo** estraga tudo. Com `nova = cap + 10`, as cópias
> são 10, 20, 30...: quase **500 milhões** para 100.000 inserções, contra
> 131.071 dobrando. Qualquer fator maior que 1 (1,5 ou 2) dá O(1) amortizado;
> somar uma constante, não.

{{exemplo}}

O app do banco guarda o histórico de Pix num vetor de 1 posição que dobra ao
encher. Chegam 16 Pix; as inserções 2, 3, 5 e 9 são as mudanças, em vermelho,
e o cofrinho cai nelas e se recupera:

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
O fluxograma segue a 9ª inserção, a mais cara: 8 de 8 ocupados, e o caminho
passa pela mudança inteira:

{{fluxograma}}

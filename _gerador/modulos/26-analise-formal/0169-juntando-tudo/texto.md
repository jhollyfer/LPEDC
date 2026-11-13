## 0169 · Juntando tudo: passos e bytes conferidos

- **Ficha de complexidade**: tempo e espaço extra de uma função, cada um com
  sua classe Θ e o caso a que se refere (ZIVIANI, 2010, cap. 1).
- **Ler o código**: a fórmula exata de passos sai dos somatórios (0167); o
  espaço extra, dos vetores, dos `malloc` e da profundidade da recursão (0168)
  (CORMEN et al., 2024, apêndice A).
- **Instrumentar**: um contador no laço mais interno, outro de bytes em cada
  `malloc` e outro de frames vivos. O TAD `custo.h` guarda os três:
  `custo_passos`, `custo_bytes` e `custo_prof_max`.
- **Dobrar o `n`**: a versão prática do Θ (0166). Em Θ(n²) a razão
  `f(2n) / f(n)` vai para 4; em Θ(n log n), fica um pouco acima de 2; em
  Θ(log n), soma 1 (FEOFILOFF, 2009).
- **O que é um passo** em cada função: um elemento somado, um elemento olhado
  na busca, um par testado, um elemento copiado na intercalação, uma chamada
  na soma recursiva.
- **Heap e pilha**: o `custo_bytes` mede o heap; a pilha só se mede em frames.

> [!WARNING]
> A medida vale para a entrada testada. A busca roda no **pior caso** (1
> centavo, que não está no vetor); com o preço do meio, faz 1 passo. Diga qual
> caso a entrada representa.

{{exemplo}}

Um fornecedor entregou cinco funções sobre o vetor de preços, cada uma com
sua ficha. Passos com `n = 1024` e `n = 2048`, razão e espaço extra: em
vermelho, o que cresce com `n`; em verde, o constante:

{{ideia}}

```c
#include <stdio.h>
#include <math.h>
#include "custo.h"

// mostra uma linha: passos medidos, fórmula, frames e bytes
void linha(const char *nome, long formula) {
    printf("%-9s %8ld %8ld %7d %7zu\n", nome, custo_passos, formula,
           custo_prof_max, custo_bytes);
}

int main(void) {
    static int preco[2048];
    for (int n = 1024; n <= 2048; n *= 2) {
        for (int i = 0; i < n; i++) {
            preco[i] = 100 + 5 * i;      // preços em centavos, já ordenados
        }
        long lg = lround(log2(n));
        printf(n == 1024 ? "n = %d\n" : "\nn = %d\n", n);
        printf("função      passos  fórmula  frames   bytes\n");

        custo_zera();
        custo_soma(preco, n);
        linha("soma", n);

        custo_zera();
        custo_busca(preco, n, 1);        // 1 centavo: não está, pior caso
        linha("busca", lg + 1);

        custo_zera();
        custo_pares(preco, n, 1000);
        linha("pares", (long)n * (n - 1) / 2);

        custo_zera();
        custo_merge(preco, n);
        linha("merge", n * lg);

        custo_zera();
        custo_soma_rec(preco, n);
        linha("soma_rec", n + 1);
    }
    return 0;
}
// Saída:
// n = 1024
// função      passos  fórmula  frames   bytes
// soma          1024     1024       1       0
// busca           11       11       1       0
// pares       523776   523776       1       0
// merge        10240    10240      12    4096
// soma_rec      1025     1025    1025       0
//
// n = 2048
// função      passos  fórmula  frames   bytes
// soma          2048     2048       1       0
// busca           12       12       1       0
// pares      2096128  2096128       1       0
// merge        22528    22528      13    8192
// soma_rec      2049     2049    2049       0
```

O fluxograma é o roteiro de conferência. "A medida bate com a fórmula?" vem
antes da classe:

{{fluxograma}}

### Passo a passo

Lendo a saída de `n = 1024` para `n = 2048`:

| função | passos | razão | ficha de tempo | frames | bytes | ficha de espaço |
| --- | --- | --- | --- | --- | --- | --- |
| soma | 1024 → 2048 | × 2 | Θ(n) | 1 → 1 | 0 | Θ(1) |
| busca | 11 → 12 | + 1 | Θ(log n) | 1 → 1 | 0 | Θ(1) |
| pares | 523.776 → 2.096.128 | × 4,00 | Θ(n²) | 1 → 1 | 0 | Θ(1) |
| merge | 10.240 → 22.528 | × 2,2 | Θ(n log n) | 12 → 13 | 4096 → 8192 | Θ(n) |
| soma_rec | 1025 → 2049 | × 2 | Θ(n) | 1025 → 2049 | 0 | Θ(n) |

As cinco fichas conferem. A soma e a soma recursiva têm o **mesmo tempo** e
espaços diferentes: a recursiva empilha um frame por elemento. O merge sort
usa o vetor auxiliar (Θ(n), que domina) e a pilha (Θ(log n), 12 e 13 frames).

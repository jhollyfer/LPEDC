## 0169 · Juntando tudo: passos e bytes conferidos

O fornecedor do caixa da loja de material de construção entregou cinco
funções sobre o vetor de preços (em centavos), cada uma com uma ficha "tempo
Θ(...), espaço extra Θ(...)". Confira as fichas rodando o programa.

O roteiro usa o módulo inteiro:

1. **Leia o código** e escreva a fórmula exata de passos (somatórios do
   assunto 0167) e o espaço extra: vetores, `malloc` e profundidade máxima da
   recursão (0168).
2. **Instrumente**: contadores de passos no laço mais interno, de bytes em
   cada `malloc` e de frames vivos.
3. **Meça e compare** com a fórmula.
4. **Dobre o `n`** e olhe a razão (a versão prática do Θ do assunto 0166): em
   Θ(n²), `f(2n) / f(n)` vai para 4; em Θ(n log n), fica um pouco acima de 2;
   em Θ(log n), soma 1.

As cinco funções ficam no TAD `custo.h` e `custo.c`, com três medidas:
`custo_passos`, `custo_bytes` (pedidos ao `malloc`) e `custo_prof_max` (frames
vivos ao mesmo tempo). Passo é: na soma, um elemento; na busca binária, um
elemento olhado; nos pares, um par testado; no merge sort, um elemento
copiado na intercalação; na soma recursiva, uma chamada.

Passos com `n = 1024` e `n = 2048`, razão e espaço extra medido. Em vermelho,
o que cresce com `n`; em verde, o constante:

{{ideia}}

O programa roda as cinco com 1024 e 2048 preços e imprime passos, fórmula,
frames e bytes:

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

O fluxograma é o roteiro, não uma função. "A medida bate com a fórmula?" vem
antes da classe: fórmula errada com classe certa passa no "parece n²":

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

> [!WARNING]
> A medida vale para a entrada testada. A busca é o **pior caso** (1 centavo,
> que não está no vetor); com o preço do meio, faz 1 passo. Os pares fazem
> `n(n-1)/2` testes em **qualquer** entrada. Decida qual caso a entrada
> representa.

> [!TIP]
> O `custo_bytes` mede o **heap**; a pilha só dá para medir em frames, que o
> AddressSanitizer aumenta com zonas de proteção.

> [!NOTE]
> **Pergunta para você:** se a busca binária virasse **recursiva**, quais
> colunas da linha "busca" mudariam com `n = 2048`? Escreva os números antes de
> trocar.

{{pratique}}

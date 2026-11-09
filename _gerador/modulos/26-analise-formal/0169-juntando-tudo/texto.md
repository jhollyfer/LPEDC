## 0169 · Juntando tudo: passos e bytes conferidos

A loja de material de construção vai trocar o sistema do caixa. O
fornecedor entregou cinco funções que trabalham sobre o vetor de preços
(em centavos) e, para cada uma, uma ficha: "tempo Θ(...), espaço extra
Θ(...)". Antes de assinar, você quer conferir as fichas com o programa
rodando, e não só acreditar.

Este assunto junta o módulo inteiro num roteiro de conferência:

1. **Leia o código** e escreva a fórmula exata de passos, com os
   somatórios do assunto 0167. Escreva também o espaço extra: vetores,
   `malloc` e a profundidade máxima da recursão (assunto 0168).
2. **Instrumente**: um contador de passos dentro do laço mais interno, um
   contador de bytes ao lado de cada `malloc` e um contador de frames vivos
   na entrada e na saída de cada função.
3. **Meça e compare** com a fórmula. Se bater, a ficha está certa para
   aquele `n`.
4. **Dobre o `n`** e olhe a razão. É a forma prática da definição de Θ do
   assunto 0166: se `f(n)` é Θ(n²), a razão `f(2n) / f(n)` vai para 4; se é
   Θ(n log n), fica um pouco acima de 2; se é Θ(log n), soma 1.

As cinco funções ficam num TAD, `custo.h` e `custo.c`, na pasta do assunto.
Elas compartilham três medidas: `custo_passos`, `custo_bytes` (pedidos ao
`malloc`) e `custo_prof_max` (frames vivos ao mesmo tempo). Cada uma conta
um passo num lugar escolhido de propósito: a soma conta por elemento, a
busca binária por elemento olhado, os pares por par testado, o merge sort
por elemento copiado na intercalação, e a soma recursiva por chamada.

Vamos ver na prática. A tabela é a ficha conferida: passos com `n = 1024`
e `n = 2048`, a razão entre eles, e o espaço extra medido. Em vermelho, o
que cresce com `n` no espaço; em verde, o que fica constante:

{{ideia}}

O programa roda as cinco com 1024 e 2048 preços e imprime, para cada uma,
os passos, a fórmula, os frames e os bytes:

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

Repara no fluxograma: é o roteiro, não uma função. A pergunta "a medida
bate com a fórmula?" vem antes da pergunta sobre a classe. Uma fórmula
errada com a classe certa ainda passa despercebida no "parece n²"; a
conferência exata pega o erro na hora:

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

As cinco fichas conferem. Repara em duas coisas. A soma e a soma
recursiva têm o **mesmo tempo** e espaços diferentes: a recursiva empilha
um frame por elemento. E o merge sort tem dois espaços extras: o vetor
auxiliar (Θ(n), que domina) e a pilha (Θ(log n), 12 e 13 frames).

> [!WARNING]
> A medida só vale para o que você mede. A busca conferida aqui é o **pior
> caso** (procurar 1 centavo, que não está no vetor); procurando o preço do
> meio, ela faz 1 passo. Os pares fazem `n(n-1)/2` testes em **qualquer**
> entrada, então ali melhor e pior coincidem. Antes de comparar com a
> fórmula, decida qual caso a entrada do teste representa, senão você
> "confirma" um Θ(log n) com uma busca que achou de primeira.

> [!TIP]
> **Por dentro do C:** os contadores são variáveis globais do `custo.c`.
> `custo_passos` é declarada com `extern` no `.h` e definida uma vez só no
> `.c`; o `prof` é `static`, invisível fora do arquivo. Repara também que os
> bytes da pilha não aparecem em `custo_bytes`: o `malloc` mede o **heap**,
> e a pilha só dá para medir em frames. Cada frame da `custo_soma_rec`
> guarda o endereço de retorno, o `v`, o `n` e o `s`, umas dezenas de bytes
> (o tamanho exato depende do compilador e das opções). Com o
> AddressSanitizer ligado, os frames ficam maiores, porque ele põe zonas de
> proteção em volta das variáveis locais.

> [!NOTE]
> **Pergunta para você:** se o fornecedor trocasse a busca binária com laço
> por uma busca binária **recursiva**, quais colunas da linha "busca"
> mudariam com `n = 2048`? Escreva os números que você espera antes de
> trocar.

{{pratique}}

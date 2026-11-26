## 0169 · Juntando tudo: passos e bytes conferidos

O fornecedor do sistema de caixa de uma loja de material de construção
entregou cinco funções que trabalham sobre o vetor de preços, em centavos.
Cada função veio com uma **ficha de complexidade**: o tempo e o espaço
extra, cada um com sua classe Θ e o caso a que se refere (ZIVIANI, 2010,
cap. 1). Fichas assim são promessas. Para conferir uma
promessa dessas, você usa tudo o que o módulo ensinou: primeiro no papel, depois
rodando o código.

O primeiro passo é **ler o código**. Os laços dão a fórmula exata de
passos, montada com os somatórios do assunto 0167: dois laços com `j < i`
dão `n(n-1)/2`, por exemplo (CORMEN et al., 2024, apêndice A). O espaço
extra sai do assunto 0168: procure os vetores auxiliares, os `malloc` e a
profundidade máxima da recursão. No fim da leitura, você tem duas fórmulas
por função e uma ficha que acredita ser a certa.

O segundo passo é **instrumentar** o código, isto é, acrescentar contadores
que registram o trabalho feito. Um contador de passos vai no laço mais
interno. Outro soma os bytes pedidos em cada `malloc`. Um terceiro acompanha
quantos frames estão vivos ao mesmo tempo e guarda o maior valor. O TAD
`custo.h` reúne os três em variáveis globais: `custo_passos`, `custo_bytes`
e `custo_prof_max`.

Para o contador significar algo, é preciso decidir o que conta como **um
passo** em cada função. Na soma, um passo é um elemento somado. Na busca
binária, um elemento olhado. Na função que testa pares, um par testado. No
merge sort, um elemento copiado durante a intercalação. Na soma recursiva,
uma chamada. A escolha segue a operação que domina o custo, a que mais se
repete.

O terceiro passo é **medir e comparar** com a fórmula. Se a fórmula diz
`n(n-1)/2` e o contador mostra outro número, a fórmula ou o código está
errado. Compare o número exato antes de olhar a classe: uma fórmula errada
pode ter a classe certa e passar despercebida.

O quarto passo é **dobrar o `n`** e olhar a razão `f(2n) / f(n)`. É a
versão prática do Θ do assunto 0166: o que importa é como o custo cresce,
e dobrar a entrada mostra isso sem precisar das constantes (FEOFILOFF,
2009). Em Θ(n), a razão é 2. Em Θ(n²), ela vai para 4, porque `(2n)² =
4n²`. Em Θ(n log n), fica um pouco acima de 2. Em Θ(log n), o custo não
multiplica: soma 1, já que `log(2n) = log n + 1`.

Um limite da instrumentação: o `custo_bytes` mede só o **heap**, a memória
do `malloc`. A pilha não tem um contador de bytes confiável, e por isso só
se mede em frames. Ferramentas como o AddressSanitizer mudam o tamanho dos
frames com zonas de proteção, o que reforça a escolha de contar frames.

> [!WARNING]
> A medida vale para a entrada testada. A busca roda no **pior caso** (1
> centavo, que não está no vetor); com o preço do meio, faz 1 passo. Os
> pares fazem `n(n-1)/2` testes em **qualquer** entrada. Diga qual caso a
> entrada representa.

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

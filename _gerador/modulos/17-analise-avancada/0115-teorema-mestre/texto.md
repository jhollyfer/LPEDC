## 0115 · Teorema mestre

Montar a árvore de recursão do assunto 0114 para cada algoritmo funciona, mas
cansa. Na declaração do Imposto de Renda, você não refaz a conta da alíquota:
acha a sua faixa na tabela e lê o resultado. O **teorema mestre** é essa
tabela para as recorrências de divisão e conquista: alguém já somou a árvore
em geral, e o resultado cabe em três linhas (CORMEN et al., 2024, cap. 4).

A forma mais usada, simplificada, é esta:

```text
T(n) = a T(n/b) + n^k
```

Cada letra responde uma das perguntas do 0114. O `a`, que vale pelo menos 1,
é **quantas chamadas** cada chamada faz. O `b`, maior que 1, é **quanto o
tamanho encolhe**: cada chamada recebe `n/b`. E `n^k` é o **trabalho fora das
chamadas**: `k = 0` quer dizer trabalho constante, `k = 1` quer dizer
trabalho linear (LINTZMAYER; MOTA, 2023). O merge sort, com duas metades e uma
intercalação linear, tem `a = 2`, `b = 2` e `k = 1`.

Para ver de onde vêm as três linhas, monte a árvore dessa forma geral. O nível
`j` tem `a^j` chamadas, cada uma com tamanho `n/b^j`, e cada uma trabalha
`(n/b^j)^k`. Multiplicando, o nível `j` custa `n^k · (a/b^k)^j`. Repare no que
isso diz: de um nível para o seguinte, o custo é multiplicado sempre pelo
mesmo número, a razão `a/b^k` (LINTZMAYER; MOTA, 2023). Toda a análise se
resume a comparar `a` com `b^k`, e só há três possibilidades.

Se `a > b^k`, a razão passa de 1 e o custo **cresce** a cada nível. O último
nível, o das folhas, manda no total: ele tem `a^(log_b n) = n^(log_b a)` folhas,
e os níveis de cima somam só um múltiplo fixo dele. O resultado é
Θ(n^(log_b a)). Se `a = b^k`, a razão é 1 e todo nível custa o mesmo `n^k`.
São `log_b n + 1` níveis, e o total é Θ(n^k log n). Se `a < b^k`, a razão fica
abaixo de 1 e o custo **cai** a cada nível. A raiz sozinha já é uma fração
fixa do total, e o resultado é Θ(n^k).

| caso | comparação | o custo por nível... | quem pesa | resultado |
| --- | --- | --- | --- | --- |
| 1 | `a > b^k` | **cresce** a cada nível | as folhas | Θ(n^(log_b a)) |
| 2 | `a = b^k` | fica **igual** | todos os níveis | Θ(n^k log n) |
| 3 | `a < b^k` | **cai** a cada nível | a raiz | Θ(n^k) |

Aplicar é ler `a`, `b` e `k` no código, calcular `b^k` e achar a linha. A
busca binária faz uma chamada com metade e trabalho constante: `a = 1`,
`b^k = 2^0 = 1`, caso 2, Θ(log n). O merge sort tem `a = 2` e `b^k = 2`, caso
2, Θ(n log n). A multiplicação de polinômios de Karatsuba faz 3 produtos de
metade do tamanho com trabalho linear: `a = 3 > 2`, caso 1, Θ(n^(log₂ 3)), que
é cerca de Θ(n^1,585).

| algoritmo | a | b | k | b^k | resultado |
| --- | --- | --- | --- | --- | --- |
| busca binária | 1 | 2 | 0 | 1 | caso 2: Θ(log n) |
| máximo dividindo ao meio | 2 | 2 | 0 | 1 | caso 1: Θ(n) |
| merge sort | 2 | 2 | 1 | 2 | caso 2: Θ(n log n) |
| multiplicar polinômios com 3 produtos (Karatsuba) | 3 | 2 | 1 | 2 | caso 1: Θ(n^1,585) |
| algo que lê tudo e segue numa metade | 1 | 2 | 1 | 2 | caso 3: Θ(n) |

O Cormen enuncia o teorema numa forma mais geral, `T(n) = a T(n/b) + f(n)`,
em que o trabalho `f(n)` pode ser qualquer função e é comparado com
`n^(log_b a)`, o número de folhas. No caso 1, `f(n)` fica abaixo de
`n^(log_b a)` por um fator polinomial, e as folhas mandam. No caso 2, `f(n)`
é Θ(n^(log_b a) · logᵖ n) com p ≥ 0, e o resultado ganha mais um fator de log:
Θ(n^(log_b a) · log^(p+1) n). Com p = 1, `2 T(n/2) + n log n` dá
Θ(n log² n), o que o exemplo A230 mede. No caso 3, `f(n)` fica acima por um
fator polinomial **e** precisa cumprir a condição de regularidade
`a f(n/b) ≤ c f(n)` para alguma constante c < 1; aí o resultado é Θ(f(n))
(CORMEN et al., 2024, cap. 4).

O teorema não cobre tudo. Em `T(n) = T(n-1) + n`, o tamanho cai subtraindo, e
não existe `b`. Em `T(n) = T(n/3) + T(2n/3) + n`, os pedaços têm tamanhos
diferentes. Nesses casos, volte à árvore de recursão, que sempre funciona
(LINTZMAYER; MOTA, 2023).

Um detalhe do C. O `n / 2` no código é divisão inteira, e arredondar para cima
ou para baixo não muda o Θ (CORMEN et al., 2024, cap. 4). O que muda é o caso
base: com `if (n == 1)`, uma chamada com `n = 0` passa reto, `0 / 2` dá 0 de
novo e a pilha estoura. Prefira `if (n <= 1)`.

> [!WARNING]
> Quatro estagiários com metade cada um é `4 T(n/2)`, não `4 T(n/4)`. Em
> `T(n) = 2 T(n-1) + 1` (Hanói) não existe `b`: `n - 1` não é `n` dividido por
> nada. Use a árvore, que dá Θ(2ⁿ).

{{exemplo}}

Um revisor lê as `n` páginas de um contrato e repassa **metade** a `a`
estagiários, que fazem o mesmo. Com `b = 2` e `k = 1`, `b^k = 2`, e `a = 1`,
2 ou 4 cai numa linha diferente. O desenho mostra cada árvore para `n = 16`:

{{ideia}}

O código faz as `a` chamadas de verdade e, no fim, dobra o `n` para ver por
quanto o total é multiplicado:

```c
#include <stdio.h>

// o revisor lê as n páginas e repassa metade do contrato para 'a' estagiários
// T(n) = a T(n/2) + n, T(1) = 1
long paginas(int a, int n) {
    if (n == 1) {
        return 1;                        // uma página: lê e pronto
    }
    long total = n;                      // f(n) = n: lê tudo
    for (int i = 0; i < a; i++) {
        total += paginas(a, n / 2);      // a chamadas com metade
    }
    return total;
}

int main(void) {
    printf("    n      a = 1      a = 2      a = 4\n");
    for (int n = 16; n <= 1024; n *= 2) {
        printf("%5d", n);
        for (int a = 1; a <= 4; a *= 2) {
            printf(" %10ld", paginas(a, n));
        }
        printf("\n");
    }
    printf("\nquando n dobra (512 -> 1024), o total multiplica por:\n");
    for (int a = 1; a <= 4; a *= 2) {
        printf("a = %d: %.2f\n", a, (double)paginas(a, 1024) / paginas(a, 512));
    }
    return 0;
}
// Saída:
//     n      a = 1      a = 2      a = 4
//    16         31         80        496
//    32         63        192       2016
//    64        127        448       8128
//   128        255       1024      32640
//   256        511       2304     130816
//   512       1023       5120     523776
//  1024       2047      11264    2096128
//
// quando n dobra (512 -> 1024), o total multiplica por:
// a = 1: 2.00
// a = 2: 2.20
// a = 4: 4.00
```

Com `a = 1`, caso 3: Θ(n), total `2n - 1`. Com `a = 2`, caso 2: Θ(n log n),
exatamente `n log₂ n + n`. Com `a = 4`, caso 1: Θ(n²), total `2n² - n`. O
fluxograma é o teorema como receita; o caminho marcado é o de `a = 2`:

{{fluxograma}}

## 0115 · Teorema mestre

- **Teorema mestre**: a soma da árvore de recursão (0114) já feita em geral,
  para recorrências de divisão e conquista. O resultado cabe em três linhas
  (CORMEN et al., 2024, cap. 4).
- **Forma simplificada**: `T(n) = a T(n/b) + n^k`. `a` (pelo menos 1) é
  quantas chamadas; `b` (maior que 1) é quanto o tamanho encolhe; `n^k` é o
  trabalho fora das chamadas (LINTZMAYER; MOTA, 2023).
- **Por que funciona**: o nível `j` tem `a^j` chamadas de tamanho `n/b^j` e
  custa `n^k · (a/b^k)^j`. De um nível ao seguinte, o custo é multiplicado
  por `a/b^k` (LINTZMAYER; MOTA, 2023).
- **Forma do Cormen**: `T(n) = a T(n/b) + f(n)`, com `f(n)` comparada a
  `n^(log_b a)`. O caso 2 aceita `f(n) = Θ(n^(log_b a) · logᵖ n)`, p ≥ 0, e dá
  Θ(n^(log_b a) · log^(p+1) n). O caso 3 exige também `a f(n/b) ≤ c f(n)`,
  c < 1 (CORMEN et al., 2024, cap. 4).
- **Quando não se aplica**: `T(n) = T(n-1) + n` (o tamanho cai subtraindo),
  `T(n) = T(n/3) + T(2n/3) + n` (pedaços diferentes). Volte à árvore, que
  sempre funciona (exemplo A230) (LINTZMAYER; MOTA, 2023).
- **Divisão inteira**: arredondar `n / 2` para cima ou para baixo não muda o
  Θ (CORMEN et al., 2024, cap. 4).

```text
T(n) = a T(n/b) + n^k
```

| caso | comparação | o custo por nível... | quem pesa | resultado |
| --- | --- | --- | --- | --- |
| 1 | `a > b^k` | **cresce** a cada nível | as folhas | Θ(n^(log_b a)) |
| 2 | `a = b^k` | fica **igual** | todos os níveis | Θ(n^k log n) |
| 3 | `a < b^k` | **cai** a cada nível | a raiz | Θ(n^k) |

| algoritmo | a | b | k | b^k | resultado |
| --- | --- | --- | --- | --- | --- |
| busca binária | 1 | 2 | 0 | 1 | caso 2: Θ(log n) |
| máximo dividindo ao meio | 2 | 2 | 0 | 1 | caso 1: Θ(n) |
| merge sort | 2 | 2 | 1 | 2 | caso 2: Θ(n log n) |
| multiplicar polinômios com 3 produtos (Karatsuba) | 3 | 2 | 1 | 2 | caso 1: Θ(n^1,585) |
| algo que lê tudo e segue numa metade | 1 | 2 | 1 | 2 | caso 3: Θ(n) |

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

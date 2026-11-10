## 0115 · Teorema mestre

Na declaração do Imposto de Renda, você acha a sua faixa na tabela e lê a
alíquota, sem refazer a conta.

O **teorema mestre** é a tabela pronta das recorrências de divisão e
conquista: a soma da árvore do assunto 0114 já foi feita em geral, e o
resultado cabe em três linhas. A forma é:

```text
T(n) = a T(n/b) + n^k
```

- `a` (pelo menos 1) é **quantas chamadas** cada chamada faz;
- `b` (maior que 1) é **quanto o tamanho encolhe**: cada chamada recebe `n/b`;
- `n^k` é o **trabalho fora das chamadas** (`k = 0` constante, `k = 1` linear).

Na árvore, o nível `j` tem `a^j` chamadas de tamanho `n/b^j`, e o nível custa
`n^k · (a/b^k)^j`: de um nível ao seguinte, o custo é multiplicado pela razão
`a/b^k`. Há três possibilidades:

| caso | comparação | o custo por nível... | quem pesa | resultado |
| --- | --- | --- | --- | --- |
| 1 | `a > b^k` | **cresce** a cada nível | as folhas | Θ(n^(log_b a)) |
| 2 | `a = b^k` | fica **igual** | todos os níveis | Θ(n^k log n) |
| 3 | `a < b^k` | **cai** a cada nível | a raiz | Θ(n^k) |

No caso 1, o último nível manda: tem `a^(log_b n) = n^(log_b a)` folhas e os
de cima somam um múltiplo fixo dele. No caso 2, são `log_b n + 1` níveis de
`n^k`. No caso 3, a raiz já é uma fração fixa do total.

Um escritório revisa um contrato de `n` páginas: o revisor lê tudo e repassa
**metade** a `a` estagiários, que fazem o mesmo. Com `b = 2` e `k = 1`, `b^k =
2`, e `a = 1`, 2 ou 4 cai numa linha diferente. O desenho mostra a árvore de
cada um para `n = 16`:

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

Confira com a tabela. Com `a = 1`, `1 < 2`: caso 3, a raiz domina, Θ(n), total
`2n - 1`. Com `a = 2`, `2 = 2`: caso 2, Θ(n log n), exatamente `n log₂ n + n`.
Com `a = 4`, `4 > 2`: caso 1, as folhas dominam, Θ(n²), total `2n² - n`.


O fluxograma é o teorema como receita: forma certa? depois `a` contra `b^k`.
O caminho marcado é o de `a = 2`:

{{fluxograma}}

A mesma receita resolve algoritmos conhecidos:

| algoritmo | a | b | k | b^k | resultado |
| --- | --- | --- | --- | --- | --- |
| busca binária | 1 | 2 | 0 | 1 | caso 2: Θ(log n) |
| máximo dividindo ao meio | 2 | 2 | 0 | 1 | caso 1: Θ(n) |
| merge sort | 2 | 2 | 1 | 2 | caso 2: Θ(n log n) |
| multiplicar polinômios com 3 produtos (Karatsuba) | 3 | 2 | 1 | 2 | caso 1: Θ(n^1,585) |
| algo que lê tudo e segue numa metade | 1 | 2 | 1 | 2 | caso 3: Θ(n) |

O teorema **não** se aplica quando a recorrência foge de `a T(n/b) + n^k`:
`T(n) = T(n-1) + n` (o tamanho cai subtraindo), `T(n) = T(n/3) + T(2n/3) + n`
(pedaços diferentes) ou `T(n) = 2 T(n/2) + n log n` (a forma do Cormen, na
nota abaixo, ainda pega este). Volte à árvore, que sempre funciona; o exemplo
A230 resolve dois desses casos.

> [!NOTE]
> **No Cormen (4ª ed.)** a forma é `T(n) = a T(n/b) + f(n)`, com `f(n)`
> comparada a `n^(log_b a)`. Caso 1: `f(n) = O(n^(log_b a - ε))` dá
> Θ(n^(log_b a)). Caso 2: `f(n) = Θ(n^(log_b a) · logᵖ n)`, p ≥ 0, dá
> Θ(n^(log_b a) · log^(p+1) n). Caso 3: `f(n) = Ω(n^(log_b a + ε))` **e**
> `a f(n/b) ≤ c f(n)` (c < 1) dão Θ(f(n)). Com p = 1, `2 T(n/2) + n log n` dá
> Θ(n log² n), o que o A230 mede.

> [!WARNING]
> Os quatro estagiários recebem metade cada um: é `4 T(n/2)`, não
> `4 T(n/4)`, e por isso o custo explode. Em `T(n) = 2 T(n-1) + 1` (Hanói) não existe `b`, pois `n - 1`
> não é `n` dividido por nada: use a árvore, que dá Θ(2ⁿ).

> [!TIP]
> **Por dentro do C:** o `n / 2` é divisão inteira; arredondar para cima ou
> para baixo não muda o Θ. Muda o **caso base**: com `if (n == 1)`, um `n = 0`
> passa, `0 / 2` dá 0 e a pilha estoura. Prefira `if (n <= 1)`.

> [!NOTE]
> **Pergunta para você:** e com `a = 3`? Antes de mudar o laço do `main`, diga
> em que linha da tabela o 3 cai e por quanto o total multiplica quando `n`
> dobra. Pista: `log₂ 3 ≈ 1,585`.

{{pratique}}

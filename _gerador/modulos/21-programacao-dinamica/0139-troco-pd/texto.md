## 0139 · Troco com programação dinâmica

- **Troco mínimo**: o menor número de moedas que somam **exatamente** um
  valor. O guloso (assunto 0133) erra em sistemas não canônicos; a PD testa
  todas as escolhas sem repetir trabalho (CORMEN et al., 2024, cap. 14).
- **Recorrência**: pelo **último** selo, `dp[v] = 1 + mín(dp[v - s])` para
  cada selo `s ≤ v`, com `dp[0] = 0` (LINTZMAYER; MOTA, 2023).
- **Subestrutura ótima**: tirando o último selo de uma solução ótima, o resto
  continua ótimo; senão daria para melhorar o todo
  (CORMEN et al., 2024, cap. 14).
- **Recuperar a solução**: `ultimo[v]` guarda o selo que deu o mínimo; anda-se
  para trás de `v` até 0 por `v - ultimo[v]` (ZIVIANI, 2010, cap. 2).
- **Custo**: `total` subproblemas, cada um testando `k` selos:
  **O(total × k)** de tempo e O(total) de memória
  (LINTZMAYER; MOTA, 2023).
- **Tabela grande**: para totais altos, aloque `dp` com `malloc` (assunto
  0054); na pilha, 1 milhão de `int` já passa do limite padrão
  (KERNIGHAN; RITCHIE, 1989).

> [!WARNING]
> O "infinito" precisa sobreviver a um `+ 1`. Com `INT_MAX`, a conta
> `dp[v - selo[s]] + 1` **estoura** o `int`. Use `1000000`, `total + 1` ou
> teste `dp[v - selo[s]] != INF` antes de somar.

{{exemplo}}

Nos Correios só há selos de R$ 1, R$ 4 e R$ 5, e a carta custa R$ 8. O guloso
cola 5 + 1 + 1 + 1, quatro selos; dois de R$ 4 bastam. No desenho, `dp[8]` olha
três vizinhos e escolhe o menor, o `dp[4]`:

{{ideia}}

```c
#include <stdio.h>

#define MAX 100
#define INF 1000000 // "impossível": maior que qualquer resposta de verdade

// dp[v] = menor número de selos que somam exatamente v reais
// ultimo[v] = o selo usado por último nessa solução
void minimo_selos(const int selo[], int k, int total, int dp[], int ultimo[]) {
    dp[0] = 0;                                  // R$ 0: nenhum selo
    for (int v = 1; v <= total; v++) {
        dp[v] = INF;
        for (int s = 0; s < k; s++) {
            // se o último selo for selo[s], antes dele faltavam v - selo[s]
            if (selo[s] <= v && dp[v - selo[s]] + 1 < dp[v]) {
                dp[v] = dp[v - selo[s]] + 1;
                ultimo[v] = selo[s];
            }
        }
    }
}

int main(void) {
    int selo[] = {1, 4, 5};                     // valores, em reais
    int porte = 8;
    int dp[MAX + 1], ultimo[MAX + 1];

    minimo_selos(selo, 3, porte, dp, ultimo);

    printf("v: ");
    for (int v = 0; v <= porte; v++) {
        printf(" %2d", v);
    }
    printf("\ndp:");
    for (int v = 0; v <= porte; v++) {
        printf(" %2d", dp[v]);
    }
    printf("\n%d selos para R$ %d:", dp[porte], porte);
    for (int v = porte; v > 0; v -= ultimo[v]) { // volta pelo último selo
        printf(" %d", ultimo[v]);
    }
    printf("\n");
    return 0;
}
// Saída:
// v:   0  1  2  3  4  5  6  7  8
// dp:  0  1  2  3  1  1  2  3  2
// 2 selos para R$ 8: 4 4
```

O laço de fora anda pelos valores e o de dentro testa cada selo como "o
último":

{{fluxograma}}

### Passo a passo

As três últimas células. Cada coluna é um selo testado como último; o mínimo
da linha vira `dp[v]`:

| v | selo 1: dp[v - 1] + 1 | selo 4: dp[v - 4] + 1 | selo 5: dp[v - 5] + 1 | dp[v] | ultimo[v] |
| --- | --- | --- | --- | --- | --- |
| 6 | dp[5] + 1 = 2 | dp[2] + 1 = 3 | dp[1] + 1 = 2 | 2 | 1 |
| 7 | dp[6] + 1 = 3 | dp[3] + 1 = 4 | dp[2] + 1 = 3 | 3 | 1 |
| 8 | dp[7] + 1 = 4 | dp[4] + 1 = **2** | dp[3] + 1 = 4 | 2 | 4 |

Em `v = 6` os selos 1 e 5 empatam. Como o teste é `<`, fica o primeiro que
achou o mínimo.

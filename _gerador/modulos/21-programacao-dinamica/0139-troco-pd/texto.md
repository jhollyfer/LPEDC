## 0139 · Troco com programação dinâmica

Nos Correios, o balcão só tem selos de R$ 1, R$ 4 e R$ 5, e sua carta custa
R$ 8 de porte. Você quer o **menor número de selos**.

O guloso do assunto 0133 pega o maior selo que cabe, R$ 5, e completa com
três de R$ 1: 4 selos. Dois selos de R$ 4 resolvem com 2. É o mesmo
contraexemplo `{1, 3, 4}` de lá: a escolha que parece melhor agora estraga o
resto.

A PD não aposta: **testa todas as escolhas sem repetir trabalho**. O **último
selo** colado foi de R$ 1, R$ 4 ou R$ 5, e antes dele sobrou um troco menor,
já resolvido com o mínimo de selos:

`dp[v] = 1 + o menor entre dp[v - 1], dp[v - 4] e dp[v - 5]`

só com os selos que cabem em `v`, e `dp[0] = 0`. `dp[v]` é o menor número de
selos que somam **exatamente** `v` reais.

Isso vale pela **subestrutura ótima**: tirando o último selo de uma solução
ótima, o resto continua ótimo (senão daria para melhorar a solução inteira).

Para saber **quais** selos usar, `ultimo[v]` guarda o selo que deu o mínimo
em `v`. Depois anda-se para trás: `v`, `v - ultimo[v]`, até 0.

No desenho, `dp[8]` olha três vizinhos, um por selo, e escolhe o menor, o
`dp[4]`:

{{ideia}}

O código enche a tabela de 1 até o porte. Valor impossível fica em
"infinito" (o A278 mostra quando):

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

Custo: `total` subproblemas, cada um testando `k` selos, **O(total × k)** de
tempo e O(total) de memória.

No fluxograma, o laço de fora anda pelos valores e o de dentro testa cada
selo como "o último":

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

> [!WARNING]
> O "infinito" precisa sobreviver a um `+ 1`. Com `INT_MAX`, a conta
> `dp[v - selo[s]] + 1` **estoura** o `int` (comportamento indefinido: o gcc
> com as flags de estudo acusa `signed integer overflow`). Use `1000000`,
> `total + 1` ou teste `dp[v - selo[s]] != INF` antes de somar.

> [!TIP]
> **Por dentro do C:** `dp` e `ultimo` ficam na pilha. Para troco de R$ 1
> milhão, seriam 8 MB e estouraria a pilha padrão do Linux: use `malloc`
> (assunto 0054).

> [!NOTE]
> **Pergunta para você:** com selos de R$ 1, R$ 4 e R$ 5, qual é o primeiro
> porte em que o atendente guloso erra? E o segundo? Mude o `porte` para 15 e
> compare a linha `dp` com o que o guloso daria em cada valor.

{{pratique}}

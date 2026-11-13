## 0139 · Troco com programação dinâmica

Nos Correios, o balcão só tem selos de R$ 1, R$ 4 e R$ 5, e a sua carta
custa R$ 8 de porte. Você quer colar o **menor número de selos** que somam
exatamente R$ 8. É o problema do **troco mínimo**: dado um conjunto de
valores, achar o menor número de peças que somam exatamente um total
(CORMEN et al., 2024, cap. 14).

O atendente guloso do assunto 0133 pega o maior selo que cabe, R$ 5, e
completa com três de R$ 1: quatro selos. Dois selos de R$ 4 resolvem com
dois. É o mesmo tropeço das fichas `{1, 3, 4}` de lá: o sistema não é
canônico, e a escolha que parece melhor agora estraga o resto. O guloso
aposta numa escolha e não volta atrás. A PD (0138) não aposta: ela testa
**todas** as escolhas, mas sem repetir trabalho.

O raciocínio é o mesmo dos degraus: olhe para o **último selo** colado. Ele
foi de R$ 1, de R$ 4 ou de R$ 5. Antes dele, sobrou um valor menor, que já
foi pago com o mínimo de selos. Então, chamando de `dp[v]` o menor número de
selos que somam exatamente `v` reais, vale `dp[v] = 1 + mín(dp[v - s])`,
tomando o mínimo sobre cada selo `s` que cabe em `v`, isto é, com `s ≤ v`. O
caso base é `dp[0] = 0`: pagar zero não pede selo nenhum (LINTZMAYER; MOTA,
2023).

Veja a conta para R$ 8. Se o último selo foi de R$ 1, antes sobraram 7, e
`dp[7] = 3`, total 4. Se foi de R$ 4, sobraram 4, e `dp[4] = 1`, total 2. Se
foi de R$ 5, sobraram 3, e `dp[3] = 3`, total 4. O menor é 2, pelo selo de
R$ 4. Para essa conta funcionar, `dp[7]`, `dp[4]` e `dp[3]` precisam estar
prontos antes, e por isso a tabela se enche de `v = 1` até o total.

Por que olhar só o último selo basta? Pela **subestrutura ótima**. Tire o
último selo de uma solução ótima para `v`: o que sobra é uma solução para
`v - s`, e ela também é ótima. Se não fosse, daria para trocá-la por uma
melhor e melhorar a solução de `v` inteira, o que contradiz ela ser ótima
(CORMEN et al., 2024, cap. 14).

A tabela `dp` diz **quantos** selos, mas não **quais**. Para isso, guarde
num segundo vetor, `ultimo[v]`, o selo que deu o mínimo em cada `v`. Depois,
ande para trás: comece em `v`, anote `ultimo[v]`, vá para `v - ultimo[v]` e
repita até chegar a 0 (ZIVIANI, 2010, cap. 2). Para R$ 8, `ultimo[8] = 4`
leva a `v = 4`, e `ultimo[4] = 4` leva a 0: dois selos de R$ 4.

Alguns valores podem ser impossíveis. Com selos de R$ 4 e R$ 5 apenas, não
dá para pagar R$ 3. A célula de um valor impossível guarda um "infinito",
um número maior que qualquer resposta de verdade, e ele nunca vence a
comparação do mínimo.

O custo segue a regra da PD: `total` subproblemas, cada um testando `k`
selos, dá **O(total × k)** de tempo e O(total) de memória (LINTZMAYER; MOTA,
2023). Para totais altos, a tabela pesa. Um milhão de `int` são 4 MB, e
`dp` e `ultimo` juntos já batem nos 8 MB da pilha padrão do Linux. Aloque
os vetores com `malloc` (assunto 0054) (KERNIGHAN; RITCHIE, 1989).

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

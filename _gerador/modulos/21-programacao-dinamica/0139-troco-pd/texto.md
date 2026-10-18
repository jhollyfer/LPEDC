## 0139 · Troco com programação dinâmica

Na agência dos Correios da cidadezinha, o balcão só tem selos de R$ 1, R$ 4 e
R$ 5. A sua carta custa R$ 8 de porte, e o envelope é pequeno: você quer
colar o **menor número de selos** possível.

O atendente faz o que todo mundo faz: pega o maior selo que cabe, R$ 5, e
completa com três de R$ 1. São 4 selos. Mas dois selos de R$ 4 também dão
R$ 8. O guloso do assunto 0133 errou de novo, e o motivo é o mesmo do
contraexemplo `{1, 3, 4}` de lá: com esses valores, a escolha que parece
melhor agora estraga o resto.

A programação dinâmica não aposta em escolha nenhuma: ela **testa todas**, mas
sem repetir trabalho. Olhe de novo para o **último selo** colado. Ele foi de
R$ 1, de R$ 4 ou de R$ 5. Se foi de R$ 4, antes dele você já tinha montado
R$ 4 da melhor forma possível. Então:

`dp[v] = 1 + o menor entre dp[v - 1], dp[v - 4] e dp[v - 5]`

só com os selos que cabem em `v` (`selo <= v`), e com `dp[0] = 0`: para
R$ 0 não precisa de selo nenhum. `dp[v]` é o menor número de selos que somam
**exatamente** `v` reais.

O que garante que isso dá certo é a **subestrutura ótima**: tire o último selo
de uma solução ótima para R$ 8, e o que sobra é uma solução ótima para o
resto. Se não fosse, você trocaria o resto por uma solução melhor e teria uma
solução para R$ 8 melhor que a ótima, o que é absurdo.

Para saber **quais** selos usar, não basta `dp`. Um segundo vetor,
`ultimo[v]`, anota o selo que deu o mínimo em `v`. Depois é só andar para
trás: `v`, `v - ultimo[v]`, e assim por diante, até chegar em 0.

Vamos ver na prática. `dp[8]` olha para três vizinhos à esquerda, um para
cada selo, e escolhe o menor deles, o `dp[4]`:

{{ideia}}

O código enche a tabela de 1 até o porte. Se um valor não pode ser montado,
`dp[v]` fica num "infinito" (o A278 mostra quando isso acontece):

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

O custo é o de toda PD: `total` subproblemas, cada um testando `k` selos.
**O(total × k)** de tempo e O(total) de memória. Para um troco de R$ 1.000
com 6 valores de selo, são 6 mil passos.

Repara no fluxograma: dois laços, um dentro do outro. O de fora anda pelos
valores, do menor para o maior; o de dentro testa cada selo como "o último":

{{fluxograma}}

### Passo a passo

As três últimas células da tabela. Cada coluna é um selo testado como
último; o mínimo da linha vira `dp[v]`:

| v | selo 1: dp[v - 1] + 1 | selo 4: dp[v - 4] + 1 | selo 5: dp[v - 5] + 1 | dp[v] | ultimo[v] |
| --- | --- | --- | --- | --- | --- |
| 6 | dp[5] + 1 = 2 | dp[2] + 1 = 3 | dp[1] + 1 = 2 | 2 | 1 |
| 7 | dp[6] + 1 = 3 | dp[3] + 1 = 4 | dp[2] + 1 = 3 | 3 | 1 |
| 8 | dp[7] + 1 = 4 | dp[4] + 1 = **2** | dp[3] + 1 = 4 | 2 | 4 |

No `v = 6` deu empate entre os selos 1 e 5. Como o teste é `<` (e não `<=`),
fica o primeiro que achou o mínimo. As duas soluções têm 2 selos: tanto faz.

> [!WARNING]
> O "infinito" precisa sobreviver a um `+ 1`. Se você usar `INT_MAX` de
> `<limits.h>`, a conta `dp[v - selo[s]] + 1` com `dp[...] == INT_MAX`
> **estoura** um `int` com sinal: é comportamento indefinido, o `rodar` acusa
> `signed integer overflow`, e sem o sanitizer o resultado vira um número
> negativo que "ganha" de todo mundo no `<`. Use um infinito folgado, como
> `1000000` ou `total + 1` (nunca se usa mais que `total` selos), ou teste
> `dp[v - selo[s]] != INF` antes de somar.

> [!TIP]
> **Por dentro do C:** os vetores `dp` e `ultimo` ficam na pilha, no frame do
> `main`: 101 `int` cada, 808 bytes no total. Para um troco de R$ 1 milhão,
> seriam 8 MB, e a pilha padrão do Linux tem 8 MB: o programa morreria com
> *stack overflow* antes da primeira conta. Para tabelas grandes, use
> `malloc` (assunto 0054). Repare também que `minimo_selos` recebe `dp` e
> `ultimo` como ponteiros: ela escreve direto nos vetores do `main`, sem
> copiar nada.

> [!NOTE]
> **Pergunta para você:** com selos de R$ 1, R$ 4 e R$ 5, qual é o primeiro
> porte em que o atendente guloso erra? E o segundo? Mude o `porte` para 15 e
> compare a linha `dp` com o que o guloso daria em cada valor.

{{pratique}}

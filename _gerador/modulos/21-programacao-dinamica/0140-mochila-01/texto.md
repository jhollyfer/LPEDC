## 0140 · Mochila 0/1

Um vendedor ambulante tem um isopor de 7 kg e quatro opções: fardo de água
(2 kg, lucro R$ 18), caixa de refrigerante (3 kg, R$ 24), caixa de suco
(4 kg, R$ 30) e pote de açaí (5 kg, R$ 35). Cada coisa vai inteira ou não
vai. O que levar para lucrar o máximo?

Na mochila **fracionária** (assunto 0135), o guloso por lucro por quilo
resolvia. Aqui erra: água (R$ 9/kg) e refrigerante (R$ 8/kg) dão R$ 42 com
5 kg e nada mais cabe, mas refrigerante e suco pesam 7 kg e dão **R$ 54**.

Esta é a **mochila 0/1** (0 = não leva, 1 = leva), com `2ⁿ` escolhas. A PD
olha **um item de cada vez**: o último item, `i`, vai ou não?

- **não vai**: vale o melhor dos itens `1..i-1` com a mesma capacidade `c`;
- **vai** (se `peso[i] <= c`): ganha `lucro[i]`, e os itens `1..i-1` dividem
  `c - peso[i]`.

A tabela é uma matriz: `t[i][c]` é o maior lucro usando só os itens `1..i`
com capacidade `c`.

`t[i][c] = o maior entre t[i-1][c] e lucro[i] + t[i-1][c - peso[i]]`

A linha 0 é toda zero, e a resposta fica no canto: `t[n][W]`.

A **recuperação** dá **o que levar**, de baixo para cima: se `t[i][c]` é igual
a `t[i-1][c]`, o item `i` ficou de fora; se mudou, ele foi junto, e a busca
segue na linha de cima com `c - peso[i]`.

No desenho, `t[3][7] = 54` (roxo) escolheu entre não levar o suco
(`t[2][7] = 42`, amarelo) e levar (`30 + t[2][3] = 54`, verde). As células
verdes são a recuperação:

{{ideia}}

Os vetores começam no índice 1, para casar com a linha 0 da tabela:

```c
#include <stdio.h>

#define N 4 // itens
#define W 7 // capacidade do isopor, em kg

int main(void) {
    const char *nome[N + 1] = {"", "água", "refri", "suco", "açaí"};
    int peso[N + 1] = {0, 2, 3, 4, 5};      // kg (o índice 0 não é usado)
    int lucro[N + 1] = {0, 18, 24, 30, 35}; // reais
    int t[N + 1][W + 1];

    // t[i][c] = maior lucro usando só os itens 1..i com capacidade c
    for (int c = 0; c <= W; c++) {
        t[0][c] = 0;                        // nenhum item: lucro 0
    }
    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= W; c++) {
            t[i][c] = t[i - 1][c];          // não leva o item i
            if (peso[i] <= c && lucro[i] + t[i - 1][c - peso[i]] > t[i][c]) {
                t[i][c] = lucro[i] + t[i - 1][c - peso[i]]; // leva o item i
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        printf("i=%d:", i);
        for (int c = 0; c <= W; c++) {
            printf(" %2d", t[i][c]);
        }
        printf("\n");
    }
    printf("Lucro máximo: R$ %d\n", t[N][W]);

    // volta pela tabela: se o valor mudou de i - 1 para i, o item i foi junto
    printf("Leva:");
    int c = W;
    for (int i = N; i >= 1; i--) {
        if (t[i][c] != t[i - 1][c]) {
            printf(" %s (%d kg)", nome[i], peso[i]);
            c -= peso[i];                   // o que sobrou para os anteriores
        }
    }
    printf("\n");
    return 0;
}
// Saída:
// i=0:  0  0  0  0  0  0  0  0
// i=1:  0  0 18 18 18 18 18 18
// i=2:  0  0 18 24 24 42 42 42
// i=3:  0  0 18 24 30 42 48 54
// i=4:  0  0 18 24 30 42 48 54
// Lucro máximo: R$ 54
// Leva: suco (4 kg) refri (3 kg)
```

São `(n + 1) × (W + 1)` células: **O(n × W)**. Como `W` é um **número**
escrito com uns log₂ W bits, o custo é **pseudopolinomial**: dobrar os bits
eleva `W` ao quadrado. A mochila 0/1 continua NP-difícil (assunto 0186).

O fluxograma mostra a decisão de uma célula; o caminho marcado é o de
`t[3][7]`:

{{fluxograma}}

### Passo a passo

A recuperação, partindo do canto `t[4][7]`:

| i | c | t[i][c] | t[i-1][c] | Mudou? | Decisão | c depois |
| --- | --- | --- | --- | --- | --- | --- |
| 4 (açaí) | 7 | 54 | 54 | não | fica | 7 |
| 3 (suco) | 7 | 54 | 42 | sim | **leva** | 7 - 4 = 3 |
| 2 (refri) | 3 | 24 | 18 | sim | **leva** | 3 - 3 = 0 |
| 1 (água) | 0 | 0 | 0 | não | fica | 0 |

> [!WARNING]
> Na recuperação, o teste é "o valor **mudou**?", e não "dá para levar?": o
> açaí cabe, mas não está na solução. Confira `peso[i] <= c` antes de ler
> `t[i - 1][c - peso[i]]`: com índice negativo, o C lê outra linha sem avisar.

> [!TIP]
> **Por dentro do C:** `t[i][c]` mora no deslocamento `i * 8 + c`, e
> `t[2][-2]` cai em `t[1][6]` sem erro. Uma linha só de `W + 1` posições basta
> se o laço de `c` andar do maior para o menor (A279).

> [!NOTE]
> **Pergunta para você:** se o isopor aguentasse 9 kg, o que o ambulante
> levaria, e com que lucro? Faça mais duas colunas na tabela à mão antes de
> trocar o `W` no código.

{{pratique}}

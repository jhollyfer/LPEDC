## 0140 · Mochila 0/1

- **Mochila 0/1**: capacidade `W` e `n` itens com peso e lucro; cada item vai
  inteiro (1) ou não vai (0). São `2ⁿ` escolhas
  (CORMEN et al., 2024, seção 15.2).
- **Guloso falha**: ordenar por lucro por quilo, que resolve a fracionária
  (assunto 0135), aqui pode deixar espaço vazio e perder lucro
  (CORMEN et al., 2024, seção 15.2).
- **Tabela**: `t[i][c]` é o maior lucro usando só os itens `1..i` com
  capacidade `c`. A linha 0 é toda zero e a resposta fica em `t[n][W]`
  (KLEINBERG; TARDOS, 2006, cap. 6).
- **Recorrência**: o item `i` **não vai** (`t[i-1][c]`) ou **vai**, se
  `peso[i] <= c` (`lucro[i] + t[i-1][c - peso[i]]`); fica o maior
  (KLEINBERG; TARDOS, 2006, cap. 6).
- **Recuperação**: de baixo para cima, se `t[i][c]` é igual a `t[i-1][c]`, o
  item `i` ficou de fora; se mudou, foi junto e `c` perde `peso[i]`
  (ZIVIANI, 2010, cap. 2).
- **Pseudopolinomial**: são `(n + 1) × (W + 1)` células, **O(n × W)**. Mas `W`
  é um número escrito com uns log₂ W bits; dobrar os bits eleva `W` ao
  quadrado. A mochila 0/1 continua NP-difícil (assunto 0186)
  (LINTZMAYER; MOTA, 2023).

> [!WARNING]
> Na recuperação, o teste é "o valor **mudou**?", e não "dá para levar?". E
> confira `peso[i] <= c` antes de ler `t[i - 1][c - peso[i]]`: com índice
> negativo, o C lê outra linha da matriz sem avisar.

{{exemplo}}

Um ambulante tem um isopor de 7 kg: água (2 kg, R$ 18), refri (3 kg, R$ 24),
suco (4 kg, R$ 30) e açaí (5 kg, R$ 35). O guloso leva água e refri (R$ 42);
refri e suco dão R$ 54. No desenho, `t[3][7] = 54` (roxo) escolheu entre não
levar o suco (amarelo) e levar (verde):

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

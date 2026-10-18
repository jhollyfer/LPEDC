## 0140 · Mochila 0/1

Sábado de praia. Um vendedor ambulante leva o isopor nas costas, e o isopor
aguenta no máximo 7 kg. Ele pode levar um fardo de água (2 kg, lucro de
R$ 18), uma caixa de refrigerante (3 kg, R$ 24), uma caixa de suco (4 kg,
R$ 30) e um pote de açaí (5 kg, R$ 35). Cada coisa vai inteira ou não vai:
não dá para levar meio pote de açaí. O que ele leva para lucrar o máximo?

Na mochila **fracionária** do assunto 0135, o guloso resolvia: ordenar por
lucro por quilo e ir enchendo, cortando o último item. Aqui ele erra. Água
(R$ 9/kg) e refrigerante (R$ 8/kg) vêm primeiro: 5 kg, R$ 42. Sobram 2 kg, e
nada mais cabe. Mas refrigerante e suco juntos pesam 7 kg e dão **R$ 54**.

Esta é a **mochila 0/1** (0 = não leva, 1 = leva). Com `n` itens há `2ⁿ`
escolhas possíveis; com 60 itens, mais de um quintilhão. A PD resolve olhando
para **um item de cada vez**: o último item, o `i`, vai ou não vai?

- **não vai**: o melhor é o que os itens `1..i-1` conseguem com a mesma
  capacidade `c`;
- **vai** (se `peso[i] <= c`): ganha `lucro[i]`, e os itens `1..i-1` dividem o
  que sobrou, `c - peso[i]`.

Com dois "parâmetros" mudando, a tabela vira uma matriz: `t[i][c]` é o maior
lucro usando só os itens `1..i` com capacidade `c`.

`t[i][c] = o maior entre t[i-1][c] e lucro[i] + t[i-1][c - peso[i]]`

A linha 0 (nenhum item) é toda zero. Cada linha só depende da de cima, então
a matriz se enche linha por linha, e a resposta fica no canto: `t[n][W]`.

A tabela dá o **valor**, mas o ambulante quer saber **o que levar**. A
**recuperação** anda de baixo para cima: se `t[i][c]` é igual a `t[i-1][c]`,
o item `i` não fez diferença e ficou de fora; se mudou, ele foi junto, e a
busca continua na linha de cima com `c - peso[i]`.

Vamos ver na prática. A célula `t[3][7] = 54` (roxo) escolheu entre não
levar o suco (`t[2][7] = 42`, amarelo) e levar (`30 + t[2][3] = 54`, verde).
As células verdes de baixo para cima são a recuperação:

{{ideia}}

O mesmo exemplo em C. Os vetores começam no índice 1 para casar com a
tabela, em que a linha 0 é "nenhum item":

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

São `(n + 1) × (W + 1)` células, cada uma com uma comparação: **O(n × W)**.
Para 100 itens e 10.000 kg de capacidade, um milhão de passos, contra os
2¹⁰⁰ subconjuntos da força bruta.

Repara no fluxograma: é o miolo do laço duplo, a decisão de uma célula. O
caminho marcado é o da célula `t[3][7]`, em que levar o suco ganhou:

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
> Na recuperação, o teste é "o valor **mudou**?", e não "dá para levar?".
> Olhar só se `peso[i] <= c` levaria o açaí, que cabe em 7 kg, mas não faz
> parte da solução ótima. E nunca leia `t[i - 1][c - peso[i]]` sem antes
> conferir `peso[i] <= c`: com o `c` menor que o peso, o índice fica
> negativo, e `t[i - 1][-2]` lê, sem erro de compilação nenhum, o fim de
> outra linha da tabela.

> [!TIP]
> **Por dentro do C:** `int t[5][8]` são 40 `int` seguidos na memória, linha
> após linha: `t[i][c]` mora no deslocamento `i * 8 + c`. Por isso
> `t[2][-2]` não derruba o programa: ele cai em `t[1][6]`, um valor errado e
> silencioso. O `rodar` acusa (`index -2 out of bounds for type 'int [8]'`,
> do UBSan), mas compilado sem sanitizer o programa segue em frente com a
> resposta errada. E como cada linha só usa a de cima, dá para guardar uma
> linha só, de `W + 1` posições, desde que o laço de `c` ande **do maior para
> o menor**. O A279 mostra esse truque e o que acontece quando ele é
> esquecido.

> [!NOTE]
> **Pergunta para você:** se o isopor aguentasse 9 kg, o que o ambulante
> levaria, e com que lucro? Faça mais duas colunas na tabela à mão antes de
> trocar o `W` no código.

{{pratique}}

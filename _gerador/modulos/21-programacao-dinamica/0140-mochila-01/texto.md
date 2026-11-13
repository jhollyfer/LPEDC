## 0140 · Mochila 0/1

Um vendedor ambulante tem um isopor que aguenta 7 kg e quatro opções para
levar à praia: um fardo de água (2 kg, lucro de R$ 18), uma caixa de
refrigerante (3 kg, R$ 24), uma caixa de suco (4 kg, R$ 30) e um pote de
açaí (5 kg, R$ 35). Cada coisa vai inteira ou não vai: ninguém leva meia
caixa de suco. O que ele põe no isopor para lucrar o máximo?

Esse é o problema da **mochila 0/1**. Há uma capacidade `W` e `n` itens,
cada um com peso e lucro, e cada item vai inteiro (1) ou fica de fora (0).
O objetivo é o maior lucro sem passar de `W` (CORMEN et al., 2024, seção
15.2). Como cada item tem duas opções, são `2ⁿ` escolhas possíveis. Para 50
itens, testar todas está fora de cogitação.

Na mochila fracionária (assunto 0135), o guloso pelo lucro por quilo
resolvia. Aqui ele erra (CORMEN et al., 2024, seção 15.2). Pela razão, a
água (R$ 9/kg) vem antes do refrigerante (R$ 8/kg). Os dois juntos pesam 5
kg e dão R$ 42, e nada mais cabe nos 2 kg que sobram. Mas refrigerante e
suco pesam exatamente 7 kg e dão **R$ 54**. O guloso deixou espaço vazio, e
como não dá para partir o suco, esse espaço virou prejuízo.

A PD (0138) olha **um item de cada vez** e pergunta: o último item, o de
número `i`, vai ou não vai? Se não vai, o lucro é o melhor que os itens de 1
a `i - 1` conseguem com a mesma capacidade `c`. Se vai, e só pode ir se
`peso[i] <= c`, o lucro é `lucro[i]` mais o melhor que os itens de 1 a
`i - 1` conseguem no espaço que sobrou, `c - peso[i]`. A resposta é a maior
das duas (KLEINBERG; TARDOS, 2006, cap. 6).

Para guardar essas respostas, a tabela é uma matriz. A célula `t[i][c]` é o
maior lucro usando só os itens de 1 a `i`, com capacidade `c`. A recorrência
fica: `t[i][c]` é o maior entre `t[i-1][c]` e `lucro[i] + t[i-1][c -
peso[i]]`, este último só quando o item cabe. A linha 0, sem nenhum item, é
toda zero. A resposta fica no canto de baixo, em `t[n][W]` (KLEINBERG;
TARDOS, 2006, cap. 6). No isopor, `t[3][7]` escolhe entre não levar o suco
(`t[2][7] = 42`) e levar (`30 + t[2][3] = 30 + 24 = 54`), e fica com 54.

A tabela diz o lucro, mas não **o que levar**. A **recuperação** responde
isso andando de baixo para cima, a partir de `t[n][W]`. Em cada linha, compare
`t[i][c]` com a célula de cima, `t[i-1][c]`. Se forem iguais, o item `i` não
fez diferença e ficou de fora. Se mudou, o item `i` foi junto, e a busca
segue na linha de cima com a capacidade reduzida, `c - peso[i]` (ZIVIANI,
2010, cap. 2). No isopor, o açaí não muda nada e fica; o suco muda e vai, e
a capacidade cai para 3; o refrigerante muda e vai, e ela cai para 0.

O custo é o tamanho da tabela: `(n + 1) × (W + 1)` células, cada uma
preenchida em tempo constante, ou seja, **O(n × W)**. Parece polinomial, mas
há uma pegadinha. `W` é um **número**, e um número se escreve com uns log₂ W
bits. Dobrar o tamanho da entrada, de 20 para 40 bits, eleva `W` ao
quadrado. Por isso esse custo se chama **pseudopolinomial**: é polinomial
no valor de `W`, não no tamanho da entrada. A mochila 0/1 continua
NP-difícil (assunto 0186) (LINTZMAYER; MOTA, 2023).

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

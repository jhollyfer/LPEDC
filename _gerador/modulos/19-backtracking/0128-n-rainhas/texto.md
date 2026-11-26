## 0128 · N-rainhas

O backtracking do assunto 0127 mostra a força real num quebra-cabeça antigo.
No xadrez, a rainha ataca qualquer peça na mesma linha, na mesma coluna ou na
mesma diagonal, a qualquer distância. O desafio é pôr `N` rainhas num
tabuleiro `N × N` sem que nenhuma ataque outra. Esse é o **problema das
N-rainhas**, o exemplo clássico de tentativa e erro (WIRTH, 1989).

Comece pelo tamanho do problema. Num tabuleiro 4 × 4, a força bruta escolheria
4 das 16 casas, sem olhar mais nada: são 1820 jeitos. A primeira observação
corta isso. Duas rainhas na mesma linha se atacam, e há `N` rainhas para `N`
linhas, então cada linha tem **exatamente uma** rainha. A solução deixa de ser
"quais casas" e vira "em que coluna fica a rainha de cada linha", um vetor
`pos` em que `pos[l]` é a coluna da rainha da linha `l` (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 3).

A busca segue o esqueleto do assunto 0127, uma linha por chamada. A função
`rainha(l)` tenta cada coluna `c` da linha `l`. Se a casa `(l, c)` é atacada
por alguma rainha já posta nas linhas de cima, a busca **poda** e passa para a
próxima coluna. Se a casa está livre, ela marca a rainha ali, desce para
`rainha(l + 1)` e, na volta, desmarca, para a casa estar limpa quando a
próxima coluna for tentada (FEOFILOFF, 2009). Quando `l` chega a `N`, todas as
linhas têm rainha, e a solução é mostrada.

Falta testar o ataque. O jeito óbvio é um laço pelas rainhas anteriores,
conferindo coluna e diagonais de cada uma. Há um jeito melhor, que depende de
uma propriedade das diagonais. Na diagonal que sobe para a direita, ↗, a
soma `l + c` é a mesma em todas as casas: andar uma casa na diagonal diminui a
linha em 1 e aumenta a coluna em 1. Essa soma vai de 0 a `2N - 2`, e serve
direto de índice. Na diagonal que desce para a direita, ↘, o que se mantém é a
diferença `l - c`, que vai de `-(N - 1)` a `N - 1`. Como índice de vetor não
pode ser negativo, some `N - 1`, e a faixa vira 0 a `2N - 2` (WIRTH, 1989).
Num 4 × 4, a casa da linha 1, coluna 3, está na ↗ de número 4 e na ↘ de número
`1 - 3 + 3 = 1`.

Com esses números, três vetores de `bool` guardam o que está ocupado:
`coluna[N]`, `diag1[2N - 1]` para as ↗ e `diag2[2N - 1]` para as ↘. A casa
`(l, c)` está livre se `coluna[c]`, `diag1[l + c]` e `diag2[l - c + N - 1]`
estão todos falsos. O laço pelas rainhas anteriores vira três leituras, em
O(1) (WIRTH, 1989). Com isso, o 8-rainhas acha as 92 soluções com 2057
chamadas.

Para marcar a rainha, o código usa uma **atribuição em cadeia**:
`coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = true`. Ela funciona porque,
em C, a atribuição é uma expressão que devolve o valor atribuído, e o
operador agrupa da direita para a esquerda: a atribuição mais à direita
acontece primeiro, e o valor dela alimenta a seguinte (KERNIGHAN; RITCHIE,
1989). Na volta, a mesma linha com `false` desmarca as três.

> [!WARNING]
> O índice da ↘ é `l - c + N - 1`, não `l - c`: para (0, 3), `diag2[-3]`
> escreve **fora** do vetor. Desmarcar só a coluna e esquecer as diagonais faz
> o programa achar menos soluções.

{{exemplo}}

Quatro rainhas num tabuleiro 4 × 4. À esquerda do desenho, a primeira solução;
no meio, `l + c` de cada casa; à direita, `l - c + 3`. A rainha da linha 1,
coluna 3, ocupa a ↗ 4 e a ↘ 1:

{{ideia}}

```c
#include <stdbool.h>
#include <stdio.h>

#define N 4

int pos[N];               // pos[l] = coluna da rainha da linha l
bool coluna[N];           // coluna[c]: já tem rainha na coluna c?
bool diag1[2 * N - 1];    // diagonal ↗, índice l + c
bool diag2[2 * N - 1];    // diagonal ↘, índice l - c + N - 1
int solucoes = 0, chamadas = 0;

void mostra(void) {
    printf("Solução %d:\n", solucoes);
    for (int l = 0; l < N; l++) {
        for (int c = 0; c < N; c++) {
            printf(c == 0 ? "%c" : " %c", pos[l] == c ? 'R' : '.');
        }
        printf("\n");
    }
}

// as linhas 0..l-1 já têm rainha; põe a da linha l
void rainha(int l) {
    chamadas++;
    if (l == N) {
        solucoes++;
        mostra();
        return;
    }
    for (int c = 0; c < N; c++) {
        if (coluna[c] || diag1[l + c] || diag2[l - c + N - 1]) {
            continue;                   // poda: a casa (l, c) está atacada
        }
        pos[l] = c;                     // escolhe
        coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = true;
        rainha(l + 1);                  // desce
        coluna[c] = diag1[l + c] = diag2[l - c + N - 1] = false; // desfaz
    }
}

int main(void) {
    rainha(0);
    printf("%d soluções, %d chamadas\n", solucoes, chamadas);
    return 0;
}
// Saída:
// Solução 1:
// . R . .
// . . . R
// R . . .
// . . R .
// Solução 2:
// . . R .
// R . . .
// . . . R
// . R . .
// 2 soluções, 17 chamadas
```

A rainha em (0, 0) nunca dá certo: a busca gasta 4 chamadas para descobrir e
esquece o galho. O fluxograma é o do assunto anterior, com um laço pelas
colunas:

{{fluxograma}}

### Passo a passo

O começo da busca, até a primeira solução. "Atacada" quer dizer que a poda
cortou a casa antes de qualquer chamada:

| linha | tenta | o que acontece |
| --- | --- | --- |
| 0 | coluna 0 | livre: marca e desce |
| 1 | colunas 0 e 1 | atacadas (coluna 0; diagonal ↘ da rainha (0, 0)) |
| 1 | coluna 2 | livre: marca e desce |
| 2 | colunas 0 a 3 | todas atacadas: volta, desmarca (1, 2) |
| 1 | coluna 3 | livre: marca e desce |
| 2 | coluna 1 | livre: marca e desce |
| 3 | colunas 0 a 3 | todas atacadas: volta; na linha 2, as colunas 2 e 3 também estão atacadas, e a linha 1 já tentou tudo: volta à linha 0 |
| 0 | coluna 1 | livre: desce, e o caminho 3, 0, 2 fecha a solução 1 |

## 0128 · N-rainhas

No clube de xadrez da praça, o desafio da semana está no quadro: pôr 4
rainhas num tabuleiro 4 × 4 sem que nenhuma ataque outra. A rainha ataca na
linha, na coluna e nas duas diagonais, até onde o tabuleiro for. Quantas
arrumações existem?

A força bruta escolheria 4 das 16 casas: 1820 jeitos, quase todos absurdos.
O primeiro corte vem de graça: duas rainhas na mesma linha se atacam, então
cada linha tem **exatamente uma** rainha. Basta decidir a coluna da rainha de
cada linha, e a solução vira um vetor `pos`, com `pos[l]` igual à coluna da
rainha da linha `l`.

Agora é backtracking puro: a função `rainha(l)` põe a rainha da linha `l`.
Ela tenta cada coluna `c` e **poda** as casas atacadas pelas rainhas das
linhas de cima. Se a casa está livre, marca, desce para a linha `l + 1` e,
na volta, desmarca. Se nenhuma coluna serve, a função simplesmente termina, e
quem a chamou passa para a próxima coluna: é o retrocesso.

O segredo está em testar o ataque em O(1), sem varrer as rainhas anteriores.
Cada casa `(l, c)` pertence a uma coluna e a duas diagonais, e as diagonais
têm um "endereço" fácil:

- na diagonal **↗** (sobe para a direita), `l + c` é o mesmo em todas as casas;
  vai de 0 a `2N - 2`;
- na diagonal **↘** (desce para a direita), `l - c` é o mesmo; vai de
  `-(N - 1)` a `N - 1`, então somamos `N - 1` para virar um índice válido.

Três vetores de `bool` guardam o que está ocupado: `coluna[N]`,
`diag1[2N - 1]` e `diag2[2N - 1]`. Uma casa está livre se as três posições
dela estão `false`.

Vamos ver na prática. À esquerda, a primeira solução que o programa acha. No
meio, o número `l + c` de cada casa; à direita, `l - c + 3`. A rainha da
linha 1, coluna 3, ocupa a diagonal ↗ número 4 e a diagonal ↘ número 1: as
casas destacadas ficam proibidas para as outras rainhas:

{{ideia}}

O programa mostra cada solução como um tabuleiro e conta as chamadas:

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

Repara que a rainha da linha 0 na coluna 0 nunca dá certo: a busca gasta 4
chamadas (uma na linha 1, duas na linha 2, uma na linha 3) para descobrir
isso, e depois esquece o galho inteiro.

Repara no fluxograma: é o esqueleto do assunto anterior, com um laço pelas
colunas no lugar de "leva ou não leva":

{{fluxograma}}

> [!WARNING]
> O índice da diagonal ↘ é `l - c + N - 1`, e não `l - c`. Para a casa
> (0, 3), `l - c` vale -3, e `diag2[-3]` escreve **fora** do vetor: o C não
> confere, o AddressSanitizer acusa e, sem ele, o programa estraga outra
> variável em silêncio. O outro erro comum é desmarcar só a coluna e esquecer
> as diagonais: o programa não trava, só acha menos soluções do que devia.

> [!TIP]
> **Por dentro do C:** os três vetores ocupam `N + 2(2N - 1)` bytes, 46 bytes
> para `N = 8`, e cada teste de ataque são três leituras de memória, em vez de
> um laço pelas rainhas anteriores. A expressão
> `coluna[c] = diag1[l + c] = diag2[...] = true` funciona porque a atribuição
> em C devolve o valor atribuído e é feita da direita para a esquerda. A
> pilha desce só `N + 1` frames. O que cresce é o número de nós da árvore,
> mas a poda é tão forte que o 8-rainhas acha as 92 soluções com 2057
> chamadas, contra 8⁸ = 16.777.216 tabuleiros da força bruta por linha.

> [!NOTE]
> **Pergunta para você:** troque `N` para 5 e para 6 antes de rodar. Quantas
> soluções você espera? O número sobe quando o tabuleiro cresce?

{{pratique}}

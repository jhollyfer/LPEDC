## 0128 · N-rainhas

No clube de xadrez, o desafio é pôr 4 rainhas num tabuleiro 4 × 4 sem que uma
ataque outra (linha, coluna ou diagonal). Quantas arrumações existem?

A força bruta escolheria 4 das 16 casas: 1820 jeitos. Mas duas rainhas na
mesma linha se atacam, então cada linha tem **exatamente uma**, e a solução é
um vetor `pos` com a coluna da rainha de cada linha.

`rainha(l)` tenta cada coluna `c` e **poda** as casas atacadas pelas rainhas
de cima; se a casa está livre, marca, desce para a linha `l + 1` e desmarca na
volta. Para testar o ataque em O(1), cada casa `(l, c)` tem um índice de
coluna e de diagonais:

- na diagonal **↗**, `l + c` é igual em todas as casas, de 0 a `2N - 2`;
- na diagonal **↘**, `l - c` é igual, de `-(N - 1)` a `N - 1`; somar `N - 1`
  dá um índice válido.

Três vetores de `bool` guardam o que está ocupado: `coluna[N]`, `diag1[2N - 1]`
e `diag2[2N - 1]`. No desenho, à esquerda está a primeira solução; no meio,
`l + c` de cada casa; à direita, `l - c + 3`. A rainha da linha 1, coluna 3,
ocupa a diagonal ↗ 4 e a ↘ 1, e as casas destacadas ficam proibidas:

{{ideia}}

O programa mostra cada solução como tabuleiro e conta as chamadas:

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

A rainha em (0, 0) nunca dá certo: a busca gasta 4 chamadas para descobrir e
esquece o galho. O fluxograma é o do assunto anterior, com um laço pelas
colunas no lugar de "leva ou não leva":

{{fluxograma}}

> [!WARNING]
> O índice da diagonal ↘ é `l - c + N - 1`, não `l - c`: para (0, 3), `diag2[-3]`
> escreve **fora** do vetor. Outro erro é desmarcar só a coluna e esquecer as
> diagonais: o programa acha menos soluções do que devia.

> [!TIP]
> **Por dentro do C:** cada teste de ataque são três leituras, sem laço pelas
> rainhas anteriores. A atribuição em cadeia funciona porque, em C, ela devolve
> o valor atribuído, da direita para a esquerda. O 8-rainhas acha as 92
> soluções com 2057 chamadas.

> [!NOTE]
> **Pergunta para você:** com `N` igual a 5 e a 6, quantas soluções você
> espera? O número sobe sempre que o tabuleiro cresce?

{{pratique}}

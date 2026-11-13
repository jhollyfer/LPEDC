## 0128 · N-rainhas

- **Problema das N-rainhas**: pôr `N` rainhas num tabuleiro `N × N` sem que
  uma ataque outra na linha, na coluna ou na diagonal. É o exemplo clássico de
  tentativa e erro (WIRTH, 1989).
- **Uma por linha**: duas rainhas na mesma linha se atacam, então a solução é
  um vetor `pos` com a coluna da rainha de cada linha
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3).
- **Busca**: `rainha(l)` tenta cada coluna, **poda** as casas atacadas e, na
  casa livre, marca, desce para `l + 1` e desmarca na volta (FEOFILOFF, 2009).
- **Diagonais**: na ↗, `l + c` é igual em todas as casas (0 a `2N - 2`); na ↘,
  `l - c` é igual, e somar `N - 1` dá um índice válido (WIRTH, 1989).
- **Ataque em O(1)**: três vetores de `bool` (`coluna[N]`, `diag1[2N - 1]`,
  `diag2[2N - 1]`) trocam o laço pelas rainhas anteriores por três leituras
  (WIRTH, 1989).
- **Atribuição em cadeia**: `a = b = c = true` funciona porque a atribuição
  devolve o valor atribuído, da direita para a esquerda
  (KERNIGHAN; RITCHIE, 1989).

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

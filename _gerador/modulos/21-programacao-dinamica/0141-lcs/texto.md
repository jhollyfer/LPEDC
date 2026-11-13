## 0141 · Maior subsequência comum (LCS)

- **Subsequência**: o que sobra depois de apagar letras, sem mudar a ordem.
  `MNG` é subsequência de `MORANGO`; `GNA` não é
  (CORMEN et al., 2024, cap. 14).
- **LCS** (*longest common subsequence*): a maior subsequência das duas
  strings. Testar todas é inviável: 30 letras já têm mais de um bilhão
  (CORMEN et al., 2024, cap. 14).
- **Recorrência**: olhe a última letra de cada uma. **Iguais**: ela fecha a
  LCS, some 1 à das duas sem ela. **Diferentes**: tire a última de `a` ou a de
  `b` e fique com a melhor (CORMEN et al., 2024, cap. 14).
- **Tabela**: `c[i][j]` é o tamanho da LCS dos **prefixos** `a[0..i-1]` e
  `b[0..j-1]`; a resposta fica em `c[m][n]` (LINTZMAYER; MOTA, 2023).
- **Recuperação**: do canto até a borda; letra igual entra na resposta e o
  caminho vai na diagonal, senão vai para o vizinho de onde o valor veio
  (CORMEN et al., 2024, cap. 14).
- **Custo**: `(m + 1) × (n + 1)` células de O(1), **O(m × n)** de tempo e de
  memória. Só o tamanho cabe em duas linhas; as letras pedem a tabela inteira
  (KLEINBERG; TARDOS, 2006, cap. 6).

| caso | `c[i][j]` |
| --- | --- |
| `i == 0` ou `j == 0` | 0 (um prefixo vazio) |
| `a[i-1] == b[j-1]` | `c[i-1][j-1] + 1` (diagonal) |
| letras diferentes | o maior entre `c[i-1][j]` (cima) e `c[i][j-1]` (esquerda) |

> [!WARNING]
> Subsequência não é **substring** (pedaço contíguo): a maior substring comum
> de MORANGO e MANGA é `ANG` (3), e a LCS tem 4. A linha `i` fala de
> `a[i - 1]`: escrever `a[i] == b[j]` compila e dá a resposta errada.

{{exemplo}}

Você ditou **MORANGO** e seu sobrinho escreveu **MANGA**. No desenho, o
caminho sai do canto roxo; as células verdes são as quatro letras da
resposta, e as amarelas, os passos sem letra:

{{ideia}}

```c
#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void) {
    const char *a = "MORANGO"; // o que foi ditado
    const char *b = "MANGA";   // o que foi escrito
    int m = strlen(a), n = strlen(b);
    int c[MAX + 1][MAX + 1];

    // c[i][j] = tamanho da maior subsequência comum de a[0..i-1] e b[0..j-1]
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;                          // um dos dois é vazio
            } else if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;        // a letra entra nas duas
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];                // descarta a letra de a
            } else {
                c[i][j] = c[i][j - 1];                // descarta a letra de b
            }
        }
    }

    printf("   -");
    for (int j = 0; j < n; j++) {
        printf(" %c", b[j]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) {
        printf("%c ", i == 0 ? '-' : a[i - 1]);
        for (int j = 0; j <= n; j++) {
            printf(" %d", c[i][j]);
        }
        printf("\n");
    }

    // recuperação: do canto até a borda, montando a resposta de trás para a frente
    char lcs[MAX + 1];
    int k = c[m][n];
    lcs[k] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[--k] = a[i - 1];                      // letra comum: diagonal
            i--;
            j--;
        } else if (c[i - 1][j] >= c[i][j - 1]) {
            i--;                                      // sobe
        } else {
            j--;                                      // vai para a esquerda
        }
    }
    printf("LCS de %s e %s: %s (%d letras)\n", a, b, lcs, c[m][n]);
    return 0;
}
// Saída:
//    - M A N G A
// -  0 0 0 0 0 0
// M  0 1 1 1 1 1
// O  0 1 1 1 1 1
// R  0 1 1 1 1 1
// A  0 1 2 2 2 2
// N  0 1 2 3 3 3
// G  0 1 2 3 4 4
// O  0 1 2 3 4 4
// LCS de MORANGO e MANGA: MANG (4 letras)
```

O caminho marcado no fluxograma é o de `c[6][4]` (G com G): as letras batem e
o valor vem da diagonal, `3 + 1`:

{{fluxograma}}

### Passo a passo

A volta, partindo de `c[7][5]`, monta a resposta **de trás para a frente**:

| posição | letras | iguais? | `c[i-1][j]` / `c[i][j-1]` | movimento | resposta até aqui |
| --- | --- | --- | --- | --- | --- |
| (7, 5) | O, A | não | 4 / 4 | sobe | |
| (6, 5) | G, A | não | 3 / 4 | esquerda | |
| (6, 4) | G, G | sim | | diagonal | G |
| (5, 3) | N, N | sim | | diagonal | NG |
| (4, 2) | A, A | sim | | diagonal | ANG |
| (3, 1) | R, M | não | 1 / 0 | sobe | ANG |
| (2, 1) | O, M | não | 1 / 0 | sobe | ANG |
| (1, 1) | M, M | sim | | diagonal | MANG |

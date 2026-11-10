## 0141 · Maior subsequência comum (LCS)

Você ditou **MORANGO** e seu sobrinho escreveu **MANGA**. Quantas letras ele
acertou na ordem certa? **MANG**: 4.

Uma **subsequência** é o que sobra depois de apagar letras, sem mudar a ordem:
`MNG` é subsequência de `MORANGO`; `GNA` não é. A **maior subsequência comum**
(*longest common subsequence*, LCS) é a mais comprida que é subsequência das
duas strings. Uma palavra de 30 letras tem mais de um bilhão delas.

A PD compara a última letra de cada string:

- **iguais**: a letra fecha a LCS; some 1 à LCS das duas sem ela;
- **diferentes**: tire a última de `a` ou a de `b` e fique com a melhor.

Na tabela, `c[i][j]` é o tamanho da LCS dos **prefixos** `a[0..i-1]` e
`b[0..j-1]`:

| caso | `c[i][j]` |
| --- | --- |
| `i == 0` ou `j == 0` | 0 (um prefixo vazio) |
| `a[i-1] == b[j-1]` | `c[i-1][j-1] + 1` (diagonal) |
| letras diferentes | o maior entre `c[i-1][j]` (cima) e `c[i][j-1]` (esquerda) |

A resposta fica em `c[m][n]`. A volta anda do canto até a borda: letras
iguais entram na resposta e o caminho vai na diagonal; senão, vai para o
vizinho de onde o valor veio (o Cormen guarda isso numa tabela de setas; aqui
refazemos na volta).

No desenho, o caminho sai do canto roxo; as células verdes são as quatro
letras da resposta, e as amarelas, os passos sem letra:

{{ideia}}

O código enche a tabela e faz a volta:

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

A tabela tem `(m + 1) × (n + 1)` células de O(1): **O(m × n)** de tempo e de
memória.

No fluxograma, o caminho marcado é o de `c[6][4]` (G com G): as letras batem
e o valor vem da diagonal, `3 + 1`:

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

> [!WARNING]
> Subsequência não é **substring** (pedaço contíguo): a maior substring comum
> de MORANGO e MANGA é `ANG` (3), e a LCS tem 4. A linha `i` fala de
> `a[i - 1]`: escrever `a[i] == b[j]` compila e dá a resposta errada.

> [!TIP]
> **Por dentro do C:** para dois textos de 10 mil caracteres a tabela passa de
> 400 MB: use `malloc`. Só o **tamanho** pede duas linhas de `n + 1` posições
> (A281); **recuperar** as letras pede a tabela inteira.

> [!NOTE]
> **Pergunta para você:** a LCS de MORANGO e MANGA é única? Troque o `>=` das
> duas comparações por `>` (na tabela e na volta) e veja se a resposta muda.
> E a LCS de `ABAB` e `BABA`?

{{pratique}}

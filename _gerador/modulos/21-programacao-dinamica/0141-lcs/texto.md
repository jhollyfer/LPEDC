## 0141 · Maior subsequência comum (LCS)

Seu sobrinho está aprendendo a escrever. Você ditou **MORANGO**, ele escreveu
**MANGA**. Quantas letras ele acertou na ordem certa? Não vale contar letra
fora de ordem nem pular para trás: o que importa é o maior pedaço da palavra
ditada que aparece, **na mesma ordem**, na palavra escrita. Aqui é **MANG**:
4 letras.

Uma **subsequência** de uma string é o que sobra depois de apagar algumas
letras, sem mudar a ordem das outras. `MNG` é subsequência de `MORANGO`
(apagando O, R, A e o último O); `GNA` não é. A **maior subsequência comum**
(em inglês, *longest common subsequence*, LCS) de duas strings é a mais
comprida que é subsequência das duas.

Força bruta é inviável: uma palavra de 30 letras tem 2³⁰, mais de um bilhão,
de subsequências. A PD de novo olha para o **fim**. Compare a última letra
de cada uma:

- **iguais**: essa letra fecha a LCS. Some 1 à LCS das duas sem a última
  letra;
- **diferentes**: pelo menos uma das duas não está na LCS. Teste as duas
  hipóteses (tirar a última de `a` ou a última de `b`) e fique com a melhor.

Na tabela, `c[i][j]` é o tamanho da LCS dos **prefixos** `a[0..i-1]` e
`b[0..j-1]` (os `i` primeiros caracteres de `a` e os `j` primeiros de `b`):

| caso | `c[i][j]` |
| --- | --- |
| `i == 0` ou `j == 0` | 0 (um prefixo vazio) |
| `a[i-1] == b[j-1]` | `c[i-1][j-1] + 1` (diagonal) |
| letras diferentes | o maior entre `c[i-1][j]` (cima) e `c[i][j-1]` (esquerda) |

A resposta fica em `c[m][n]`. Para recuperar as letras, anda-se do canto de
volta até a borda: onde as letras batem, a letra entra e o caminho vai na
diagonal; onde não batem, ele vai para o vizinho de onde o valor veio.

Vamos ver na prática. Cada linha é uma letra de MORANGO e cada coluna uma de
MANGA. O caminho de volta sai do canto roxo; as células verdes são as quatro
letras da resposta, e as amarelas, os passos sem letra:

{{ideia}}

O mesmo exemplo em C:

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

A tabela tem `(m + 1) × (n + 1)` células e cada uma custa O(1): **O(m × n)**
de tempo e de memória. Duas strings de 1.000 letras dão um milhão de
células, uns 4 MB de `int`; a força bruta nem começaria.

Repara no fluxograma: é a decisão de uma célula. O caminho marcado é o da
célula da linha G com a coluna G (`c[6][4]`), em que as letras batem e o
valor vem da diagonal, `3 + 1`:

{{fluxograma}}

### Passo a passo

A volta, partindo de `c[7][5]`. Repare que a recuperação monta a resposta
**de trás para a frente**: G sai primeiro e M por último:

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
> Subsequência não é **substring**. Uma substring é um pedaço **contíguo**:
> em MORANGO e MANGA, a maior substring comum é `ANG`, com 3 letras,
> enquanto a LCS tem 4. A outra pegadinha são os índices: a tabela tem uma
> linha e uma coluna a mais (a do prefixo vazio), então a linha `i` fala da
> letra `a[i - 1]`. Escrever `a[i] == b[j]` compila, roda sem reclamar do
> sanitizer (no fim, compara com o `'\0'`) e dá a resposta errada.

> [!TIP]
> **Por dentro do C:** `int c[51][51]` mora na pilha e ocupa 51 × 51 × 4 =
> 10.404 bytes, mesmo que as palavras sejam curtas. Para comparar dois textos
> de 10 mil caracteres, seriam 400 MB: não cabe na pilha nem com muita
> vontade. Se você só precisa do **tamanho** da LCS, cada linha só usa a de
> cima, e duas linhas de `n + 1` posições bastam (o A281 faz isso). Para
> **recuperar** as letras, a tabela inteira, alocada com `malloc`, é o jeito
> simples.

> [!NOTE]
> **Pergunta para você:** a LCS de MORANGO e MANGA é única? Troque o `>=` das
> duas comparações por `>` (na tabela e na volta) e veja se a resposta muda.
> E a LCS de `ABAB` e `BABA`?

{{pratique}}

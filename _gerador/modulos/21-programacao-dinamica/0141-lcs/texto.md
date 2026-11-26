## 0141 · Maior subsequência comum (LCS)

Você ditou **MORANGO** e o seu sobrinho escreveu **MANGA**. Quantas letras
ele acertou na ordem certa? Comparar posição por posição não serve, porque
um erro no começo desalinha o resto. A pergunta certa é: qual a maior
sequência de letras que aparece nas duas palavras, na mesma ordem, mesmo com
outras letras no meio? Aqui é **MANG**, quatro letras. A mesma pergunta
compara versões de um arquivo e trechos de DNA.

Uma **subsequência** de uma string é o que sobra depois de apagar algumas
letras dela, sem mudar a ordem das que ficam (CORMEN et al., 2024, cap. 14).
`MNG` é subsequência de `MORANGO`: apague O, R, A e O. `GNA` não é, porque
em MORANGO o G vem depois do N e do A. A **maior subsequência comum**
(*longest common subsequence*, LCS) de duas strings é a mais comprida que é
subsequência das duas ao mesmo tempo (CORMEN et al., 2024, cap. 14).

Testar todas não dá. Cada letra pode ficar ou sair, então uma palavra de 30
letras tem 2³⁰, mais de um bilhão, de subsequências (CORMEN et al., 2024, cap.
14). A PD (0138) resolve olhando só a **última letra** de cada string. Se as
duas forem **iguais**, essa letra pode fechar a LCS: a resposta é 1 mais a
LCS das duas strings sem a última letra. Se forem **diferentes**, pelo menos
uma delas não entra na LCS. Então tire a última de `a` ou a última de `b`,
resolva cada caso e fique com o melhor (CORMEN et al., 2024, cap. 14).

Cada passo encurta uma string ou as duas, e o que sobra são sempre
**prefixos**, os começos das strings. Daí a tabela: `c[i][j]` é o tamanho da
LCS do prefixo de `a` com `i` letras, `a[0..i-1]`, com o prefixo de `b` com
`j` letras, `b[0..j-1]`. Com `m` e `n` letras nas duas strings, a resposta
fica em `c[m][n]` (LINTZMAYER; MOTA, 2023). A linha 0 e a coluna 0 valem 0,
porque nada é comum com um prefixo vazio.

Repare no deslocamento de índice. A linha `i` da tabela fala da letra
`a[i-1]`, porque a linha 0 é reservada ao prefixo vazio. Comparar `a[i]` com
`b[j]` é o erro clássico. A tabela resume os três casos, e cada célula olha
no máximo três vizinhas já preenchidas: a de cima, a da esquerda e a da
diagonal:

| caso | `c[i][j]` |
| --- | --- |
| `i == 0` ou `j == 0` | 0 (um prefixo vazio) |
| `a[i-1] == b[j-1]` | `c[i-1][j-1] + 1` (diagonal) |
| letras diferentes | o maior entre `c[i-1][j]` (cima) e `c[i][j-1]` (esquerda) |

O número no canto diz o tamanho, mas não quais letras. A **recuperação**
anda do canto `c[m][n]` até a borda. Se as letras da posição são iguais,
ela entra na resposta e o caminho segue na diagonal. Se não, o caminho vai
para o vizinho, de cima ou da esquerda, de onde o valor veio (CORMEN et al.,
2024, cap. 14). As letras saem de trás para a frente: em MORANGO e MANGA,
primeiro G, depois N, A e M. O Cormen guarda a direção de cada célula numa
tabela de setas; também dá para refazer a comparação na volta.

O custo é o tamanho da tabela. São `(m + 1) × (n + 1)` células, cada uma
calculada em O(1), o que dá **O(m × n)** de tempo e de memória. Se você só
quer o **tamanho** da LCS, duas linhas bastam, porque cada linha só olha a
anterior. Para **recuperar** as letras, porém, o caminho de volta precisa da
tabela inteira (KLEINBERG; TARDOS, 2006, cap. 6).

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

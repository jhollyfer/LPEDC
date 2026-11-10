## 0142 · Distância de edição

Você digita "pesoa" e o corretor oferece "pessoa": falta inserir um `s`. Ele
ranqueia as sugestões pelo número de **edições** entre as palavras.

A **distância de edição** (ou **de Levenshtein**) é o menor número de
operações que transforma uma string em outra. Cada uma custa 1: **inserir**,
**remover** ou **trocar** uma letra.

Como na LCS (assunto 0141), a PD olha o fim das palavras. Últimas letras
**iguais**: o custo é o das palavras sem elas. **Diferentes**: vale a mais
barata das três operações:

- **trocar** a última de `a` pela última de `b`: 1 + resolver as duas sem a
  última letra;
- **remover** a última de `a`: 1 + transformar `a` sem ela em `b`;
- **inserir** a última de `b`: 1 + transformar `a` em `b` sem ela.

Na tabela, `d[i][j]` é a distância entre os prefixos `a[0..i-1]` e
`b[0..j-1]`. A **borda** difere da LCS: `d[i][0] = i` (`i` remoções) e
`d[0][j] = j` (`j` inserções).

| caso | `d[i][j]` |
| --- | --- |
| `a[i-1] == b[j-1]` | `d[i-1][j-1]` (diagonal, de graça) |
| letras diferentes | `1 +` o menor entre `d[i-1][j-1]` (troca), `d[i-1][j]` (remove) e `d[i][j-1]` (insere) |

CARTA e ARTES distam 3: remover o C, inserir um E e trocar o último A por S
(CARTA, ARTA, ARTEA, ARTES). As setas mostram de onde cada célula veio:

{{ideia}}

A volta mostra as edições do fim para o começo (o E852 monta o alinhamento na
ordem certa):

```c
#include <stdio.h>
#include <string.h>

#define MAX 50

int menor3(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int main(void) {
    const char *a = "CARTA"; // de onde parte
    const char *b = "ARTES"; // aonde quer chegar
    int m = strlen(a), n = strlen(b);
    int d[MAX + 1][MAX + 1];

    // d[i][j] = menor número de edições que transforma a[0..i-1] em b[0..j-1]
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;                                // apagar as i letras
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;                                // inserir as j letras
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[i][j] = d[i - 1][j - 1];          // letra igual: de graça
            } else {
                d[i][j] = 1 + menor3(d[i - 1][j - 1], // troca a[i-1] por b[j-1]
                                     d[i - 1][j],     // remove a[i-1]
                                     d[i][j - 1]);    // insere b[j-1]
            }
        }
    }

    printf("     -");
    for (int j = 0; j < n; j++) {
        printf("  %c", b[j]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) {
        printf("  %c", i == 0 ? '-' : a[i - 1]);
        for (int j = 0; j <= n; j++) {
            printf("  %d", d[i][j]);
        }
        printf("\n");
    }
    printf("distância de %s para %s: %d\n", a, b, d[m][n]);

    // volta: de onde veio cada célula? As edições saem do fim para o começo
    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) {
            i--;                                    // igual: não custa nada
            j--;
        } else if (i > 0 && j > 0 && d[i][j] == d[i - 1][j - 1] + 1) {
            printf("  troca %c por %c\n", a[i - 1], b[j - 1]);
            i--;
            j--;
        } else if (i > 0 && d[i][j] == d[i - 1][j] + 1) {
            printf("  remove %c\n", a[i - 1]);
            i--;
        } else {
            printf("  insere %c\n", b[j - 1]);
            j--;
        }
    }
    return 0;
}
// Saída:
//      -  A  R  T  E  S
//   -  0  1  2  3  4  5
//   C  1  1  2  3  4  5
//   A  2  1  2  3  4  5
//   R  3  2  1  2  3  4
//   T  4  3  2  1  2  3
//   A  5  4  3  2  2  3
// distância de CARTA para ARTES: 3
//   troca A por S
//   insere E
//   remove C
```

O custo é **O(m × n)**. Um corretor que compara a palavra com 300 mil do
dicionário descarta antes as de tamanho muito diferente: a distância é pelo
menos a diferença dos tamanhos.

No fluxograma, o caminho marcado é o de `d[5][5]` (A contra S), em que a
troca ganhou:

{{fluxograma}}

### Passo a passo

A volta, partindo de `d[5][5] = 3`. Em cada célula: "de qual vizinho eu vim?"

| posição | letras | candidatos: troca / remove / insere | veio de | operação |
| --- | --- | --- | --- | --- |
| (5, 5) | A, S | 2 + 1 / 3 + 1 / 2 + 1 | diagonal (troca, testada primeiro) | troca A por S |
| (4, 4) | T, E | 2 + 1 / 3 + 1 / 1 + 1 | esquerda | insere E |
| (4, 3) | T, T | iguais | diagonal | nenhuma |
| (3, 2) | R, R | iguais | diagonal | nenhuma |
| (2, 1) | A, A | iguais | diagonal | nenhuma |
| (1, 0) | C, - | borda | cima | remove C |

> [!WARNING]
> A borda **não** é zero, como na LCS: sem `d[i][0] = i` e `d[0][j] = j`,
> CARTA e ARTES dariam 2. Na volta, confira `i > 0` e `j > 0` antes de ler
> `d[i - 1][...]` ou `a[i - 1]`.

> [!TIP]
> **Por dentro do C:** com `gcc -O2`, o compilador costuma embutir `menor3`
> no laço (*inline*), sem empilhar um frame por célula.

> [!NOTE]
> **Pergunta para você:** a distância de A para B é sempre igual à de B para
> A? Troque `a` e `b` no código e compare a tabela e as operações. O que
> acontece com cada "insere" e cada "remove"?

{{pratique}}

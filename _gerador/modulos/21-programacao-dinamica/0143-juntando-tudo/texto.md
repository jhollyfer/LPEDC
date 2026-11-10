## 0143 · Juntando tudo: um mini-diff

Você e sua mãe dividem a lista de compras num arquivo, uma coisa por linha.
O que mudou depois que ela salvou? Comparar linha com linha não serve: uma
linha nova no começo faz **todas** parecerem diferentes.

O `diff` resolve com a **LCS** do assunto 0141, de **linhas** em vez de
letras (duas linhas casam quando `strcmp` dá 0). As linhas da LCS ficaram
iguais; as que só estão na versão antiga foram **removidas** (`-`); as que só
estão na nova foram **adicionadas** (`+`).

`linhas.h` e `linhas.c` (assunto 0034) leem com `fgets`, tiram o `'\n'` e
guardam cada linha num `malloc` exato, num `char **` que dobra com `realloc`
(assunto 0055).

A tabela é dos **sufixos**: `c[i][j]` é a LCS de `a[i..m-1]` e `b[j..n-1]`. A
resposta fica em `c[0][0]` e a volta anda do **começo** para o fim. Linhas
iguais saem com dois espaços; se não, o vizinho com a LCS maior decide se a
linha de `a` sai com `-` ou a de `b` com `+`.

No desenho, a lista antiga fica à esquerda, a nova à direita, e os traços
ligam as cinco linhas da LCS:

{{ideia}}

Sem argumentos, o programa compara duas listas gravadas em `/tmp`; com dois
nomes de arquivo (assunto 0069), compara os seus:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linhas.h"

// diff linha a linha: LCS dos SUFIXOS, para a volta andar do começo ao fim
void diff(char **a, int m, char **b, int n) {
    // c[i * w + j] = LCS de a[i..m-1] e b[j..n-1]: a matriz (m+1) x (n+1)
    // num bloco só do malloc, linha após linha
    int w = n + 1;
    int *c = malloc((size_t) (m + 1) * w * sizeof *c);
    if (c == NULL) {
        return;
    }
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == m || j == n) {
                c[i * w + j] = 0;                      // um sufixo vazio
            } else if (strcmp(a[i], b[j]) == 0) {
                c[i * w + j] = c[(i + 1) * w + j + 1] + 1;
            } else {
                int baixo = c[(i + 1) * w + j], dir = c[i * w + j + 1];
                c[i * w + j] = baixo >= dir ? baixo : dir;
            }
        }
    }

    int i = 0, j = 0, iguais = 0, menos = 0, mais = 0;
    while (i < m || j < n) {
        if (i < m && j < n && strcmp(a[i], b[j]) == 0) {
            printf("  %s\n", a[i]);                    // está nas duas versões
            i++;
            j++;
            iguais++;
        } else if (j == n || (i < m && c[(i + 1) * w + j] >= c[i * w + j + 1])) {
            printf("- %s\n", a[i]);                    // só na versão antiga
            i++;
            menos++;
        } else {
            printf("+ %s\n", b[j]);                    // só na versão nova
            j++;
            mais++;
        }
    }
    printf("(%d iguais, %d removidas, %d adicionadas)\n", iguais, menos, mais);
    free(c);
}

int main(int argc, char *argv[]) {
    const char *antigo = "/tmp/compras-v1.txt";
    const char *novo = "/tmp/compras-v2.txt";
    if (argc == 3) {                                   // ./programa a.txt b.txt
        antigo = argv[1];
        novo = argv[2];
    } else {                                           // sem argumentos: o exemplo
        const char *v1[] = {"arroz", "feijão", "café", "leite", "pão", "banana",
                            "sabão"};
        const char *v2[] = {"arroz", "feijão", "açúcar", "café", "leite sem lactose",
                            "pão", "banana"};
        grava_linhas(antigo, v1, 7);
        grava_linhas(novo, v2, 7);
    }

    int m = 0, n = 0;
    char **a = le_linhas(antigo, &m);
    char **b = le_linhas(novo, &n);
    if (a != NULL && b != NULL) {
        diff(a, m, b, n);
    }
    libera_linhas(a, m);
    libera_linhas(b, n);
    return 0;
}
// Saída:
//   arroz
//   feijão
// + açúcar
//   café
// - leite
// + leite sem lactose
//   pão
//   banana
// - sabão
// (5 iguais, 2 removidas, 2 adicionadas)
```

"leite" e "leite sem lactose" viram uma remoção e uma adição. O A286 usa a
distância de edição (0142) para perceber que a linha só foi **alterada**.

No fluxograma, o caminho marcado é o das duas primeiras linhas, iguais:

{{fluxograma}}

> [!WARNING]
> `fgets` guarda o `'\n'`, e a última linha do arquivo pode vir **sem** ele.
> Sem tirá-lo, "banana\n" e "banana" diferem no `strcmp` e o diff acusa uma
> mudança invisível. O `buf[strcspn(buf, "\n")] = '\0'` do `linhas.c` corta o
> `'\n'` se existir e não faz nada se não existir.

> [!TIP]
> **Por dentro do C:** a tabela não pode ser `int c[m + 1][n + 1]` na pilha:
> dois arquivos de 2.000 linhas pediriam 16 MB, o dobro da pilha. Ela é um
> bloco só do `malloc`, e a célula `(i, j)` mora em `c[i * w + j]`, com
> `w = n + 1`. Com 100 mil linhas seriam 40 GB; por isso o `diff` real usa o
> algoritmo de Myers, O((m + n) × D), com D o número de diferenças.

> [!NOTE]
> **Pergunta para você:** se sua mãe só tivesse trocado a ordem de "pão" e
> "banana", quantas linhas sairiam com `-` e com `+`? Troque a ordem em `v2` e
> confira.

{{pratique}}

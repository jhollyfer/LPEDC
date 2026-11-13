## 0143 · Juntando tudo: um mini-diff

- **`diff`**: mostra o que mudou entre duas versões de um arquivo. Comparar
  linha com linha não serve: uma linha nova no começo faz todas parecerem
  diferentes (LINUX MAN-PAGES, s.d.).
- **LCS de linhas**: a LCS (assunto 0141) com linhas no lugar de letras; duas
  linhas casam quando `strcmp` dá 0. As da LCS ficaram iguais; as que só estão
  na antiga foram **removidas** (`-`); as que só estão na nova, **adicionadas**
  (`+`) (CORMEN et al., 2024, cap. 14).
- **Tabela de sufixos**: `c[i][j]` é a LCS de `a[i..m-1]` e `b[j..n-1]`. A
  resposta fica em `c[0][0]` e a volta anda do **começo** para o fim
  (LINTZMAYER; MOTA, 2023).
- **Ler linhas**: `fgets` guarda o `'\n'`; `buf[strcspn(buf, "\n")] = '\0'`
  corta-o se existir (CPPREFERENCE, s.d.).
- **Matriz num bloco**: a tabela vem de um único `malloc`, e a célula `(i, j)`
  mora em `c[i * w + j]`, com `w = n + 1` (KERNIGHAN; RITCHIE, 1989).
- **Algoritmo de Myers**: o `diff` real gasta O((m + n) × D), com D o número
  de diferenças, em vez de O(m × n) (MYERS, 1986).

> [!WARNING]
> Sem tirar o `'\n'`, "banana\n" e "banana" diferem no `strcmp` e o diff acusa
> uma mudança invisível. A última linha do arquivo pode vir **sem** `'\n'`.

{{exemplo}}

Você e sua mãe dividem a lista de compras num arquivo. `linhas.h` e
`linhas.c` (assunto 0034) leem as linhas num `char **` que dobra com
`realloc` (assunto 0055). No desenho, a lista antiga fica à esquerda, a nova à
direita, e os traços ligam as cinco linhas da LCS:

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

"leite" e "leite sem lactose" viram uma remoção e uma adição; o A286 usa a
distância de edição (0142) para ver que a linha só foi **alterada**. O caminho
marcado é o das duas primeiras linhas, iguais:

{{fluxograma}}

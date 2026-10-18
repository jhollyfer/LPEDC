## 0143 · Juntando tudo: um mini-diff

Você e sua mãe dividem a lista de compras do mês num arquivo de texto, uma
coisa por linha. Ela abriu o arquivo, mexeu e salvou. O que mudou? Comparar
linha 1 com linha 1, linha 2 com linha 2 não serve: basta ela inserir uma
linha no começo para **todas** as outras parecerem diferentes.

A ferramenta que responde isso existe em todo sistema Unix e se chama
`diff`. É ela que mostra as mudanças num controle de versão. E o coração
dela é a **LCS** do assunto 0141, só que de **linhas** em vez de letras: as
linhas da LCS ficaram iguais; as que só estão na versão antiga foram
**removidas** (`-`); as que só estão na nova foram **adicionadas** (`+`).
Duas linhas são "a mesma letra" quando `strcmp` dá 0.

A leitura dos arquivos fica num módulo pequeno (assunto 0034), `linhas.h` e
`linhas.c`, na pasta do assunto. `le_linhas` lê com `fgets`, tira o `'\n'`
e guarda cada linha num `malloc` do tamanho exato, dentro de um `char **`
que dobra com `realloc` (assunto 0055). `grava_linhas` escreve um vetor de
strings num arquivo, e `libera_linhas` devolve tudo.

Uma mudança em relação ao 0141 deixa a saída mais simples. Lá, a volta
começava no **fim** das strings e a resposta saía de trás para a frente.
Aqui a tabela é dos **sufixos**: `c[i][j]` é a LCS de `a[i..m-1]` e
`b[j..n-1]`, cheia de baixo para cima. A resposta fica em `c[0][0]`, e a
volta anda do **começo** para o fim, imprimindo cada linha já na ordem
certa. Em cada passo: linhas iguais saem com dois espaços e as duas
avançam; se não, o vizinho com a LCS maior decide se a linha de `a` sai com
`-` ou a de `b` entra com `+`.

Vamos ver na prática. A lista antiga à esquerda, a nova à direita. Os
traços ligam as cinco linhas da LCS; o que sobra de cada lado vira `-` ou
`+`:

{{ideia}}

O programa: sem argumentos, ele grava as duas listas em `/tmp` e compara;
com dois nomes de arquivo (assunto 0069), compara os seus:

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
    if (argc == 3) {                                   // rodar mini-diff.c a.txt b.txt
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

Repare na linha do leite: "leite" e "leite sem lactose" são linhas
diferentes, então viram uma remoção e uma adição. O A286 usa a distância de
edição do assunto 0142 para perceber que a linha foi só **alterada**.

Repara no fluxograma: é a volta do diff, que imprime enquanto anda. O
caminho marcado é o das duas primeiras linhas, iguais nas duas versões:

{{fluxograma}}

> [!WARNING]
> `fgets` guarda o `'\n'` no fim da linha, e a última linha de um arquivo
> pode vir **sem** ele (quando ninguém deu Enter no final). Sem tirar o
> `'\n'`, "banana\n" e "banana" ficam diferentes no `strcmp`, e o diff
> acusa uma mudança invisível na última linha. O
> `buf[strcspn(buf, "\n")] = '\0'` do `linhas.c` corta o `'\n'` se ele
> existir e não faz nada se não existir.

> [!TIP]
> **Por dentro do C:** a tabela não pode ser um `int c[m + 1][n + 1]` na
> pilha: dois arquivos de 2.000 linhas pediriam 16 MB, o dobro da pilha. Ela
> é um bloco só do `malloc`, e a célula `(i, j)` mora em `c[i * w + j]`, com
> `w = n + 1`: a mesma conta que o compilador faz por baixo numa matriz de
> verdade. Para arquivos de 100 mil linhas, seriam 40 GB, e nem o heap
> aguenta. Por isso o `diff` de verdade usa o algoritmo de Myers, que gasta
> O((m + n) × D), em que D é o número de diferenças, quase sempre pequeno.

> [!NOTE]
> **Pergunta para você:** se sua mãe só tivesse trocado a ordem de "pão" e
> "banana", quantas linhas sairiam com `-` e quantas com `+`? E qual das duas
> o diff escolheria manter como "igual"? Troque a ordem em `v2` e confira.

{{pratique}}

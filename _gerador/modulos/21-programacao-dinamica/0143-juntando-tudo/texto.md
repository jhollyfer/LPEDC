## 0143 · Juntando tudo: um mini-diff

Você e a sua mãe dividem a lista de compras num arquivo de texto, uma coisa
por linha. Ela abriu, mexeu e salvou. O que mudou? O programa que responde
isso é o `diff`: ele recebe duas versões de um arquivo e mostra o que entrou
e o que saiu (LINUX MAN-PAGES, s.d.). Este projeto monta uma versão pequena
dele.

A primeira ideia, comparar a linha 1 com a linha 1, a 2 com a 2, e assim
por diante, não serve. Se ela acrescentou "açúcar" no começo, todas as
linhas descem uma posição, e todas parecem diferentes, embora quase nada
tenha mudado (LINUX MAN-PAGES, s.d.). O que você quer é achar o maior
pedaço que ficou igual, na mesma ordem, mesmo com linhas novas no meio.

Isso é a LCS do assunto 0141, com **linhas** no lugar de letras. Duas linhas
casam quando `strcmp` devolve 0. As linhas que entram na LCS ficaram iguais
nas duas versões. As que só estão na versão antiga foram **removidas** e
saem com `-`. As que só estão na nova foram **adicionadas** e saem com `+`
(CORMEN et al., 2024, cap. 14). Uma linha alterada, como "leite" que virou
"leite sem lactose", aparece como uma remoção e uma adição.

Há um ajuste na tabela. Na LCS do 0141, `c[i][j]` falava dos prefixos e a
volta andava do fim para o começo, então as letras saíam ao contrário. Para
o diff, a saída tem de vir na ordem do arquivo. A solução é trabalhar com
**sufixos**, os finais das listas: `c[i][j]` é a LCS de `a[i..m-1]` e
`b[j..n-1]`. A tabela se enche de trás para a frente, a resposta fica em
`c[0][0]` e a volta anda do **começo** para o fim, imprimindo na ordem
certa (LINTZMAYER; MOTA, 2023).

Na volta, em cada posição `(i, j)`, se as linhas são iguais, a linha sai
com dois espaços na frente e as duas listas avançam. Se não são, olhe os
vizinhos `c[i+1][j]` e `c[i][j+1]`: o maior diz qual lado avançar. Avançar
em `a` quer dizer que a linha `a[i]` não está na nova versão, e ela sai com
`-`; avançar em `b` quer dizer que `b[j]` é nova, e ela sai com `+`.

Para ler as linhas, o programa usa `fgets`, que traz a linha inteira para
um buffer, inclusive o `'\n'` do fim. Esse `'\n'` atrapalha a comparação e
precisa sair. A linha `buf[strcspn(buf, "\n")] = '\0'` resolve: `strcspn`
devolve a posição do primeiro `'\n'`, ou o tamanho da string se não houver
nenhum, e ali entra o terminador (CPPREFERENCE, s.d.).

A tabela pode ser grande. Dois arquivos de 2000 linhas pedem 4 milhões de
células, 16 MB de `int`, o dobro da pilha padrão do Linux. Por isso ela não
é uma matriz local: vem de um único `malloc` de `(m + 1) × (n + 1)` inteiros,
e a célula `(i, j)` mora na posição `i * w + j` desse bloco, com `w = n + 1`,
a largura de uma linha (KERNIGHAN; RITCHIE, 1989).

Mesmo assim, O(m × n) não escala. Com 100 mil linhas de cada lado, seriam
40 GB de tabela. O `diff` de verdade usa o algoritmo de Myers, que gasta
O((m + n) × D), com D o número de diferenças (MYERS, 1986). Como dois
arquivos parecidos têm poucas diferenças, ele roda rápido justamente no caso
mais comum.

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

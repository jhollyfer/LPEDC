## 0142 · Distância de edição

Você digita "pesoa" no celular e o corretor oferece "pessoa". Como ele sabe
que "pessoa" está mais perto do que você digitou do que "pescoço" ou
"lagoa"? Ele mede quantas **edições** de uma letra separam as duas palavras.
De "pesoa" para "pessoa" falta só inserir um `s`.

A **distância de edição** (ou **distância de Levenshtein**) entre duas
strings é o menor número de operações que transforma uma na outra. São
três operações, cada uma custando 1: **inserir** uma letra, **remover** uma
letra ou **trocar** uma letra por outra.

É a prima da LCS do assunto 0141, e a PD olha de novo para o fim das duas
palavras. Se as últimas letras são **iguais**, elas já combinam: o custo é o
das palavras sem elas. Se são **diferentes**, a última operação foi uma das
três, e você fica com a mais barata:

- **trocar** a última de `a` pela última de `b`: 1 + resolver as duas sem a
  última letra;
- **remover** a última de `a`: 1 + transformar `a` sem ela em `b` inteira;
- **inserir** no fim a última de `b`: 1 + transformar `a` inteira em `b` sem
  ela.

Na tabela, `d[i][j]` é a distância entre os prefixos `a[0..i-1]` e
`b[0..j-1]`. A diferença para a LCS está na **borda**: transformar `i` letras
em nada custa `i` remoções, então `d[i][0] = i`; e transformar nada em `j`
letras custa `j` inserções, `d[0][j] = j`.

| caso | `d[i][j]` |
| --- | --- |
| `a[i-1] == b[j-1]` | `d[i-1][j-1]` (diagonal, de graça) |
| letras diferentes | `1 +` o menor entre `d[i-1][j-1]` (troca), `d[i-1][j]` (remove) e `d[i][j-1]` (insere) |

Vamos ver na prática com CARTA e ARTES. A resposta é 3, e a volta pela
tabela mostra quais edições: remover o C, inserir um E e trocar o último A
por S (CARTA, ARTA, ARTEA, ARTES). As setas mostram de onde cada célula do
caminho veio:

{{ideia}}

O mesmo exemplo em C. A volta mostra as edições do fim da palavra para o
começo (o E852 monta o alinhamento na ordem certa):

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

O custo é o mesmo da LCS: `(m + 1) × (n + 1)` células, cada uma com três
comparações, **O(m × n)**. Um corretor ortográfico que compara a palavra
digitada com 300 mil palavras do dicionário faz 300 mil tabelas pequenas;
por isso os de verdade primeiro descartam as palavras de tamanho muito
diferente (a distância é pelo menos a diferença dos tamanhos).

Repara no fluxograma: é a decisão de uma célula do miolo, com o caminho da
célula `d[5][5]` (o último A contra o S), em que a troca ganhou:

{{fluxograma}}

### Passo a passo

A volta, partindo de `d[5][5] = 3`. Em cada célula, a pergunta é "de qual
vizinho eu vim?":

| posição | letras | candidatos: troca / remove / insere | veio de | operação |
| --- | --- | --- | --- | --- |
| (5, 5) | A, S | 2 + 1 / 3 + 1 / 2 + 1 | diagonal (troca, testada primeiro) | troca A por S |
| (4, 4) | T, E | 2 + 1 / 3 + 1 / 1 + 1 | esquerda | insere E |
| (4, 3) | T, T | iguais | diagonal | nenhuma |
| (3, 2) | R, R | iguais | diagonal | nenhuma |
| (2, 1) | A, A | iguais | diagonal | nenhuma |
| (1, 0) | C, - | borda | cima | remove C |

> [!WARNING]
> A borda **não** é zero, como era na LCS. Esquecer `d[i][0] = i` e
> `d[0][j] = j` (ou copiar a inicialização da LCS) faz a tabela achar que
> apagar ou escrever o começo da palavra é de graça: "CARTA" e "ARTES"
> dariam 2, e "SOL" contra a palavra vazia daria 0. E na volta, confira
> `i > 0` e `j > 0` antes de ler `d[i - 1][...]` ou `a[i - 1]`: na borda,
> só uma das direções existe.

> [!TIP]
> **Por dentro do C:** `menor3` é chamada `m × n` vezes. Com otimização
> (`gcc -O2`), o compilador costuma colocar o corpo dela direto no laço
> (*inline*), sem o custo de empilhar um frame por célula. Repare também que
> a tabela de `int` é um desperdício para palavras: a distância nunca passa
> do tamanho da maior palavra, então um `unsigned char` (até 255) bastaria
> para palavras de até 255 letras, e a tabela de 51 × 51 cairia de 10.404
> para 2.601 bytes.

> [!NOTE]
> **Pergunta para você:** a distância de A para B é sempre igual à de B para
> A? Troque `a` e `b` no código e compare a tabela e as operações. O que
> acontece com cada "insere" e cada "remove"?

{{pratique}}

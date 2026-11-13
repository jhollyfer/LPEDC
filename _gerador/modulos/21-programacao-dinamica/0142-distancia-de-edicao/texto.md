## 0142 · Distância de edição

Você digita "pesoa" e o corretor oferece "pessoa". Ele percebeu que falta
um `s`, e que "pesoa" está muito mais perto de "pessoa" do que de "pedra".
Para ordenar as sugestões, o corretor precisa de um número que diga o
quanto duas palavras são parecidas. A medida mais usada conta quantas
correções separam uma da outra.

A **distância de edição**, também chamada **distância de Levenshtein**, é o
menor número de operações que transforma uma string em outra. São três
operações, e cada uma custa 1: **inserir** uma letra, **remover** uma letra
e **trocar** uma letra por outra (LEVENSHTEIN, 1966). De "pesoa" para
"pessoa", basta inserir um `s`: distância 1. De CARTA para ARTES, a
distância é 3: remova o C (ARTA), insira um E (ARTEA) e troque o último A
por S (ARTES).

A PD segue o mesmo raciocínio da LCS (0141): olhe o **fim** das duas
palavras. Se as últimas letras são **iguais**, elas não pedem correção, e a
distância é a mesma das palavras sem elas. Se são **diferentes**, alguma
operação tem de resolver essa última posição, e há três candidatas
(KLEINBERG; TARDOS, 2006, cap. 6).

Cada candidata deixa um problema menor. **Trocar** a última letra de `a`
pela última de `b` custa 1, e sobra transformar as duas palavras sem a
última letra. **Remover** a última letra de `a` custa 1, e sobra transformar
`a` sem ela em `b` inteira. **Inserir** no fim de `a` a última letra de `b`
custa 1, e sobra transformar `a` inteira em `b` sem a última letra. A
distância é 1 mais a mais barata das três.

A tabela segue os prefixos, como na LCS. A célula `d[i][j]` é a distância
entre o prefixo `a[0..i-1]`, com `i` letras, e o prefixo `b[0..j-1]`, com
`j` letras. A resposta fica em `d[m][n]` (LINTZMAYER; MOTA, 2023). As três
operações viram três vizinhas: a diagonal `d[i-1][j-1]` é a troca, a de
cima `d[i-1][j]` é a remoção e a da esquerda `d[i][j-1]` é a inserção. A
tabela de consulta resume:

| caso | `d[i][j]` |
| --- | --- |
| `a[i-1] == b[j-1]` | `d[i-1][j-1]` (diagonal, de graça) |
| letras diferentes | `1 +` o menor entre `d[i-1][j-1]` (troca), `d[i-1][j]` (remove) e `d[i][j-1]` (insere) |

A diferença para a LCS está na **borda**. Na LCS, a linha e a coluna 0
valiam zero. Aqui, transformar `i` letras numa palavra vazia pede `i`
remoções, então `d[i][0] = i`. E transformar a palavra vazia em `j` letras
pede `j` inserções, então `d[0][j] = j` (LINTZMAYER; MOTA, 2023).

O custo é o da tabela: `(m + 1) × (n + 1)` células de O(1), **O(m × n)**.
Um corretor que compara a palavra digitada com 300 mil palavras do
dicionário não quer pagar isso para todas. Ele usa um limite inferior
barato: a distância é pelo menos a diferença dos tamanhos, porque cada
letra a mais pede uma remoção ou inserção. Palavras de tamanho muito
diferente saem antes de qualquer tabela (KLEINBERG; TARDOS, 2006, cap. 6).

A tabela dá o número; a volta dá as edições. Partindo de `d[m][n]`, você
pergunta em cada célula de qual vizinha o valor veio: diagonal sem custo
quer dizer letras iguais; diagonal com custo é troca; de cima é remoção; da
esquerda é inserção. As operações saem do fim para o começo. Escritas em
ordem, elas formam um **alinhamento** das duas palavras, como o que se usa
para comparar trechos de DNA (KLEINBERG; TARDOS, 2006, cap. 6).

> [!WARNING]
> A borda **não** é zero, como na LCS: sem `d[i][0] = i` e `d[0][j] = j`,
> CARTA e ARTES dariam 2. Na volta, confira `i > 0` e `j > 0` antes de ler
> `d[i - 1][...]` ou `a[i - 1]`.

{{exemplo}}

Um corretor ranqueia sugestões pelo número de edições. CARTA e ARTES distam 3:
remover o C, inserir um E e trocar o último A por S (CARTA, ARTA, ARTEA,
ARTES). As setas mostram de onde cada célula veio:

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

No fluxograma, o caminho marcado é o de `d[5][5]` (A contra S), em que a troca
ganhou:

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

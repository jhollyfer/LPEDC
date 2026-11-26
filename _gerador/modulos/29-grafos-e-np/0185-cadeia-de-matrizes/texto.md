## 0185 · Cadeia de matrizes

Uma rede de farmácias multiplica quatro tabelas de dados em sequência: uma 10
× 30, uma 30 × 5, uma 5 × 60 e uma 60 × 10. O resultado final é uma matriz 10
× 10 em qualquer ordem de cálculo, mas numa ordem o servidor faz 5 mil
multiplicações e noutra, 33 mil. O problema da **multiplicação de cadeia de
matrizes** é achar a ordem mais barata, e ele é o exemplo clássico de
programação dinâmica do Cormen (CORMEN et al., 2024, cap. 14).

Primeiro, o preço de um produto. Uma matriz `p × q` (p linhas, q colunas)
vezes uma `q × r` dá uma matriz `p × r`. Cada uma das `p · r` casas do
resultado é a soma de `q` produtos, uma linha da primeira vezes uma coluna da
segunda. O total é **p · q · r** multiplicações escalares (CORMEN et al., 2024,
cap. 14). Na rede de farmácias, a 10 × 30 vezes a 30 × 5 custa 10 · 30 · 5 =
1500.

A multiplicação de matrizes é **associativa**: `(A B) C` dá o mesmo resultado
que `A (B C)`. Os parênteses não mudam a resposta, só o trabalho. Cada jeito
de pôr os parênteses numa cadeia se chama uma **parentização**, e o número
delas cresce depressa: 4 matrizes têm 5 parentizações; 10 têm 4862; 20 têm
mais de 1,7 bilhão. Esses números são os **números de Catalan**, que crescem
exponencialmente (CORMEN et al., 2024, cap. 14). Testar todas é inviável
já para cadeias médias.

A saída é olhar para a última multiplicação feita. Em qualquer parentização,
o último passo junta duas metades: `(A1 ... Ak)` vezes `(Ak+1 ... An)`, para
algum ponto de corte `k`. Se a parentização inteira é a melhor, cada metade
também tem de estar na melhor ordem; senão, trocar a ordem dessa metade
baratearia o todo. Essa propriedade se chama **subestrutura ótima**: a
solução ótima é feita de soluções ótimas de pedaços menores. Escrevendo
`m[i][j]` para o menor custo de multiplicar `Ai` até `Aj`, e lembrando que
`Ai` tem tamanho `p[i-1] × p[i]`, sai a recorrência (FEOFILOFF, s.d.,
*Análise de algoritmos*):

```text
m[i][i] = 0
m[i][j] = min sobre k de i até j-1:  m[i][k] + m[k+1][j] + p[i-1] · p[k] · p[j]
```

Leia o termo da direita com calma. `m[i][k]` é o custo de montar a metade da
esquerda, que vira uma `p[i-1] × p[k]`. `m[k+1][j]` é o da direita, que vira
uma `p[k] × p[j]`. E `p[i-1] · p[k] · p[j]` é o preço de multiplicar as duas.
Uma matriz sozinha não custa nada, por isso `m[i][i] = 0`. A cadeia de n
matrizes precisa de n + 1 números em `p`, porque matrizes vizinhas
compartilham uma dimensão.

O valor mínimo não basta: você quer saber onde pôr os parênteses. Uma segunda
tabela, `s[i][j]`, guarda o `k` que venceu o mínimo. Para remontar a
resposta, você olha `s[1][n]`, divide a cadeia ali e repete em cada metade
(CORMEN et al., 2024, cap. 14).

A ordem de preencher a tabela importa. `m[i][j]` usa `m[i][k]` e `m[k+1][j]`,
que são cadeias **menores**. Então o laço de fora percorre o **tamanho** da
cadeia (2, 3, ..., n), e os de dentro percorrem o início `i` e o corte `k`. A
tabela enche diagonal por diagonal: primeiro os pares, depois os trios, até
a casa do canto, `m[1][n]`, que é a resposta. São O(n²) casas, cada uma com
até n cortes testados: **O(n³)** de tempo e O(n²) de espaço, contra o
exponencial de testar todas as parentizações (CORMEN et al., 2024, cap. 14).

Um detalhe de C: as dimensões cabem num `int`, mas o produto de três delas
pode não caber. Por isso o código converte para `long` antes de multiplicar,
`(long)p[i - 1] * p[k] * p[j]`; converter só o resultado chega tarde, depois
do estouro.

> [!WARNING]
> Preencher linha por linha calcula `m[1][3]` antes de `m[2][3]` existir e usa
> zero no lugar de 9000. Preencha por tamanho de cadeia. E `Ai` é
> `p[i-1] × p[i]`: `p` tem n + 1 números.

{{exemplo}}

Uma rede de farmácias multiplica quatro tabelas: 10 × 30, 30 × 5, 5 × 60 e
60 × 10. Numa ordem são 5 mil multiplicações; noutra, 33 mil. A diagonal
principal é zero, cada diagonal acima usa as de baixo, e `m[1][4]` é a
resposta:

{{ideia}}

```c
#include <limits.h>
#include <stdio.h>

#define N 4 // quantas matrizes

// A1 é 10x30, A2 é 30x5, A3 é 5x60, A4 é 60x10: Ai tem p[i-1] linhas e p[i] colunas
const int p[N + 1] = {10, 30, 5, 60, 10};
long m[N + 1][N + 1]; // m[i][j]: menor custo para multiplicar Ai..Aj
int s[N + 1][N + 1];  // s[i][j]: onde cortar Ai..Aj na melhor ordem

void parenteses(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    parenteses(i, s[i][j]);
    printf(" ");
    parenteses(s[i][j] + 1, j);
    printf(")");
}

int main(void) {
    for (int tam = 2; tam <= N; tam++) {         // cadeias de 2, depois 3, ...
        for (int i = 1; i + tam - 1 <= N; i++) {
            int j = i + tam - 1;
            m[i][j] = LONG_MAX;
            for (int k = i; k < j; k++) {        // corta entre Ak e Ak+1
                long custo = m[i][k] + m[k + 1][j] + (long)p[i - 1] * p[k] * p[j];
                if (custo < m[i][j]) {
                    m[i][j] = custo;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Tabela m (multiplicações):\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j < i) printf("%8s", "-");
            else printf("%8ld", m[i][j]);
        }
        printf("\n");
    }
    printf("Melhor ordem: ");
    parenteses(1, N);
    printf("\nCusto: %ld multiplicações\n", m[1][N]);
    return 0;
}
// Saída:
// Tabela m (multiplicações):
//        0    1500    4500    5000
//        -       0    9000    4500
//        -       -       0    3000
//        -       -       -       0
// Melhor ordem: ((A1 A2) (A3 A4))
// Custo: 5000 multiplicações
```

São três laços: tamanho da cadeia, início `i` e corte `k`, que guarda o
menor:

{{fluxograma}}

### Passo a passo

Com `p = {10, 30, 5, 60, 10}`. Cada linha é uma casa, na ordem em que o
programa preenche; o vencedor está em negrito:

| Casa | Cortes testados (k) | m | s |
| --- | --- | --- | --- |
| m[1][2] | k=1: 10·30·5 = 1500 | 1500 | 1 |
| m[2][3] | k=2: 30·5·60 = 9000 | 9000 | 2 |
| m[3][4] | k=3: 5·60·10 = 3000 | 3000 | 3 |
| m[1][3] | k=1: 0 + 9000 + 10·30·60 = 27000; **k=2: 1500 + 0 + 10·5·60 = 4500** | 4500 | 2 |
| m[2][4] | **k=2: 0 + 3000 + 30·5·10 = 4500**; k=3: 9000 + 0 + 30·60·10 = 27000 | 4500 | 2 |
| m[1][4] | k=1: 0 + 4500 + 3000 = 7500; **k=2: 1500 + 3000 + 500 = 5000**; k=3: 4500 + 0 + 6000 = 10500 | 5000 | 2 |

`s[1][4] = 2` corta em `(A1 A2)(A3 A4)`. Da esquerda para a direita, `((A1 A2)
A3) A4` custaria 10500; a pior ordem, `(A1 (A2 A3)) A4`, 33000. O A370
multiplica matrizes reais na ordem ótima.

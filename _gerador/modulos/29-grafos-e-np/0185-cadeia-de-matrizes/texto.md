## 0185 · Cadeia de matrizes

Uma rede de farmácias multiplica quatro tabelas: 10 × 30, 30 × 5, 5 × 60 e 60
× 10. O resultado é 10 × 10 em qualquer ordem, mas numa o servidor faz 5 mil
multiplicações e noutra, 33 mil.

**Custo de uma multiplicação.** Uma matriz `p × q` por uma `q × r` dá uma `p ×
r`, e cada uma das `p · r` casas soma `q` produtos: **p · q · r**
multiplicações.

**A ordem importa.** A multiplicação é **associativa**, `(A B) C = A (B C)`:
os parênteses mudam só o trabalho. Quatro matrizes têm 5 parentizações; 10,
4862; 20, mais de 1,7 bilhão (números de Catalan). Testar todas é inviável.

**Subestrutura ótima.** A última multiplicação da melhor ordem corta a cadeia
em algum `k`: `(A1..Ak)(Ak+1..An)`, e cada metade também está na melhor
ordem. Com `Ai` de tamanho `p[i-1] × p[i]`, a recorrência é:

```text
m[i][i] = 0
m[i][j] = min sobre k de i até j-1:  m[i][k] + m[k+1][j] + p[i-1] · p[k] · p[j]
```

O último termo é o custo de juntar as metades: uma `p[i-1] × p[k]` com uma
`p[k] × p[j]`. A tabela `s[i][j]` guarda o `k` vencedor, para remontar os
parênteses.

**A ordem de preencher.** `m[i][j]` depende de cadeias **menores**, então o
laço externo é o **tamanho** da cadeia (2, 3, ..., n): a tabela enche diagonal
por diagonal. São O(n²) casas com até n cortes: **O(n³)** de tempo e O(n²) de
espaço, contra o exponencial da força bruta (o A369 compara).

No desenho, a diagonal principal é zero e cada diagonal acima usa as de
baixo. A casa do canto, `m[1][4]`, é a resposta:

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

O fluxograma tem três laços: tamanho da cadeia, início `i` e corte `k`, que
guarda o menor:

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

> [!WARNING]
> Preencher linha por linha (`for i`, `for j`) calcula `m[1][3]` antes de
> `m[2][3]` existir, usa zero no lugar de 9000, e a resposta sai menor do que
> é possível. Preencha por tamanho de cadeia. E `Ai` é `p[i-1] × p[i]`: `p`
> tem n + 1 números.

> [!TIP]
> O `(long)` antes de `p[i - 1] * p[k] * p[j]` evita que o produto de três
> `int` estoure antes de ir para o `long`.

> [!NOTE]
> **Pergunta para você:** se a última tabela tivesse 60 × 100 em vez de 60 ×
> 10 (troque o último 10 de `p` por 100), a melhor ordem continua a mesma?
> Qual a casa da tabela que muda primeiro?

{{pratique}}

## 0185 · Cadeia de matrizes

O analista de dados de uma rede de farmácias precisa multiplicar quatro
tabelas em sequência: 10 regiões × 30 lojas, 30 lojas × 5 categorias,
5 categorias × 60 produtos e 60 produtos × 10 fornecedores. O resultado é um só,
uma tabela 10 × 10, qualquer que seja a ordem das contas. Mas numa ordem o
servidor faz 5 mil multiplicações; noutra, 33 mil. É a diferença entre
pagar um minuto ou sete de nuvem.

**Custo de uma multiplicação.** Multiplicar uma matriz `p × q` por uma
`q × r` dá uma `p × r`, e cada uma das `p · r` casas é uma soma de `q`
produtos: **p · q · r** multiplicações. As colunas da primeira precisam ser
iguais às linhas da segunda.

**A ordem importa.** A multiplicação de matrizes é **associativa**:
`(A B) C = A (B C)`. Os parênteses não mudam o resultado, só o trabalho. Com quatro matrizes existem 5 parentizações; com 10, 4862; com 20,
mais de 1,7 bilhão (são os números de Catalan). Testar todas está fora de
questão.

**Subestrutura ótima.** A última multiplicação da melhor ordem corta a
cadeia em algum ponto `k`: `(A1..Ak)(Ak+1..An)`. Cada metade, por sua vez,
tem que estar na melhor ordem dela, senão trocar a metade por uma melhor
baixaria o total. Isso dá a recorrência, com `Ai` de tamanho
`p[i-1] × p[i]`:

```text
m[i][i] = 0
m[i][j] = min sobre k de i até j-1:  m[i][k] + m[k+1][j] + p[i-1] · p[k] · p[j]
```

O último termo é o custo de juntar as duas metades: uma `p[i-1] × p[k]` com
uma `p[k] × p[j]`. A tabela `s[i][j]` guarda o `k` vencedor, para remontar
os parênteses no fim.

**A ordem de preencher.** `m[i][j]` depende de cadeias **menores** que ela.
Por isso o laço externo é o **tamanho** da cadeia (2, 3, ..., n), e não a
linha `i`: a tabela é preenchida diagonal por diagonal. São O(n²) casas,
cada uma com até n cortes: **O(n³)** de tempo e O(n²) de espaço, contra
o crescimento exponencial da força bruta (o A369 compara).

No desenho, a diagonal principal é zero (uma matriz sozinha não
custa nada); cada diagonal acima usa as de baixo. A casa do canto, `m[1][4]`,
é a resposta, e a seta mostra de onde ela veio:

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

O fluxograma tem três laços aninhados, e o de fora é o tamanho da cadeia. O
de dentro testa cada corte `k` e guarda o menor:

{{fluxograma}}

### Passo a passo

Com `p = {10, 30, 5, 60, 10}`. Cada linha é uma casa da tabela, na ordem em
que o programa preenche; o vencedor de cada uma está em negrito:

| Casa | Cortes testados (k) | m | s |
| --- | --- | --- | --- |
| m[1][2] | k=1: 10·30·5 = 1500 | 1500 | 1 |
| m[2][3] | k=2: 30·5·60 = 9000 | 9000 | 2 |
| m[3][4] | k=3: 5·60·10 = 3000 | 3000 | 3 |
| m[1][3] | k=1: 0 + 9000 + 10·30·60 = 27000; **k=2: 1500 + 0 + 10·5·60 = 4500** | 4500 | 2 |
| m[2][4] | **k=2: 0 + 3000 + 30·5·10 = 4500**; k=3: 9000 + 0 + 30·60·10 = 27000 | 4500 | 2 |
| m[1][4] | k=1: 0 + 4500 + 3000 = 7500; **k=2: 1500 + 3000 + 500 = 5000**; k=3: 4500 + 0 + 6000 = 10500 | 5000 | 2 |

`s[1][4] = 2` corta em `(A1 A2)(A3 A4)`. A conta da esquerda para a direita,
`((A1 A2) A3) A4`, custaria 1500 + 3000 + 6000 = 10500; a pior ordem,
`(A1 (A2 A3)) A4`, custa 9000 + 18000 + 6000 = 33000. O A370 multiplica
matrizes reais na ordem ótima, contando as multiplicações.


> [!WARNING]
> O erro clássico é preencher a tabela linha por linha (`for i`, `for j`).
> Aí `m[1][3]` é calculado antes de `m[2][3]` existir, e o programa usa um
> zero no lugar de 9000: a resposta sai menor do que é possível. Preencha por
> tamanho de cadeia (ou de baixo para cima nas linhas, com `i` decrescente).
> E cuidado com os índices: `Ai` é `p[i-1] × p[i]`, então `p` tem n + 1
> números. É o bug do E1109.

> [!TIP]
> **Por dentro do C:** `m` e `s` usam só a metade de cima da matriz; a outra
> metade são 4 × 4 casas desperdiçadas, que para n pequeno não importam. O
> `(long)` antes de `p[i - 1] * p[k] * p[j]` está ali porque o produto de
> três `int` é calculado em `int`: com dimensões de 2000 já passa de 2³¹ e
> estoura **antes** de ser guardado no `long`. Converter o primeiro fator
> faz a conta inteira em `long`. E `LONG_MAX`, de `<limits.h>`, é o
> "infinito" inicial do mínimo.

> [!NOTE]
> **Pergunta para você:** se a última tabela tivesse 60 × 100 em vez de
> 60 × 10 (troque o último 10 de `p` por 100), a melhor ordem continua a
> mesma? Qual a casa da tabela que muda primeiro?


{{pratique}}

## 0115 · Teorema mestre

Na declaração do Imposto de Renda, ninguém refaz a conta do imposto do zero.
Você acha a sua faixa na tabela progressiva e lê a alíquota. A tabela já
embute todo o cálculo: basta saber em que linha você cai.

O **teorema mestre** é a tabela pronta das recorrências de divisão e
conquista. No assunto anterior, cada recorrência pedia uma árvore de
recursão desenhada e somada nível por nível. Para a forma mais comum, essa
soma já foi feita uma vez, de modo geral, e o resultado cabe em três linhas.

A forma é esta:

```text
T(n) = a T(n/b) + n^k
```

- `a` (pelo menos 1) é **quantas chamadas** recursivas cada chamada faz;
- `b` (maior que 1) é **quanto o tamanho encolhe**: cada chamada recebe `n/b`;
- `n^k` é o **trabalho fora das chamadas**: `k = 0` é constante, `k = 1` é
  linear, `k = 2` é quadrático.

De onde vêm as três linhas? Da árvore. No nível `j` há `a^j` chamadas, cada
uma com tamanho `n/b^j`, custando `(n/b^j)^k`. O nível inteiro custa
`n^k · (a/b^k)^j`. Ou seja: de um nível para o seguinte, o custo é
multiplicado sempre pela mesma razão, `a/b^k`. Só há três possibilidades:

| caso | comparação | o custo por nível... | quem pesa | resultado |
| --- | --- | --- | --- | --- |
| 1 | `a > b^k` | **cresce** a cada nível | as folhas | Θ(n^(log_b a)) |
| 2 | `a = b^k` | fica **igual** | todos os níveis | Θ(n^k log n) |
| 3 | `a < b^k` | **cai** a cada nível | a raiz | Θ(n^k) |

Quando o custo cresce (caso 1), o último nível manda: ele tem
`a^(log_b n) = n^(log_b a)` folhas, e os níveis de cima, somados, não
passam de um múltiplo fixo dele. Quando fica igual (caso 2), são `log_b n + 1` níveis de `n^k`. Quando
cai (caso 3), a raiz sozinha já é uma fração fixa do total. Comparar `a`
com `b^k` é o mesmo que comparar o expoente `log_b a` com `k`.

Vamos ver na prática. Um escritório revisa um contrato de `n` páginas: o
revisor lê tudo (`n` páginas) e repassa **metade** do contrato para `a`
estagiários, que fazem o mesmo. Só o `a` muda: 1, 2 ou 4 estagiários. Com
`b = 2` e `k = 1`, temos `b^k = 2`, e cada valor de `a` cai numa linha
diferente da tabela. O desenho mostra a árvore de cada um para `n = 16`:

{{ideia}}

O código calcula o total de páginas lidas fazendo as `a` chamadas de
verdade. A última parte faz o teste prático do teorema: dobra o `n` e vê por
quanto o total é multiplicado:

```c
#include <stdio.h>

// o revisor lê as n páginas e repassa metade do contrato para 'a' estagiários
// T(n) = a T(n/2) + n, T(1) = 1
long paginas(int a, int n) {
    if (n == 1) {
        return 1;                        // uma página: lê e pronto
    }
    long total = n;                      // f(n) = n: lê tudo
    for (int i = 0; i < a; i++) {
        total += paginas(a, n / 2);      // a chamadas com metade
    }
    return total;
}

int main(void) {
    printf("    n      a = 1      a = 2      a = 4\n");
    for (int n = 16; n <= 1024; n *= 2) {
        printf("%5d", n);
        for (int a = 1; a <= 4; a *= 2) {
            printf(" %10ld", paginas(a, n));
        }
        printf("\n");
    }
    printf("\nquando n dobra (512 -> 1024), o total multiplica por:\n");
    for (int a = 1; a <= 4; a *= 2) {
        printf("a = %d: %.2f\n", a, (double)paginas(a, 1024) / paginas(a, 512));
    }
    return 0;
}
// Saída:
//     n      a = 1      a = 2      a = 4
//    16         31         80        496
//    32         63        192       2016
//    64        127        448       8128
//   128        255       1024      32640
//   256        511       2304     130816
//   512       1023       5120     523776
//  1024       2047      11264    2096128
//
// quando n dobra (512 -> 1024), o total multiplica por:
// a = 1: 2.00
// a = 2: 2.20
// a = 4: 4.00
```

Confira com a tabela. Com `a = 1`, `1 < 2`: caso 3, a raiz domina, Θ(n),
e o total é `2n - 1` (dobra quando `n` dobra). Com `a = 2`, `2 = 2`: caso 2,
empate, Θ(n log n), exatamente `n log₂ n + n` (dobra e mais um pouco). Com
`a = 4`, `4 > 2`: caso 1, as folhas dominam, Θ(n^(log₂ 4)) = Θ(n²), e o
total é `2n² - n` (quadruplica). Três escritórios, a mesma leitura de `n` páginas no topo, e
uma diferença de mil vezes em `n = 1024`.

Repara no fluxograma: é o teorema como receita. Primeiro a pergunta que
ninguém pode pular (a recorrência tem a forma certa?), depois a comparação
de `a` com `b^k`. O caminho marcado é o de `a = 2`:

{{fluxograma}}

A mesma receita resolve os algoritmos que você já conhece:

| algoritmo | a | b | k | b^k | resultado |
| --- | --- | --- | --- | --- | --- |
| busca binária | 1 | 2 | 0 | 1 | caso 2: Θ(log n) |
| máximo dividindo ao meio | 2 | 2 | 0 | 1 | caso 1: Θ(n) |
| merge sort | 2 | 2 | 1 | 2 | caso 2: Θ(n log n) |
| multiplicar polinômios com 3 produtos (Karatsuba) | 3 | 2 | 1 | 2 | caso 1: Θ(n^1,585) |
| algo que lê tudo e segue numa metade | 1 | 2 | 1 | 2 | caso 3: Θ(n) |

E quando o teorema **não** se aplica? Quando a recorrência não tem a forma
`a T(n/b) + n^k`: `T(n) = T(n-1) + n` (o tamanho cai **subtraindo**, não
dividindo), `T(n) = T(n/3) + T(2n/3) + n` (pedaços de tamanhos diferentes),
`T(n) = 2 T(n/2) + n log n` (o trabalho fica no meio do caminho entre `n^1`
e `n^(1+algo)`). Aí você volta para a árvore de recursão, que sempre
funciona. O exemplo A230 resolve dois desses casos.

> [!WARNING]
> `a` e `b` são coisas diferentes e não precisam ser iguais. `a` conta as
> chamadas; `b` diz quanto cada uma encolhe. Os quatro estagiários do exemplo
> recebem metade cada um, então é `4 T(n/2)`, e não `4 T(n/4)`: as metades se
> sobrepõem, e é isso que faz o custo explodir. E o erro mais comum de todos:
> aplicar o teorema em `T(n) = 2 T(n-1) + 1` (Hanói). Ali não existe `b`,
> porque `n - 1` não é `n` dividido por nada. Quem força `b = 1` chega num
> absurdo; o certo é a árvore, que dá Θ(2ⁿ).

> [!TIP]
> **Por dentro do C:** o `n / 2` do código é divisão inteira. Com `n` ímpar,
> as metades de um merge sort ficam com `⌊n/2⌋` e `⌈n/2⌉` elementos, e o
> teorema continua valendo: arredondar para cima ou para baixo não muda o
> Θ. O que muda tudo é o **caso base**. Se a função pode receber `n = 0`
> (um vetor vazio, um `n / 2` a partir de `n = 1`), um teste `if (n == 1)`
> deixa passar o zero, `0 / 2` dá 0 de novo, e a recursão nunca termina: a
> pilha estoura. Por isso o caso base mais seguro é `if (n <= 1)`.

> [!NOTE]
> **Pergunta para você:** e com `a = 3`? Antes de mudar o laço do `main`
> para `a = 1, 2, 3, 4`, diga em que linha da tabela o 3 cai e por quanto o
> total deve multiplicar quando `n` dobra. Uma pista: `log₂ 3 ≈ 1,585` e
> `2^1,585 = 3`.

{{pratique}}

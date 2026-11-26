## 0167 · Somatórios que saem de laços

Na reunião de condomínio, cada morador que chega aperta a mão de quem já
está na sala. O primeiro não cumprimenta ninguém, o segundo cumprimenta 1,
o terceiro 2, e assim por diante. Quantos apertos de mão acontecem com 8
moradores? E com 1000? Contar passos (assunto 0071) é fácil quando o laço
de dentro roda sempre o mesmo número de vezes. Aqui não: o número de
cumprimentos depende de quem está chegando.

Um laço assim, em que o de dentro roda um número de vezes que depende do
`i` do laço de fora, se chama **laço dependente**, e a conta dos passos dele
vira um **somatório** (FEOFILOFF, s.d.). O símbolo `Σ` (a letra grega
sigma) significa "some": ele soma a expressão da direita para cada valor de
`i`, do limite de baixo até o de cima.

```text
 n-1
  Σ  i  =  0 + 1 + 2 + ... + (n-1)  =  n(n-1)/2
 i=0
```

A tradução do código para a soma é direta. Cada `for` vira um `Σ`; os
limites do laço viram os limites da soma, e o corpo vira a parcela (CORMEN
et al., 2024, apêndice A). No condomínio, o laço `for (j = 0; j < i; j++)`
faz `i` passos para cada `i`, então o total é a soma de `i` com `i` indo de
0 a `n-1`.

Falta achar quanto essa soma dá. Há um truque antigo. Escreva a soma duas
vezes, uma de frente para trás e outra de trás para frente, uma embaixo da
outra: `0 + 1 + ... + (n-1)` em cima e `(n-1) + (n-2) + ... + 0` embaixo.
Cada coluna soma `n-1`, e são `n` colunas, então as duas linhas juntas
valem `n(n-1)`. Como isso é o dobro da soma, ela vale `n(n-1)/2`. Para 8
moradores, 28 apertos; para 1000, 499.500. Essa é a **soma aritmética**, e
ela é **Θ(n²)**: a divisão por 2 muda a constante, não a classe (CORMEN et
al., 2024, apêndice A).

Nem todo par de laços aninhados dá n², e a **soma geométrica** é o caso que
mais engana. Se o laço de fora dobra `t` a cada volta (`t = 1, 2, 4, 8,
...`) e o de dentro roda `t` vezes, o total é `1 + 2 + 4 + ... + 2^(k-1)`,
que vale `2^k - 1`. A última parcela sozinha supera todas as anteriores
juntas: `512 > 1 + 2 + ... + 256`. Como a última parcela é menor que `n`, o
total fica abaixo de `2n`, e dois laços aninhados resultam em Θ(n)
(LINTZMAYER; MOTA, 2023).

A **soma harmônica** é `1 + 1/2 + 1/3 + ... + 1/n`, e ela cresce devagar,
como o logaritmo natural `ln n` (CORMEN et al., 2024, apêndice A). Ela
aparece quando o laço de dentro anda de `p` em `p`: para cada `p` de 1 a
`n`, ele roda umas `n/p` vezes. O total é `n` vezes a soma harmônica, perto
de `n ln n`, que é Θ(n log n).

Na hora de calcular a fórmula em C, cuidado com o estouro. Com
`int n = 70000`, a conta `n * (n - 1)` passa do maior `int` **antes** da
divisão por 2, embora o resultado final caiba num `long`. Estouro de `int`
com sinal é comportamento indefinido; guarde `n` num `long` antes de
multiplicar.

A tabela reúne as quatro somas que mais aparecem em laços:

| laço | somatório | fórmula | classe |
| --- | --- | --- | --- |
| `for i < n`, `for j < i` | aritmética: `Σ i` | `n(n-1)/2` | Θ(n²) |
| `for i < n`, `for j < i*i` | quadrados: `Σ i²` | `(n-1)n(2n-1)/6` | Θ(n³) |
| `for (t = 1; t < n; t *= 2)`, `for j < t` | geométrica: `1 + 2 + 4 + ...` | `2^k - 1` (menos que `2n`) | Θ(n) |
| `for p = 1..n`, `for (j = 0; j < n; j += p)` | harmônica: `Σ n/p` | `≈ n ln n` | Θ(n log n) |

> [!WARNING]
> Cuidado com os limites. `for (j = 0; j < i; j++)` roda `i` vezes e soma
> `n(n-1)/2`. Com `j <= i`, cada volta ganha um a mais: `n(n+1)/2`. Na
> classe tanto faz (Θ(n²)); no **número exato**, é resposta errada. Teste
> com `n = 1` e `n = 2` à mão.

{{exemplo}}

Numa reunião de condomínio, cada morador que chega aperta a mão de quem já
está na sala. Cada quadradinho roxo é um aperto; o triângulo é metade do
quadrado de 8 por 8, sem a diagonal:

{{ideia}}

```c
#include <stdio.h>

// cada morador que chega aperta a mão de todos que já estão na sala
long apertos_de_mao(int n) {
    long apertos = 0;
    for (int i = 0; i < n; i++) {        // o morador i chega
        for (int j = 0; j < i; j++) {    // cumprimenta os i que já estão
            apertos++;
        }
    }
    return apertos;
}

int main(void) {
    printf("     n   contados   n(n-1)/2\n");
    int moradores[] = {8, 100, 1000, 20000};
    for (int k = 0; k < 4; k++) {
        long n = moradores[k];
        printf("%6ld %10ld %10ld\n", n, apertos_de_mao(moradores[k]), n * (n - 1) / 2);
    }
    return 0;
}
// Saída:
//      n   contados   n(n-1)/2
//      8         28         28
//    100       4950       4950
//   1000     499500     499500
//  20000  199990000  199990000
```

O teste `j < i?` torna o laço dependente: em `i = 0` dá "Não" de cara; em
`i = 7`, "Sim" sete vezes. A soma dos "Sim" é o somatório:

{{fluxograma}}

### Passo a passo

Com `n = 8`, cada volta de `i` soma `i` apertos ao total:

| i (quem chega) | apertos nesta volta | total |
| --- | --- | --- |
| 0 | 0 | 0 |
| 1 | 1 | 1 |
| 2 | 2 | 3 |
| 3 | 3 | 6 |
| 4 | 4 | 10 |
| 5 | 5 | 15 |
| 6 | 6 | 21 |
| 7 | 7 | **28** |

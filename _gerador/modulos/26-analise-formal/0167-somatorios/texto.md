## 0167 · Somatórios que saem de laços

Reunião de condomínio. Os moradores chegam um por vez, e cada um que entra
aperta a mão de todo mundo que já está na sala. O primeiro não cumprimenta
ninguém, o segundo cumprimenta 1, o terceiro 2... Com 8 moradores, quantos
apertos de mão acontecem? E com os 1000 moradores de um conjunto grande?

Contar passos, como no assunto 0071, é fácil quando o laço de dentro roda
sempre o mesmo número de vezes: `n` vezes `n` dá `n²`. Aqui não: o laço de
dentro depende de `i`. É um **laço dependente**, e a contagem vira uma soma
de parcelas diferentes, um **somatório**:

```text
 n-1
  Σ  i  =  0 + 1 + 2 + ... + (n-1)  =  n(n-1)/2
 i=0
```

O `Σ` (sigma) só quer dizer "some a expressão da direita para cada valor de
`i`, do de baixo até o de cima". Cada laço `for` vira um `Σ`: os limites do
laço viram os limites da soma, e o que o corpo faz vira a parcela.

A fórmula fechada da soma de `0` a `n-1` sai de um truque antigo: escreva a
soma de frente para trás e de trás para frente, uma embaixo da outra. Cada
coluna soma `n-1`, e são `n` colunas. Isso é o dobro da soma: `n(n-1)/2`.
Para 8 moradores, `8 · 7 / 2 = 28`. Para 1000, 499.500. É **Θ(n²)**: o
"só metade" do laço dependente corta a constante pela metade, mas não muda
a classe.

As quatro somas que mais aparecem quando você lê laços:

| laço | somatório | fórmula | classe |
| --- | --- | --- | --- |
| `for i < n`, `for j < i` | aritmética: `Σ i` | `n(n-1)/2` | Θ(n²) |
| `for i < n`, `for j < i*i` | quadrados: `Σ i²` | `(n-1)n(2n-1)/6` | Θ(n³) |
| `for (t = 1; t < n; t *= 2)`, `for j < t` | geométrica: `1 + 2 + 4 + ...` | `2^k - 1` (menos que `2n`) | Θ(n) |
| `for p = 1..n`, `for (j = 0; j < n; j += p)` | harmônica: `Σ n/p` | `≈ n ln n` | Θ(n log n) |

A **geométrica** engana: dois laços aninhados, e mesmo assim linear, porque
a última parcela sozinha é maior que todas as outras juntas
(`512 > 1 + 2 + ... + 256`). A **harmônica** é a soma `1 + 1/2 + 1/3 + ... +
1/n`, que cresce como `ln n`; multiplicada por `n`, dá `n ln n`.

Vamos ver na prática. Cada linha é um morador que chega, cada quadradinho
roxo é um aperto de mão com quem já estava na sala. O triângulo roxo é
metade do quadrado de 8 por 8, sem a diagonal:

{{ideia}}

O programa conta os apertos com os dois laços e compara com a fórmula:

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

Repara no fluxograma: o teste `j < i?` é o que torna o laço dependente. Na
volta de `i = 0`, ele dá "Não" de cara; na volta de `i = 7`, dá "Sim" sete
vezes. Somar os "Sim" de todas as voltas é exatamente o somatório:

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

> [!WARNING]
> A pegadinha está nos limites. `for (j = 0; j < i; j++)` roda `i` vezes, e
> a soma de `i = 0` até `n-1` dá `n(n-1)/2`. Troque para `j <= i` e cada volta
> ganha um a mais: `n(n+1)/2`. Comece `i` em 1 em vez de 0 e some de novo.
> Na classe, tanto faz (tudo é Θ(n²)); numa questão que pede o **número
> exato** de execuções, a diferença de `n` é a resposta errada. Antes de
> aplicar a fórmula, teste com `n = 1` e `n = 2` à mão.

> [!TIP]
> **Por dentro do C:** a fórmula também tem armadilha. Com `int n = 70000`,
> o produto `n * (n - 1)` passa de 4,8 bilhões e estoura o `int` (máximo de
> 2.147.483.647) **antes** da divisão por 2, mesmo que o resultado final
> (2,4 bilhões) caiba num `long`. Estouro de `int` com sinal é comportamento
> indefinido: o programa pode mostrar um número negativo ou qualquer outra
> coisa. Por isso o `main` guarda `n` num `long` antes de multiplicar. E um
> detalhe curioso: com `-O2`, o compilador pode reconhecer o laço que só
> incrementa um contador e trocar os dois `for` pela própria fórmula
> fechada. O laço de Θ(n²) vira uma conta de Θ(1) no código de máquina.

> [!NOTE]
> **Pergunta para você:** se cada morador que chega apertasse a mão de quem
> já está **e** a dele mesmo (troque `j < i` por `j <= i`), quantos apertos
> seriam com 8 moradores? E se cada um formasse trios com dois que já estão
> (três laços, `k < j < i`)? Escreva o somatório antes de mudar o programa.

{{pratique}}

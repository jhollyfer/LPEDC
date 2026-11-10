## 0167 · Somatórios que saem de laços

Na reunião de condomínio, cada morador que chega aperta a mão de quem já está
na sala: o primeiro ninguém, o segundo 1, o terceiro 2... Quantos apertos com
8 moradores? E com 1000?

Contar passos (assunto 0071) é fácil quando o laço de dentro roda sempre o
mesmo número de vezes. Aqui ele depende de `i`: é um **laço dependente**, e a
conta vira um **somatório**:

```text
 n-1
  Σ  i  =  0 + 1 + 2 + ... + (n-1)  =  n(n-1)/2
 i=0
```

O `Σ` (sigma) soma a expressão da direita para cada `i`, do limite de baixo ao
de cima. Cada `for` vira um `Σ`: os limites do laço são os da soma, e o corpo
é a parcela.

A fórmula da soma de `0` a `n-1` vem de um truque: escreva a soma de frente
para trás e de trás para frente, uma embaixo da outra. Cada coluna soma `n-1`,
são `n` colunas, e isso é o dobro: `n(n-1)/2`. Para 8 moradores, 28; para
1000, 499.500. É **Θ(n²)**: a metade corta a constante, não a classe.

As quatro somas que mais aparecem em laços:

| laço | somatório | fórmula | classe |
| --- | --- | --- | --- |
| `for i < n`, `for j < i` | aritmética: `Σ i` | `n(n-1)/2` | Θ(n²) |
| `for i < n`, `for j < i*i` | quadrados: `Σ i²` | `(n-1)n(2n-1)/6` | Θ(n³) |
| `for (t = 1; t < n; t *= 2)`, `for j < t` | geométrica: `1 + 2 + 4 + ...` | `2^k - 1` (menos que `2n`) | Θ(n) |
| `for p = 1..n`, `for (j = 0; j < n; j += p)` | harmônica: `Σ n/p` | `≈ n ln n` | Θ(n log n) |

A **geométrica** engana: dois laços aninhados e mesmo assim linear, pois a
última parcela supera todas as outras juntas (`512 > 1 + 2 + ... + 256`). A **harmônica**, `1 + 1/2 + ... + 1/n`, cresce como `ln n`;
multiplicada por `n`, dá `n ln n`.

Cada linha é um morador e cada quadradinho roxo, um aperto de mão. O
triângulo é metade do quadrado de 8 por 8, sem a diagonal:

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

> [!WARNING]
> Cuidado com os limites. `for (j = 0; j < i; j++)` roda `i` vezes e soma
> `n(n-1)/2`. Com `j <= i`, cada volta ganha um a mais: `n(n+1)/2`. Na
> classe tanto faz (Θ(n²)); no **número exato**, é resposta errada. Teste com
> `n = 1` e `n = 2` à mão.

> [!TIP]
> Com `int n = 70000`, `n * (n - 1)` estoura o `int` **antes** da divisão por
> 2, embora o resultado caiba num `long`. Estouro de `int` com sinal é
> comportamento indefinido; por isso o `main` guarda `n` num `long`.

> [!NOTE]
> **Pergunta para você:** com `j <= i`, quantos apertos seriam com 8
> moradores? E trios com dois que já estão (três laços, `k < j < i`)? Escreva
> o somatório antes de mudar o programa.

{{pratique}}

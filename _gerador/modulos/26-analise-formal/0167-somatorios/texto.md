## 0167 · Somatórios que saem de laços

- **Laço dependente**: o laço de dentro roda um número de vezes que depende
  do `i` de fora. A conta de passos vira um **somatório** (FEOFILOFF, s.d.).
- **Do `for` ao `Σ`**: cada laço vira um `Σ`; os limites do laço são os da
  soma e o corpo é a parcela (CORMEN et al., 2024, apêndice A).

```text
 n-1
  Σ  i  =  0 + 1 + 2 + ... + (n-1)  =  n(n-1)/2
 i=0
```

- **Soma aritmética**: some a sequência de frente para trás e de trás para
  frente; cada coluna dá `n-1`, são `n` colunas, e isso é o dobro. Sai
  `n(n-1)/2`, Θ(n²) (CORMEN et al., 2024, apêndice A).
- **Soma geométrica**: a última parcela supera todas as anteriores juntas
  (`512 > 1 + 2 + ... + 256`); dois laços aninhados podem dar Θ(n)
  (LINTZMAYER; MOTA, 2023).
- **Soma harmônica**: `1 + 1/2 + ... + 1/n` cresce como `ln n`; vezes `n`, dá
  `n ln n` (CORMEN et al., 2024, apêndice A).
- **Estouro na fórmula**: com `int n = 70000`, `n * (n - 1)` estoura antes da
  divisão por 2; guarde `n` num `long`.

| laço | somatório | fórmula | classe |
| --- | --- | --- | --- |
| `for i < n`, `for j < i` | aritmética: `Σ i` | `n(n-1)/2` | Θ(n²) |
| `for i < n`, `for j < i*i` | quadrados: `Σ i²` | `(n-1)n(2n-1)/6` | Θ(n³) |
| `for (t = 1; t < n; t *= 2)`, `for j < t` | geométrica: `1 + 2 + 4 + ...` | `2^k - 1` (menos que `2n`) | Θ(n) |
| `for p = 1..n`, `for (j = 0; j < n; j += p)` | harmônica: `Σ n/p` | `≈ n ln n` | Θ(n log n) |

> [!WARNING]
> `for (j = 0; j < i; j++)` roda `i` vezes e soma `n(n-1)/2`; com `j <= i`
> soma `n(n+1)/2`. A classe é a mesma, mas o número exato fica errado. Teste
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

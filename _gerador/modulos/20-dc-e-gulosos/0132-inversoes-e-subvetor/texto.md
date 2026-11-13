## 0132 · Inversões e subvetor de soma máxima

- **Inversão**: par de posições `i < j` com `v[i] > v[j]`. O vetor ordenado
  tem zero; o vetor ao contrário tem `n(n - 1)/2`
  (CORMEN et al., 2024).
- **Contar por divisão e conquista**: toda inversão está inteira na metade
  esquerda, inteira na direita ou **cruza** o meio. A recursão conta as duas
  primeiras (KLEINBERG; TARDOS, 2006, cap. 5).
- **Contar na intercalação**: com as metades ordenadas, quando um elemento da
  direita sai antes, ele forma inversão com todos os `q - i` que sobram na
  esquerda (KLEINBERG; TARDOS, 2006, cap. 5).
- **Custo**: é o merge sort com um contador, **O(n log n)**, contra O(n²) de
  testar todos os pares (KLEINBERG; TARDOS, 2006, cap. 5).
- **Subvetor de soma máxima**: a faixa de posições **seguidas** com a maior
  soma. Está na esquerda, na direita ou cruzando o meio; o caso que cruza é o
  melhor final da esquerda mais o melhor começo da direita, um laço O(n), e o
  total fica O(n log n) (CORMEN et al., 2012, seção 4.1).
- **Contador largo**: 100 000 elementos ao contrário dão 4 999 950 000
  inversões. Use `long long` (KERNIGHAN; RITCHIE, 1989).

> [!WARNING]
> A soma é `inv += q - i`, e não `inv++`: o `v[j]` que sai está fora de ordem
> com **todos** de `v[i]` a `v[q - 1]`. E o `<=` importa: valores iguais
> **não** são inversão.

{{exemplo}}

Você e o Caio montaram o top 8 de séries. Embaixo de cada série sua vai a
posição dela no ranking do Caio. São 3 inversões na esquerda, 4 na direita e 6
na intercalação:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

// junta v[p..q-1] e v[q..r-1], já ordenados, e devolve quantas inversões
// cruzam as duas metades
long long intercala(int v[], int w[], int p, int q, int r) {
    long long inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i;       // v[j] é menor que TODOS os que sobram à esquerda
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

// ordena v[p..r-1] e devolve o número de inversões que havia nele
long long conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;                       // 0 ou 1 elemento: nenhuma inversão
    }
    int q = p + (r - p) / 2;
    long long esq = conta(v, w, p, q);  // inversões dentro da esquerda
    long long dir = conta(v, w, q, r);  // inversões dentro da direita
    long long cruz = intercala(v, w, p, q, r); // um de cada lado
    printf("[%d, %d): %lld + %lld + %lld\n", p, r, esq, dir, cruz);
    return esq + dir + cruz;
}

int main(void) {
    // posição, no ranking do Caio, de cada série do seu top 8
    int caio[] = {3, 7, 1, 5, 8, 2, 6, 4};
    int n = 8;
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    long long total = conta(caio, w, 0, n);
    printf("Pares em desacordo: %lld de %d\n", total, n * (n - 1) / 2);
    free(w);
    return 0;
}
// Saída:
// [0, 2): 0 + 0 + 0
// [2, 4): 0 + 0 + 0
// [0, 4): 0 + 0 + 3
// [4, 6): 0 + 0 + 1
// [6, 8): 0 + 0 + 1
// [4, 8): 1 + 1 + 2
// [0, 8): 3 + 4 + 6
// Pares em desacordo: 13 de 28
```

Contar também **ordena**; para manter a ordem original, conte numa cópia. As
duas chamadas recursivas contam dentro de cada metade e a intercalação conta o
que cruza:

{{fluxograma}}

### Passo a passo

Última intercalação: `1 3 5 7` com `2 4 6 8`. Quando o menor vem da direita,
soma os que sobram na esquerda:

| sai | de onde | sobram na esquerda | soma |
| --- | --- | --- | --- |
| 1 | esquerda | | 0 |
| 2 | direita | 3, 5, 7 | 3 |
| 3 | esquerda | | 3 |
| 4 | direita | 5, 7 | 5 |
| 5 | esquerda | | 5 |
| 6 | direita | 7 | 6 |
| 7 | esquerda | | 6 |
| 8 | direita | (nenhum) | 6 |

No subvetor de soma máxima, com o lucro de 8 dias `4 -6 3 5 -2 6 -9 2`: a
esquerda dá `3 5` (8), a direita `6` (6) e o que cruza, `3 5 -2 6`, dá **12**,
do dia 2 ao 5. O A263 traz o algoritmo em C e o A264, um jeito em O(n).

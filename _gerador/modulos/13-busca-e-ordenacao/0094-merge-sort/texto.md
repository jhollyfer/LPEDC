## 0094 · Merge sort

- **Intercalação** (*merge*): juntar duas sequências ordenadas numa só,
  olhando o primeiro de cada e tirando o menor. Juntar `n` elementos custa no
  máximo `n - 1` comparações (FEOFILOFF, 2009).
- **Merge sort** (ordenação por intercalação): **divide** o vetor ao meio,
  **ordena** cada metade com o próprio merge sort (recursão, 0032) e
  **intercala** as duas (CORMEN et al., 2024, cap. 2).
- **Dividir e conquistar**: quebrar o problema em pedaços menores do mesmo
  tipo, resolver cada um e combinar (CORMEN et al., 2024, cap. 2).
- **Caso base e intervalo**: pedaço de 0 ou 1 elemento. O código usa o
  intervalo **semiaberto** `[p, r)`: metades `[p, q)` e `[q, r)` sem repetir
  ninguém. O Cormen usa o fechado `A[p..r]` (FEOFILOFF, 2009).
- **Custo**: `log₂ n` níveis, e em cada nível as intercalações passam pelos
  `n` elementos: **O(n log n)** em **todos** os casos. O preço é um vetor
  auxiliar (o **rascunho**), **O(n)** de memória (ZIVIANI, 2010, cap. 4).
- **Estável**: o `<=` da intercalação pega o da esquerda no empate
  (FEOFILOFF, 2009).

> [!WARNING]
> Com o intervalo semiaberto, o caso base é `r - p < 2`. Com
> `if (p >= r) return;`, um pedaço de 1 elemento passa direto e a chamada
> recebe o mesmo pedaço para sempre: **estouro de pilha**.

{{exemplo}}

Duas monitoras entregam pilhas de provas, cada uma em ordem de nota. As 8
notas descem divididas até pedaços de 1 e sobem intercaladas (verde):

{{ideia}}

O rascunho `w` é alocado **uma vez** no `main` e serve a todas as
intercalações; a recursão termina a metade esquerda antes da direita (0031):

```c
#include <stdio.h>
#include <stdlib.h>

static int comparacoes = 0;

// junta v[p..q-1] e v[q..r-1], já ordenados, usando w como rascunho
void intercala(int v[], int w[], int p, int q, int r) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {            // as duas metades ainda têm cartas
        comparacoes++;
        if (v[i] <= v[j]) {             // <= mantém a ordem dos iguais
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];      // sobrou só a esquerda
    while (j < r) w[k++] = v[j++];      // sobrou só a direita
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];                // devolve para o lugar
    }
    printf("intercala [%d, %d):", p, r);
    for (k = p; k < r; k++) printf(" %d", v[k]);
    printf("\n");
}

// ordena v[p..r-1] (intervalo semiaberto)
void merge_sort(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return;                         // 0 ou 1 elemento: já está ordenado
    }
    int q = p + (r - p) / 2;
    merge_sort(v, w, p, q);             // ordena a metade esquerda
    merge_sort(v, w, q, r);             // ordena a metade direita
    intercala(v, w, p, q, r);           // junta as duas
}

int main(void) {
    int notas[] = {52, 18, 33, 7, 41, 26, 60, 12};
    int n = 8;
    int *w = malloc(n * sizeof *w);     // um rascunho só, para todas as intercalações
    if (w == NULL) {
        return 1;
    }

    merge_sort(notas, w, 0, n);
    printf("%d comparações\n", comparacoes);
    free(w);
    return 0;
}
// Saída:
// intercala [0, 2): 18 52
// intercala [2, 4): 7 33
// intercala [0, 4): 7 18 33 52
// intercala [4, 6): 26 41
// intercala [6, 8): 12 60
// intercala [4, 8): 12 26 41 60
// intercala [0, 8): 7 12 18 26 33 41 52 60
// 17 comparações
```

### Passo a passo

A última intercalação, `7 18 33 52` com `12 26 41 60`. `i` anda na esquerda,
`j` na direita:

| comparação | v[i] | v[j] | vai para o rascunho | rascunho |
| --- | --- | --- | --- | --- |
| 1 | 7 | 12 | 7 (esquerda) | 7 |
| 2 | 18 | 12 | 12 (direita) | 7 12 |
| 3 | 18 | 26 | 18 (esquerda) | 7 12 18 |
| 4 | 33 | 26 | 26 (direita) | 7 12 18 26 |
| 5 | 33 | 41 | 33 (esquerda) | ... 26 33 |
| 6 | 52 | 41 | 41 (direita) | ... 33 41 |
| 7 | 52 | 60 | 52 (esquerda) | ... 41 52 |
| | (esquerda acabou) | 60 | 60, sem comparar | ... 52 60 |

Sete comparações para 8 elementos, o máximo. Somando os níveis:
4 + 6 + 7 = **17 comparações**.

Cada caixa `merge_sort` repete o fluxograma inteiro para uma metade:

{{fluxograma}}

## 0094 · Merge sort

Duas monitoras entregam pilhas de provas, cada uma já em ordem de nota. Para
montar uma pilha só, você olha o topo das duas, pega a menor nota e repete.
Quando uma acaba, a outra vai inteira para o fim.

Juntar duas sequências ordenadas numa só é a **intercalação** (*merge*). Cada
comparação manda **um** elemento para o resultado, então juntar `n` elementos
custa no máximo `n - 1` comparações (exemplo A188).

O **merge sort** (ordenação por intercalação) usa **dividir e conquistar**:

1. **divida** o vetor ao meio;
2. **ordene** cada metade, com o próprio merge sort (recursão, assunto 0032);
3. **intercale** as duas metades ordenadas.

O caso base é o pedaço com 0 ou 1 elemento. O código usa o intervalo
**semiaberto** `[p, r)`: o pedaço tem `r - p` elementos e as metades `[p, q)`
e `[q, r)` se encaixam sem repetir ninguém. O Cormen usa o intervalo fechado
`A[p..r]`: muda a conta dos índices, não o algoritmo.

Dividir ao meio dá `log₂ n` níveis (8 elementos: 3 níveis), e em **cada**
nível as intercalações passam pelos `n` elementos: **O(n log n)** em **todos**
os casos. O preço é um vetor auxiliar (o **rascunho**): **O(n)** de memória
extra.

As notas descem divididas até pedaços de 1 e sobem intercaladas (verde):

{{ideia}}

O rascunho `w` é alocado **uma vez** no `main` e serve a todas as
intercalações:

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

A recursão termina a metade esquerda (`[0, 4)`) antes da direita (assunto
0031).

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

Sete comparações para 8 elementos, o máximo (`n - 1`). Somando os níveis:
4 + 6 + 7 = **17 comparações**. No fluxograma, cada caixa `merge_sort` repete
o fluxograma inteiro para uma metade:

{{fluxograma}}

> [!WARNING]
> Com o intervalo semiaberto, o caso base é `r - p < 2`. Com
> `if (p >= r) return;`, um pedaço de 1 elemento passa direto e
> `merge_sort(v, w, q, r)` recebe o mesmo pedaço para sempre: **estouro de
> pilha**. Misturar intervalo fechado e semiaberto dá o mesmo erro.

> [!TIP]
> O `<=` da intercalação pega o da **esquerda** em caso de empate: o merge
> sort é **estável**. A memória que pesa é o rascunho (1 milhão de `int` são
> 4 MB).

> [!NOTE]
> **Pergunta para você:** quantas comparações o código faria com as notas já em
> ordem, `7 12 18 26 33 41 52 60`? Pense na intercalação em que a metade
> esquerda inteira é menor que a direita.

{{pratique}}

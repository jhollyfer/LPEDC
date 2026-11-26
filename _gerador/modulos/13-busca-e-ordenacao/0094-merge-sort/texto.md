## 0094 · Merge sort

Os três métodos do 0091 ao 0093 custam O(n²) no pior caso. Com mil elementos
isso dá meio milhão de comparações; com um milhão, meio trilhão. Para ordenar
volumes grandes, você precisa de uma ideia diferente, e ela começa num
problema mais fácil que ordenar.

Duas monitoras entregam pilhas de provas, cada uma já em ordem de nota. Para
montar uma pilha só, você olha a prova de cima de cada pilha, pega a de menor
nota e repete. Quando uma pilha acaba, a outra vai inteira para o fim. Juntar
duas sequências ordenadas numa só é a **intercalação** (*merge*). Cada
comparação manda **um** elemento para o resultado, e o último elemento nunca
precisa ser comparado, então intercalar `n` elementos custa no máximo `n - 1`
comparações (FEOFILOFF, 2009). A intercalação é rápida, mas exige que as duas
partes já estejam ordenadas.

O **merge sort** (ordenação por intercalação) resolve isso com recursão, a
técnica do assunto 0032. Ele **divide** o vetor ao meio, **ordena** cada
metade chamando o próprio merge sort e **intercala** as duas metades, que
agora estão ordenadas (CORMEN et al., 2024, cap. 2). A recursão para no
**caso base**: um pedaço com 0 ou 1 elemento já está ordenado e volta como
está.

Essa forma de pensar tem nome: **dividir e conquistar**. Você quebra o
problema em pedaços menores do mesmo tipo, resolve cada pedaço da mesma
maneira e combina as respostas (CORMEN et al., 2024, cap. 2). No merge sort, a
divisão é trivial (achar o meio) e todo o trabalho fica na combinação, a
intercalação.

```c
void merge_sort(int v[], int w[], int p, int r) { // ordena v[p..r-1]
    if (r - p < 2) return;       // 0 ou 1 elemento: já ordenado
    int q = p + (r - p) / 2;
    merge_sort(v, w, p, q);      // metade esquerda  [p, q)
    merge_sort(v, w, q, r);      // metade direita   [q, r)
    intercala(v, w, p, q, r);    // junta as duas usando o rascunho w
}
```

O código usa o intervalo **semiaberto** `[p, r)`: inclui `p` e exclui `r`, e
o pedaço tem `r - p` elementos. A vantagem é que as metades `[p, q)` e
`[q, r)` se encaixam sem repetir nem perder ninguém. O Cormen usa o intervalo
fechado `A[p..r]`, com os dois extremos incluídos; isso muda as contas dos
índices, não o algoritmo (FEOFILOFF, 2009).

O custo sai de uma conta de níveis. Dividir ao meio repetidas vezes até
chegar a pedaços de 1 dá `log₂ n` níveis: com 8 elementos, 3 níveis (8, 4, 2,
1). Em **cada** nível, as intercalações juntas passam por todos os `n`
elementos uma vez. São `n` de trabalho em `log₂ n` níveis: **O(n log n)**, e
em **todos** os casos, porque a divisão não depende dos valores (ZIVIANI,
2010, cap. 4). Para um milhão de elementos, isso dá cerca de 20 milhões de
operações, contra meio trilhão do insertion sort no pior caso.

O preço é memória. A intercalação não consegue juntar as metades dentro do
próprio vetor sem atropelar valores, então usa um vetor auxiliar, o
**rascunho** `w`, do mesmo tamanho: **O(n)** de memória extra (ZIVIANI, 2010,
cap. 4). Um milhão de `int` no rascunho são 4 MB. Em troca, o merge sort é
**estável** (o 0092 define o termo): no empate, a intercalação usa `<=` e
pega o elemento da metade **esquerda**, que tinha chegado antes (FEOFILOFF,
2009).

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

## 0099 · Merge sort

Fim de semestre: duas monitoras corrigiram as provas da turma, cada uma
metade, e cada uma entregou a sua pilha já em ordem de nota. Para montar uma
pilha só, ninguém reordena tudo do zero. Você olha o topo das duas pilhas,
pega a menor nota, e repete. Quando uma pilha acaba, a outra vai inteira para
o fim.

Juntar duas sequências ordenadas numa só é a **intercalação** (em inglês,
*merge*). Ela é barata: cada comparação manda **um** elemento para o
resultado, então juntar `n` elementos custa no máximo `n - 1` comparações.
O exemplo A198 mostra a intercalação sozinha.

O **merge sort** (ordenação por intercalação) usa isso com a ideia de
**dividir e conquistar**:

1. **divida** o vetor ao meio;
2. **ordene** cada metade, com o próprio merge sort (recursão, assunto 0037);
3. **intercale** as duas metades ordenadas.

O caso base é o pedaço com 0 ou 1 elemento: ele já está ordenado, não há o
que fazer. O código usa o intervalo **semiaberto** `[p, r)`: `p` é o primeiro
e `r` é uma posição depois do último. Assim, o pedaço tem `r - p` elementos e
as metades `[p, q)` e `[q, r)` se encaixam sem sobrar nem repetir ninguém.

Por que é rápido? Dividir ao meio dá `log₂ n` níveis (8 elementos: 3 níveis).
Em **cada** nível, as intercalações juntas passam por todos os `n` elementos
uma vez. Total: `n log₂ n`, ou **O(n log n)**, e isso em **todos** os casos,
inclusive o pior. Para 1 milhão de elementos, são uns 20 milhões de passos,
contra 500 bilhões de um algoritmo O(n²).

O preço é memória: a intercalação precisa de um vetor auxiliar (o
**rascunho**) do tamanho do pedaço. O merge sort usa **O(n)** de memória
extra.

Vamos ver na prática. As notas descem sendo divididas até virar pares (e,
mais embaixo, pedaços de 1). Depois sobem sendo intercaladas, em verde, até
formar o vetor inteiro:

{{ideia}}

O mesmo exemplo em C. O rascunho `w` é alocado **uma vez** no `main` e
emprestado para todas as intercalações:

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

Repara na ordem das linhas da saída: a recursão termina **toda** a metade
esquerda (`[0, 4)`) antes de começar a direita. É a pilha de chamadas do
assunto 0036 trabalhando.

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

Sete comparações para 8 elementos: o máximo, `n - 1`. Somando os níveis:
4 + 6 + 7 = **17 comparações**.

Repara no fluxograma: ele é curto porque a recursão esconde o trabalho. As
duas caixas `merge_sort` são o fluxograma inteiro de novo, para cada metade:

{{fluxograma}}

> [!WARNING]
> Com o intervalo semiaberto, o caso base é `r - p < 2`, e não `p < r` virado
> ao contrário. Se você escrever `if (p >= r) return;`, um pedaço de 1
> elemento (`r = p + 1`) passa direto, `q` vira `p`, e a chamada
> `merge_sort(v, w, q, r)` recebe **o mesmo** pedaço de novo, para sempre.
> O programa morre com **estouro de pilha** (*stack overflow*). Misturar
> intervalo fechado num lugar e semiaberto em outro dá o mesmo resultado.

> [!TIP]
> **Por dentro do C:** a profundidade da recursão é só `log₂ n` (20 frames
> para 1 milhão de elementos), então a pilha não preocupa. A memória que pesa
> é o rascunho: 1 milhão de `int` são 4 MB. Alocar com `malloc` uma vez e
> passar `w` para baixo evita um `malloc`/`free` por intercalação (seriam
> quase 1 milhão de chamadas). E o `<=` da intercalação não é detalhe: em
> caso de empate, ele pega o da **esquerda** primeiro, mantendo a ordem
> original dos iguais. Isso faz o merge sort ser **estável**.

> [!NOTE]
> **Pergunta para você:** quantas comparações o A197 faria se as notas já
> estivessem em ordem, `7 12 18 26 33 41 52 60`? Pista: na intercalação, o
> que acontece quando a metade esquerda inteira é menor que a direita?

{{pratique}}

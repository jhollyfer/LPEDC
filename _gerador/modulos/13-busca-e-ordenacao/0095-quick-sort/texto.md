## 0095 · Quick sort

Black Friday: você tem 7 fones na lista, de R$ 35, 12, 48, 7, 29, 51 e 20 (é
promoção, vai). Em vez de comparar todos com todos, você escolhe um deles, o
de R$ 20, e faz dois montes: os que custam até 20 de um lado, os mais caros do
outro. O de 20 já está no lugar certo, entre os dois montes. Agora é só fazer
o mesmo dentro de cada monte.

Esse é o **quick sort**, inventado por Tony Hoare em 1960. O elemento
escolhido é o **pivô**, e o passo de fazer os montes é a **separação** (ou
**partição**):

1. escolha o pivô (aqui, o **último** do pedaço, `v[r]`);
2. **separe**: rearranje o pedaço para ficar `menores ou iguais | pivô |
   maiores`. O pivô cai na sua posição **final**, `j`;
3. ordene, com o próprio quick sort, `v[p..j-1]` e `v[j+1..r]`.

Compare com o merge sort. Lá, dividir é trivial (corta no meio) e o trabalho
está em **juntar**. Aqui, o trabalho está em **dividir**, e juntar é de graça:
depois das chamadas recursivas, não há nada a fazer. E não precisa de
rascunho: tudo acontece com trocas no próprio vetor.

A separação usada aqui (chamada de **Lomuto**) anda com `k` pelo pedaço e
mantém `j` na fronteira: tudo em `v[p..j-1]` é `<=` pivô. Achou alguém
`<=` pivô? Troca com `v[j]` e avança `j`. No fim, troca o pivô com `v[j]`.

O custo depende do pivô. Se ele cai perto do meio, o vetor é cortado em
metades, como no merge sort: **O(n log n)**. Se ele é sempre o menor ou o
maior, um dos montes fica vazio e o outro com `n - 1`: são `n` níveis e
**O(n²)**. Com o pivô no fim, isso acontece justamente no vetor **já
ordenado** (veja o exemplo A190). Na média, com dados embaralhados, o quick
sort é O(n log n) e costuma ser o mais rápido na prática.

Vamos ver na prática. O 20 (roxo) separa o vetor: 12 e 7 à esquerda, o resto
à direita, e ele fica verde, no lugar. Depois, cada lado escolhe o próprio
pivô (o último de cada pedaço):

{{ideia}}

O mesmo exemplo em C:

```c
#include <stdio.h>

static int comparacoes = 0;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// separa v[p..r] em torno do pivô v[r]: menores ou iguais à esquerda,
// maiores à direita. Devolve a posição final do pivô.
int separa(int v[], int p, int r) {
    int pivo = v[r];
    int j = p;                          // v[p..j-1] são os <= pivô
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);                // o pivô vai para o meio deles
    return j;
}

// ordena v[p..r] (intervalo fechado)
void quick_sort(int v[], int p, int r) {
    if (p >= r) {
        return;                         // 0 ou 1 elemento
    }
    int j = separa(v, p, r);
    printf("pivô %d foi para a posição %d:", v[j], j);
    for (int i = p; i <= r; i++) printf(" %d", v[i]);
    printf("\n");
    quick_sort(v, p, j - 1);            // o pivô já está no lugar:
    quick_sort(v, j + 1, r);            // fica fora das duas chamadas
}

int main(void) {
    int precos[] = {35, 12, 48, 7, 29, 51, 20};
    int n = 7;

    quick_sort(precos, 0, n - 1);
    printf("resultado:");
    for (int i = 0; i < n; i++) printf(" %d", precos[i]);
    printf("\n%d comparações\n", comparacoes);
    return 0;
}
// Saída:
// pivô 20 foi para a posição 2: 12 7 20 35 29 51 48
// pivô 7 foi para a posição 0: 7 12
// pivô 48 foi para a posição 5: 35 29 48 51
// pivô 29 foi para a posição 3: 29 35
// resultado: 7 12 20 29 35 48 51
// 11 comparações
```

### Passo a passo

A primeira separação, com pivô 20. `k` anda; `j` marca onde entra o próximo
"pequeno":

| k | v[k] | `v[k] <= 20`? | ação | vetor | j |
| --- | --- | --- | --- | --- | --- |
| | | | | 35 12 48 7 29 51 **20** | 0 |
| 0 | 35 | não | nada | 35 12 48 7 29 51 20 | 0 |
| 1 | 12 | sim | troca v[0] e v[1] | 12 35 48 7 29 51 20 | 1 |
| 2 | 48 | não | nada | 12 35 48 7 29 51 20 | 1 |
| 3 | 7 | sim | troca v[1] e v[3] | 12 7 48 35 29 51 20 | 2 |
| 4 | 29 | não | nada | 12 7 48 35 29 51 20 | 2 |
| 5 | 51 | não | nada | 12 7 48 35 29 51 20 | 2 |
| fim | | | troca v[2] e o pivô | 12 7 **20** 35 29 51 48 | 2 |

Seis comparações, e o 20 está na posição 2 para sempre. Depois vêm `[12 7]`
(1 comparação), `[35 29 51 48]` (3) e `[35 29]` (1): **11 comparações**.

Repara no fluxograma: o pivô não entra em nenhuma das duas chamadas
recursivas. É isso que garante que o problema sempre diminui:

{{fluxograma}}

> [!WARNING]
> Se as chamadas forem `quick_sort(v, p, j)` e `quick_sort(v, j + 1, r)`, o
> pivô entra de novo no pedaço da esquerda. Quando ele é o maior do pedaço
> (`j == r`), a chamada recebe **exatamente** o mesmo pedaço e nunca para:
> estouro de pilha. Outra armadilha: copiar uma separação de outro livro
> (Hoare, com dois índices que se cruzam) e manter as chamadas desta versão.
> Cada separação promete uma coisa diferente sobre `j`, e as chamadas
> precisam bater com a promessa.

> [!TIP]
> **Por dentro do C:** no pior caso, a recursão desce `n` níveis, e cada nível
> é um frame na pilha (assunto 0031). Com um vetor ordenado de 1 milhão de
> elementos e o pivô no fim, são 1 milhão de frames: a pilha de 8 MB do Linux
> estoura e o programa morre com *segmentation fault*. Implementações sérias
> se protegem de três jeitos: escolhem o pivô melhor (o do meio, um sorteado,
> ou a **mediana de três**: primeiro, meio e último), fazem a recursão só no
> lado **menor** e um laço no maior (a pilha fica com no máximo `log₂ n`
> níveis), e trocam para o insertion sort em pedaços pequenos.

> [!NOTE]
> **Pergunta para você:** o quick sort é estável? Pense no que acontece com
> `3a 3b 1` (dois 3 iguais, `a` chegou antes de `b`) quando o pivô é o 1.
> Faça a separação à mão antes de ler o assunto 0096.

{{pratique}}

## 0095 · Quick sort

Black Friday: 7 fones de R$ 35, 12, 48, 7, 29, 51 e 20. Você escolhe o de
R$ 20 e faz dois montes: os que custam até 20 de um lado, os mais caros do
outro. O de 20 já está no lugar certo.

Esse é o **quick sort**, inventado por Tony Hoare em 1960. O elemento escolhido
é o **pivô**, e o passo de fazer os montes é a **separação** (ou
**partição**):

1. escolha o pivô (aqui, o **último** do pedaço, `v[r]`);
2. **separe**: rearranje o pedaço para ficar `menores ou iguais | pivô |
   maiores`. O pivô cai na sua posição **final**, `j`;
3. ordene, com o próprio quick sort, `v[p..j-1]` e `v[j+1..r]`.

No merge sort o trabalho está em juntar; aqui está em dividir, e juntar é
de graça. Não precisa de rascunho.

A separação de **Lomuto** (a `PARTITION` do Cormen) anda com `k` pelo pedaço e
mantém `j` na fronteira: tudo em `v[p..j-1]` é `<=` pivô. Achou um `<=` pivô?
Troca com `v[j]` e avança `j`. No fim, troca o pivô com `v[j]`. A de **Hoare**
(Ziviani, Tenenbaum) usa dois índices vindos das pontas.

O custo depende do pivô. Perto do meio, corta em metades: **O(n log n)**.
Sempre o menor ou o maior, um monte fica vazio e o outro com `n - 1`: **O(n²)**.
Com o pivô no fim, isso ocorre no vetor **já ordenado** (exemplo A190). Em
dados embaralhados, é O(n log n) na média.

O 20 (roxo) separa o vetor e fica verde, no lugar. Cada lado escolhe o seu pivô:

{{ideia}}

Em C:

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

Seis comparações. Depois vêm `[12 7]` (1), `[35 29 51 48]` (3) e `[35 29]`
(1): **11 comparações**. O pivô fica fora das duas chamadas, e por isso o
problema sempre diminui:

{{fluxograma}}

> [!WARNING]
> Com `quick_sort(v, p, j)`, o pivô entra de novo no pedaço da esquerda. Se ele
> é o maior (`j == r`), a chamada recebe o mesmo pedaço e nunca para: estouro
> de pilha. As chamadas precisam bater com o que a separação promete sobre `j`.

> [!TIP]
> No pior caso a recursão desce `n` níveis (assunto 0031): 1 milhão de frames
> estouram a pilha de 8 MB do Linux. Defesas: **mediana de três** como pivô e
> recursão só no lado **menor** (no máximo `log₂ n` níveis).

> [!NOTE]
> **Pergunta para você:** o quick sort é estável? Pense em `3a 3b 1` (dois 3
> iguais, `a` chegou antes de `b`) quando o pivô é o 1. Faça a separação à mão
> antes de ler o assunto 0096.

{{pratique}}

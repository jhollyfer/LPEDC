## 0095 · Quick sort

O merge sort do 0094 garante O(n log n), mas gasta um rascunho do tamanho do
vetor. Dá para ter a mesma rapidez, na média, ordenando dentro do próprio
vetor? Dá, invertendo onde fica o trabalho. No merge sort, dividir é trivial
e juntar dá trabalho. No quick sort, dividir dá trabalho e juntar é de graça.

Black Friday: sete fones custam R$ 35, 12, 48, 7, 29, 51 e 20. Você escolhe o
de R$ 20 e faz dois montes: os que custam até 20 de um lado, os mais caros do
outro. Sem ordenar nenhum monte, você já sabe uma coisa: o fone de 20 está no
lugar certo, porque todo mundo à esquerda dele é mais barato e todo mundo à
direita é mais caro. Agora basta ordenar cada monte da mesma forma.

Esse é o **quick sort**, criado por Tony Hoare em 1960. O elemento escolhido é
o **pivô**. O método separa o pedaço em `menores ou iguais | pivô | maiores` e
ordena cada lado com o próprio quick sort, por recursão (CORMEN et al., 2024,
cap. 7). Quando os dois lados voltam ordenados, o pedaço inteiro está
ordenado, sem nenhuma intercalação: é por isso que juntar sai de graça.

O passo de fazer os montes se chama **separação**, também chamado de
**partição**. Ele rearranja o pedaço `v[p..r]` e devolve a posição `j` em que
o pivô ficou, que é a sua posição **final** no vetor ordenado. As chamadas
seguintes trabalham em `v[p..j-1]` e `v[j+1..r]`, e o pivô fica de fora das
duas (FEOFILOFF, 2009). Como os dois montes ficam dentro do próprio vetor, o
quick sort não precisa de rascunho.

Há duas separações clássicas. A de **Lomuto**, que o Cormen chama de
`PARTITION`, escolhe o último elemento, `v[r]`, como pivô. Um índice `k` anda
pelo pedaço, e um índice `j` marca a fronteira: tudo em `v[p..j-1]` é menor ou
igual ao pivô. Quando `k` acha um elemento `<=` pivô, troca esse elemento com
`v[j]` e avança `j`. No fim, troca o pivô com `v[j]`, e ele cai entre os dois
montes (CORMEN et al., 2024, cap. 7). A separação de **Hoare** usa dois
índices que partem das pontas e andam um na direção do outro, trocando os
pares que estão do lado errado (ZIVIANI, 2010, cap. 4).

O custo depende do pivô. Se ele cai perto do meio, cada separação corta o
pedaço em duas metades, e a conta de níveis do merge sort se repete:
**O(n log n)**. Se ele é sempre o menor ou o maior do pedaço, um monte fica
vazio e o outro com `n - 1` elementos, e a soma vira `n + (n - 1) + ... + 1`:
**O(n²)**. Com o pivô no fim, esse pior caso acontece justamente no vetor
**já ordenado**, que parece o caso mais fácil. Em dados embaralhados, o custo
médio é O(n log n) (CORMEN et al., 2024, cap. 7). O quick sort não é estável:
as trocas de longa distância da separação podem inverter iguais.

O pior caso traz mais um risco, agora de memória. A recursão desce um nível
por chamada, e no pior caso desce `n` níveis; cada nível é um quadro na pilha
de chamadas do assunto 0031. Um milhão de quadros estoura a pilha de 8 MB que
o Linux dá a um programa. Há duas defesas. A **mediana de três** escolhe como
pivô o valor do meio entre o primeiro, o do meio e o último do pedaço, o que
afasta o pior caso dos vetores quase ordenados. E fazer a chamada recursiva só
no lado **menor**, tratando o maior com um laço, limita a profundidade a
`log₂ n` níveis (FEOFILOFF, 2009).

> [!WARNING]
> Com `quick_sort(v, p, j)`, o pivô entra de novo no pedaço da esquerda. Se é
> o maior (`j == r`), a chamada recebe o mesmo pedaço e nunca para: estouro de
> pilha. As chamadas precisam bater com o que a separação promete sobre `j`.

{{exemplo}}

Black Friday: 7 fones de R$ 35, 12, 48, 7, 29, 51 e 20. O 20 (roxo) é o pivô:
separa o vetor e fica verde, no lugar. Cada lado escolhe o seu pivô:

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
(1): **11 comparações**.

O pivô fica fora das duas chamadas, e por isso o problema sempre diminui:

{{fluxograma}}

## 0103 · Heapsort

Fim da corrida de rua do bairro. Os tempos dos corredores, em minutos, foram
anotados na ordem de chegada ao posto de controle: 52, 18, 73, 40, 91, 25 e 66.
Você precisa do ranking em ordem crescente, no próprio vetor, sem alocar outro.

O heap do assunto anterior já sabe tirar o maior, um de cada vez, em O(log n).
Tire os n elementos e eles saem em ordem decrescente. Esse é o **heapsort**:
ordenar usando um heap. O truque que deixa tudo **no mesmo vetor** é perceber
que, a cada máximo que sai, o heap encolhe uma casa, e essa casa livre no fim é
exatamente onde o máximo deve ficar.

O algoritmo tem duas fases:

1. **Construir o heap** dentro do próprio vetor. Dá para inserir um por um (cada
   inserção sobe), mas existe um jeito melhor: as folhas já são heaps de um
   elemento só, então basta fazer cada **pai** descer, do último pai
   (`n / 2 - 1`) até a raiz. Essa construção custa só O(n).
2. **Ordenar**: troque a raiz (o máximo) com o último elemento do heap. O máximo
   está no lugar definitivo. Diminua o heap em uma casa e faça a nova raiz
   descer. Repita até o heap ter um elemento só.

Durante a fase 2, o vetor tem duas partes: o **heap** no começo e a parte
**ordenada** no fim, com os maiores elementos já na posição final. A divisão
anda uma casa para a esquerda por volta.

O custo: a fase 1 é O(n) e a fase 2 faz n - 1 descidas de no máximo log₂ n
níveis. Total O(n log n), e isso vale **sempre**, até no pior caso. O quick sort
(assunto 0095) costuma ser mais rápido na média, mas pode cair em O(n²); o
merge sort (0094) garante n log n, mas precisa de um vetor extra. O heapsort
garante n log n sem memória extra.

Vamos ver na prática. Depois da fase 1, o vetor dos tempos é o heap
`[91 52 73 40 18 25 66]`. No primeiro passo da fase 2, o 91 troca com o 66 e
fica no fim, verde. O 66 vai para a raiz e desce pelo maior filho (73). O heap
agora tem 6 elementos:

{{ideia}}

O `desce` é o mesmo do heap, só que recebe o vetor e o tamanho atual do heap.
A função `mostra` imprime a parte do heap e a parte ordenada, separadas por `|`:

```c
#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// mostra o heap (v[0..fim-1]) e a parte já ordenada, separados por |
void mostra(const char *rotulo, const int v[], int n, int fim) {
    printf("%-12s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(i == fim ? " | %d" : " %d", v[i]);
    }
    printf("\n");
}

// desce v[i] dentro do heap v[0..n-1], trocando com o maior filho
void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(int v[], int n) {
    // fase 1: transforma o vetor em heap, do último pai até a raiz
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    mostra("heap:", v, n, n);
    // fase 2: o máximo vai para o fim; o heap encolhe uma casa
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
        mostra("", v, n, fim);
    }
}

int main(void) {
    int tempos[] = {52, 18, 73, 40, 91, 25, 66}; // minutos de cada corredor
    int n = 7;

    mostra("antes:", tempos, n, n);
    heapsort(tempos, n);
    return 0;
}
// Saída:
// antes:       52 18 73 40 91 25 66
// heap:        91 52 73 40 18 25 66
//              73 52 66 40 18 25 | 91
//              66 52 25 40 18 | 73 91
//              52 40 25 18 | 66 73 91
//              40 18 25 | 52 66 73 91
//              25 18 | 40 52 66 73 91
//              18 | 25 40 52 66 73 91
```

Repara no fluxograma: a fase 1 é uma caixa só, e o laço da fase 2 faz sempre o
mesmo par de coisas, trocar e descer, até `fim` chegar a 0:

{{fluxograma}}

### Passo a passo

A fase 1 nos tempos da corrida. Os pais são os índices 2, 1 e 0 (`n / 2 - 1 = 2`):

| Pai que desce | Filhos | O que acontece | Vetor |
| --- | --- | --- | --- |
| `v[2] = 73` | 25 e 66 | 73 já é o maior: fica | `52 18 73 40 91 25 66` |
| `v[1] = 18` | 40 e 91 | troca com o 91 | `52 91 73 40 18 25 66` |
| `v[0] = 52` | 91 e 73 | troca com o 91; depois, filhos 40 e 18: fica | `91 52 73 40 18 25 66` |

> [!WARNING]
> Na fase 2, o `desce` recebe o tamanho **do heap** (`fim`), e não o tamanho do
> vetor (`n`). Com `desce(v, n, 0)`, a raiz enxerga os elementos já ordenados no
> fim como se fossem filhos, puxa o 91 de volta para o heap e desfaz o
> trabalho. O vetor sai embaralhado, sem nenhum aviso do compilador ou do
> AddressSanitizer: os índices continuam dentro do vetor.

> [!TIP]
> **Por dentro do C:** o heapsort é **in-place**: além do vetor, usa só umas
> poucas variáveis (`i`, `f`, `fim` e a temporária da troca), O(1) de memória,
> sem recursão. O lado ruim é o acesso à memória: `desce` pula de `i` para
> `2i + 1`, cada vez mais longe, e nos vetores grandes isso sai do cache. Por
> isso, na prática, o quick sort costuma ganhar. Bibliotecas como a do C++
> usam o *introsort*: quick sort, e se a recursão ficar funda demais (sinal do
> pior caso), troca para heapsort. E o heapsort **não é estável**: dois tempos
> iguais podem trocar de ordem.

> [!NOTE]
> **Pergunta para você:** o exemplo A206 ordena mil números em ordem
> decrescente com insertion sort e com heapsort. Quantas comparações você acha
> que cada um faz? Chute antes de rodar. E se o vetor já estivesse em ordem
> crescente, qual dos dois ganharia?

{{pratique}}

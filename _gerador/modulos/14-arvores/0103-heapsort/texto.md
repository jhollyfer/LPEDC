## 0103 · Heapsort

Os tempos da corrida de rua, em minutos, chegaram nesta ordem: 52, 18, 73,
40, 91, 25 e 66. Você quer o ranking em ordem crescente, no próprio vetor,
sem alocar outro, e com O(n log n) garantido. O merge sort (0094) garante o
tempo, mas pede um rascunho; o quick sort (0095) dispensa o rascunho, mas
pode cair em O(n²). O heap do 0102 resolve as duas exigências de uma vez.

A ideia parte de uma observação. O heap entrega o maior elemento em
O(log n). Se você tirar os n elementos um a um, eles saem do maior para o
menor, já em ordem. Esse é o **heapsort**: ordenar tirando o máximo
do heap n vezes (CORMEN et al., 2024, cap. 6). O truque que dispensa o
segundo vetor é este: a cada máximo que sai, o heap encolhe uma casa, e a
casa que ficou livre no fim do vetor é exatamente a posição final daquele
máximo. O heap e a parte ordenada dividem o mesmo vetor.

O método tem duas fases. A **fase 1 constrói o heap** dentro do vetor
bagunçado. Inserir um elemento por vez funcionaria, mas há um jeito mais
barato: fazer cada **pai** descer, como na remoção do 0102, começando pelo
último pai, no índice `n / 2 - 1`, e voltando até a raiz. As folhas, que são
a metade final do vetor, já são heaps de um elemento só e não precisam de
nada. Como a maioria dos nós está nos níveis de baixo e desce pouco, a fase
inteira custa só O(n). No Cormen ela se chama `BUILD-MAX-HEAP` (CORMEN et
al., 2024, cap. 6). Nos tempos da corrida, os pais são os índices 2, 1 e 0, e
o vetor vira o heap `[91 52 73 40 18 25 66]`.

A **fase 2 ordena**. Você troca a raiz, que é o máximo, com o último elemento
do heap; o máximo cai no lugar definitivo. Depois encolhe o heap em uma casa,
para que ele deixe de enxergar esse máximo, e faz a nova raiz descer para
consertar a ordem. Repete até restar um elemento. Durante essa fase, o vetor
tem o **heap** no começo e a parte **ordenada** no fim, e a fronteira anda
uma casa para a esquerda a cada volta (FEOFILOFF, 2009). Na primeira volta,
o 91 troca com o 66 e fica no fim; o 66 desce pelo maior filho, o 73.

O custo sai das duas fases. A fase 1 é O(n). A fase 2 faz n - 1 descidas, e
cada uma desce no máximo log₂ n níveis. O total é **O(n log n)** em
**todos** os casos, porque nenhuma entrada força o heap a ficar mais alto
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6). É a garantia do merge sort
sem o rascunho do merge sort.

Duas propriedades completam o retrato. O heapsort é **in-place**: usa O(1)
de memória extra e nem precisa de recursão, porque a descida é um laço. E
não é **estável** (o termo está no 0092): as trocas entre a raiz e o fim do
vetor atravessam longas distâncias e podem inverter chaves iguais. Mesmo com
a garantia, na prática o quick sort costuma ser mais rápido, porque acessa
posições vizinhas da memória e aproveita melhor o cache do processador,
enquanto o heapsort salta de `i` para `2 * i + 1` (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 6).

> [!WARNING]
> Na fase 2, o `desce` recebe o tamanho **do heap** (`fim`), não o do vetor
> (`n`). Com `desce(v, n, 0)`, a raiz trata os já ordenados como filhos e
> desfaz o trabalho, sem aviso: os índices continuam válidos.

{{exemplo}}

Os tempos da corrida de rua chegaram como 52, 18, 73, 40, 91, 25 e 66. Depois
da fase 1, o heap é `[91 52 73 40 18 25 66]`. O 91 troca com o 66 e fica no
fim, em verde; o 66 desce pelo maior filho (73):

{{ideia}}

O `desce` é o do heap, com o tamanho atual do heap como parâmetro. A `mostra`
separa o heap da parte ordenada com `|`:

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

No fluxograma, a fase 1 é uma caixa só, e o laço da fase 2 repete trocar e
descer até `fim` chegar a 0:

{{fluxograma}}

### Passo a passo

A fase 1. Os pais são os índices 2, 1 e 0 (`n / 2 - 1 = 2`):

| Pai que desce | Filhos | O que acontece | Vetor |
| --- | --- | --- | --- |
| `v[2] = 73` | 25 e 66 | 73 já é o maior: fica | `52 18 73 40 91 25 66` |
| `v[1] = 18` | 40 e 91 | troca com o 91 | `52 91 73 40 18 25 66` |
| `v[0] = 52` | 91 e 73 | troca com o 91; depois, filhos 40 e 18: fica | `91 52 73 40 18 25 66` |

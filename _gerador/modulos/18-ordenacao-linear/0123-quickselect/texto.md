## 0123 · Quickselect

Às vezes você não quer o vetor inteiro em ordem: quer um valor só. Ao procurar
apartamento, você anota nove aluguéis e quer saber o "típico". A média engana,
porque um aluguel de luxo puxa o número para cima. O valor típico é a
**mediana**, o que fica no meio da lista quando ela está em ordem. Ordenar
tudo para achá-la funciona, mas arruma posições que ninguém pediu e custa
O(n log n).

O problema geral se chama **seleção**: dado um vetor e um número `k`, achar o
**k-ésimo menor** elemento, o que ocuparia a posição `k` se o vetor estivesse
ordenado (CORMEN et al., 2024, cap. 9). Contando as posições a partir de 0,
como em C, o mínimo é `k = 0`, o máximo é `k = n - 1` e a mediana é
`k = n / 2`. Com 9 aluguéis, a mediana é o elemento de posição 4.

O **quickselect**, proposto por Hoare em 1961, aproveita a separação do quick
sort, a função `separa` do assunto 0095 (HOARE, 1961). Depois de uma
separação, o pivô fica na sua posição **final** `j`: todos os menores estão à
esquerda dele e todos os maiores, à direita. Isso já diz muita coisa sobre o
`k` procurado.

A regra do lado sai daí. Se `j == k`, o pivô é exatamente o k-ésimo menor, e
a busca acaba. Se `k < j`, a resposta está entre os menores, à **esquerda**, e
tudo o que está à direita pode ser esquecido. Se `k > j`, a resposta está à
**direita**, e a esquerda sai da conta (FEOFILOFF, 2009). Com os aluguéis, se
o pivô cai na posição 2, a mediana (posição 4) está à direita, e os três
primeiros nunca mais são lidos.

Essa é a diferença para o quick sort, que depois de separar ordena os **dois**
lados. O quickselect segue **um lado só**. Como não há dois ramos para
acompanhar, a recursão vira um laço: um `while` que encolhe o intervalo
`[p, r]` até sobrar a resposta (FEOFILOFF, 2009). É a ideia do exercício E569,
do módulo 13.

O custo depende do pivô. Se ele cai perto do meio, cada separação descarta
metade do que sobrou, e o trabalho total é `n + n/2 + n/4 + ...`, uma soma que
fica abaixo de `2n`. Então o quickselect é **O(n) em média**, contra O(n log n)
de ordenar tudo. Se o pivô cai sempre num extremo, como acontece num vetor já
ordenado com o pivô no fim, cada separação descarta um elemento só, e o custo
sobe para **O(n²)** (CORMEN et al., 2024, cap. 9).

Para fugir do azar, sorteie o pivô. O Cormen chama essa versão de
`RANDOMIZED-SELECT`, e o tempo esperado dela é O(n) para qualquer entrada,
porque nenhuma ordem dos dados força pivôs ruins sempre (CORMEN et al., 2024,
cap. 9). Existe ainda uma garantia mais forte. O algoritmo `SELECT`, conhecido
como **mediana das medianas**, escolhe o pivô com cuidado: divide o vetor em
grupos de 5, acha a mediana de cada grupo e usa a mediana dessas medianas como
pivô. Esse pivô é bom o bastante para garantir O(n) no **pior** caso (BLUM et
al., 1973).

A memória também é pouca. A versão com `while` usa só algumas variáveis,
O(1) extra. A versão recursiva faz a chamada como último passo da função, o
que se chama **recursão de cauda**, e o gcc com `-O2` costuma transformá-la em
laço. Sem a otimização, cada chamada empilha um frame novo, e no pior caso são
`n` frames (SEDGEWICK, 1998, cap. 7).

> [!WARNING]
> As posições começam em 0: "o 3º menor" é `k = 2`, e `quickselect(v, n, 3)`
> devolve o 4º. O quickselect também **bagunça o vetor**: para manter a ordem
> original, passe uma cópia.

{{exemplo}}

Nove aluguéis anotados, de R$ 980 a R$ 3100; o típico é a mediana. O pivô
1300 cai na posição 2, e a mediana (posição 4) está à direita: os três
primeiros nunca mais são lidos.

{{ideia}}

```c
#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// separação de Lomuto (assunto 0095): pivô v[r]; devolve a posição final dele
int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// devolve o elemento que ficaria na posição k (0, 1, ...) se v fosse ordenado
int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        printf("pivô %d na posição %d:", v[j], j);
        for (int i = p; i <= r; i++) {
            printf(" %d", v[i]);
        }
        if (j == k) {
            printf("  -> achou\n");
            return v[j];
        }
        if (k < j) {
            printf("  -> segue à esquerda\n");
            r = j - 1;                  // a resposta está em v[p..j-1]
        } else {
            printf("  -> segue à direita\n");
            p = j + 1;                  // a resposta está em v[j+1..r]
        }
    }
    return v[p];                        // sobrou um só
}

int main(void) {
    int alugueis[] = {1850, 1200, 2400, 980, 1450, 2050, 3100, 1600, 1300};
    int n = 9;

    int mediana = quickselect(alugueis, n, n / 2);
    printf("aluguel mediano: R$ %d\n", mediana);
    return 0;
}
// Saída:
// pivô 1300 na posição 2: 1200 980 1300 1850 1450 2050 3100 1600 2400  -> segue à direita
// pivô 2400 na posição 7: 1850 1450 2050 1600 2400 3100  -> segue à esquerda
// pivô 1600 na posição 4: 1450 1600 2050 1850  -> achou
// aluguel mediano: R$ 1600
```

Foram 8 + 5 + 3 = 16 comparações (o quick sort completo faz 18). Cada volta do
laço escolhe um lado e descarta o outro:

{{fluxograma}}

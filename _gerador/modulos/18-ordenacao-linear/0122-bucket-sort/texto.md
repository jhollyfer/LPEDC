## 0122 · Bucket sort

O counting sort e o radix sort ordenam inteiros. Notas de prova como 6,4 e
7,85, preços em reais e medidas de sensor são números reais, e não servem de
índice de vetor. O bucket sort leva a ideia de "o valor diz onde o elemento
vai" para esses números, desde que você conheça o intervalo em que eles caem.

Pense na secretária de uma escola com uma pilha de provas corrigidas, de nota
0 a 10. Ela separa 10 envelopes, um para cada nota inteira, e joga cada prova
no envelope da parte inteira da nota: a de 6,4 vai para o envelope 6. Depois
arruma cada envelope, que tem poucas provas, e empilha os envelopes em ordem.
Esse é o **bucket sort**, ou ordenação por baldes. Ele divide o intervalo dos
valores em **faixas** de mesmo tamanho e dá a cada faixa um **balde** (CORMEN
et al., 2024, cap. 8).

O algoritmo tem três passos. Primeiro, joga cada elemento no balde da sua
faixa: para notas de 0 a 10 com 10 baldes, o balde de `x` é `(int) x`, a parte
inteira. Como o intervalo [0, 10] é fechado, a nota 10,0 pediria um décimo
primeiro balde: use 11 baldes ou trate o máximo à parte. Segundo, ordena cada
balde, que tem poucos elementos. Terceiro,
**concatena** os baldes, do primeiro ao último, e o resultado sai em ordem
(CORMEN et al., 2024, cap. 8).

O passo três só funciona porque a função que escolhe o balde **preserva a
ordem**: se `x < y`, o balde de `x` vem antes do balde de `y` ou é o mesmo.
Tudo o que está no balde 2 é menor que tudo o que está no balde 4, então
juntar os baldes em sequência não desarruma nada. A literatura chama essa
escolha de **cálculo de endereço**: o valor calcula a posição aproximada em
que o elemento vai ficar (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6). Uma função
que não preserva a ordem, como o resto da divisão das tabelas hash do módulo
15, espalharia os valores e estragaria o resultado.

Cada balde é uma **lista encadeada** (assunto 0076), porque não dá para saber
de antemão quantos elementos cada um vai receber. O segundo passo pode até
sumir: se cada elemento entra na lista do balde já na posição certa, como na
lista ordenada do assunto 0078, o balde nasce em ordem (ROVAI, 2018). Para a
ordenação ser estável, o elemento novo entra depois dos iguais que já estão
lá. Cada nó custa um `malloc`, e cada `malloc` pede o seu `free`; o código do
exemplo libera cada nó logo depois de copiar o valor para a saída. Com 1
milhão de valores, fica mais rápido contar antes quantos vão para cada balde
e usar um vetor só, como no counting sort do assunto 0120.

O custo depende de como os valores se espalham. Se eles estão bem
distribuídos pelo intervalo e há uns `n` baldes, cada balde recebe em média
um elemento, e ordenar baldes quase vazios é barato. O Cormen faz essa conta
supondo `n` valores **uniformes** em [0, 1), ou seja, qualquer trecho do
intervalo tem a mesma chance de receber um valor, e `n` baldes, com `x` indo
para o balde ⌊n · x⌋. Nessas condições, o custo esperado é Θ(n) (CORMEN et
al., 2024, cap. 8).

O pior caso aparece quando a suposição falha. Se todos os valores caem no
mesmo balde, sobra um único balde com `n` elementos, e ordenar esse balde por
inserção custa O(n²) (CORMEN et al., 2024, cap. 8). Uma turma em que todo
mundo tirou entre 5 e 6 enche o envelope 5 e deixa os outros vazios.

> [!WARNING]
> O índice do balde tem que caber no vetor: a nota 10,0 dá `baldes[10]`, que
> não existe. O bucket sort precisa **conhecer o intervalo**; valor fora da
> faixa escreve fora do vetor.

{{exemplo}}

A secretária da escola joga cada prova no envelope da sua nota inteira (a de
6,4 vai para o 6). Três notas caem no balde 2 e quatro baldes ficam vazios:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

#define NB 10 // um balde para cada nota inteira: 0, 1, ..., 9

typedef struct No {
    double valor;
    struct No *prox;
} No;

// insere x na lista sem perder a ordem: é o insertion sort, na lista
No *insere_ordenado(No *lista, double x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->valor = x;
    if (lista == NULL || x < lista->valor) {
        novo->prox = lista;               // entra na frente
        return novo;
    }
    No *p = lista;
    while (p->prox != NULL && p->prox->valor <= x) {
        p = p->prox;                      // <= : iguais ficam na ordem de chegada
    }
    novo->prox = p->prox;
    p->prox = novo;
    return lista;
}

void bucket_sort(double v[], int n) {
    No *baldes[NB] = {NULL};
    for (int i = 0; i < n; i++) {
        int b = (int) v[i];               // 6.4 vai para o balde 6
        baldes[b] = insere_ordenado(baldes[b], v[i]);
    }
    int k = 0;
    for (int b = 0; b < NB; b++) {        // junta os baldes, em ordem
        if (baldes[b] == NULL) {
            continue;                     // balde vazio
        }
        printf("balde %d:", b);
        No *p = baldes[b];
        while (p != NULL) {
            printf(" %.1f", p->valor);
            v[k++] = p->valor;
            No *prox = p->prox;
            free(p);                      // devolve o nó assim que copia
            p = prox;
        }
        printf("\n");
    }
}

int main(void) {
    double notas[] = {6.4, 2.7, 8.1, 4.5, 2.2, 9.6, 6.9, 0.8, 4.1, 2.9};
    int n = 10;

    bucket_sort(notas, n);
    printf("ordenadas:");
    for (int i = 0; i < n; i++) {
        printf(" %.1f", notas[i]);
    }
    printf("\n");
    return 0;
}
// Saída:
// balde 0: 0.8
// balde 2: 2.2 2.7 2.9
// balde 4: 4.1 4.5
// balde 6: 6.4 6.9
// balde 8: 8.1
// balde 9: 9.6
// ordenadas: 0.8 2.2 2.7 2.9 4.1 4.5 6.4 6.9 8.1 9.6
```

O custo escondido está no `insere_ordenado`, que anda pela lista do balde:

{{fluxograma}}

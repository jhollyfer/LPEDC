## 0122 · Bucket sort

A secretária da escola joga cada prova corrigida no envelope da sua nota
inteira (a de 6,4 vai para o 6), arruma cada envelope, que tem poucas provas,
e empilha os envelopes em ordem.

Esse é o **bucket sort** (ordenação por baldes). Ele divide o intervalo dos
valores em **faixas** de mesmo tamanho, uma por **balde**:

1. joga cada elemento no balde da sua faixa (para notas de 0 a 10 e 10 baldes,
   o balde de `x` é `(int) x`);
2. ordena cada balde, que é pequeno;
3. **concatena** os baldes, do primeiro ao último.

Funciona porque a escolha do balde **preserva a ordem**: tudo no balde 2 é
menor que tudo no balde 4. Cada balde é uma **lista encadeada** (assunto
0076), e o elemento já entra **no lugar certo**, como na lista ordenada do
assunto 0078.

Com `n` valores bem **espalhados** e uns `n` baldes, cada balde recebe em média
um elemento e o custo é **O(n)** em média. Se todos caem no mesmo balde, sobra
um insertion sort de `n` elementos: **O(n²)**. O Θ(n) médio do Cormen supõe
valores **uniformes** em [0, 1), com `x` indo para ⌊n · x⌋.

No exemplo, três notas caem no balde 2 e quatro baldes ficam vazios:

{{ideia}}

Em C, os baldes são um vetor de 10 ponteiros para lista, todos em `NULL`:

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

> [!WARNING]
> O índice do balde tem que caber no vetor: a nota 10,0 dá `baldes[10]`, que
> não existe. Com o intervalo fechado [0, 10], use 11 baldes ou trate o máximo
> à parte. O bucket sort precisa **conhecer o intervalo**: valor fora da
> faixa também escreve fora do vetor.

> [!TIP]
> **Por dentro do C:** cada nota custa um `malloc` de um nó de 16 bytes, e cada
> `malloc` pede o seu `free` (o código libera o nó logo depois de copiar o
> valor). Para 1 milhão de valores, fica mais rápido contar quantos vão para
> cada balde e usar um vetor só, como no counting sort do assunto 0120.

> [!NOTE]
> **Pergunta para você:** a turma de reforço tirou 5,1; 5,4; 5,0; 5,8; 5,3;
> 5,6; 5,2 e 5,9. Em quantos baldes essas notas caem? Como você mudaria a
> função do balde para espalhá-las melhor?

{{pratique}}

## 0122 · Bucket sort

- **Bucket sort** (ordenação por baldes): divide o intervalo dos valores em
  **faixas** de mesmo tamanho, uma por **balde** (CORMEN et al., 2024, cap. 8).
- **Três passos**: jogar cada elemento no balde da sua faixa, ordenar cada
  balde (que é pequeno) e **concatenar** os baldes em ordem
  (CORMEN et al., 2024, cap. 8).
- **Cálculo de endereço**: a função que escolhe o balde **preserva a ordem**.
  Tudo no balde 2 é menor que tudo no balde 4
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 6).
- **Balde como lista**: cada balde é uma lista encadeada (assunto 0076) e o
  elemento entra já no lugar certo, como na lista ordenada (assunto 0078)
  (ROVAI, 2018).
- **Custo médio**: com `n` valores **uniformes** em [0, 1) e `n` baldes, `x`
  vai para ⌊n · x⌋ e o custo esperado é Θ(n) (CORMEN et al., 2024, cap. 8).
- **Pior caso**: todos no mesmo balde. Sobra um insertion sort de `n`
  elementos, O(n²) (CORMEN et al., 2024, cap. 8).

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

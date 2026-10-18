## 0122 · Bucket sort

Na secretaria da escola, as provas corrigidas chegam numa pilha só, fora de
ordem. A secretária espalha dez envelopes na mesa, um para cada nota inteira
(0, 1, 2, ..., 9), e vai jogando cada prova no envelope certo: a de 6,4 vai
para o envelope 6, a de 2,7 para o 2. Depois arruma cada envelope, que tem
poucas provas, e empilha os envelopes em ordem.

Esse é o **bucket sort** (ordenação por baldes). Ele divide o intervalo dos
valores em **faixas** de mesmo tamanho, uma por **balde**, e:

1. joga cada elemento no balde da sua faixa: para notas de 0 a 10 e 10
   baldes, o balde de `x` é `(int) x`;
2. ordena cada balde, que é pequeno, com um método simples;
3. **concatena** os baldes, do primeiro ao último.

Funciona porque a função que escolhe o balde **preserva a ordem**: tudo que
está no balde 2 é menor que tudo que está no balde 4. É quase uma tabela hash
(assunto 0105), só que ao contrário: o hash quer espalhar sem ordem, o
bucket sort quer espalhar **em ordem**.

Cada balde é uma **lista encadeada** (assunto 0076): não dá para saber de
antemão quantos elementos caem em cada um. E em vez de ordenar a lista
depois, cada elemento já entra **no lugar certo** da lista, como na lista
ordenada do assunto 0078. Isso é o insertion sort feito na lista.

Quanto custa? Se os `n` valores estão bem **espalhados** pelo intervalo e há
uns `n` baldes, cada balde recebe em média um elemento, e o custo total é
**O(n)** em média. Se todos caem no mesmo balde, sobra um insertion sort de
`n` elementos: **O(n²)**. O bucket sort aposta na distribuição dos dados.

Vamos ver na prática. Dez notas finais, dez baldes. Três notas caem no balde
2 e entram em ordem na lista; quatro baldes ficam vazios. Ler os baldes de
cima para baixo já dá o vetor ordenado:

{{ideia}}

O mesmo exemplo em C. Os baldes são um vetor de 10 ponteiros para lista,
todos começando em `NULL`:

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

Repara no fluxograma: o laço de espalhar passa uma vez pelo vetor, e o de
juntar passa uma vez por cada balde e cada nó. O trabalho escondido está no
`insere_ordenado`, que anda pela lista do balde: com baldes curtos, é quase
nada:

{{fluxograma}}

> [!WARNING]
> O índice do balde tem que caber no vetor de baldes. Uma nota 10,0 dá
> `(int) 10.0 == 10`, e `baldes[10]` não existe: escrita fora do vetor. Com
> o intervalo fechado [0, 10], use 11 baldes ou trate o máximo à parte (`b
> = b == NB ? NB - 1 : b`). O mesmo vale para valores negativos e para
> qualquer valor fora da faixa que você imaginou: o bucket sort precisa
> **conhecer o intervalo** dos dados antes de começar.

> [!TIP]
> **Por dentro do C:** cada nota custa um `malloc` de um nó de 16 bytes (8
> do `double`, 8 do ponteiro), mais o controle que o próprio `malloc` guarda
> junto. Para 10 notas tanto faz, mas para 1 milhão são 1 milhão de chamadas
> ao alocador e nós espalhados pelo heap, o que o cache detesta. Por isso
> implementações rápidas fazem uma **contagem** antes (quantos vão para cada
> balde) e usam um vetor só, dividido em pedaços, sem lista nenhuma. É o
> counting sort do assunto 0120 com chaves que são faixas. E cada `malloc`
> pede o seu `free`: este código libera cada nó logo depois de copiar o
> valor.

> [!NOTE]
> **Pergunta para você:** a turma de reforço tirou 5,1; 5,4; 5,0; 5,8; 5,3;
> 5,6; 5,2 e 5,9. Em quantos baldes essas notas caem? Quantas comparações o
> `insere_ordenado` faz no total? Como você mudaria a função do balde para
> espalhar melhor essas notas?

{{pratique}}

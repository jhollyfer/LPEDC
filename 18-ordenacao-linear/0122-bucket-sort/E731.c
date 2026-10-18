// 0122 · Bucket sort
// Exercício E731 · ★★★
//
// Ache os bugs. A padaria ordena os pedidos do dia pelo valor com um bucket
// sort, e quer que pedidos de mesmo valor fiquem na ordem de chegada. O
// programa roda sem erro de memória, mas a saída é um desastre: tem pedido
// repetido e pedido sumido. São DOIS erros. Conserte os dois e rode.
//
//   Saída esperada:
//   I:9 B:12 E:12 A:35 C:35 H:35 G:38 F:50 D:87
//
//   Saída que aparece:
//   D:87 H:35 C:35 G:38 E:12 F:50 G:38 H:35 I:9
//
// Dicas:
// 1. Mostre o valor de k toda vez que um pedido volta para o vetor. Ele
//    devia andar de 0 a 8 sem repetir.
// 2. Com o primeiro erro consertado, a saída fica quase certa:
//    I:9 B:12 E:12 A:35 H:35 C:35 G:38 F:50 D:87. Compare A, C e H com a
//    ordem de chegada. Quem decide onde entra um valor IGUAL a outro?
// 3. Resposta esperada: o int k = 0 está dentro do for dos baldes, então
//    cada balde volta a escrever a partir de v[0]; ele tem que vir antes do
//    for. E o laço do insere_ordenado anda com < em vez de <=: um valor
//    igual para antes dos iguais que já estavam na lista, e a ordem de
//    chegada se perde. Com <=, ele entra depois deles.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

#define NB 10 // valores de R$ 0 a R$ 99: um balde para cada R$ 10

typedef struct {
    char cliente;
    int valor; // em reais
} Pedido;

typedef struct No {
    Pedido p;
    struct No *prox;
} No;

No *insere_ordenado(No *lista, Pedido x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->p = x;
    if (lista == NULL || x.valor < lista->p.valor) {
        novo->prox = lista;
        return novo;
    }
    No *q = lista;
    while (q->prox != NULL && q->prox->p.valor < x.valor) {
        q = q->prox;
    }
    novo->prox = q->prox;
    q->prox = novo;
    return lista;
}

void bucket_sort(Pedido v[], int n) {
    No *baldes[NB] = {NULL};
    for (int i = 0; i < n; i++) {
        int b = v[i].valor / 10;
        baldes[b] = insere_ordenado(baldes[b], v[i]);
    }

    for (int b = 0; b < NB; b++) {
        int k = 0;
        while (baldes[b] != NULL) {
            No *q = baldes[b];
            v[k++] = q->p;
            baldes[b] = q->prox;
            free(q);
        }
    }
}

int main(void) {
    // pedidos da padaria, na ordem em que chegaram
    Pedido dia[] = {{'A', 35}, {'B', 12}, {'C', 35}, {'D', 87}, {'E', 12},
                    {'F', 50}, {'G', 38}, {'H', 35}, {'I', 9}};
    int n = 9;

    bucket_sort(dia, n);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%c:%d" : " %c:%d", dia[i].cliente, dia[i].valor);
    }
    printf("\n");
    return 0;
}

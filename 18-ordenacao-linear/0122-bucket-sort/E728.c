// 0122 · Bucket sort
// Exercício E728 · ★☆☆
//
// Os tempos da prova de natação vão de 0 a 599 segundos. O programa abaixo
// já espalha os tempos em 6 baldes (um para cada 100 s), junta os baldes e
// libera os nós. Falta a peça principal: complete insere_ordenado, que
// insere x na lista do balde sem perder a ordem crescente, e devolve o novo
// começo da lista.
//
//   Saída esperada:
//   balde 0:
//   balde 1:
//   balde 2: 201 255 287 295 298
//   balde 3: 318 365
//   balde 4: 409 433 470
//   balde 5: 512
//   ordenados: 201 255 287 295 298 318 365 409 433 470 512
//
// Dicas:
// 1. Crie o nó com malloc (confira NULL) e guarde x nele.
// 2. Lista vazia, ou x menor que o primeiro: o novo nó vira o começo.
// 3. Senão, ande com p enquanto p->prox existir e p->prox->valor <= x, e
//    encaixe o nó depois de p.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete insere_ordenado):

#include <stdio.h>
#include <stdlib.h>

#define NB 6 // tempos de 0 a 599 segundos: um balde para cada 100 s

typedef struct No {
    int valor;
    struct No *prox;
} No;

// insere x na lista, mantendo a ordem crescente
No *insere_ordenado(No *lista, int x) {
    (void) x; // apague esta linha
    return lista;
}

int main(void) {
    // tempos da prova de 1 km da natação, em segundos
    int tempos[] = {512, 287, 433, 298, 365, 201, 470, 255, 318, 409, 295};
    int n = 11;
    No *baldes[NB] = {NULL};

    for (int i = 0; i < n; i++) {
        int b = tempos[i] / 100;
        baldes[b] = insere_ordenado(baldes[b], tempos[i]);
    }
    int k = 0;
    for (int b = 0; b < NB; b++) {
        printf("balde %d:", b);
        while (baldes[b] != NULL) {
            No *p = baldes[b];
            printf(" %d", p->valor);
            tempos[k++] = p->valor;
            baldes[b] = p->prox;
            free(p);
        }
        printf("\n");
    }
    printf("ordenados:");
    for (int i = 0; i < n; i++) {
        printf(" %d", tempos[i]);
    }
    printf("\n");
    return 0;
}

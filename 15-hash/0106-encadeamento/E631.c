// 0106 · Encadeamento
// Exercício E631 · ★☆☆
//
// Uma tabela com encadeamento tem 5 baldes e usa h(k) = k % 5. Cada número
// novo entra no INÍCIO da corrente do seu balde. O programa abaixo já insere
// 12, 7, 20, 17, 3 e 25, nessa ordem, e já libera a memória. Escreva a
// função mostra: ela imprime um balde por linha, com os números na ordem em
// que aparecem na corrente, e no fim mostra quantos baldes ficaram vazios e
// o tamanho da corrente mais comprida.
//
//   Saída esperada:
//   [0] 25 20
//   [1]
//   [2] 17 7 12
//   [3] 3
//   [4]
//   vazios: 2, maior corrente: 3
//
// Dicas:
// 1. Para cada balde, ande com "for (No *p = baldes[b]; p != NULL;
//    p = p->prox)" contando os nós.
// 2. Corrente com 0 nós soma um vazio; guarde a maior contagem vista.
// 3. Resposta esperada: a saída acima. Inserir no início inverte a ordem:
//    o último a chegar fica na frente.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct No {
    int chave;
    struct No *prox;
} No;

void insere(No *baldes[], int chave) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return;
    }
    novo->chave = chave;
    novo->prox = baldes[chave % M]; // entra no início da corrente
    baldes[chave % M] = novo;
}

void mostra(No *baldes[]) {
    (void)baldes; // apague esta linha quando usar baldes

    // complete aqui

}

void libera(No *baldes[]) {
    for (int b = 0; b < M; b++) {
        No *p = baldes[b];
        while (p != NULL) {
            No *prox = p->prox;
            free(p);
            p = prox;
        }
        baldes[b] = NULL;
    }
}

int main(void) {
    No *baldes[M] = {NULL};
    int chaves[] = {12, 7, 20, 17, 3, 25};
    for (int i = 0; i < 6; i++) {
        insere(baldes, chaves[i]);
    }
    mostra(baldes);
    libera(baldes);
    return 0;
}

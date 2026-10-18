// 0086 · Juntando tudo
// Exercício E515 · ★★★
//
// Os três erros: (1) "Garota de Ipanema" tem 18 bytes com o '\0' e o vetor
// tinha 12: strcpy escreveu fora; agora o vetor tem 40 e a cópia é com
// snprintf. (2) chama lia p->prox depois do free e deixava o fim apontando
// para o pedido liberado quando a fila esvaziava. (3) o pedido que sobrou
// na fila nunca era liberado.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedido {
    char nome[10];
    struct pedido *prox;
    char musica[40];
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
    int tamanho;
} Karaoke;

static void pede(Karaoke *k, const char *musica, const char *nome) {
    Pedido *novo = malloc(sizeof(Pedido));
    if (novo == NULL) exit(1);
    snprintf(novo->musica, sizeof novo->musica, "%s", musica);
    snprintf(novo->nome, sizeof novo->nome, "%s", nome);
    novo->prox = NULL;
    if (k->fim != NULL) k->fim->prox = novo;
    else k->inicio = novo;
    k->fim = novo;
    k->tamanho++;
}

static void chama(Karaoke *k) {
    Pedido *p = k->inicio;
    if (p == NULL) return;
    printf("cantando: %s (%s)\n", p->musica, p->nome);
    k->inicio = p->prox;              // anda antes do free
    if (k->inicio == NULL) k->fim = NULL; // esvaziou
    free(p);
    k->tamanho--;
}

static void encerra(Karaoke *k) {
    while (k->inicio != NULL) {
        Pedido *seguinte = k->inicio->prox;
        free(k->inicio);
        k->inicio = seguinte;
    }
    k->fim = NULL;
    k->tamanho = 0;
}

int main(void) {
    Karaoke bar = {NULL, NULL, 0};
    pede(&bar, "Evidências", "Rui");
    pede(&bar, "Garota de Ipanema", "Lia");
    chama(&bar);
    chama(&bar);
    pede(&bar, "Asa Branca", "Gil");
    pede(&bar, "Aquarela", "Bia");
    chama(&bar);
    printf("ainda na fila: %d\n", bar.tamanho);
    encerra(&bar);
    return 0;
}

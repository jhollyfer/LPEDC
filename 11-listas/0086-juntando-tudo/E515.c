// 0086 · Juntando tudo
// Exercício E515 · ★★★
//
// No karaokê do bar, os pedidos entram numa fila (lista encadeada com
// ponteiro para o início e para o fim): pede põe no fim, chama tira do
// começo. O programa tem TRÊS erros de propósito. Rode, leia cada relatório
// do AddressSanitizer e conserte um de cada vez.
//
//   Saída esperada depois do conserto:
//   cantando: Evidências (Rui)
//   cantando: Garota de Ipanema (Lia)
//   cantando: Asa Branca (Gil)
//   ainda na fila: 1
//
// Dicas:
// 1. Primeiro relatório: "heap-buffer-overflow" dentro do strcpy. Quantos
//    bytes tem "Garota de Ipanema" (conte o '\0')? Aumente o vetor musica
//    para 40 e troque strcpy por snprintf, que nunca passa do tamanho.
// 2. Segundo: "heap-use-after-free" em chama (o gcc já avisava: "pointer
//    'p' used after 'free'"). Leia p->prox antes do free.
//    E quando a fila esvazia, o fim continua apontando para o pedido
//    liberado: o próximo pede escreve nele. Zere o fim nesse caso.
// 3. Terceiro: "memory leaks" no fim. O pedido que ficou na fila nunca foi
//    liberado. Escreva uma função que libera tudo e chame no fim do main.
// 4. Resposta esperada: a saída acima, sem nenhum relatório do ASan.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedido {
    char nome[10];
    struct pedido *prox;
    char musica[12];
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
    int tamanho;
} Karaoke;

static void pede(Karaoke *k, const char *musica, const char *nome) {
    Pedido *novo = malloc(sizeof(Pedido));
    if (novo == NULL) exit(1);
    strcpy(novo->musica, musica);
    strcpy(novo->nome, nome);
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
    free(p);
    k->inicio = p->prox;
    k->tamanho--;
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
    return 0;
}

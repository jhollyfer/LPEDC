// 0111 · Encadeamento
// Exercício E665 · ★★★
//
// A lista de convidados do aniversário fica numa tabela com encadeamento. O
// programa mostra a tabela certinho, mas o gcc dá um aviso e o
// AddressSanitizer acusa "heap-use-after-free" no fim. O erro está aí de
// propósito. Rode, leia o aviso e o relatório e responda:
//
// a) Em que linha está o erro e o que ela faz de errado?
// b) Por que o programa às vezes "funciona" sem o AddressSanitizer?
//
// Depois conserte a função libera.
//
// Dicas:
// 1. O relatório mostra duas pilhas: onde o nó foi liberado e onde ele foi
//    usado depois. Compare as duas linhas.
// 2. Depois do free(p), a memória de *p não é mais sua, nem para ler p->prox.
// 3. Resposta esperada: a) a linha "p = p->prox;" logo depois do free(p): lê
//    o campo prox de um nó já liberado. b) o free normalmente não apaga os
//    bytes na hora, então o prox antigo ainda está lá por sorte; um malloc no
//    meio pode reaproveitar a memória. Conserto: guardar o próximo antes:
//    "No *prox = p->prox; free(p); p = prox;".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3

typedef struct No {
    char nome[16];
    struct No *prox;
} No;

unsigned espalha(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h % M;
}

void convida(No *baldes[], const char *nome) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return;
    }
    snprintf(novo->nome, sizeof novo->nome, "%s", nome);
    unsigned b = espalha(nome);
    novo->prox = baldes[b];
    baldes[b] = novo;
}

void libera(No *baldes[]) {
    for (int b = 0; b < M; b++) {
        No *p = baldes[b];
        while (p != NULL) {
            free(p);
            p = p->prox;
        }
        baldes[b] = NULL;
    }
}

int main(void) {
    No *baldes[M] = {NULL};
    const char *nomes[] = {"rita", "joao", "lara", "tiago"};
    for (int i = 0; i < 4; i++) {
        convida(baldes, nomes[i]);
    }
    for (int b = 0; b < M; b++) {
        printf("[%d]", b);
        for (No *p = baldes[b]; p != NULL; p = p->prox) {
            printf(" %s", p->nome);
        }
        printf("\n");
    }
    libera(baldes);
    return 0;
}

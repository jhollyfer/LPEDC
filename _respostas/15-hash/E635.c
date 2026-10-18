// 0106 · Encadeamento
// Exercício E635 · ★★★
//
// Resposta: a) a linha "p = p->prox;" logo depois de "free(p);": ela lê o
// campo prox de um nó que acabou de ser liberado. b) o free normalmente não
// apaga os bytes na hora, então o prox antigo ainda está lá por sorte; um
// malloc no meio (ou outro alocador) pode reaproveitar a memória e o laço
// segue para um endereço qualquer. Conserto: guardar o próximo antes do free.

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
            No *prox = p->prox; // guarda antes de liberar
            free(p);
            p = prox;
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

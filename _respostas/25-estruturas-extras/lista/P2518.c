// Lista · Módulo 25 · Estruturas especiais
// Exercício P2518 · ★★☆ · A transposição que perde o contato

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[16];
    struct No *prox;
} No;

No *inicio = NULL;

void poe_no_fim(const char *nome) {
    No **p = &inicio;
    while (*p != NULL) p = &(*p)->prox;
    *p = malloc(sizeof(No));
    if (*p == NULL) exit(1);
    strcpy((*p)->nome, nome);
    (*p)->prox = NULL;
}

// transposição religando ponteiros: aa -> a -> x vira aa -> x -> a
void liga(const char *nome) {
    No *aa = NULL, *a = NULL, *x = inicio;
    while (x != NULL && strcmp(x->nome, nome) != 0) {
        aa = a;
        a = x;
        x = x->prox;
    }
    if (x == NULL || a == NULL) return; // não achou, ou já é o primeiro
    a->prox = x->prox;
    x->prox = a;
    if (aa != NULL) aa->prox = x;
    else inicio = x; // o conserto: a era o primeiro, agora o primeiro é x
}

void mostra(const char *rotulo) {
    printf("%s:", rotulo);
    for (No *x = inicio; x != NULL; x = x->prox) printf(" %s", x->nome);
    printf("\n");
}

int main(void) {
    const char *contatos[] = {"Avó", "Banco", "Clínica", "Dona Rosa"};
    for (int k = 0; k < 4; k++) poe_no_fim(contatos[k]);
    mostra("início");
    liga("Clínica");
    mostra("Clínica");
    liga("Clínica");
    mostra("Clínica");
    liga("Dona Rosa");
    mostra("Dona Rosa");
    while (inicio != NULL) {
        No *x = inicio;
        inicio = x->prox;
        free(x);
    }
    return 0;
}

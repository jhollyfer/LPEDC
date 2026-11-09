// Lista · Módulo 25 · Estruturas especiais
// Exercício P2509 · ★☆☆ · A agenda que sobe um degrau

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

// transposição: o achado troca de lugar com o anterior (trocando os nomes)
int liga(const char *nome) {
    No *anterior = NULL;
    int custo = 0;
    for (No *x = inicio; x != NULL; x = x->prox) {
        custo++;
        if (strcmp(x->nome, nome) == 0) {
            if (anterior != NULL) {
                char t[16];
                strcpy(t, anterior->nome);
                strcpy(anterior->nome, x->nome);
                strcpy(x->nome, t);
            }
            return custo;
        }
        anterior = x;
    }
    return custo;
}

void mostra(void) {
    for (No *x = inicio; x != NULL; x = x->prox) printf(" %s", x->nome);
    printf("\n");
}

int main(void) {
    const char *contatos[] = {"Mãe", "Chefe", "Pizzaria", "Dentista", "Vizinho"};
    for (int k = 0; k < 5; k++) poe_no_fim(contatos[k]);
    const char *ligacoes[] = {"Vizinho", "Vizinho", "Pizzaria", "Vizinho", "Vizinho"};
    int total = 0;
    for (int k = 0; k < 5; k++) {
        int c = liga(ligacoes[k]);
        total += c;
        printf("%-9s custo %d:", ligacoes[k], c);
        mostra();
    }
    printf("Custo total: %d\n", total);
    while (inicio != NULL) {
        No *x = inicio;
        inicio = x->prox;
        free(x);
    }
    return 0;
}

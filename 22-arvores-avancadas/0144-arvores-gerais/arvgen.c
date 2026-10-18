// arvgen.c · implementação do TAD árvore geral (primeiro filho / próximo irmão)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvgen.h"

NoG *ag_cria(const char *nome, int valor) {
    NoG *n = malloc(sizeof(NoG));
    if (n == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    snprintf(n->nome, sizeof n->nome, "%s", nome);
    n->valor = valor;
    n->filho = NULL;
    n->irmao = NULL;
    return n;
}

NoG *ag_adiciona(NoG *pai, const char *nome, int valor) {
    NoG *novo = ag_cria(nome, valor);
    if (pai->filho == NULL) {
        pai->filho = novo; // primeiro filho
    } else {
        NoG *p = pai->filho;
        while (p->irmao != NULL) { // anda até o último irmão
            p = p->irmao;
        }
        p->irmao = novo;
    }
    return novo;
}

NoG *ag_busca(NoG *r, const char *nome) {
    if (strcmp(r->nome, nome) == 0) {
        return r;
    }
    for (NoG *p = r->filho; p != NULL; p = p->irmao) {
        NoG *achou = ag_busca(p, nome);
        if (achou != NULL) {
            return achou;
        }
    }
    return NULL;
}

int ag_grau(const NoG *n) {
    int g = 0;
    for (const NoG *p = n->filho; p != NULL; p = p->irmao) {
        g++;
    }
    return g;
}

int ag_total(const NoG *r) {
    int soma = r->valor;
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        soma += ag_total(p); // cada filho traz o total da sua subárvore
    }
    return soma;
}

int ag_conta(const NoG *r) {
    int n = 1;
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        n += ag_conta(p);
    }
    return n;
}

int ag_altura(const NoG *r) {
    int maior = -1; // sem filhos: 1 + (-1) = 0
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        int h = ag_altura(p);
        if (h > maior) {
            maior = h;
        }
    }
    return 1 + maior;
}

static void mostra(const NoG *r, int nivel) {
    printf("%*s%s: %d\n", 2 * nivel, "", r->nome, ag_total(r));
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        mostra(p, nivel + 1);
    }
}

void ag_mostra(const NoG *r) {
    mostra(r, 0);
}

void ag_libera(NoG *r) {
    NoG *p = r->filho;
    while (p != NULL) {
        NoG *prox = p->irmao; // guarda antes de liberar
        ag_libera(p);
        p = prox;
    }
    free(r);
}

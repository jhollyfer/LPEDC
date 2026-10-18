// autolista.c · implementação do TAD lista autoajustável
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autolista.h"

AutoLista *al_cria(void) {
    AutoLista *l = malloc(sizeof(AutoLista));
    if (l == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    l->inicio = NULL;
    l->n = 0;
    return l;
}

void al_insere_fim(AutoLista *l, const char *nome) {
    NoAuto *novo = malloc(sizeof(NoAuto));
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    snprintf(novo->nome, sizeof novo->nome, "%s", nome); // corta se for longo
    novo->acessos = 0;
    novo->prox = NULL;
    NoAuto **p = &l->inicio;
    while (*p != NULL) {
        p = &(*p)->prox;
    }
    *p = novo;
    l->n++;
}

bool al_busca(const AutoLista *l, const char *nome, int *custo) {
    int c = 0;
    const NoAuto *p = l->inicio;
    while (p != NULL) {
        c++;
        if (strcmp(p->nome, nome) == 0) {
            break;
        }
        p = p->prox;
    }
    if (custo != NULL) {
        *custo = c;
    }
    return p != NULL;
}

bool al_busca_mtf(AutoLista *l, const char *nome, int *custo) {
    int c = 0;
    NoAuto *ant = NULL;
    NoAuto *p = l->inicio;
    while (p != NULL) {
        c++;
        if (strcmp(p->nome, nome) == 0) {
            break;
        }
        ant = p;
        p = p->prox;
    }
    if (custo != NULL) {
        *custo = c;
    }
    if (p == NULL) {
        return false;
    }
    if (ant != NULL) {       // se p já é o primeiro, nada a fazer
        ant->prox = p->prox; // tira p do lugar...
        p->prox = l->inicio; // ...e põe na frente
        l->inicio = p;
    }
    return true;
}

bool al_busca_transpoe(AutoLista *l, const char *nome, int *custo) {
    int c = 0;
    NoAuto *ant2 = NULL; // o anterior do anterior
    NoAuto *ant = NULL;
    NoAuto *p = l->inicio;
    while (p != NULL) {
        c++;
        if (strcmp(p->nome, nome) == 0) {
            break;
        }
        ant2 = ant;
        ant = p;
        p = p->prox;
    }
    if (custo != NULL) {
        *custo = c;
    }
    if (p == NULL) {
        return false;
    }
    if (ant != NULL) { // ant2 -> ant -> p -> x  vira  ant2 -> p -> ant -> x
        ant->prox = p->prox;
        p->prox = ant;
        if (ant2 == NULL) {
            l->inicio = p;
        } else {
            ant2->prox = p;
        }
    }
    return true;
}

bool al_busca_conta(AutoLista *l, const char *nome, int *custo) {
    int c = 0;
    NoAuto *ant = NULL;
    NoAuto *p = l->inicio;
    while (p != NULL) {
        c++;
        if (strcmp(p->nome, nome) == 0) {
            break;
        }
        ant = p;
        p = p->prox;
    }
    if (custo != NULL) {
        *custo = c;
    }
    if (p == NULL) {
        return false;
    }
    p->acessos++;
    // tira p da lista e reinsere antes do primeiro que tem MENOS acessos
    if (ant == NULL) {
        l->inicio = p->prox;
    } else {
        ant->prox = p->prox;
    }
    NoAuto **q = &l->inicio;
    while (*q != NULL && (*q)->acessos >= p->acessos) {
        q = &(*q)->prox;
    }
    p->prox = *q;
    *q = p;
    return true;
}

void al_mostra(const AutoLista *l) {
    for (const NoAuto *p = l->inicio; p != NULL; p = p->prox) {
        printf("%s%s", p == l->inicio ? "" : " ", p->nome);
    }
}

void al_libera(AutoLista *l) {
    NoAuto *p = l->inicio;
    while (p != NULL) {
        NoAuto *prox = p->prox;
        free(p);
        p = prox;
    }
    free(l);
}

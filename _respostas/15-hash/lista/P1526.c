// Lista · Módulo 15 · Tabelas hash
// Exercício P1526 · ★★★ · O cache das páginas mais recentes

#include <stdio.h>
#include <stdlib.h>

#define M 7
#define CAPACIDADE 3

typedef struct Pagina {
    int id;
    struct Pagina *ant, *prox;   // lista dupla: da mais recente à mais antiga
    struct Pagina *prox_balde;   // corrente do balde na tabela hash
} Pagina;

typedef struct {
    Pagina *baldes[M];
    Pagina *frente, *fundo;
    int n;
} Cache;

Pagina *acha(Cache *c, int id) {
    for (Pagina *p = c->baldes[id % M]; p != NULL; p = p->prox_balde) {
        if (p->id == id) {
            return p;
        }
    }
    return NULL;
}

void tira_da_lista(Cache *c, Pagina *p) {
    if (p->ant != NULL) {
        p->ant->prox = p->prox;
    } else {
        c->frente = p->prox;
    }
    if (p->prox != NULL) {
        p->prox->ant = p->ant;
    } else {
        c->fundo = p->ant;
    }
}

void poe_na_frente(Cache *c, Pagina *p) {
    p->ant = NULL;
    p->prox = c->frente;
    if (c->frente != NULL) {
        c->frente->ant = p;
    } else {
        c->fundo = p;
    }
    c->frente = p;
}

void tira_da_tabela(Cache *c, Pagina *alvo) {
    Pagina **pp = &c->baldes[alvo->id % M];
    while (*pp != alvo) {
        pp = &(*pp)->prox_balde;
    }
    *pp = alvo->prox_balde;
}

// devolve 1 se a página já estava no cache
int acessa(Cache *c, int id) {
    Pagina *p = acha(c, id);
    if (p != NULL) {
        tira_da_lista(c, p);
        poe_na_frente(c, p);
        return 1;
    }
    if (c->n == CAPACIDADE) { // cheio: sai a usada há mais tempo
        Pagina *velha = c->fundo;
        tira_da_lista(c, velha);
        tira_da_tabela(c, velha);
        printf(" (sai %d)", velha->id);
        free(velha);
        c->n--;
    }
    p = malloc(sizeof(Pagina));
    if (p == NULL) {
        exit(1);
    }
    p->id = id;
    p->prox_balde = c->baldes[id % M];
    c->baldes[id % M] = p;
    poe_na_frente(c, p);
    c->n++;
    return 0;
}

int main(void) {
    Cache c = {{NULL}, NULL, NULL, 0};
    int acessos[] = {10, 20, 10, 30, 40, 20, 10, 40, 50, 40};
    int acertos = 0;

    for (int i = 0; i < 10; i++) {
        printf("página %d:", acessos[i]);
        int achou = acessa(&c, acessos[i]);
        acertos += achou;
        printf(" %s, cache:", achou ? "acerto" : "falta");
        for (Pagina *p = c.frente; p != NULL; p = p->prox) {
            printf(" %d", p->id);
        }
        printf("\n");
    }
    printf("acertos: %d de 10\n", acertos);

    while (c.frente != NULL) {
        Pagina *prox = c.frente->prox;
        free(c.frente);
        c.frente = prox;
    }
    return 0;
}

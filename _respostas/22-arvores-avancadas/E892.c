// 0149 · Juntando tudo
// Exercício E892 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corretor.h"

typedef struct Erro {
    char palavra[COR_MAX];
    int vezes;
    struct Erro *esq, *dir;
} Erro;

Erro *anota(Erro *r, const char *p) {
    if (r == NULL) {
        Erro *n = malloc(sizeof(Erro));
        if (n == NULL) {
            exit(1);
        }
        strcpy(n->palavra, p);
        n->vezes = 1;
        n->esq = n->dir = NULL;
        return n;
    }
    int c = strcmp(p, r->palavra);
    if (c < 0) {
        r->esq = anota(r->esq, p);
    } else if (c > 0) {
        r->dir = anota(r->dir, p);
    } else {
        r->vezes++;
    }
    return r;
}

void relatorio(const Erro *r, int *diferentes, int *ocorrencias) {
    if (r != NULL) {
        relatorio(r->esq, diferentes, ocorrencias);
        printf("%s: %d\n", r->palavra, r->vezes);
        (*diferentes)++;
        *ocorrencias += r->vezes;
        relatorio(r->dir, diferentes, ocorrencias);
    }
}

void solta(Erro *r) {
    if (r != NULL) {
        solta(r->esq);
        solta(r->dir);
        free(r);
    }
}

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *texto = "hoje a fiera tem pao barato e cafe barato mas ontem a fiera "
                        "tinha pao caro e o onibus pasou cedo";
    char palavra[COR_MAX];
    Erro *erros = NULL;
    while (cor_proxima(&texto, palavra)) {
        if (!cor_contem(dic, palavra)) {
            erros = anota(erros, palavra);
        }
    }
    int diferentes = 0, ocorrencias = 0;
    relatorio(erros, &diferentes, &ocorrencias);
    printf("%d palavras diferentes, %d ocorrências\n", diferentes, ocorrencias);
    solta(erros);
    cor_libera(dic);
    return 0;
}

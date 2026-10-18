// esparsa.c · implementação do TAD matriz esparsa
#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"

static void *aloca(size_t bytes) {
    void *p = malloc(bytes);
    if (p == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    return p;
}

Esparsa *esp_cria(int linhas, int colunas) {
    Esparsa *m = aloca(sizeof(Esparsa));
    m->linhas = linhas;
    m->colunas = colunas;
    m->nao_zeros = 0;
    m->linha = aloca(linhas * sizeof(Celula *));
    for (int i = 0; i < linhas; i++) {
        m->linha[i] = NULL; // linha vazia: tudo zero
    }
    return m;
}

static int fora(const Esparsa *m, int i, int j) {
    return i < 0 || i >= m->linhas || j < 0 || j >= m->colunas;
}

void esp_define(Esparsa *m, int i, int j, int valor) {
    if (fora(m, i, j)) {
        fprintf(stderr, "esp_define: (%d, %d) fora da matriz\n", i, j);
        return;
    }
    Celula *ant = NULL;
    Celula *p = m->linha[i];
    while (p != NULL && p->col < j) { // a lista está em ordem de coluna
        ant = p;
        p = p->prox;
    }
    if (p != NULL && p->col == j) { // a célula já existe
        if (valor != 0) {
            p->valor = valor;
            return;
        }
        if (ant == NULL) { // virou zero: sai da lista
            m->linha[i] = p->prox;
        } else {
            ant->prox = p->prox;
        }
        free(p);
        m->nao_zeros--;
        return;
    }
    if (valor == 0) {
        return; // já era zero: nada a guardar
    }
    Celula *nova = aloca(sizeof(Celula)); // entra entre ant e p
    nova->col = j;
    nova->valor = valor;
    nova->prox = p;
    if (ant == NULL) {
        m->linha[i] = nova;
    } else {
        ant->prox = nova;
    }
    m->nao_zeros++;
}

int esp_valor(const Esparsa *m, int i, int j) {
    if (fora(m, i, j)) {
        return 0;
    }
    const Celula *p = m->linha[i];
    while (p != NULL && p->col < j) {
        p = p->prox;
    }
    return (p != NULL && p->col == j) ? p->valor : 0;
}

void esp_mostra(const Esparsa *m) {
    for (int i = 0; i < m->linhas; i++) {
        const Celula *p = m->linha[i];
        for (int j = 0; j < m->colunas; j++) {
            if (p != NULL && p->col == j) { // anda na lista junto com o j
                printf("%3d", p->valor);
                p = p->prox;
            } else {
                printf("%3d", 0);
            }
        }
        printf("\n");
    }
}

void esp_libera(Esparsa *m) {
    for (int i = 0; i < m->linhas; i++) {
        Celula *p = m->linha[i];
        while (p != NULL) {
            Celula *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    free(m->linha);
    free(m);
}

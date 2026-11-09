// sondagem.c · implementação do endereçamento aberto com três sondagens
#include <stdio.h>
#include <stdlib.h>
#include "sondagem.h"

typedef enum { LIVRE, OCUPADA, LAPIDE } Estado;

typedef struct {
    int chave;
    Estado estado;
} Posicao;

struct Sondagem {
    Posicao *v;
    int m;
    int n;       // chaves guardadas
    int lapides; // posições com lápide
    ModoSondagem modo;
};

Sondagem *sd_cria(int m, ModoSondagem modo) {
    Sondagem *t = malloc(sizeof(Sondagem));
    if (t == NULL) {
        return NULL;
    }
    t->v = calloc((size_t)m, sizeof(Posicao)); // calloc: tudo LIVRE (0)
    if (t->v == NULL) {
        free(t);
        return NULL;
    }
    t->m = m;
    t->n = 0;
    t->lapides = 0;
    t->modo = modo;
    return t;
}

int sd_posicao(const Sondagem *t, int chave, int i) {
    int m = t->m;
    int h1 = chave % m;
    switch (t->modo) {
    case SD_LINEAR:
        return (h1 + i) % m;
    case SD_QUADRATICA:
        return (int)((h1 + (long)i * i) % m);
    default: { // dupla: o passo h2 depende da chave e nunca é 0
        int h2 = 1 + chave % (m - 1);
        return (int)((h1 + (long)i * h2) % m);
    }
    }
}

int sd_insere(Sondagem *t, int chave, int *sondagens) {
    int lapide = -1; // a primeira lápide do caminho: lugar para reaproveitar
    int i = 0;
    for (; i < t->m; i++) {
        int j = sd_posicao(t, chave, i);
        if (t->v[j].estado == LIVRE) {
            break;
        }
        if (t->v[j].estado == OCUPADA && t->v[j].chave == chave) {
            if (sondagens != NULL) {
                *sondagens = i + 1;
            }
            return j; // já estava
        }
        if (t->v[j].estado == LAPIDE && lapide < 0) {
            lapide = j;
        }
    }
    if (sondagens != NULL) {
        *sondagens = i < t->m ? i + 1 : t->m;
    }
    int j = lapide >= 0 ? lapide : (i < t->m ? sd_posicao(t, chave, i) : -1);
    if (j < 0) {
        return -1; // a sequência não achou lugar
    }
    if (t->v[j].estado == LAPIDE) {
        t->lapides--;
    }
    t->v[j].chave = chave;
    t->v[j].estado = OCUPADA;
    t->n++;
    return j;
}

// devolve a posição da chave ou -1; passa reto pelas lápides
static int procura(const Sondagem *t, int chave, int *sondagens) {
    int i = 0;
    for (; i < t->m; i++) {
        int j = sd_posicao(t, chave, i);
        if (t->v[j].estado == LIVRE) {
            break; // a sequência acaba aqui: não está
        }
        if (t->v[j].estado == OCUPADA && t->v[j].chave == chave) {
            if (sondagens != NULL) {
                *sondagens = i + 1;
            }
            return j;
        }
    }
    if (sondagens != NULL) {
        *sondagens = i < t->m ? i + 1 : t->m;
    }
    return -1;
}

bool sd_busca(const Sondagem *t, int chave, int *sondagens) {
    return procura(t, chave, sondagens) >= 0;
}

bool sd_remove(Sondagem *t, int chave) {
    int j = procura(t, chave, NULL);
    if (j < 0) {
        return false;
    }
    t->v[j].estado = LAPIDE; // não LIVRE: quem passou por aqui ainda é achado
    t->n--;
    t->lapides++;
    return true;
}

int sd_tamanho(const Sondagem *t) {
    return t->n;
}

int sd_lapides(const Sondagem *t) {
    return t->lapides;
}

double sd_carga(const Sondagem *t) {
    return (double)t->n / t->m;
}

void sd_mostra(const Sondagem *t) {
    for (int j = 0; j < t->m; j++) {
        if (t->v[j].estado == OCUPADA) {
            printf(" %3d", t->v[j].chave);
        } else {
            printf(" %3s", t->v[j].estado == LIVRE ? "." : "x");
        }
    }
    printf("\n");
}

void sd_libera(Sondagem *t) {
    if (t != NULL) {
        free(t->v);
        free(t);
    }
}

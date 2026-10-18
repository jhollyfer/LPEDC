// aberta.c · implementação do TAD com sondagem linear e marca de removida
#include "aberta.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum { LIVRE, OCUPADA, REMOVIDA } Estado; // LIVRE = 0: o calloc já zera

typedef struct {
    int chave;
    int valor;
    Estado estado;
} Vaga;

struct Aberta {
    int m;   // número de posições
    int n;   // posições ocupadas
    Vaga *v; // um bloco só, contíguo
};

Aberta *aberta_cria(int m) {
    Aberta *t = malloc(sizeof *t);
    if (t == NULL) {
        return NULL;
    }
    t->v = calloc((size_t)m, sizeof *t->v);
    if (t->v == NULL) {
        free(t);
        return NULL;
    }
    t->m = m;
    t->n = 0;
    return t;
}

// anda a partir de chave % m até achar a chave ou uma posição LIVRE;
// passa reto pelas REMOVIDAS. Devolve a posição da chave ou -1.
static int procura(const Aberta *t, int chave, int *sondagens) {
    int i = chave % t->m;
    int olhadas = 0;
    for (int passo = 0; passo < t->m; passo++) {
        olhadas++;
        if (t->v[i].estado == LIVRE) {
            break; // a corrente de tentativas acaba aqui
        }
        if (t->v[i].estado == OCUPADA && t->v[i].chave == chave) {
            if (sondagens != NULL) {
                *sondagens = olhadas;
            }
            return i;
        }
        i = (i + 1) % t->m; // a próxima, dando a volta no fim
    }
    if (sondagens != NULL) {
        *sondagens = olhadas;
    }
    return -1;
}

int aberta_insere(Aberta *t, int chave, int valor, int *sondagens) {
    int i = chave % t->m;
    int destino = -1; // primeira REMOVIDA ou LIVRE do caminho
    int olhadas = 0;
    for (int passo = 0; passo < t->m; passo++) {
        olhadas++;
        Vaga *p = &t->v[i];
        if (p->estado == OCUPADA && p->chave == chave) {
            p->valor = valor; // já estava: só atualiza
            destino = i;
            break;
        }
        if (p->estado == REMOVIDA && destino < 0) {
            destino = i; // reaproveita, mas continua: a chave pode estar adiante
        }
        if (p->estado == LIVRE) {
            if (destino < 0) {
                destino = i;
            }
            break;
        }
        i = (i + 1) % t->m;
    }
    if (sondagens != NULL) {
        *sondagens = olhadas;
    }
    if (destino < 0) {
        return -1; // deu a volta inteira: cheia
    }
    if (t->v[destino].estado != OCUPADA) {
        t->v[destino] = (Vaga){chave, valor, OCUPADA};
        t->n++;
    }
    return destino;
}

bool aberta_busca(const Aberta *t, int chave, int *valor, int *sondagens) {
    int i = procura(t, chave, sondagens);
    if (i < 0) {
        return false;
    }
    *valor = t->v[i].valor;
    return true;
}

bool aberta_remove(Aberta *t, int chave) {
    int i = procura(t, chave, NULL);
    if (i < 0) {
        return false;
    }
    t->v[i].estado = REMOVIDA; // LIVRE aqui quebraria a busca de quem pulou esta vaga
    t->n--;
    return true;
}

void aberta_mostra(const Aberta *t) {
    for (int i = 0; i < t->m; i++) {
        printf("[%2d] ", i);
        if (t->v[i].estado == OCUPADA) {
            printf("%d\n", t->v[i].chave);
        } else if (t->v[i].estado == REMOVIDA) {
            printf("(removida)\n");
        } else {
            printf("-\n");
        }
    }
}

void aberta_libera(Aberta *t) {
    free(t->v);
    free(t);
}

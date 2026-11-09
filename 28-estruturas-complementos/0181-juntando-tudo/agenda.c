// agenda.c · implementação da agenda: as três estruturas do módulo juntas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

// ---------- pacientes: hash com dispersão dupla (0179) ----------
#define M 101 // primo; o passo h2 usa m - 1 = 100

typedef enum { LIVRE, OCUPADA } EstadoPos;

typedef struct {
    int cpf;
    char nome[24];
    int horario; // -1: sem consulta
    bool na_espera;
    EstadoPos estado;
} Paciente;

// ---------- horários: rubro-negra com sentinela (0177) ----------
typedef enum { VERMELHO, PRETO } Cor;

typedef struct NoAg {
    int horario;
    int cpf; // 0: horário vago (a consulta foi desmarcada e ninguém assumiu)
    Cor cor;
    struct NoAg *esq, *dir, *pai;
} NoAg;

// ---------- fila de espera: lista dupla circular com sentinela (0174) ----------
typedef struct NoFila {
    int cpf;
    struct NoFila *ant, *prox;
} NoFila;

struct Agenda {
    Paciente tab[M];
    int pacientes;
    NoAg *raiz;
    NoAg nil;
    int consultas;
    NoFila fila; // a sentinela da fila
    int na_fila;
};

Agenda *ag_cria(void) {
    Agenda *a = calloc(1, sizeof(Agenda)); // calloc: toda posição da hash LIVRE
    if (a == NULL) {
        return NULL;
    }
    a->nil.cor = PRETO;
    a->nil.esq = a->nil.dir = a->nil.pai = &a->nil;
    a->raiz = &a->nil;
    a->fila.prox = a->fila.ant = &a->fila;
    return a;
}

// --- hash ---
static int sonda(int cpf, int i) {
    return (int)((cpf % M + (long)i * (1 + cpf % (M - 1))) % M);
}

// devolve a posição do paciente, ou -1; *sondagens recebe as olhadas
static int acha_pos(const Agenda *a, int cpf, int *sondagens) {
    for (int i = 0; i < M; i++) {
        int j = sonda(cpf, i);
        if (a->tab[j].estado == LIVRE) {
            if (sondagens != NULL) {
                *sondagens = i + 1;
            }
            return -1;
        }
        if (a->tab[j].cpf == cpf) {
            if (sondagens != NULL) {
                *sondagens = i + 1;
            }
            return j;
        }
    }
    if (sondagens != NULL) {
        *sondagens = M;
    }
    return -1;
}

static Paciente *paciente(const Agenda *a, int cpf) {
    int j = acha_pos(a, cpf, NULL);
    return j < 0 ? NULL : (Paciente *)&a->tab[j];
}

bool ag_cadastra(Agenda *a, int cpf, const char *nome) {
    if (cpf <= 0 || paciente(a, cpf) != NULL || a->pacientes >= M / 2) {
        return false; // carga até 1/2: a busca continua curta
    }
    for (int i = 0; i < M; i++) {
        Paciente *p = &a->tab[sonda(cpf, i)];
        if (p->estado == LIVRE) {
            p->cpf = cpf;
            snprintf(p->nome, sizeof p->nome, "%s", nome);
            p->horario = -1;
            p->na_espera = false;
            p->estado = OCUPADA;
            a->pacientes++;
            return true;
        }
    }
    return false;
}

const char *ag_nome(const Agenda *a, int cpf) {
    const Paciente *p = paciente(a, cpf);
    return p == NULL ? NULL : p->nome;
}

// --- rubro-negra ---
static void gira_esq(Agenda *a, NoAg *x) {
    NoAg *y = x->dir;
    x->dir = y->esq;
    if (y->esq != &a->nil) {
        y->esq->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == &a->nil) {
        a->raiz = y;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
}

static void gira_dir(Agenda *a, NoAg *x) {
    NoAg *y = x->esq;
    x->esq = y->dir;
    if (y->dir != &a->nil) {
        y->dir->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == &a->nil) {
        a->raiz = y;
    } else if (x == x->pai->dir) {
        x->pai->dir = y;
    } else {
        x->pai->esq = y;
    }
    y->dir = x;
    x->pai = y;
}

static void conserta(Agenda *a, NoAg *z) {
    while (z->pai->cor == VERMELHO) {
        NoAg *avo = z->pai->pai;
        if (z->pai == avo->esq) {
            NoAg *tio = avo->dir;
            if (tio->cor == VERMELHO) {
                z->pai->cor = tio->cor = PRETO;
                avo->cor = VERMELHO;
                z = avo;
            } else {
                if (z == z->pai->dir) {
                    z = z->pai;
                    gira_esq(a, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                gira_dir(a, z->pai->pai);
            }
        } else {
            NoAg *tio = avo->esq;
            if (tio->cor == VERMELHO) {
                z->pai->cor = tio->cor = PRETO;
                avo->cor = VERMELHO;
                z = avo;
            } else {
                if (z == z->pai->esq) {
                    z = z->pai;
                    gira_dir(a, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                gira_esq(a, z->pai->pai);
            }
        }
    }
    a->raiz->cor = PRETO;
}

static NoAg *busca_no(const Agenda *a, int horario) {
    NoAg *x = a->raiz;
    while (x != &a->nil && x->horario != horario) {
        x = horario < x->horario ? x->esq : x->dir;
    }
    return x;
}

// pendura um nó novo (vago) para o horário e conserta as cores
static NoAg *novo_horario(Agenda *a, int horario) {
    NoAg *y = &a->nil;
    NoAg *x = a->raiz;
    while (x != &a->nil) {
        y = x;
        x = horario < x->horario ? x->esq : x->dir;
    }
    NoAg *z = malloc(sizeof(NoAg));
    if (z == NULL) {
        return NULL;
    }
    z->horario = horario;
    z->cpf = 0;
    z->pai = y;
    z->esq = z->dir = &a->nil;
    z->cor = VERMELHO;
    if (y == &a->nil) {
        a->raiz = z;
    } else if (horario < y->horario) {
        y->esq = z;
    } else {
        y->dir = z;
    }
    conserta(a, z);
    return z;
}

static const NoAg *sucessor(const Agenda *a, const NoAg *x) {
    if (x->dir != &a->nil) {
        x = x->dir;
        while (x->esq != &a->nil) {
            x = x->esq;
        }
        return x;
    }
    const NoAg *y = x->pai;
    while (y != &a->nil && x == y->dir) {
        x = y;
        y = y->pai;
    }
    return y;
}

// o primeiro nó com horário >= h
static const NoAg *teto(const Agenda *a, int h) {
    const NoAg *candidato = &a->nil;
    const NoAg *x = a->raiz;
    while (x != &a->nil) {
        if (x->horario >= h) {
            candidato = x;
            x = x->esq;
        } else {
            x = x->dir;
        }
    }
    return candidato;
}

// --- fila de espera ---
static NoFila *fila_busca(Agenda *a, int cpf) {
    a->fila.cpf = cpf; // o truque da sentinela do 0174
    NoFila *x = a->fila.prox;
    while (x->cpf != cpf) {
        x = x->prox;
    }
    return x;
}

static void fila_tira(Agenda *a, NoFila *x) {
    x->ant->prox = x->prox;
    x->prox->ant = x->ant;
    free(x);
    a->na_fila--;
}

// --- operações da agenda ---
bool ag_marca(Agenda *a, int horario, int cpf) {
    Paciente *p = paciente(a, cpf);
    if (p == NULL || p->horario != -1) {
        return false;
    }
    NoAg *x = busca_no(a, horario);
    if (x != &a->nil && x->cpf != 0) {
        return false; // horário ocupado
    }
    if (x == &a->nil) {
        x = novo_horario(a, horario);
        if (x == NULL) {
            return false;
        }
    }
    x->cpf = cpf;
    p->horario = horario;
    a->consultas++;
    if (p->na_espera) { // conseguiu horário: sai da fila
        fila_tira(a, fila_busca(a, cpf));
        p->na_espera = false;
    }
    return true;
}

bool ag_espera(Agenda *a, int cpf) {
    Paciente *p = paciente(a, cpf);
    if (p == NULL || p->horario != -1 || p->na_espera) {
        return false;
    }
    NoFila *x = malloc(sizeof(NoFila));
    if (x == NULL) {
        return false;
    }
    x->cpf = cpf; // entra antes da sentinela: no fim
    x->prox = &a->fila;
    x->ant = a->fila.ant;
    a->fila.ant->prox = x;
    a->fila.ant = x;
    a->na_fila++;
    p->na_espera = true;
    return true;
}

int ag_cancela(Agenda *a, int horario) {
    NoAg *x = busca_no(a, horario);
    if (x == &a->nil || x->cpf == 0) {
        return -1;
    }
    paciente(a, x->cpf)->horario = -1;
    x->cpf = 0;
    a->consultas--;
    if (a->na_fila == 0) {
        return 0; // ninguém esperando: o horário fica vago na árvore
    }
    int cpf = a->fila.prox->cpf; // o primeiro da fila assume
    ag_marca(a, horario, cpf);   // ag_marca já tira ele da fila
    return cpf;
}

int ag_horario_de(const Agenda *a, int cpf) {
    const Paciente *p = paciente(a, cpf);
    return p == NULL ? -1 : p->horario;
}

int ag_proximo(const Agenda *a, int horario) {
    for (const NoAg *x = teto(a, horario); x != &a->nil; x = sucessor(a, x)) {
        if (x->cpf != 0) {
            return x->horario;
        }
    }
    return -1;
}

int ag_intervalo(const Agenda *a, int de, int ate, int *horarios, int max) {
    int k = 0;
    for (const NoAg *x = teto(a, de); x != &a->nil && x->horario <= ate && k < max;
         x = sucessor(a, x)) {
        if (x->cpf != 0) {
            horarios[k++] = x->horario;
        }
    }
    return k;
}

static void mostra(const Agenda *a, const NoAg *x) {
    if (x == &a->nil) {
        return;
    }
    mostra(a, x->esq);
    printf("%02d:%02d  ", x->horario / 100, x->horario % 100);
    if (x->cpf == 0) {
        printf("(vago)\n");
    } else {
        printf("%s\n", ag_nome(a, x->cpf));
    }
    mostra(a, x->dir);
}

void ag_mostra(const Agenda *a) {
    mostra(a, a->raiz);
}

void ag_mostra_espera(const Agenda *a) {
    printf("Espera:");
    if (a->na_fila == 0) {
        printf(" (ninguém)");
    }
    for (const NoFila *x = a->fila.prox; x != &a->fila; x = x->prox) {
        printf(" %s", ag_nome(a, x->cpf));
    }
    printf("\n");
}

static int altura(const Agenda *a, const NoAg *x) {
    if (x == &a->nil) {
        return -1;
    }
    int he = altura(a, x->esq), hd = altura(a, x->dir);
    return 1 + (he > hd ? he : hd);
}

void ag_estatisticas(const Agenda *a) {
    int nos = 0, bh = 0;
    for (const NoAg *x = teto(a, 0); x != &a->nil; x = sucessor(a, x)) {
        nos++;
    }
    for (const NoAg *x = a->raiz; x != &a->nil; x = x->esq) {
        bh += x->esq->cor == PRETO;
    }
    long soma = 0;
    for (int j = 0; j < M; j++) {
        if (a->tab[j].estado == OCUPADA) {
            int s;
            acha_pos(a, a->tab[j].cpf, &s);
            soma += s;
        }
    }
    printf("Horários na árvore: %d (%d com consulta) | altura %d | altura negra %d\n", nos,
           a->consultas, altura(a, a->raiz), bh);
    printf("Pacientes: %d em %d posições | média de sondagens: %.2f\n", a->pacientes, M,
           a->pacientes > 0 ? (double)soma / a->pacientes : 0.0);
    printf("Na fila de espera: %d\n", a->na_fila);
}

static void libera_arvore(Agenda *a, NoAg *x) {
    if (x != &a->nil) {
        libera_arvore(a, x->esq);
        libera_arvore(a, x->dir);
        free(x);
    }
}

void ag_libera(Agenda *a) {
    if (a == NULL) {
        return;
    }
    libera_arvore(a, a->raiz);
    NoFila *x = a->fila.prox;
    while (x != &a->fila) {
        NoFila *seguinte = x->prox;
        free(x);
        x = seguinte;
    }
    free(a);
}

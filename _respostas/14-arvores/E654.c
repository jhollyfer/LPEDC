// 0109 · Juntando tudo
// Exercício E654 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

// BST de nomes: só para saber quem já entrou
typedef struct NoNome {
    char nome[20];
    struct NoNome *esq, *dir;
} NoNome;

int tem_nome(const NoNome *r, const char *nome) {
    while (r != NULL) {
        int c = strcmp(nome, r->nome);
        if (c == 0) {
            return 1;
        }
        r = c < 0 ? r->esq : r->dir;
    }
    return 0;
}

NoNome *insere_nome(NoNome *r, const char *nome) {
    if (r == NULL) {
        NoNome *n = malloc(sizeof(NoNome));
        if (n == NULL) {
            exit(1);
        }
        strcpy(n->nome, nome); // cópia: o buffer de leitura muda a cada linha
        n->esq = n->dir = NULL;
        return n;
    }
    if (strcmp(nome, r->nome) < 0) {
        r->esq = insere_nome(r->esq, nome);
    } else {
        r->dir = insere_nome(r->dir, nome);
    }
    return r;
}

void libera_nomes(NoNome *r) {
    if (r != NULL) {
        libera_nomes(r->esq);
        libera_nomes(r->dir);
        free(r);
    }
}

// heap de máximo pela prioridade
typedef struct {
    int prio;
    char nome[20];
} Paciente;

Paciente fila[MAX];
int n = 0;

void troca(int a, int b) {
    Paciente t = fila[a];
    fila[a] = fila[b];
    fila[b] = t;
}

void entra(int prio, const char *nome) {
    int i = n++;
    fila[i].prio = prio;
    strcpy(fila[i].nome, nome);
    while (i > 0 && fila[(i - 1) / 2].prio < fila[i].prio) {
        troca((i - 1) / 2, i);
        i = (i - 1) / 2;
    }
}

Paciente sai(void) {
    Paciente primeiro = fila[0];
    fila[0] = fila[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && fila[f + 1].prio > fila[f].prio) {
            f++;
        }
        if (fila[i].prio >= fila[f].prio) {
            break;
        }
        troca(i, f);
        i = f;
    }
    return primeiro;
}

int main(void) {
    NoNome *nomes = NULL;
    char nome[20];
    int prio;

    while (n < MAX && scanf("%19s %d", nome, &prio) == 2) {
        if (tem_nome(nomes, nome)) {
            printf("%s já está na lista\n", nome);
        } else {
            nomes = insere_nome(nomes, nome);
            entra(prio, nome);
        }
    }
    while (n > 0) {
        Paciente p = sai();
        printf("Chamando: %s (%d)\n", p.nome, p.prio);
    }
    libera_nomes(nomes);
    return 0;
}

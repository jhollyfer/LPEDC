// Lista · Módulo 11 · Listas
// Exercício P1123 · ★★★ · Turmas e alunos: uma lista de listas

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[16];
    struct aluno *prox;
} Aluno;

typedef struct turma {
    char nome[16];
    int n;
    Aluno *alunos;
    struct turma *prox;
} Turma;

// encaixa um nó já criado, em ordem alfabética, e devolve o novo início
Aluno *encaixa(Aluno *inicio, Aluno *novo) {
    if (inicio == NULL || strcmp(novo->nome, inicio->nome) < 0) {
        novo->prox = inicio;
        return novo;
    }
    Aluno *p = inicio;
    while (p->prox != NULL && strcmp(p->prox->nome, novo->nome) < 0) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return inicio;
}

// desliga o aluno da lista (sem liberar) e devolve o nó, ou NULL
Aluno *desliga(Aluno **inicio, const char *nome) {
    Aluno *ant = NULL, *p = *inicio;
    while (p != NULL && strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return NULL;
    }
    if (ant == NULL) {
        *inicio = p->prox;
    } else {
        ant->prox = p->prox;
    }
    p->prox = NULL;
    return p;
}

Turma *acha(Turma *turmas, const char *nome) {
    for (Turma *t = turmas; t != NULL; t = t->prox) {
        if (strcmp(t->nome, nome) == 0) {
            return t;
        }
    }
    return NULL;
}

Turma *matricula(Turma *turmas, const char *turma, const char *aluno) {
    Turma *t = acha(turmas, turma);
    if (t == NULL) {
        t = malloc(sizeof *t);
        if (t == NULL) {
            fprintf(stderr, "sem memória\n");
            exit(1);
        }
        strcpy(t->nome, turma);
        t->n = 0;
        t->alunos = NULL;
        t->prox = NULL;
        if (turmas == NULL) {
            turmas = t;
        } else {
            Turma *u = turmas;
            while (u->prox != NULL) {
                u = u->prox;
            }
            u->prox = t;
        }
    }
    Aluno *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    strcpy(novo->nome, aluno);
    t->alunos = encaixa(t->alunos, novo);
    t->n++;
    return turmas;
}

bool cancela(Turma *turmas, const char *turma, const char *aluno) {
    Turma *t = acha(turmas, turma);
    if (t == NULL) {
        return false;
    }
    Aluno *a = desliga(&t->alunos, aluno);
    if (a == NULL) {
        return false;
    }
    free(a);
    t->n--;
    return true;
}

bool transfere(Turma *turmas, const char *aluno, const char *de, const char *para) {
    Turma *origem = acha(turmas, de), *destino = acha(turmas, para);
    if (origem == NULL || destino == NULL) {
        return false;
    }
    Aluno *a = desliga(&origem->alunos, aluno);
    if (a == NULL) {
        return false;
    }
    origem->n--;
    destino->alunos = encaixa(destino->alunos, a);
    destino->n++;
    return true;
}

void mostra(const Turma *turmas) {
    for (const Turma *t = turmas; t != NULL; t = t->prox) {
        printf("%s (%d):", t->nome, t->n);
        for (const Aluno *a = t->alunos; a != NULL; a = a->prox) {
            printf(" %s", a->nome);
        }
        printf("\n");
    }
}

void libera_tudo(Turma *turmas) {
    while (turmas != NULL) {
        Aluno *a = turmas->alunos;
        while (a != NULL) {
            Aluno *seguinte = a->prox;
            free(a);
            a = seguinte;
        }
        Turma *proxima = turmas->prox;
        free(turmas);
        turmas = proxima;
    }
}

int main(void) {
    Turma *turmas = NULL;
    turmas = matricula(turmas, "C", "Bia");
    turmas = matricula(turmas, "Python", "Ana");
    turmas = matricula(turmas, "C", "Ana");
    turmas = matricula(turmas, "C", "Caio");
    turmas = matricula(turmas, "Python", "Davi");
    mostra(turmas);
    printf("--\n");
    transfere(turmas, "Caio", "C", "Python");
    cancela(turmas, "Python", "Ana");
    mostra(turmas);
    libera_tudo(turmas);
    return 0;
}

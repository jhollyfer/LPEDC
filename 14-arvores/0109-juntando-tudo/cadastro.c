// cadastro.c · implementação do cadastro da academia (BST de alunos)
#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"

NoAluno *cad_insere(NoAluno *r, Aluno a) {
    if (r == NULL) {
        NoAluno *n = malloc(sizeof(NoAluno));
        if (n == NULL) {
            fprintf(stderr, "sem memória\n");
            exit(1);
        }
        n->a = a; // a struct inteira é copiada
        n->esq = NULL;
        n->dir = NULL;
        return n;
    }
    if (a.matricula < r->a.matricula) {
        r->esq = cad_insere(r->esq, a);
    } else if (a.matricula > r->a.matricula) {
        r->dir = cad_insere(r->dir, a);
    }
    return r;
}

Aluno *cad_busca(NoAluno *r, int matricula) {
    while (r != NULL && r->a.matricula != matricula) {
        r = matricula < r->a.matricula ? r->esq : r->dir;
    }
    return r == NULL ? NULL : &r->a;
}

NoAluno *cad_remove(NoAluno *r, int matricula) {
    if (r == NULL) {
        return NULL;
    }
    if (matricula < r->a.matricula) {
        r->esq = cad_remove(r->esq, matricula);
    } else if (matricula > r->a.matricula) {
        r->dir = cad_remove(r->dir, matricula);
    } else if (r->esq == NULL || r->dir == NULL) {
        NoAluno *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        NoAluno *suc = r->dir;
        while (suc->esq != NULL) {
            suc = suc->esq;
        }
        r->a = suc->a; // copia o aluno sucessor inteiro
        r->dir = cad_remove(r->dir, suc->a.matricula);
    }
    return r;
}

void cad_lista(const NoAluno *r) {
    if (r == NULL) {
        return;
    }
    cad_lista(r->esq);
    printf("  %3d  %-8s %2d treinos\n", r->a.matricula, r->a.nome, r->a.treinos);
    cad_lista(r->dir);
}

int cad_conta(const NoAluno *r) {
    return r == NULL ? 0 : 1 + cad_conta(r->esq) + cad_conta(r->dir);
}

int cad_altura(const NoAluno *r) {
    if (r == NULL) {
        return -1;
    }
    int he = cad_altura(r->esq);
    int hd = cad_altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

int cad_para_vetor(const NoAluno *r, Aluno v[], int pos) {
    if (r == NULL) {
        return pos;
    }
    pos = cad_para_vetor(r->esq, v, pos);
    v[pos++] = r->a;
    return cad_para_vetor(r->dir, v, pos);
}

NoAluno *cad_libera(NoAluno *r) {
    if (r != NULL) {
        cad_libera(r->esq);
        cad_libera(r->dir);
        free(r);
    }
    return NULL;
}

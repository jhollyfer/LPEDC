// cadastro.h · interface do cadastro da academia: uma BST de alunos,
// ordenada pela matrícula
#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct {
    int matricula;
    char nome[20];
    int treinos; // treinos no mês
} Aluno;

typedef struct NoAluno {
    Aluno a;
    struct NoAluno *esq;
    struct NoAluno *dir;
} NoAluno;

// insere pela matrícula e devolve a raiz (matrícula repetida é ignorada)
NoAluno *cad_insere(NoAluno *r, Aluno a);

// devolve o aluno (para ler ou alterar) ou NULL
Aluno *cad_busca(NoAluno *r, int matricula);

// remove pela matrícula e devolve a nova raiz
NoAluno *cad_remove(NoAluno *r, int matricula);

void cad_lista(const NoAluno *r); // um aluno por linha, em ordem de matrícula
int cad_conta(const NoAluno *r);
int cad_altura(const NoAluno *r);

// copia os alunos em ordem de matrícula para v a partir de v[pos] e
// devolve a próxima posição livre
int cad_para_vetor(const NoAluno *r, Aluno v[], int pos);

NoAluno *cad_libera(NoAluno *r);

#endif

// 0109 · Juntando tudo
// Exercício E651 · ★★☆

#include <stdio.h>
#include "cadastro.h"

#define MAX 16

// insere o do meio primeiro: ele vira a raiz desta parte
NoAluno *monta(NoAluno *r, const Aluno v[], int ini, int fim) {
    if (ini > fim) {
        return r;
    }
    int meio = (ini + fim) / 2;
    r = cad_insere(r, v[meio]);
    r = monta(r, v, ini, meio - 1);
    return monta(r, v, meio + 1, fim);
}

NoAluno *rebalanceia(NoAluno *r) {
    Aluno v[MAX];
    int n = cad_para_vetor(r, v, 0); // em ordem de matrícula
    r = cad_libera(r);
    return monta(NULL, v, 0, n - 1);
}

void matriculas(const NoAluno *r) {
    if (r != NULL) {
        matriculas(r->esq);
        printf(" %d", r->a.matricula);
        matriculas(r->dir);
    }
}

int main(void) {
    Aluno planilha[] = {
        {20, "Davi", 4}, {30, "Bruno", 8}, {40, "Eva", 20}, {50, "Ana", 12},
        {60, "Fabio", 9}, {70, "Carla", 15}, {80, "Gil", 11},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 7; i++) {
        cad = cad_insere(cad, planilha[i]);
    }
    printf("Antes:  altura %d\n", cad_altura(cad));

    cad = rebalanceia(cad);
    printf("Depois: altura %d, raiz %d (%s)\n", cad_altura(cad), cad->a.matricula, cad->a.nome);
    printf("Alunos em ordem:");
    matriculas(cad);
    printf("\n");

    cad = cad_libera(cad);
    return 0;
}

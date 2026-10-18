// 0104 · Juntando tudo
// Exercício E623 · ★★★
//
// Resposta: pos é passado por valor. A chamada da esquerda enchia o vetor e
// devolvia a próxima posição livre, mas o valor era jogado fora: cada nó
// escrevia por cima do que a esquerda tinha escrito.

#include <stdio.h>
#include "cadastro.h"

int copia(const NoAluno *r, Aluno v[], int pos) {
    if (r == NULL) {
        return pos;
    }
    pos = copia(r->esq, v, pos); // a esquerda diz onde parou
    v[pos++] = r->a;
    return copia(r->dir, v, pos);
}

int main(void) {
    Aluno turma[] = {
        {50, "Ana", 12}, {30, "Bruno", 8}, {70, "Carla", 15}, {20, "Davi", 4},
        {40, "Eva", 20}, {60, "Fabio", 9}, {80, "Gil", 11},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 7; i++) {
        cad = cad_insere(cad, turma[i]);
    }

    Aluno v[16];
    int n = copia(cad, v, 0);
    printf("copiados: %d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%s%d %s", i > 0 ? ", " : "", v[i].matricula, v[i].nome);
    }
    printf("\n");

    cad = cad_libera(cad);
    return 0;
}

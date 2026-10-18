// 0104 · Juntando tudo
// Exercício E623 · ★★★
//
// Ache o bug. Esta função copia faz o mesmo que cad_para_vetor: deveria
// colocar os alunos no vetor em ordem de matrícula. Mas a lista sai errada:
//
//   Saída esperada:
//   copiados: 7
//   20 Davi, 30 Bruno, 40 Eva, 50 Ana, 60 Fabio, 70 Carla, 80 Gil
//
//   Saída que aparece:
//   copiados: 3
//   50 Ana, 70 Carla, 80 Gil
//
// Ache a linha errada, conserte e rode até sair a saída esperada.
//
// Dicas:
// 1. pos é passado por VALOR. Quando a chamada da esquerda coloca 3 alunos
//    no vetor, a chamada de cima fica sabendo?
// 2. Siga a chamada da raiz: a esquerda escreve em v[0], v[1], v[2]... e
//    depois a raiz escreve onde?
// 3. Resposta esperada: a linha "copia(r->esq, v, pos);" ignora o valor
//    devolvido. O certo é "pos = copia(r->esq, v, pos);". Do jeito errado,
//    cada nó escreve por cima do que a subárvore esquerda escreveu: a raiz
//    sobrescreve v[0] com o 50, o 70 sobrescreve o 60 em v[1] e o 80 vai
//    para v[2]. Só os nós do caminho mais à direita sobrevivem: 3.
//    Consertado, os 7 aparecem em ordem.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include "cadastro.h"

int copia(const NoAluno *r, Aluno v[], int pos) {
    if (r == NULL) {
        return pos;
    }
    copia(r->esq, v, pos);
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

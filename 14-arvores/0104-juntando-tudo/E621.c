// 0104 · Juntando tudo
// Exercício E621 · ★★☆
//
// A academia importou os alunos de uma planilha em ordem crescente de
// matrícula, e a BST virou uma fila indiana (altura 6 com 7 alunos). Escreva
// rebalanceia(r): copie os alunos para um vetor (já em ordem, com
// cad_para_vetor), libere a árvore velha e monte uma nova inserindo SEMPRE O
// DO MEIO primeiro. A função devolve a raiz nova.
//
//   Saída esperada:
//   Antes:  altura 6
//   Depois: altura 2, raiz 50 (Ana)
//   Alunos em ordem: 20 30 40 50 60 70 80
//
// Dicas:
// 1. Uma função auxiliar monta(r, v, ini, fim): se ini > fim, devolve r. Senão,
//    meio = (ini + fim) / 2; insere v[meio]; chama monta para v[ini..meio-1]
//    e para v[meio+1..fim].
// 2. Como o do meio entra antes das duas metades, ele vira a raiz da
//    subárvore, e cada metade fica de um lado. É a busca binária ao
//    contrário.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete rebalanceia):

#include <stdio.h>
#include "cadastro.h"

#define MAX 16

NoAluno *rebalanceia(NoAluno *r) {
    return r; // troque por sua versão
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

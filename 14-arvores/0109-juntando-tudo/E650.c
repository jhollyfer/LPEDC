// 0109 · Juntando tudo
// Exercício E650 · ★☆☆
//
// SEM RODAR, preveja a saída. Desenhe a BST de matrículas a cada operação.
//
// Dicas:
// 1. Inserção na ordem 40, 20, 60, 10, 30, 50: a árvore fica cheinha.
// 2. Remover o 40 (a raiz, com dois filhos): o sucessor é o menor da direita.
//    E a busca pelo 40, depois disso?
// 3. Resposta esperada:
//    altura 2, 6 alunos
//    40 saiu; nova raiz: 50 (Joana)
//    busca 40: não achou
//    altura 2, 5 alunos
//    e a lista em ordem de matrícula: 10 Rita (3 treinos), 20 Paulo (7),
//    30 Lia (9), 50 Joana (5) e 60 Caio (6).
//
// Escreva sua resposta abaixo (a saída, como comentário):

#include <stdio.h>
#include "cadastro.h"

int main(void) {
    Aluno turma[] = {
        {40, "Teo", 11}, {20, "Paulo", 7}, {60, "Caio", 6},
        {10, "Rita", 3}, {30, "Lia", 9}, {50, "Joana", 5},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 6; i++) {
        cad = cad_insere(cad, turma[i]);
    }
    printf("altura %d, %d alunos\n", cad_altura(cad), cad_conta(cad));

    cad = cad_remove(cad, 40);
    printf("40 saiu; nova raiz: %d (%s)\n", cad->a.matricula, cad->a.nome);
    printf("busca 40: %s\n", cad_busca(cad, 40) != NULL ? "achou" : "não achou");
    printf("altura %d, %d alunos\n", cad_altura(cad), cad_conta(cad));
    cad_lista(cad);

    cad = cad_libera(cad);
    return 0;
}

// 0104 · Juntando tudo
// Exercício E620 · ★☆☆
//
// Complete a função resumo(cad), que mostra numa linha a matrícula e o nome
// de quem está na raiz do cadastro, a altura e a quantidade de alunos, ou
// "cadastro vazio" se não houver ninguém. O main chama resumo depois de
// inserir seis alunos e depois de cada remoção da raiz:
//
//   Saída esperada:
//   raiz 40 (Teo), altura 2, 6 alunos
//   raiz 50 (Joana), altura 2, 5 alunos
//   raiz 60 (Caio), altura 2, 4 alunos
//   raiz 20 (Paulo), altura 1, 3 alunos
//   raiz 30 (Lia), altura 1, 2 alunos
//   raiz 10 (Rita), altura 0, 1 alunos
//   cadastro vazio
//
// Dicas:
// 1. A raiz é o próprio ponteiro cad: os dados estão em cad->a.matricula e
//    cad->a.nome. Teste cad == NULL antes de usar.
// 2. A altura e a contagem vêm prontas do TAD: cad_altura e cad_conta.
// 3. Resposta esperada: a saída acima. Quando o 60 sai, ele só tinha filho
//    esquerdo: o 20 sobe direto para a raiz, sem sucessor.
//
// Escreva sua resposta abaixo (complete resumo):

#include <stdio.h>
#include "cadastro.h"

void resumo(const NoAluno *cad) {
    (void)cad; // apague esta linha quando escrever a função
}

int main(void) {
    Aluno turma[] = {
        {40, "Teo", 11}, {20, "Paulo", 7}, {60, "Caio", 6},
        {10, "Rita", 3}, {30, "Lia", 9}, {50, "Joana", 5},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 6; i++) {
        cad = cad_insere(cad, turma[i]);
    }
    resumo(cad);

    // remove sempre quem está na raiz, até não sobrar ninguém
    while (cad != NULL) {
        cad = cad_remove(cad, cad->a.matricula);
        resumo(cad);
    }
    return 0;
}

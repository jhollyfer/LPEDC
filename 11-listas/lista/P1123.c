// Lista · Módulo 11 · Listas
// Exercício P1123 · ★★★ · Turmas e alunos: uma lista de listas
//
// O cursinho guarda uma lista de TURMAS, e cada turma guarda a sua própria
// lista de ALUNOS (em ordem alfabética). Escreva:
//
//   Turma *matricula(Turma *turmas, const char *turma, const char *aluno)
//     acha a turma (ou cria no FIM da lista de turmas) e insere o aluno em
//     ordem; devolve o início da lista de turmas;
//   bool cancela(Turma *turmas, const char *turma, const char *aluno)
//   bool transfere(Turma *turmas, const char *aluno, const char *de,
//                  const char *para)
//     NÃO cria nem libera nó: desliga o nó do aluno de uma turma e o encaixa
//     na outra.
//   void libera_tudo(Turma *turmas)   // cada aluno de cada turma, e as turmas
//
// Faça as matrículas (C, Bia), (Python, Ana), (C, Ana), (C, Caio),
// (Python, Davi); mostre; transfira Caio de C para Python, cancele Ana em
// Python; mostre de novo.
//
//   Saída esperada:
//   C (3): Ana Bia Caio
//   Python (2): Ana Davi
//   --
//   C (2): Ana Bia
//   Python (2): Caio Davi
//
// Dicas:
// 1. typedef struct aluno { char nome[16]; struct aluno *prox; } Aluno;
//    typedef struct turma { char nome[16]; int n; Aluno *alunos;
//    struct turma *prox; } Turma;
// 2. Escreva uma função auxiliar que encaixa um nó de aluno JÁ CRIADO na
//    posição certa de uma lista. A matrícula cria o nó e chama essa função;
//    a transferência desliga o nó e chama a mesma função.
// 3. libera_tudo tem dois laços: para cada turma, libere os alunos dela e
//    só depois a turma (guardando o prox antes de cada free).
// 4. Resposta esperada: a saída acima, sem vazamento.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}

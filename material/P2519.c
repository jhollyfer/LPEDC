// Lista · Módulo 25 · Estruturas especiais
// Exercício P2519 · ★★☆ · Transpor as triplas sem ordenar
//
// As notas da turma (4 alunos × 5 disciplinas) estão em triplas
// (aluno, disciplina, nota) em ordem de aluno. A coordenação quer por
// disciplina. Trocar lin com col e ordenar custaria O(n log n). A
// TRANSPOSIÇÃO RÁPIDA faz em O(n + colunas):
//   1. conte quantas triplas cada coluna tem;
//   2. calcule onde a primeira tripla de cada coluna vai cair no resultado
//      (a soma das contagens das colunas anteriores);
//   3. numa passada só, mande cada tripla para inicio[col]++, já trocada.
// Escreva transpoe(a, n, colunas, b) do zero, mostrando a contagem e o
// início de cada coluna.
//
//   Saída esperada:
//   por aluno: (0,1,7) (0,3,9) (1,0,6) (1,3,8) (1,4,5) (2,1,10) (3,0,4) (3,2,8) (3,4,9)
//   coluna 0: 2 tripla(s), começa em 0
//   coluna 1: 2 tripla(s), começa em 2
//   coluna 2: 1 tripla(s), começa em 4
//   coluna 3: 2 tripla(s), começa em 5
//   coluna 4: 2 tripla(s), começa em 7
//   por disciplina: (0,1,6) (0,3,4) (1,0,7) (1,2,10) (2,3,8) (3,0,9) (3,1,8) (4,1,5) (4,3,9)
//
// Dicas:
// 1. inicio[0] = 0 e inicio[c] = inicio[c - 1] + conta[c - 1].
// 2. Como a entrada está em ordem de aluno, dentro de cada disciplina os
//    alunos já saem em ordem: o resultado fica ordenado sem sort.
// 3. Resposta esperada: a disciplina 2 só tem uma nota e começa na posição
//    4; o resultado começa com (0,1,6) (0,3,4).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define MAXT 32

typedef struct {
    int lin, col, valor;
} Tripla;

void mostra(const char *rotulo, const Tripla t[], int n) {
    printf("%s:", rotulo);
    for (int k = 0; k < n; k++) printf(" (%d,%d,%d)", t[k].lin, t[k].col, t[k].valor);
    printf("\n");
}

int main(void) {
    Tripla notas[] = {{0, 1, 7}, {0, 3, 9}, {1, 0, 6}, {1, 3, 8}, {1, 4, 5},
                      {2, 1, 10}, {3, 0, 4}, {3, 2, 8}, {3, 4, 9}};
    int n = 9;
    mostra("por aluno", notas, n);
    return 0;
}

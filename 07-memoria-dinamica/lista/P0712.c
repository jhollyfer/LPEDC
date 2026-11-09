// Lista · Módulo 07 · Memória dinâmica
// Exercício P0712 · ★★☆ · Turmas de tamanhos diferentes
//
// O cursinho tem três turmas, cada uma com um número diferente de alunos:
//
//   turma A: 7.5 8.0 6.0
//   turma B: 9.0 5.5 7.0 8.5 6.5
//   turma C: 4.0 10.0
//
// Em vez de uma matriz retangular (que desperdiça casas), monte no heap um
// vetor de 3 ponteiros, em que a linha i tem EXATAMENTE tam[i] notas:
// double **notas e int tam[3] = {3, 5, 2}. Calcule a média de cada turma, a
// média geral (de todos os alunos) e mostre quantos bytes de notas foram
// alocados contra os de uma matriz 3x5:
//
//   Saída esperada:
//   Turma A (3 alunos): média 7.17
//   Turma B (5 alunos): média 7.30
//   Turma C (2 alunos): média 7.00
//   Média geral: 7.20
//   Bytes das notas: 80 (matriz 3x5 usaria 120)
//
// Dicas:
// 1. notas = malloc(3 * sizeof *notas); notas[i] = malloc(tam[i] * sizeof
//    *notas[i]);
// 2. A média geral NÃO é a média das três médias: some todas as notas e
//    divida pelo total de alunos (10).
// 3. Bytes: (3 + 5 + 2) * sizeof(double) contra 3 * 5 * sizeof(double).
// 4. Libere cada linha e depois o vetor de ponteiros.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double dados[10] = {7.5, 8.0, 6.0, 9.0, 5.5, 7.0, 8.5, 6.5, 4.0, 10.0};
    int tam[3] = {3, 5, 2};
    (void) dados, (void) tam; // apague esta linha quando escrever

    return 0;
}

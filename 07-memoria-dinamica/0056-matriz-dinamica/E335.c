// 0056 · Matriz dinâmica
// Exercício E335 · ★★★
//
// Este programa monta a grade de 3 turnos x 5 dias de uma clínica, com o
// número de consultas, e mostra o total. Ele tem DOIS erros de memória, de
// propósito (o gcc até avisa sobre um deles). Rode com o rodar, leia o aviso
// e os relatórios e conserte um de cada vez, rodando de novo a cada conserto
// até sair o total sem relatório nenhum.
//
//   Saída esperada depois do conserto:
//   Total de consultas: 105
//
// Dicas:
// 1. Primeiro relatório: heap-buffer-overflow. Quantos bytes tem um int? E
//    um int *?
// 2. Segundo erro: o aviso "may be used after free" do gcc, que vira
//    heap-use-after-free quando roda. Depois de free(grade), como o laço
//    ainda acha grade[i]?
// 3. Resposta esperada: (a) malloc(turnos * sizeof(int)) aloca 12 bytes para
//    3 ponteiros que precisam de 24; use sizeof *grade (ou sizeof(int *)).
//    (b) free(grade) vem antes do laço que libera as linhas; inverta a
//    ordem: primeiro as linhas, depois grade. Total: 3 * 5 * 7 = 105.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int turnos = 3;
    int dias = 5;
    int **grade = malloc(turnos * sizeof(int));
    if (grade == NULL) {
        return 1;
    }
    for (int i = 0; i < turnos; i++) {
        grade[i] = malloc(dias * sizeof(int));
        if (grade[i] == NULL) {
            return 1;
        }
        for (int j = 0; j < dias; j++) {
            grade[i][j] = 7; // 7 consultas por turno
        }
    }

    int total = 0;
    for (int i = 0; i < turnos; i++) {
        for (int j = 0; j < dias; j++) {
            total += grade[i][j];
        }
    }
    printf("Total de consultas: %d\n", total);

    free(grade);
    for (int i = 0; i < turnos; i++) {
        free(grade[i]);
    }
    return 0;
}

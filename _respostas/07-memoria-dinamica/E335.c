// 0056 · Matriz dinâmica
// Exercício E335 · ★★★
//
// Os dois erros: (a) malloc(turnos * sizeof(int)) dava 12 bytes para 3
// ponteiros de 8 bytes (24): heap-buffer-overflow ao gravar grade[1]. (b)
// free(grade) antes de liberar as linhas: o laço lia grade[i] num bloco já
// devolvido (heap-use-after-free). Bônus: se uma linha falhasse, as
// anteriores vazavam; agora são liberadas.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int turnos = 3;
    int dias = 5;
    int **grade = malloc(turnos * sizeof *grade); // 3 ponteiros
    if (grade == NULL) {
        return 1;
    }
    for (int i = 0; i < turnos; i++) {
        grade[i] = malloc(dias * sizeof *grade[i]);
        if (grade[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(grade[k]);
            }
            free(grade);
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

    for (int i = 0; i < turnos; i++) {
        free(grade[i]); // primeiro as linhas
    }
    free(grade);        // depois o vetor de ponteiros
    return 0;
}
// Saída:
// Total de consultas: 105

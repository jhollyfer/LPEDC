// 0058 · Juntando tudo
// Exercício E346 · ★★☆

#include <stdio.h>
#include <stdlib.h>

void liberar_notas(double **notas, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(notas[i]);
    }
    free(notas);
}

int main(void) {
    int alunos, provas;
    printf("Alunos e provas: ");
    if (scanf("%d %d", &alunos, &provas) != 2 || alunos <= 0 || provas <= 0) {
        return 1;
    }

    double **notas = malloc(alunos * sizeof *notas);
    if (notas == NULL) {
        return 1;
    }
    for (int i = 0; i < alunos; i++) {
        notas[i] = malloc(provas * sizeof *notas[i]);
        if (notas[i] == NULL) {
            liberar_notas(notas, i);
            return 1;
        }
    }
    double *medias = malloc(alunos * sizeof *medias);
    if (medias == NULL) {
        liberar_notas(notas, alunos);
        return 1;
    }

    for (int i = 0; i < alunos; i++) {
        printf("Notas do aluno %d: ", i + 1);
        double soma = 0;
        for (int j = 0; j < provas; j++) {
            if (scanf("%lf", &notas[i][j]) != 1) {
                notas[i][j] = 0;
            }
            soma += notas[i][j];
        }
        medias[i] = soma / provas;
    }

    double turma = 0;
    for (int i = 0; i < alunos; i++) {
        printf("Aluno %d: %.1f\n", i + 1, medias[i]);
        turma += medias[i];
    }
    printf("Turma: %.1f\n", turma / alunos);

    free(medias);
    liberar_notas(notas, alunos);
    return 0;
}
// Exemplo de uso:
// Alunos e provas: 3 2
// Notas do aluno 1: 7 8
// Notas do aluno 2: 5 6
// Notas do aluno 3: 9 10
// Aluno 1: 7.5
// Aluno 2: 5.5
// Aluno 3: 9.5
// Turma: 7.5

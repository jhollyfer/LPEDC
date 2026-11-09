// Lista · Módulo 07 · Memória dinâmica
// Exercício P0712 · ★★☆ · Turmas de tamanhos diferentes

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double dados[10] = {7.5, 8.0, 6.0, 9.0, 5.5, 7.0, 8.5, 6.5, 4.0, 10.0};
    int tam[3] = {3, 5, 2};
    char nomes[3] = {'A', 'B', 'C'};

    double **notas = malloc(3 * sizeof *notas);
    if (notas == NULL) {
        return 1;
    }
    int k = 0;
    for (int i = 0; i < 3; i++) {
        notas[i] = malloc(tam[i] * sizeof *notas[i]); // linha do tamanho exato
        if (notas[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(notas[j]);
            }
            free(notas);
            return 1;
        }
        for (int j = 0; j < tam[i]; j++) {
            notas[i][j] = dados[k++];
        }
    }

    double soma_geral = 0;
    int alunos = 0;
    for (int i = 0; i < 3; i++) {
        double soma = 0;
        for (int j = 0; j < tam[i]; j++) {
            soma += notas[i][j];
        }
        printf("Turma %c (%d alunos): média %.2f\n", nomes[i], tam[i], soma / tam[i]);
        soma_geral += soma;
        alunos += tam[i];
    }
    printf("Média geral: %.2f\n", soma_geral / alunos);
    printf("Bytes das notas: %zu (matriz 3x5 usaria %zu)\n",
           alunos * sizeof(double), 3 * 5 * sizeof(double));

    for (int i = 0; i < 3; i++) {
        free(notas[i]);
    }
    free(notas);
    return 0;
}

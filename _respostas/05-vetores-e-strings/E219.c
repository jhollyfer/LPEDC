// 0037 · Vetores
// Exercício E219 · ★★☆

#include <stdio.h>

#define ALUNOS 5

int main(void) {
    double notas[ALUNOS];
    double soma = 0.0;

    for (int i = 0; i < ALUNOS; i++) {
        printf("Nota do aluno %d: ", i + 1);
        if (scanf("%lf", &notas[i]) != 1) {
            printf("Entrada inválida.\n");
            return 1;
        }
        soma += notas[i];
    }

    double media = soma / ALUNOS;
    printf("Média da turma: %.2f\n", media);
    printf("Acima da média:\n");
    for (int i = 0; i < ALUNOS; i++) {
        if (notas[i] > media) {
            printf("Aluno %d: %.1f\n", i + 1, notas[i]);
        }
    }
    return 0;
}

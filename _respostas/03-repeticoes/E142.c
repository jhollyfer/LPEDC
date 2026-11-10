// 0024 · Laços aninhados
// Exercício E142 · ★★☆

#include <stdio.h>

int main(void) {
    int turma = 1;
    int aluno;

    while (turma <= 3) {
        aluno = 1; // recomeça a contagem a cada turma
        while (aluno <= 4) {
            printf("T%d-A%d ", turma, aluno);
            aluno++;
        }
        printf("\n");
        turma++;
    }
    return 0;
}

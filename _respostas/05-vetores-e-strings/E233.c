// 0039 · Matrizes
// Exercício E233 · ★★★
//
// Resposta: os limites estão trocados (o laço dos alunos ia até 4 e lia
// notas[2] e notas[3], linhas que não existem; o das provas ia só até 2); e
// soma / 4 é divisão de int por int, que joga fora o ,50 (use soma / 4.0).

#include <stdio.h>

#define ALUNOS 2
#define PROVAS 4

int main(void) {
    int notas[ALUNOS][PROVAS] = {
        {7, 8, 6, 9},
        {5, 10, 8, 6},
    };

    for (int a = 0; a < ALUNOS; a++) {
        int soma = 0;
        for (int p = 0; p < PROVAS; p++) {
            soma += notas[a][p];
        }
        double media = soma / 4.0;
        printf("Aluno %d: média %.2f\n", a + 1, media);
    }
    return 0;
}

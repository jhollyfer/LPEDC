// 0029 · Laços aninhados
// Exercício E172 · ★★☆
//
// Resposta: aluno nunca volta para 1. Depois da turma 1 ele vale 5, e o while
// de dentro não roda mais. Conserto: "aluno = 1;" dentro do while de fora,
// logo antes do while de dentro.

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

// 0029 · Laços aninhados
// Exercício E172 · ★★☆
//
// A escola quer a lista de chamada de 3 turmas com 4 alunos cada, uma turma
// por linha (T1-A1 T1-A2 ...). O programa abaixo mostra só a primeira turma e
// depois duas linhas vazias. O código com o erro está logo abaixo. Faça o
// teste de mesa, ache o erro e conserte (continue usando while).
//
//   Saída esperada depois do conserto:
//   T1-A1 T1-A2 T1-A3 T1-A4
//   T2-A1 T2-A2 T2-A3 T2-A4
//   T3-A1 T3-A2 T3-A3 T3-A4
//
// Dicas:
// 1. Quanto vale aluno quando a turma 2 começa?
// 2. Com for, o "aluno = 1" fica no cabeçalho do laço de dentro e roda toda
//    vez. Com while, você precisa fazer isso à mão.
// 3. Resposta esperada: aluno nunca volta para 1. Depois da turma 1 ele vale
//    5, e o while de dentro não roda mais. Conserto: "aluno = 1;" dentro do
//    while de fora, logo antes do while de dentro.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int turma = 1;
    int aluno = 1;

    while (turma <= 3) {
        while (aluno <= 4) {
            printf("T%d-A%d ", turma, aluno);
            aluno++;
        }
        printf("\n");
        turma++;
    }
    return 0;
}

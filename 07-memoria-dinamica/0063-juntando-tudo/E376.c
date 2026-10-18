// 0063 · Juntando tudo
// Exercício E376 · ★★☆
//
// Leia a quantidade de alunos e de provas e depois as notas, linha por
// linha. Guarde numa matriz dinâmica de double (vetor de ponteiros) e
// mostre a média de cada aluno e a da turma. As médias de cada aluno também
// vão para um vetor alocado.
//
//   Exemplo de uso:
//   Alunos e provas: 3 2
//   Notas do aluno 1: 7 8
//   Notas do aluno 2: 5 6
//   Notas do aluno 3: 9 10
//   Aluno 1: 7.5
//   Aluno 2: 5.5
//   Aluno 3: 9.5
//   Turma: 7.5
//
// Para testar: printf '3 2\n7 8\n5 6\n9 10\n' | ~/LPEDC/rodar <este arquivo>
//
// Dicas:
// 1. double **notas = malloc(alunos * sizeof *notas); e uma linha de
//    provas doubles para cada aluno.
// 2. double *medias = malloc(alunos * sizeof *medias);
// 3. Resposta esperada: a saída acima. São alunos + 2 malloc (3 linhas, o
//    vetor de linhas e as médias) e o mesmo número de free.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

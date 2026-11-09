// Lista · Módulo 13 · Busca e ordenação
// Exercício P1315 · ★★☆ · Quem ordena sem bagunçar os empates
//
// A lista da escola está em ordem alfabética: Ana (turma 2), Beto (1),
// Caio (2), Duda (1), Eva (3), Fabio (2). A secretaria quer por turma,
// mantendo a ordem alfabética dentro de cada turma, ou seja, uma ordenação
// ESTÁVEL.
//
// Escreva selection(Aluno v[], int n) e insertion(Aluno v[], int n), as duas
// ordenando pelo campo turma (o selection troca o menor com v[i]; o insertion
// usa > no while). Ordene duas cópias da lista e mostre as duas.
//
//   typedef struct { char nome[10]; int turma; } Aluno;
//
//   Saída esperada:
//   selection: Beto(1) Duda(1) Caio(2) Ana(2) Fabio(2) Eva(3)
//   insertion: Beto(1) Duda(1) Ana(2) Caio(2) Fabio(2) Eva(3)
//
// Dicas:
// 1. Struct se copia com =, então dá para trocar com Aluno t = v[i]; ...
// 2. Faça o selection à mão: na passada 1 o Duda troca com a Ana, e a Ana
//    vai parar DEPOIS do Caio. É a troca à distância que quebra a
//    estabilidade.
// 3. O insertion só move um elemento por cima de vizinhos MAIORES; iguais
//    nunca passam um pelo outro.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    char nome[10];
    int turma;
} Aluno;

int main(void) {

    return 0;
}

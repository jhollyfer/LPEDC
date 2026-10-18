// 0066 · Vetor de structs
// Exercício E392 · ★☆☆
//
// Complete o programa: falta o laço que calcula a média de cada aluno
// (média simples das duas provas), mostra se passou (média >= 7) e conta os
// aprovados.
//
//   Saída esperada:
//   Caio: 8.0 aprovado
//   Duda: 5.5 reprovado
//   Enzo: 7.0 aprovado
//   Lara: 6.8 reprovado
//   Aprovados: 2 de 4
//
// Dicas:
// 1. A média do aluno i é (turma[i].p1 + turma[i].p2) / 2.
// 2. %.1f mostra uma casa: (6.0 + 7.5) / 2 = 6.75 aparece como 6.8.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

typedef struct {
    char nome[20];
    double p1;
    double p2;
} Aluno;

int main(void) {
    Aluno turma[] = {
        {"Caio", 7.5, 8.5},
        {"Duda", 6.0, 5.0},
        {"Enzo", 7.0, 7.0},
        {"Lara", 6.0, 7.5},
    };
    int n = sizeof turma / sizeof turma[0];
    int aprovados = 0;

    // seu laço aqui

    printf("Aprovados: %d de %d\n", aprovados, n);
    return 0;
}

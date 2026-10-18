// 0066 · Vetor de structs
// Exercício E392 · ★☆☆

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

    for (int i = 0; i < n; i++) {
        double media = (turma[i].p1 + turma[i].p2) / 2;
        if (media >= 7) {
            aprovados++;
        }
        printf("%s: %.1f %s\n", turma[i].nome, media, media >= 7 ? "aprovado" : "reprovado");
    }

    printf("Aprovados: %d de %d\n", aprovados, n);
    return 0;
}

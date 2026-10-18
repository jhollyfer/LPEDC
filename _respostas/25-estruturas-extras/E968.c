// 0162 · Matriz esparsa
// Exercício E968 · ★☆☆

#include <stdio.h>

typedef struct {
    int lin, col, horas;
} Tripla;

int valor(const Tripla t[], int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        if (t[k].lin == i && t[k].col == j) {
            return t[k].horas;
        }
    }
    return 0; // não está nas triplas: vaga livre
}

int main(void) {
    const Tripla vagas[] = {{0, 2, 2}, {1, 0, 5}, {1, 4, 1}, {3, 1, 3}, {3, 5, 4}};
    int n = 5;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%3d", valor(vagas, n, i, j));
        }
        printf("\n");
    }

    int total = 0;
    for (int k = 0; k < n; k++) {
        total += vagas[k].horas;
    }
    printf("Total: %d horas em %d vagas ocupadas\n", total, n);
    return 0;
}

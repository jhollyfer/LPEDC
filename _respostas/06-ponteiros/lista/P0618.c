// Lista · Módulo 06 · Ponteiros
// Exercício P0618 · ★★☆ · Ponteiro para uma linha inteira

#include <stdio.h>

void medias(int (*linha)[4], int n, double *saida) {
    for (int i = 0; i < n; i++) {
        int soma = 0;
        for (int j = 0; j < 4; j++) {
            soma += (*linha)[j];
        }
        saida[i] = soma / 4.0;
        linha++; // pula uma linha inteira (4 int)
    }
}

int main(void) {
    int notas[3][4] = {{7, 8, 6, 9}, {5, 6, 7, 4}, {10, 9, 9, 8}};
    double m[3];

    medias(notas, 3, m);
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: %.2f\n", i + 1, m[i]);
    }
    int (*p)[4] = notas;
    printf("sizeof *p = %zu bytes\n", sizeof *p);
    printf("notas + 1 fica %d bytes depois de notas\n", (int) ((char *) (notas + 1) - (char *) notas));
    return 0;
}

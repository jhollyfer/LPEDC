// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1916 · ★★☆ · Pacotes de pão de queijo

#include <stdio.h>

#define T 3
#define PAES 15

const int pacote[T] = {3, 4, 5};
int usados[PAES], nu = 0;
int total = 0;

void escolhe(int menor, int falta) {
    if (falta == 0) {
        total++;
        for (int i = 0; i < nu; i++) {
            printf("%s%d", i ? " + " : "", usados[i]);
        }
        printf("\n");
        return;
    }
    for (int j = menor; j < T; j++) {
        if (pacote[j] > falta) {
            break;
        }
        usados[nu++] = pacote[j];
        escolhe(j, falta - pacote[j]);
        nu--;
    }
}

int main(void) {
    escolhe(0, PAES);
    printf("Total: %d jeitos\n", total);
    return 0;
}

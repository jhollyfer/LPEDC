// Lista · Módulo 06 · Ponteiros
// Exercício P0612 · ★★☆ · O qsort numa matriz de char

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(const void *a, const void *b) {
    // cada elemento é uma linha char[20]: o endereço dela é o da string
    return strcmp((const char *) a, (const char *) b);
}

int main(void) {
    char bairros[6][20] = {"Flores", "Adrianopolis", "Compensa",
                           "Aleixo", "Educandos", "Cachoeirinha"};

    qsort(bairros, 6, sizeof bairros[0], compara);
    for (int i = 0; i < 6; i++) {
        printf("%d. %s\n", i + 1, bairros[i]);
    }
    printf("Cada elemento tem %zu bytes\n", sizeof bairros[0]);
    return 0;
}

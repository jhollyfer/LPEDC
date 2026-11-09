// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0915 · ★★☆ · A média com modo detalhado

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    bool verboso = argc >= 2 && strcmp(argv[1], "-v") == 0;
    int primeira = verboso ? 2 : 1;
    int n = argc - primeira;
    if (n < 1) {
        printf("uso: P0915 [-v] nota1 nota2 ...\n");
        return 1;
    }
    double soma = 0;
    for (int i = primeira; i < argc; i++) {
        double nota = atof(argv[i]);
        if (verboso) {
            printf("nota %d: %.1f\n", i - primeira + 1, nota);
        }
        soma += nota;
    }
    printf("Média: %.2f\n", soma / n);
    return 0;
}

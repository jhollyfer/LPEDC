// 0069 · Argumentos da linha de comando
// Exercício E412 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <nome> <vezes>\n", argv[0]);
        return 1;
    }
    char *nome = argv[1];
    char *fim;
    long vezes = strtol(argv[2], &fim, 10);
    if (*fim != '\0' || vezes <= 0) {
        fprintf(stderr, "Uso: %s <nome> <vezes>  (vezes inteiro positivo)\n", argv[0]);
        return 1;
    }

    for (long i = 0; i < vezes; i++) {
        printf("Olá, %s!\n", nome);
    }
    return 0;
}

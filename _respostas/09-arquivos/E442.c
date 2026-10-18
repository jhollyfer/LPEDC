// 0074 · Argumentos da linha de comando
// Exercício E442 · ★★☆
//
// Resposta: a) argv[0] é o caminho do programa; o nome está em argv[1] e as
// vezes em argv[2]. Com o índice errado, atoi("Ana") dava 0 e o laço não
// rodava. b) Sem argumentos, argv[1] é NULL e atoi(NULL) derruba o programa:
// confira argc antes de tocar no argv.

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

// A138 · O que chega no argv

#include <stdio.h>
#include <string.h>

// Rode assim:  ~/LPEDC/rodar 09-arquivos/0069-argumentos/A138.c 10 -v "São Paulo" 3.5
int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);
    // argv[0] é o caminho do executável; os seus argumentos começam no 1
    for (int i = 1; i < argc; i++) {
        printf("argv[%d] = \"%s\" (%zu bytes)", i, argv[i], strlen(argv[i]));
        if (argv[i][0] == '-') {
            printf("  <- parece uma opção");
        }
        printf("\n");
    }
    // o vetor termina com um ponteiro NULL, como uma string termina em '\0'
    printf("argv[%d] é %s\n", argc, argv[argc] == NULL ? "NULL" : "outra coisa");
    return 0;
}
// $ rodar A138.c 10 -v "São Paulo" 3.5
// argc = 5
// argv[1] = "10" (2 bytes)
// argv[2] = "-v" (2 bytes)  <- parece uma opção
// argv[3] = "São Paulo" (10 bytes)
// argv[4] = "3.5" (3 bytes)
// argv[5] é NULL

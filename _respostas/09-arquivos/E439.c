// 0074 · Argumentos da linha de comando
// Exercício E439 · ★☆☆

#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%s", argv[i]);
    }
    if (argc > 1) {
        printf("\n");
    }
    printf("%d argumentos\n", argc - 1);
    return 0;
}

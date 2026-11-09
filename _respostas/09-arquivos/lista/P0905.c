// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0905 · ★☆☆ · A cidade de nome mais comprido

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("uso: P0905 cidade1 cidade2 ...\n");
        return 1;
    }
    int maior = 1;
    for (int i = 2; i < argc; i++) {
        if (strlen(argv[i]) > strlen(argv[maior])) {
            maior = i;
        }
    }
    printf("%d cidades\n", argc - 1);
    printf("Maior nome: %s (%zu letras)\n", argv[maior], strlen(argv[maior]));
    return 0;
}

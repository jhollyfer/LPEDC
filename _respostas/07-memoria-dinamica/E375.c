// 0063 · Juntando tudo
// Exercício E375 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void liberar(char **v, int n) {
    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
}

int main(void) {
    int cap = 1;
    int qtd = 0;
    int cresceu = 0;
    char **frutas = malloc(cap * sizeof *frutas);
    if (frutas == NULL) {
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof buffer, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "fim") == 0) {
            break;
        }
        if (qtd == cap) {
            char **maior = realloc(frutas, 2 * cap * sizeof *frutas);
            if (maior == NULL) {
                liberar(frutas, qtd);
                return 1;
            }
            frutas = maior;
            cap *= 2;
            cresceu++;
        }
        frutas[qtd] = malloc(strlen(buffer) + 1);
        if (frutas[qtd] == NULL) {
            liberar(frutas, qtd);
            return 1;
        }
        strcpy(frutas[qtd], buffer);
        qtd++;
    }

    printf("Ao contrário:");
    for (int i = qtd - 1; i >= 0; i--) {
        printf(" %s", frutas[i]);
    }
    printf("\nO vetor cresceu %d vezes\n", cresceu);
    liberar(frutas, qtd);
    return 0;
}
// Exemplo de uso:
// uva
// manga
// caju
// acerola
// fim
// Ao contrário: acerola caju manga uva
// O vetor cresceu 2 vezes

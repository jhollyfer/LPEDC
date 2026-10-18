// 0042 · Lendo strings
// Exercício E248 · ★☆☆
//
// Resposta: [Maria] [Clar] [a Souza]. O 1º %s lê "Maria" e para no espaço.
// O %4s pula o espaço e lê só 4 caracteres: "Clar". O fgets pega o resto da
// linha a partir dali, "a Souza\n", e o strcspn tira o '\n'.

#include <stdio.h>
#include <string.h>

int main(void) {
    char a[20], b[20], resto[20];

    if (scanf("%19s", a) != 1 || scanf("%4s", b) != 1) {
        return 1;
    }
    if (fgets(resto, sizeof(resto), stdin) == NULL) {
        return 1;
    }
    resto[strcspn(resto, "\n")] = '\0';

    printf("[%s] [%s] [%s]\n", a, b, resto);
    return 0;
}

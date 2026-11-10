// 0059 · Struct
// Exercício E352 · ★★☆

#include <stdio.h>
#include <string.h>

struct jogadora {
    char nome[20];
    int gols;
};

int main(void) {
    struct jogadora a, b;

    strcpy(a.nome, "Marta");
    a.gols = 17;
    b = a;

    printf("%s: %d gols\n", b.nome, b.gols);
    if (strcmp(a.nome, b.nome) == 0 && a.gols == b.gols) {
        printf("a e b são iguais\n");
    }
    return 0;
}

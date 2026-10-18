// 0064 · Struct
// Exercício E382 · ★★☆
//
// Resposta: (1) faltava ; depois da } da struct; (2) a.nome = "Marta" não
// compila porque nome é vetor: use strcpy; (3) a == b não existe para
// struct: compare campo a campo.

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

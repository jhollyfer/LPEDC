// A118 · A ficha copiada

#include <stdio.h>
#include <string.h>

struct endereco {
    char cidade[20];
    char uf[3];
};

// uma struct pode ter outra struct dentro (struct aninhada)
struct cliente {
    char nome[20];
    int pontos;
    struct endereco end;
};

int main(void) {
    // inicialização com nomes de campo (C99): a ordem não importa
    struct cliente ana = {
        .nome = "Ana",
        .pontos = 120,
        .end = {.cidade = "Recife", .uf = "PE"},
    };

    struct cliente copia = ana; // copia TODOS os bytes, inclusive os vetores
    strcpy(copia.nome, "Bia");  // campo vetor: strcpy, não =
    copia.pontos = 0;
    strcpy(copia.end.cidade, "Natal"); // ponto encadeado: copia.end.cidade

    printf("%s, %d pontos, %s-%s\n", ana.nome, ana.pontos, ana.end.cidade, ana.end.uf);
    printf("%s, %d pontos, %s-%s\n", copia.nome, copia.pontos, copia.end.cidade, copia.end.uf);
    return 0;
}
// Saída:
// Ana, 120 pontos, Recife-PE
// Bia, 0 pontos, Natal-PE

// 0062 · Ponteiro para struct
// Exercício E372 · ★★★
//
// Resposta: Caio (o amigo de Ana); Bia (o amigo do amigo de Ana); 25 (p + 1
// é g[1], a Bia); "Bia 30" (depois de p++, p é a Bia, e o amigo dela é a
// Ana); A (primeira letra do nome da amiga da Bia); 24 (o tamanho de uma
// Pessoa: 10 + 2 de sobra + 4 + 8).

#include <stdio.h>

typedef struct Pessoa {
    char nome[10];
    int idade;
    struct Pessoa *amigo;
} Pessoa;

int main(void) {
    Pessoa g[3] = {{"Ana", 30, NULL}, {"Bia", 25, NULL}, {"Caio", 41, NULL}};
    g[0].amigo = &g[2];
    g[1].amigo = &g[0];
    g[2].amigo = &g[1];

    Pessoa *p = g;
    printf("%s\n", p->amigo->nome);
    printf("%s\n", p->amigo->amigo->nome);
    printf("%d\n", (p + 1)->idade);
    p++;
    printf("%s %d\n", p->nome, p->amigo->idade);
    printf("%c\n", (*p->amigo).nome[0]);
    printf("%td\n", (char *)(p + 1) - (char *)p);
    return 0;
}

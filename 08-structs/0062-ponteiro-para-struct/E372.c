// 0062 · Ponteiro para struct
// Exercício E372 · ★★★
//
// Uma struct pode ter um ponteiro para outra struct do mesmo tipo (é a base
// das listas encadeadas do módulo 11). Para isso, ela precisa de nome:
// dentro dela, o apelido do typedef ainda não existe. Preveja cada linha:
//
//   typedef struct Pessoa {
//       char nome[10];
//       int idade;
//       struct Pessoa *amigo;
//   } Pessoa;
//
//   Pessoa g[3] = {{"Ana", 30, NULL}, {"Bia", 25, NULL}, {"Caio", 41, NULL}};
//   g[0].amigo = &g[2];
//   g[1].amigo = &g[0];
//   g[2].amigo = &g[1];
//
//   Pessoa *p = g;
//   printf("%s\n", p->amigo->nome);
//   printf("%s\n", p->amigo->amigo->nome);
//   printf("%d\n", (p + 1)->idade);
//   p++;
//   printf("%s %d\n", p->nome, p->amigo->idade);
//   printf("%c\n", (*p->amigo).nome[0]);
//   printf("%td\n", (char *)(p + 1) - (char *)p);
//
// Dicas:
// 1. Desenhe os três quadrados e as setas dos amigos: Ana -> Caio -> Bia -> Ana.
// 2. p + 1 anda um elemento inteiro (uma Pessoa), não um byte.
// 3. A última linha mede, em bytes, o tamanho de uma Pessoa: nome (10), 2 de
//    sobra, idade (4), amigo (8, um ponteiro em 64 bits).
// 4. Resposta esperada: Caio; Bia; 25; "Bia 30"; A; 24.
//
// Escreva sua resposta abaixo (como comentário; depois cole o código no main
// e confira):

#include <stdio.h>

int main(void) {

    return 0;
}

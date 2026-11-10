// 0150 · Componentes e ciclos
// Exercício E900 · ★★★
//
// O restaurante tem dois turnos, A e B, e oito funcionários. Alguns pares
// não podem trabalhar juntos (conflito, de mão dupla). Escreva a função
// divide(): ela põe cada pessoa num turno de modo que todo par em conflito
// fique em turnos diferentes, e mostra os dois turnos; se for impossível,
// mostra o primeiro par que cairia junto.
//
// Use uma DFS que pinta: quem começa uma DFS nova vai para o turno A, e
// cada vizinho recebe o turno oposto ao de quem o descobriu. Examine os
// vizinhos em ordem de índice.
//
//   Saída esperada:
//   Turno A: Ana Caio Enzo Gui
//   Turno B: Bia Duda Flor Hana
//   Impossível: Caio e Ana cairiam no mesmo turno
//
// Escreva sua resposta abaixo (escreva divide e o que mais precisar):

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *nomes[V] = {"Ana", "Bia", "Caio", "Duda", "Enzo", "Flor", "Gui", "Hana"};
int conflito[V][V];

void divide(void) {
}

void liga(int a, int b) {
    conflito[a][b] = 1;
    conflito[b][a] = 1;
}

int main(void) {
    int pares[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {6, 7}, {5, 6}};
    for (int k = 0; k < 7; k++) liga(pares[k][0], pares[k][1]);
    divide();

    liga(0, 2); // Ana e Caio brigaram também
    divide();
    return 0;
}

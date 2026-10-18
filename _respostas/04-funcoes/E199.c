// 0034 · Parâmetros e passagem por valor
// Exercício E199 · ★☆☆
//
// Resposta: dentro: 300 / main: 150 / dentro: 300 / main: 300. Na primeira
// chamada a função dobra a cópia e o retorno é jogado fora; na segunda, o main
// guarda o retorno na própria variável.

#include <stdio.h>

int dobrar_pontos(int pontos) {
    pontos = pontos * 2;
    printf("dentro: %d\n", pontos);
    return pontos;
}

int main(void) {
    int pontos = 150;
    dobrar_pontos(pontos);
    printf("main: %d\n", pontos);
    pontos = dobrar_pontos(pontos);
    printf("main: %d\n", pontos);
    return 0;
}

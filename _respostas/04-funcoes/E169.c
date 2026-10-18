// 0029 · Parâmetros e passagem por valor
// Exercício E169 · ★☆☆

#include <stdio.h>

int dobrar_pontos(int pontos) {
    pontos = pontos * 2; // muda só a cópia
    printf("dentro: %d\n", pontos);
    return pontos;
}

int main(void) {
    int pontos = 150;

    dobrar_pontos(pontos); // o retorno é jogado fora
    printf("main: %d\n", pontos);

    pontos = dobrar_pontos(pontos); // agora o retorno é guardado
    printf("main: %d\n", pontos);
    return 0;
}

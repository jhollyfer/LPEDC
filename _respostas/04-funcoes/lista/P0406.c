// Lista · Módulo 04 · Funções e modularização
// Exercício P0406 · ★☆☆ · O recorde do fliperama

#include <stdio.h>

int recorde(int pontos) {
    static int melhor = 0; // vive o programa inteiro, mas só a função enxerga
    if (pontos > melhor) {
        melhor = pontos;
    }
    return melhor;
}

int main(void) {
    printf("Partida com 1200 -> recorde %d\n", recorde(1200));
    printf("Partida com 3400 -> recorde %d\n", recorde(3400));
    printf("Partida com 2100 -> recorde %d\n", recorde(2100));
    printf("Partida com 5000 -> recorde %d\n", recorde(5000));
    return 0;
}

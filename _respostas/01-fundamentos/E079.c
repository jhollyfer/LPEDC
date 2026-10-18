// 0014 · Atribuição, ++ e --
// Exercício E079 · ★☆☆

#include <stdio.h>

int main(void) {
    int pontos = 100, vidas = 3, moedas = 20, tempo = 90, fase = 3;

    pontos += 10;
    vidas--;
    moedas *= 2;
    tempo /= 2;
    fase++;

    printf("pontos %d, vidas %d, moedas %d, tempo %d, fase %d\n",
           pontos, vidas, moedas, tempo, fase);
    return 0;
}

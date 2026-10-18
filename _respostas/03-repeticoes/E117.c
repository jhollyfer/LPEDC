// 0020 · While
// Exercício E117 · ★★☆
//
// Resposta: o laço perguntava "ainda tem água?" (litros > 0) e deixava gastar
// 180 litros no 6º dia, quando só havia 100. A pergunta certa é "tem água para
// mais um dia inteiro?".

#include <stdio.h>

int main(void) {
    int litros = 1000;
    int consumo = 180;
    int dias = 0;

    while (litros >= consumo) {
        litros = litros - consumo;
        dias++;
    }
    printf("Dá para %d dias. Sobram %d litros.\n", dias, litros);
    return 0;
}

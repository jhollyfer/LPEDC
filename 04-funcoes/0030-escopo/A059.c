// A059 · A função que lembra o recorde

#include <stdbool.h>
#include <stdio.h>

// devolve true quando a temperatura bate o recorde do dia
bool novo_recorde(int temperatura) {
    static bool primeira = true; // true só até a primeira chamada
    static int recorde = 0;      // o maior valor visto até agora

    if (primeira || temperatura > recorde) {
        primeira = false;
        recorde = temperatura;
        return true;
    }
    return false;
}

void leitura(int hora, int temperatura) {
    printf("%2dh: %d °C", hora, temperatura);
    if (novo_recorde(temperatura)) {
        printf(" (recorde!)");
    }
    printf("\n");
}

int main(void) {
    leitura(6, 19);  // a primeira leitura é sempre recorde
    leitura(9, 24);
    leitura(12, 22); // 22 < 24: a static lembra do 24
    leitura(15, 30);
    leitura(18, 27);
    // printf("%d\n", recorde); // erro: recorde só existe dentro da função
    return 0;
}
// Saída:
//  6h: 19 °C (recorde!)
//  9h: 24 °C (recorde!)
// 12h: 22 °C
// 15h: 30 °C (recorde!)
// 18h: 27 °C

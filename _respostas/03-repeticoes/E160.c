// 0027 · For
// Exercício E160 · ★★☆
//
// Resposta: o ";" logo depois do for vira o corpo do laço (vazio). O laço gira
// 5 vezes sem fazer nada, i termina em 6 e o bloco { } roda uma vez só,
// depois. Tirando o ";", mostra Série 1 a Série 5.

#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 5; i++) {
        printf("Série %d\n", i);
    }
    return 0;
}

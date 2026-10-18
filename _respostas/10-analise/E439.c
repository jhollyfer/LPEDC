// 0074 · TAD: interface (.h) e implementação (.c)
// Exercício E439 · ★☆☆
//
// Resposta: Subiram 4, ficaram no ponto 2; depois 1 a bordo; na garagem, 0.
// (O contador.h e o contador.c desta pasta são cópias dos de
// 10-analise/0074-tad/, para a resolução compilar com o rodar.)

#include <stdio.h>

#include "contador.h"

int main(void) {
    Contador *van = contador_cria(4);
    if (van == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    int ficaram = 0;
    for (int aluno = 0; aluno < 6; aluno++) {
        if (!contador_incrementa(van)) {
            ficaram++;
        }
    }
    printf("Subiram %d, ficaram no ponto %d\n", contador_valor(van), ficaram);

    for (int i = 0; i < 3; i++) {
        contador_decrementa(van);
    }
    printf("Depois de descerem 3: %d a bordo\n", contador_valor(van));

    contador_zera(van);
    printf("Na garagem: %d a bordo\n", contador_valor(van));
    contador_libera(van);
    return 0;
}

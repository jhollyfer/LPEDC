// 0037 · Vetores
// Exercício E221 · ★★★
//
// Resposta: o laço usa i <= 6 e lê temps[6], que não existe (troque por
// i < 6); e maior começa em 0, que nenhuma temperatura supera, então a máxima
// sairia 0 (comece maior e menor com temps[0]).

#include <stdio.h>

int main(void) {
    int temps[6] = {-2, -6, -1, -4, -3, -5};
    int maior = temps[0];
    int menor = temps[0];

    for (int i = 0; i < 6; i++) {
        if (temps[i] > maior) {
            maior = temps[i];
        }
        if (temps[i] < menor) {
            menor = temps[i];
        }
    }

    printf("Máxima: %d graus\n", maior);
    printf("Mínima: %d graus\n", menor);
    return 0;
}

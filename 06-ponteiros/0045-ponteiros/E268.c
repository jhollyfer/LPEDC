// 0045 · Ponteiros
// Exercício E268 · ★★☆
//
// No check-in do aeroporto, a companhia aceita uma mala de até 23 kg sem
// cobrar. Você tem duas malas: mala_azul com 19 kg e mala_preta com 26 kg.
// Complete o programa: faça o ponteiro pesada apontar para a mala mais
// pesada e, usando só o ponteiro, tire 4 kg dela (você passou umas roupas
// para a mochila). Depois mostre as duas malas.
//
//   Saída esperada:
//   Mais pesada: 26 kg
//   Depois de tirar 4 kg: azul 19 kg, preta 22 kg
//
// Dicas:
// 1. Use um if para escolher: pesada = &mala_azul ou pesada = &mala_preta.
// 2. Para tirar 4 kg pelo ponteiro: *pesada -= 4;
// 3. Resposta esperada: a preta é a mais pesada (26); vira 22 e a azul
//    continua 19.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int mala_azul = 19, mala_preta = 26;
    int *pesada = NULL;

    // 1. faça pesada apontar para a mala mais pesada

    // 2. mostre "Mais pesada: ... kg" usando o ponteiro

    // 3. tire 4 kg usando o ponteiro

    if (pesada == NULL) {
        printf("pesada ainda não aponta para nenhuma mala\n");
    }

    printf("Depois de tirar 4 kg: azul %d kg, preta %d kg\n", mala_azul, mala_preta);
    return 0;
}

// 0046 · Passagem por referência
// Exercício E274 · ★★☆
//
// Resposta: *contador++ andava com o ponteiro em vez de somar no valor:
// o certo é (*contador)++. E zera recebia uma cópia: precisa receber int *
// e ser chamada com &avulsos.

#include <stdio.h>

void passa(int *contador) {
    (*contador)++;
}

void zera(int *valor) {
    *valor = 0;
}

int main(void) {
    int passageiros = 0, avulsos = 5;

    passa(&passageiros);
    passa(&passageiros);
    passa(&passageiros);
    zera(&avulsos);

    printf("Passageiros: %d\n", passageiros);
    printf("Bilhetes avulsos: %d\n", avulsos);
    return 0;
}

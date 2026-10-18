// 0051 · Passagem por referência
// Exercício E304 · ★★☆
//
// A catraca do metrô conta passageiros, e este programa tem DOIS erros de
// propósito. Ele deveria mostrar:
//
//   Passageiros: 3
//   Bilhetes avulsos: 0
//
// mas mostra outra coisa. Rode, leia o aviso do compilador e descubra os
// dois erros. Conserte sem mudar o main (exceto se precisar acrescentar um
// & numa chamada).
//
// Dicas:
// 1. Em *contador++, o ++ age antes do *: ele anda com o ponteiro, não
//    soma no valor.
// 2. Uma função que recebe int recebe uma cópia.
// 3. Resposta esperada: (1) *contador++ vira (*contador)++ (ou
//    *contador += 1); o aviso era "value computed is not used";
//    (2) zera recebe uma cópia: mude para void zera(int *valor) com
//    *valor = 0 e chame zera(&avulsos).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void passa(int *contador) {
    *contador++;
}

void zera(int valor) {
    valor = 0;
}

int main(void) {
    int passageiros = 0, avulsos = 5;

    passa(&passageiros);
    passa(&passageiros);
    passa(&passageiros);
    zera(avulsos);

    printf("Passageiros: %d\n", passageiros);
    printf("Bilhetes avulsos: %d\n", avulsos);
    return 0;
}

// 0010 · math.h
// Exercício E059 · ★★★
//
// Três contas, três erros. O programa compila com um aviso e mostra três
// valores errados. Explique cada erro e conserte.
//
// - A caixa d'água em forma de cubo tem 27 m³. Qual a aresta? (3 m)
// - O termômetro marcou -2.75 °C. Quanto falta para chegar a 0? (2.75)
// - São 7 convidados e 2 por mesa. Quantas mesas? (4)
//
//   Saída esperada (depois de consertar):
//   Aresta: 3.00 m
//   Faltam 2.75 graus
//   Mesas: 4
//
// Dicas:
// 1. Calcule 1/3 e 7/2 sabendo que os dois lados são int.
// 2. Procure "abs" no aviso do gcc.
// 3. Resposta esperada: pow(27, 1/3) dá 1, porque 1/3 é 0: use 1.0 / 3.
//    abs é a versão para int (do stdlib.h) e corta para 2: use fabs.
//    ceil(7 / 2) recebe 3, já cortado: use ceil(7 / 2.0), que dá 4.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double aresta = pow(27, 1 / 3);
    double falta = abs(-2.75);
    double mesas = ceil(7 / 2);

    printf("Aresta: %.2f m\n", aresta);
    printf("Faltam %.2f graus\n", falta);
    printf("Mesas: %.0f\n", mesas);
    return 0;
}

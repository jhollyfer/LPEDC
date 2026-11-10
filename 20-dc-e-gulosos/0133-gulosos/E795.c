// 0133 · Algoritmos gulosos
// Exercício E795 · ★★☆
//
// Numa enchente, cada barco de resgate leva no máximo 2 pessoas e no máximo
// 150 kg. Os pesos das 8 pessoas a resgatar, em kg:
//
//   60 95 80 120 45 70 100 55
//
// Use o menor número de barcos com este guloso: ordene os pesos; a pessoa
// mais pesada que falta SEMPRE vai no próximo barco; se a mais leve que
// falta couber junto, vai junto. Mostre cada barco (o mais pesado primeiro)
// e o total.
//
//   Saída esperada:
//   Barco 1: 120
//   Barco 2: 100 + 45
//   Barco 3: 95 + 55
//   Barco 4: 80 + 60
//   Barco 5: 70
//   Total: 5 barcos
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int peso[] = {60, 95, 80, 120, 45, 70, 100, 55};
    int n = 8;
    int limite = 150;
    (void)peso;
    (void)n;
    (void)limite;

    return 0;
}

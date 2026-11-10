// Lista · Módulo 03 · Laços
// Exercício P0310 · ★☆☆ · A parcela que sobrou
//
// A geladeira foi parcelada em 10 vezes de R$ 189.90, mas o programa abaixo
// mostra 11 parcelas e um total errado. O erro está no for, de propósito.
// Conserte o laço para mostrar as 10 parcelas e o total certo:
//
//   Saída esperada:
//   Parcela 1: R$ 189.90
//   Parcela 2: R$ 189.90
//   Parcela 3: R$ 189.90
//   Parcela 4: R$ 189.90
//   Parcela 5: R$ 189.90
//   Parcela 6: R$ 189.90
//   Parcela 7: R$ 189.90
//   Parcela 8: R$ 189.90
//   Parcela 9: R$ 189.90
//   Parcela 10: R$ 189.90
//   Total: R$ 1899.00
//
// Dicas:
// 1. Conte quantas voltas o for dá começando em 0 e indo até <= 10.
// 2. Ou começa em 1 e vai até <= 10, ou começa em 0 e vai até < 10. O número
//    mostrado tem que ir de 1 a 10.
// 3. Resposta esperada: 10 parcelas, Total: R$ 1899.00.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    double parcela = 189.90;
    double total = 0.0;

    for (int i = 0; i <= 10; i++) {
        printf("Parcela %d: R$ %.2f\n", i, parcela);
        total += parcela;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}

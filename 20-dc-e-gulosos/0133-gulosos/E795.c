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
// Dicas:
// 1. Ordene com qsort em ordem crescente e use dois índices: leve = 0 e
//    pesado = n - 1. O laço vai enquanto leve <= pesado.
// 2. Se leve < pesado e a soma cabe, o leve vai junto (leve++). Em todo
//    caso, pesado-- e barcos++.
// 3. Resposta esperada: a saída acima. Por que dá certo: se o mais pesado
//    não cabe nem com o mais leve, não cabe com ninguém e precisa ir
//    sozinho; se cabe, pôr o mais leve com ele nunca piora o resto.
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

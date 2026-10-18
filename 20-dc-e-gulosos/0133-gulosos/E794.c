// 0133 · Algoritmos gulosos
// Exercício E794 · ★☆☆
//
// O guloso do texto dá as moedas uma por uma. Quando a moeda de 100 cabe
// várias vezes, dá para resolver de uma vez com divisão inteira: valor / 100
// diz quantas moedas de 100 saem, e valor % 100 diz quanto sobra. Complete o
// programa no lugar marcado com "COMPLETE AQUI", usando / e %, para o troco
// de 285 centavos. Mostre só as moedas que aparecem.
//
//   Saída esperada:
//   Troco de 285 centavos:
//     2 de 100
//     1 de 50
//     1 de 25
//     1 de 10
//   Total: 5 moedas
//
// Dicas:
// 1. Duas linhas fazem o trabalho: quantas = valor / moedas[i]; e
//    valor %= moedas[i]; (nesta ordem!).
// 2. Mostre a linha só se quantas > 0. Some quantas em total sempre.
// 3. Resposta esperada: a saída acima. A versão com / e % faz uma volta por
//    tipo de moeda, O(k), qualquer que seja o valor do troco.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int moedas[] = {100, 50, 25, 10, 5};
    int valor = 285; // centavos
    int total = 0;

    printf("Troco de %d centavos:\n", valor);
    for (int i = 0; i < 5; i++) {
        int quantas = 0;
        // COMPLETE AQUI
        (void)moedas;
        total += quantas;
    }
    printf("Total: %d moedas\n", total);
    return 0;
}

// 0133 · Algoritmos gulosos
// Exercício E796 · ★★☆
//
// O sistema da lanchonete lê as moedas de um arquivo de configuração, e elas
// chegam fora de ordem: {10, 50, 5, 100, 25}. A função troco_guloso é a do
// texto e está certa, mas o troco sai absurdo. Rode e veja:
//
//   Saída que aparece:
//   Troco de 190: 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 (19 moedas)
//   Troco de 65: 10 10 10 10 10 10 5 (7 moedas)
//
// Conserte sem mexer na função nem na linha que declara o vetor: antes das
// chamadas, ordene as moedas em ordem DECRESCENTE com qsort, escrevendo a
// função de comparação.
//
//   Saída esperada:
//   Troco de 190: 100 50 25 10 5 (5 moedas)
//   Troco de 65: 50 10 5 (3 moedas)
//
// Dicas:
// 1. A comparação recebe const void *. Converta: int x = *(const int *)a;
// 2. Para a ordem decrescente, devolva negativo quando x > y. A forma
//    (x < y) - (x > y) faz isso sem o risco de estouro de "y - x".
// 3. Resposta esperada: qsort(moedas, 5, sizeof moedas[0], decrescente);
//    e a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int troco_guloso(const int moedas[], int k, int valor) {
    int quantas = 0;
    int i = 0;
    printf("Troco de %d:", valor);
    while (valor > 0 && i < k) {
        if (moedas[i] <= valor) {
            printf(" %d", moedas[i]);
            valor -= moedas[i];
            quantas++;
        } else {
            i++;
        }
    }
    printf(" (%d moedas)\n", quantas);
    return quantas;
}

int main(void) {
    // as moedas chegaram do arquivo de configuração nesta ordem
    int moedas[] = {10, 50, 5, 100, 25};
    troco_guloso(moedas, 5, 190);
    troco_guloso(moedas, 5, 65);
    return 0;
}

// 0092 · Selection sort
// Exercício E548 · ★☆☆
//
// Cinco caixas de uma mudança estão numeradas fora de ordem: 3, 1, 2, 5, 4.
// O programa abaixo ordena com selection sort e conta as trocas. Estenda o
// programa:
//
// a) conte também as comparações (caixas[j] < caixas[menor]) e mostre o
//    total no fim;
// b) nas passadas em que o menor já estava no lugar (nenhuma troca), escreva
//    " (sem troca)" no fim da linha.
//
//   Saída esperada:
//   i = 0: 1 3 2 5 4
//   i = 1: 1 2 3 5 4
//   i = 2: 1 2 3 5 4 (sem troca)
//   i = 3: 1 2 3 4 5
//   trocas: 3
//   comparações: 10
//
// Dicas:
// 1. O contador de comparações sobe dentro do laço de dentro, uma vez por
//    volta.
// 2. "Sem troca" é exatamente quando menor == i depois do laço de dentro.
// 3. As comparações não dependem dos valores: 4 + 3 + 2 + 1 = 10.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (modifique o código):

#include <stdio.h>

int main(void) {
    int caixas[] = {3, 1, 2, 5, 4};
    int n = 5, trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (caixas[j] < caixas[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int aux = caixas[i];
            caixas[i] = caixas[menor];
            caixas[menor] = aux;
            trocas++;
        }
        printf("i = %d:", i);
        for (int k = 0; k < n; k++) {
            printf(" %d", caixas[k]);
        }
        printf("\n");
    }
    printf("trocas: %d\n", trocas);
    return 0;
}

// A107 · As corridas do mês

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quantas corridas? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade inválida\n");
        return 1;
    }

    // pede n * 8 bytes ao heap; o tamanho só é conhecido agora
    double *corridas = malloc(n * sizeof(double));
    if (corridas == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Valor da corrida %d: ", i + 1);
        if (scanf("%lf", &corridas[i]) != 1) { // usa como um vetor comum
            printf("Valor inválido\n");
            free(corridas);
            return 1;
        }
    }

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += corridas[i];
    }
    printf("Total: R$ %.2f\n", total);
    printf("Média: R$ %.2f\n", total / n);

    free(corridas);  // devolve os bytes ao heap
    corridas = NULL; // o ponteiro não aponta mais para lugar nenhum
    return 0;
}
// Exemplo de uso:
// Quantas corridas? 4
// Valor da corrida 1: 12.50
// Valor da corrida 2: 18
// Valor da corrida 3: 25.90
// Valor da corrida 4: 9.60
// Total: R$ 66.00
// Média: R$ 16.50
//
// Para testar sem digitar: printf '4\n12.50 18 25.90 9.60\n' | ~/LPEDC/rodar 07-memoria-dinamica/0054-malloc-free/A107.c

// 0052 · Ponteiros e vetores
// Exercício E310 · ★★☆
//
// O programa da sorveteria tem DOIS erros de propósito. A ideia era mudar o
// estoque do sabor de índice 3 para 20 e depois mostrar os 5 sabores:
//
//   Saída esperada:
//   12 8 15 20 9
//
// Rode com o rodar: um erro só aparece no resultado, o outro o
// AddressSanitizer denuncia. Explique cada um e conserte.
//
// Dicas:
// 1. Depois de p += 1, para onde p aponta? E p[3], então, é qual elemento?
// 2. Um vetor de 5 tem endereços válidos para leitura de estoque até
//    estoque + 4.
// 3. Resposta esperada: (1) com p em estoque[1], p[3] é estoque[4] (o
//    índice é relativo a p), e o 9 virou 20: o certo é p[2] = 20 (ou
//    estoque[3] = 20); (2) o laço vai até q <= estoque + 5 e lê uma gaveta
//    depois do fim (stack-buffer-overflow): o certo é q < estoque + 5.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int estoque[5] = {12, 8, 15, 4, 9};
    int *p = estoque;

    p += 1;
    p[3] = 20;

    for (int *q = estoque; q <= estoque + 5; q++) {
        printf("%d ", *q);
    }
    printf("\n");
    return 0;
}

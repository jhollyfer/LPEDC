// 0092 · Selection sort
// Exercício E548 · ★☆☆
//
// Cinco caixas de uma mudança estão numeradas fora de ordem: 3, 1, 2, 5, 4.
// SEM RODAR, escreva a saída exata do programa abaixo, incluindo o total de
// trocas. Depois rode e confira.
//
// Dicas:
// 1. Em cada passada i, ache o menor de v[i..4] e veja se ele já está em v[i].
// 2. Repare no if (menor != i): troca de alguém com ele mesmo não conta.
// 3. Resposta esperada: i = 0: 1 3 2 5 4; i = 1: 1 2 3 5 4; i = 2: 1 2 3 5
//    4; i = 3: 1 2 3 4 5; trocas: 3.
//
// Escreva sua resposta abaixo (como comentário):

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

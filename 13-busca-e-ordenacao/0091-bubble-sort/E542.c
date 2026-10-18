// 0091 · Bubble sort
// Exercício E542 · ★☆☆
//
// A fila do caixa preferencial tem senhas fora de ordem: 9, 4, 7, 1, 5. O
// programa abaixo ordena com bubble sort (sem bandeira) e mostra o vetor no
// fim de cada passada. SEM RODAR, escreva a saída exata, incluindo o total
// de trocas. Depois rode e confira.
//
// Dicas:
// 1. Na passada 1, o 9 ganha todas as comparações e vai para o fim.
// 2. Sem bandeira, o programa faz as 4 passadas mesmo se o vetor já estiver
//    ordenado antes.
// 3. Conte as inversões do vetor original: é o total de trocas.
// 4. Resposta esperada: passada 1: 4 7 1 5 9; passada 2: 4 1 5 7 9; passada
//    3: 1 4 5 7 9; passada 4: 1 4 5 7 9; trocas: 7 (as inversões: 9 com 4, 7, 1
//    e 5; 4 com 1; 7 com 1 e 5).
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {
    int senhas[] = {9, 4, 7, 1, 5};
    int n = 5, trocas = 0;

    for (int passada = 1; passada < n; passada++) {
        for (int j = 0; j < n - passada; j++) {
            if (senhas[j] > senhas[j + 1]) {
                int aux = senhas[j];
                senhas[j] = senhas[j + 1];
                senhas[j + 1] = aux;
                trocas++;
            }
        }
        printf("passada %d:", passada);
        for (int i = 0; i < n; i++) {
            printf(" %d", senhas[i]);
        }
        printf("\n");
    }
    printf("trocas: %d\n", trocas);
    return 0;
}

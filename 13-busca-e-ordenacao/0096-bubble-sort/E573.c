// 0096 · Bubble sort
// Exercício E573 · ★★☆
//
// Este bubble sort deveria ordenar as idades da turma de natação: 34, 19,
// 27, 45, 22. Ele tem DOIS erros, de propósito. Rode: o sanitizer
// ("runtime error: index 5 out of bounds") acusa um deles. Ache os dois, explique e conserte.
//
//   Saída esperada (depois de consertar):
//   19 22 27 34 45
//
// Dicas:
// 1. Na passada 1, qual o maior valor de j? E de j + 1?
// 2. Conserte o primeiro erro e rode de novo: alguma idade sumiu e outra
//    apareceu duas vezes?
// 3. Faça o teste de mesa da troca com idades[0] = 34 e idades[1] = 19.
// 4. Resposta esperada: o laço interno deve ser j < n - passada (com + 1, ele
//    lê idades[5], fora do vetor); e a troca precisa de uma variável
//    auxiliar: int aux = idades[j]; idades[j] = idades[j + 1];
//    idades[j + 1] = aux;
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int idades[] = {34, 19, 27, 45, 22};
    int n = 5;

    for (int passada = 1; passada < n; passada++) {
        for (int j = 0; j < n - passada + 1; j++) {
            if (idades[j] > idades[j + 1]) {
                idades[j] = idades[j + 1];
                idades[j + 1] = idades[j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", idades[i]);
    }
    printf("\n");
    return 0;
}

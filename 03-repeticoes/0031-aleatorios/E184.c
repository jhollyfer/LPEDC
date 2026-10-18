// 0031 · Aleatórios
// Exercício E184 · ★★☆
//
// O programa abaixo deveria sortear 10 lançamentos de um dado. Rode e repare:
// sai o mesmo número 10 vezes, e às vezes esse número é 0. São DOIS erros.
// O código com os erros está logo abaixo. Ache, explique e conserte.
//
// Dicas:
// 1. Quantas vezes o srand roda? E quanto vale time(NULL) nas 10 voltas, que
//    acontecem dentro do mesmo segundo?
// 2. Qual a faixa de rand() % 6?
// 3. Resposta esperada: (1) o srand(time(NULL)) está dentro do laço: a cada
//    volta a sequência recomeça com a mesma semente (o segundo atual) e o
//    rand devolve o mesmo primeiro número. O srand vai uma vez só, antes do
//    laço. (2) rand() % 6 vai de 0 a 5; o dado é 1 + rand() % 6.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    for (int i = 1; i <= 10; i++) {
        srand(time(NULL));
        int dado = rand() % 6;
        printf("%d ", dado);
    }
    printf("\n");
    return 0;
}

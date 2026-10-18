// 0026 · Aleatórios
// Exercício E154 · ★★☆
//
// Resposta: (1) o srand(time(NULL)) estava dentro do laço: a cada volta a
// sequência recomeçava com a mesma semente (o segundo atual) e o rand devolvia
// o mesmo primeiro número. O srand vai uma vez só, antes do laço.
// (2) rand() % 6 vai de 0 a 5; o dado é 1 + rand() % 6.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned) time(NULL));
    for (int i = 1; i <= 10; i++) {
        int dado = 1 + rand() % 6;
        printf("%d ", dado);
    }
    printf("\n");
    return 0;
}

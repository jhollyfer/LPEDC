// 0049 · Ponteiro para ponteiro
// Exercício E292 · ★★☆
//
// A função aponta_maior deveria fazer o ponteiro do main apontar para o
// maior lance do leilão. Mas o programa tem um erro de propósito: o
// ponteiro do main continua NULL e o programa cai. Rode, veja o relatório
// do AddressSanitizer e explique por que a função não funciona. Depois
// conserte (a função e a chamada).
//
//   Saída esperada:
//   Maior lance: R$ 870
//
// Dicas:
// 1. A função recebe int *res: uma CÓPIA do ponteiro do main.
// 2. Para mudar um int * de quem chamou, a função precisa de um int **.
// 3. Resposta esperada: res = ... muda só a cópia local; o vencedor do
//    main continua NULL e *vencedor desreferencia NULL (SEGV). Conserto:
//    void aponta_maior(int *a, int *b, int **res) com *res = ...; e a
//    chamada aponta_maior(&lance1, &lance2, &vencedor).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void aponta_maior(int *a, int *b, int *res) {
    if (*a > *b) {
        res = a;
    } else {
        res = b;
    }
}

int main(void) {
    int lance1 = 870, lance2 = 640;
    int *vencedor = NULL;

    aponta_maior(&lance1, &lance2, vencedor);
    printf("Maior lance: R$ %d\n", *vencedor);
    return 0;
}

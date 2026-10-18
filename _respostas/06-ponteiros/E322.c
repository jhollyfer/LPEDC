// 0054 · Ponteiro para ponteiro
// Exercício E322 · ★★☆
//
// Resposta: res era uma cópia do ponteiro do main; mudar res não muda
// vencedor, que continuava NULL (e *vencedor derrubava o programa). A
// função precisa receber o endereço do ponteiro: int **res.

#include <stdio.h>

void aponta_maior(int *a, int *b, int **res) {
    if (*a > *b) {
        *res = a;
    } else {
        *res = b;
    }
}

int main(void) {
    int lance1 = 870, lance2 = 640;
    int *vencedor = NULL;

    aponta_maior(&lance1, &lance2, &vencedor);
    printf("Maior lance: R$ %d\n", *vencedor);
    return 0;
}

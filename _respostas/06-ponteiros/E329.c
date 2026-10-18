// 0055 · Ponteiro para função
// Exercício E329 · ★★★
//
// Resposta: x - y estoura o int quando x = 2000000000 e y = -2000000000
// (o resultado, 4000000000, não cabe). O valor "dá a volta", fica negativo
// e o qsort entende que 2000000000 vem antes. A comparação só precisa do
// sinal: (x > y) - (x < y) devolve -1, 0 ou 1 sem fazer conta.

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int saldos[3] = {2000000000, -2000000000, 5};

    qsort(saldos, 3, sizeof saldos[0], compara);
    for (int i = 0; i < 3; i++) {
        printf("%d ", saldos[i]);
    }
    printf("\n");
    return 0;
}

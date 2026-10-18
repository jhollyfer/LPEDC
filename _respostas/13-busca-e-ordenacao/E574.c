// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E574 · ★★☆
//
// Resposta: x - y estoura o int quando os dois têm sinais opostos e são
// grandes. 2000000000 - (-1500000000) = 3500000000, que não cabe em int (o
// máximo é 2147483647): é overflow de inteiro com sinal, comportamento
// indefinido, e o UBSan acusa "signed integer overflow". Na prática o
// resultado "dá a volta" e vira negativo, então a compara responde que
// 2000000000 vem ANTES de -1500000000, e a ordem sai errada. Conserto: comparar
// sem fazer conta, com (x > y) - (x < y).

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    int x = *(const int *) a;
    int y = *(const int *) b;
    return (x > y) - (x < y);
}

int main(void) {
    int saldos[] = {2000000000, -1500000000, 15, -7, 1000000000};
    size_t n = sizeof saldos / sizeof saldos[0];

    qsort(saldos, n, sizeof saldos[0], compara);
    for (size_t i = 0; i < n; i++) {
        printf("%d\n", saldos[i]);
    }
    return 0;
}

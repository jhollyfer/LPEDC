// 0125 · Subconjuntos
// Exercício E749 · ★★★
//
// Resposta: m & (1 << i) vale 0 ou 1 << i (1, 2, 4, 8), e não 0 ou 1. O
// teste == 1 só reconhecia o bacon (bit 0). O certo é testar se o resultado
// é diferente de zero, nos dois lugares em que o bit é lido.

#include <stdio.h>

#define N 4

int main(void) {
    const char *nomes[N] = {"bacon", "cheddar", "catupiry", "cebola"};
    const int precos[N] = {6, 4, 5, 2};
    int conta = 0;

    for (int m = 0; m < (1 << N); m++) {
        int total = 0;
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) { // diferente de zero = bit ligado
                total += precos[i];
            }
        }
        if (total > 10) {
            continue;
        }
        conta++;
        printf("R$ %d:", total);
        if (m == 0) {
            printf(" nenhum");
        }
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) { // diferente de zero = bit ligado
                printf(" %s", nomes[i]);
            }
        }
        printf("\n");
    }
    printf("%d combinações até R$ 10\n", conta);
    return 0;
}

// A104 · O primeiro dia da meta

#include <stdio.h>

// devolve o endereço do primeiro elemento >= meta, ou NULL se não houver
const int *primeiro_acima(const int *v, int n, int meta) {
    for (const int *p = v; p < v + n; p++) {
        if (*p >= meta) {
            return p;
        }
    }
    return NULL;
}

int main(void) {
    int passos[7] = {6200, 8100, 10400, 7300, 12000, 9800, 11050};
    const int *achou = primeiro_acima(passos, 7, 10000);

    if (achou != NULL) {
        // ponteiro menos ponteiro = distância em ELEMENTOS, não em bytes;
        // o resultado é um ptrdiff_t, e o formato dele é %td
        printf("Meta batida no dia %td com %d passos\n", achou - passos + 1, *achou);
        if (achou > passos && achou < passos + 6) { // tem véspera e dia seguinte?
            printf("Véspera: %d  Dia seguinte: %d\n", achou[-1], achou[1]); // relativo a achou
        }
    }

    int *p = passos;
    // vetor não é ponteiro: sizeof mostra a diferença
    printf("sizeof passos = %zu  sizeof p = %zu\n", sizeof passos, sizeof p);
    return 0;
}
// Saída:
// Meta batida no dia 3 com 10400 passos
// Véspera: 8100  Dia seguinte: 7300
// sizeof passos = 28  sizeof p = 8

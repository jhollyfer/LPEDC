// 0127 · Backtracking
// Exercício E762 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define N 7
#define ALVO 10

char sinal[N + 1];   // sinal[k] = sinal antes do número k + 1
int resto[N + 2];    // resto[k] = (k) + (k + 1) + ... + N
int achadas = 0, chamadas = 0;

// já decidiu os sinais dos números 1..k-1, que dão soma
void tenta(int k, int soma) {
    chamadas++;
    if (abs(ALVO - soma) > resto[k]) {
        return;                        // nem somando nem subtraindo tudo chega
    }
    if (k > N) {
        if (soma == ALVO) {
            achadas++;
            printf("1");
            for (int j = 2; j <= N; j++) {
                printf("%c%d", sinal[j], j);
            }
            printf(" = %d\n", ALVO);
        }
        return;
    }
    sinal[k] = '+';
    tenta(k + 1, soma + k);
    sinal[k] = '-';
    tenta(k + 1, soma - k);
}

int main(void) {
    resto[N + 1] = 0;
    for (int k = N; k >= 1; k--) {
        resto[k] = resto[k + 1] + k;
    }
    tenta(2, 1); // o 1 é sempre positivo
    printf("%d expressões, %d chamadas\n", achadas, chamadas);
    return 0;
}

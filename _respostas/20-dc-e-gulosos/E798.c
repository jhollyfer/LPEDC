// 0133 · Algoritmos gulosos
// Exercício E798 · ★★★

#include <stdio.h>

#define N 6

int main(void) {
    const char *nome[N] = {"Ana", "Bruno", "Carla", "Davi", "Eva", "Fábio"};
    int pagou[N] = {18000, 0, 6000, 12000, 0, 9000}; // centavos

    int total = 0;
    for (int i = 0; i < N; i++) {
        total += pagou[i];
    }
    int parte = total / N;
    int saldo[N]; // positivo: tem a receber; negativo: deve
    for (int i = 0; i < N; i++) {
        saldo[i] = pagou[i] - parte;
    }
    printf("Total R$ %.2f, cada um R$ %.2f\n", total / 100.0, parte / 100.0);

    int pix = 0;
    for (;;) {
        int dev = 0, cred = 0; // o que mais deve e o que mais tem a receber
        for (int i = 1; i < N; i++) {
            if (saldo[i] < saldo[dev]) dev = i;
            if (saldo[i] > saldo[cred]) cred = i;
        }
        if (saldo[dev] == 0) {
            break;             // ninguém deve mais nada
        }
        int valor = -saldo[dev] < saldo[cred] ? -saldo[dev] : saldo[cred];
        printf("%s -> %s: R$ %.2f\n", nome[dev], nome[cred], valor / 100.0);
        saldo[dev] += valor;
        saldo[cred] -= valor;
        pix++;
    }
    printf("%d Pix\n", pix);
    return 0;
}

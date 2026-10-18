// 0056 · void * e cast
// Exercício E333 · ★★☆

#include <stdio.h>

void zera(void *p, size_t tam) {
    unsigned char *b = p;
    for (size_t i = 0; i < tam; i++) {
        b[i] = 0;
    }
}

void mostra(const int *gols, int n, double saldo) {
    for (int i = 0; i < n; i++) {
        printf("%d ", gols[i]);
    }
    printf("| %.2f\n", saldo);
}

int main(void) {
    int gols[5] = {2, 1, 3, 0, 4};
    double saldo = 99.90;

    printf("antes: ");
    mostra(gols, 5, saldo);
    zera(gols, sizeof gols);
    zera(&saldo, sizeof saldo);
    printf("depois: ");
    mostra(gols, 5, saldo);
    return 0;
}

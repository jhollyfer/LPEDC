// Lista · Módulo 06 · Ponteiros
// Exercício P0617 · ★★☆ · Conserte o reajuste dos preços

#include <stdio.h>

void reajustar(int *precos, int n) {
    int *fim = precos + n;
    for (int *p = precos; p < fim; p++) {
        (*p)++; // soma no valor apontado (o p++ do for já anda)
    }
}

int total(const int *precos, int n) {
    int soma = 0;
    const int *fim = precos + n;
    for (const int *p = precos; p < fim; p++) { // fim não pode ser lido
        soma += *p;
    }
    return soma;
}

int main(void) {
    int precos[5] = {4, 7, 3, 10, 6}; // coxinha, suco, café, prato, bolo

    reajustar(precos, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d%s", precos[i], i < 4 ? " " : "\n");
    }
    printf("Total: R$ %d\n", total(precos, 5));
    return 0;
}

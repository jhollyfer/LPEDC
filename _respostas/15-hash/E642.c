// 0107 · Endereçamento aberto
// Exercício E642 · ★★★

#include <stdio.h>

#define M 11
#define N 8
#define LIVRE -1

// passo 1: sondagem linear; passo dependente da chave: hash duplo
int passo_linear(int chave) {
    (void)chave;
    return 1;
}

int passo_duplo(int chave) {
    return 1 + chave % 10; // de 1 a 10: nunca 0, e 11 é primo
}

int simula(const char *nome, int (*passo)(int), const int chaves[]) {
    int tab[M];
    for (int i = 0; i < M; i++) {
        tab[i] = LIVRE;
    }
    int total = 0;
    printf("%s:", nome);
    for (int k = 0; k < N; k++) {
        int i = chaves[k] % M;
        int s = 1;
        while (tab[i] != LIVRE) {
            i = (i + passo(chaves[k])) % M;
            s++;
        }
        tab[i] = chaves[k];
        printf(" %d", s);
        total += s;
    }
    printf(" | total: %d\n", total);
    return total;
}

int main(void) {
    int chaves[N] = {5, 16, 27, 8, 38, 19, 30, 2};
    simula("linear", passo_linear, chaves);
    simula("duplo ", passo_duplo, chaves);
    return 0;
}

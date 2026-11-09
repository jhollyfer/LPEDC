// Lista · Módulo 15 · Tabelas hash
// Exercício P1524 · ★★★ · Os períodos em que o caixa zerou

#include <stdio.h>

#define M 31

// tabela aberta: soma acumulada -> quantas vezes ela apareceu
int usada[M], soma[M], vezes[M];

int h(int k) {
    return ((k % M) + M) % M; // somas podem ser negativas
}

int posicao(int k) {
    int pos = h(k);
    while (usada[pos] && soma[pos] != k) {
        pos = (pos + 1) % M;
    }
    return pos;
}

int main(void) {
    int mov[] = {50, -20, -30, 10, 40, -50, 20, -20, 30, -30};
    int n = 10;

    // a soma "antes do primeiro dia" é 0 e já conta uma vez
    int p = posicao(0);
    usada[p] = 1;
    soma[p] = 0;
    vezes[p] = 1;

    int acumulado = 0;
    long periodos = 0;
    for (int j = 0; j < n; j++) {
        acumulado += mov[j];
        p = posicao(acumulado);
        if (usada[p]) {
            // cada vez que esta soma apareceu antes é um período que zera em j
            printf("dia %d (saldo %d): +%d\n", j + 1, acumulado, vezes[p]);
            periodos += vezes[p];
            vezes[p]++;
        } else {
            usada[p] = 1;
            soma[p] = acumulado;
            vezes[p] = 1;
        }
    }

    long bruta = 0;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            s += mov[j];
            if (s == 0) {
                bruta++;
            }
        }
    }
    printf("períodos que zeram: %ld (força bruta: %ld)\n", periodos, bruta);
    return 0;
}

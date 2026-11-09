// Lista · Módulo 15 · Tabelas hash
// Exercício P1513 · ★★☆ · Quantos pares fecham o vale-presente

#include <stdio.h>

#define M 17
#define VAZIO -1

// tabela aberta: chave = preço, valor = quantas vezes já apareceu
int chave[M], vezes[M];

int posicao(int k) {
    int pos = k % M;
    while (chave[pos] != VAZIO && chave[pos] != k) {
        pos = (pos + 1) % M;
    }
    return pos;
}

int quantas(int k) {
    int pos = posicao(k);
    return chave[pos] == k ? vezes[pos] : 0;
}

void soma_um(int k) {
    int pos = posicao(k);
    chave[pos] = k;
    vezes[pos]++;
}

int main(void) {
    int precos[] = {20, 30, 50, 30, 70, 20, 80, 50, 45};
    int n = 9, meta = 100;
    for (int i = 0; i < M; i++) {
        chave[i] = VAZIO;
        vezes[i] = 0;
    }

    long pares = 0;
    for (int j = 0; j < n; j++) {
        int falta = meta - precos[j];
        int q = (falta > 0) ? quantas(falta) : 0; // pares com quem veio antes
        if (q > 0) {
            printf("R$ %d com os R$ %d anteriores: +%d\n", precos[j], falta, q);
        }
        pares += q;
        soma_um(precos[j]);
    }

    long bruta = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (precos[i] + precos[j] == meta) {
                bruta++;
            }
        }
    }
    printf("pares com hash: %ld, força bruta: %ld\n", pares, bruta);
    return 0;
}

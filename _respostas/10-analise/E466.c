// 0078 · Invariantes de laço e corretude
// Exercício E466 · ★★☆
//
// Resposta: a) falha o início: maior = 0 não é elemento do vetor, e com todos
// os saldos negativos ele nunca é trocado; b) maior = v[0] e i começa em 1;
// c) recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1].

#include <stdio.h>

// Recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1].
int maximo(const int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        // invariante: maior é um máximo de v[0..i-1]
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

int main(void) {
    int saldos[4] = {-120, -45, -300, -80};

    printf("Maior saldo: R$ %d\n", maximo(saldos, 4));
    return 0;
}

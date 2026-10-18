// 0038 · Vetores e funções
// Exercício E227 · ★★★
//
// Resposta: dentro da função, sizeof(doacoes) é o tamanho de um endereço (8),
// não do vetor (24). A conta 8 / 4 dá 2, e o laço soma só 50 + 20 = 70.
// Conserto: receber o tamanho num parâmetro e calcular n com sizeof no main,
// onde o vetor foi declarado.

#include <stdio.h>

int total(const int doacoes[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += doacoes[i];
    }
    return soma;
}

int main(void) {
    int doacoes[] = {50, 20, 100, 35, 15, 80};
    int n = sizeof(doacoes) / sizeof(doacoes[0]);

    printf("Total arrecadado: R$ %d\n", total(doacoes, n));
    return 0;
}

// 0038 · Vetores e funções
// Exercício E227 · ★★★
//
// O programa abaixo deveria somar as 6 doações de uma vaquinha online
// (R$ 50 + 20 + 100 + 35 + 15 + 80 = R$ 300), mas mostra outro valor. Ele
// tem UM erro de propósito, e o gcc até avisa: rode com o rodar e leia o
// aviso (warning) com calma.
//
//   1. Que valor ele mostra no seu PC, e por quê?
//   2. Conserte sem mudar o main mais do que o necessário.
//
//   Saída esperada depois do conserto:
//   Total arrecadado: R$ 300
//
// Dicas:
// 1. O aviso fala em "sizeof on array function parameter". O que a função
//    recebe de verdade: o vetor ou o endereço dele?
// 2. Num PC de 64 bits, um endereço tem 8 bytes e um int tem 4.
// 3. Resposta esperada: dentro da função, sizeof(doacoes) é o tamanho de um
//    endereço (8), não do vetor (24). A conta 8 / 4 dá 2, e o laço soma só
//    50 + 20 = 70. Conserto: receber o tamanho num parâmetro, int total(const
//    int doacoes[], int n), e no main calcular n com sizeof, onde o vetor foi
//    declarado.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int total(const int doacoes[]) {
    int n = sizeof(doacoes) / sizeof(doacoes[0]);
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += doacoes[i];
    }
    return soma;
}

int main(void) {
    int doacoes[] = {50, 20, 100, 35, 15, 80};

    printf("Total arrecadado: R$ %d\n", total(doacoes));
    return 0;
}

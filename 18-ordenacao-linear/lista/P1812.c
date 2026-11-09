// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1812 · ★★☆ · Radix LSD mostrando o vetor C de cada passada
//
// Na prova, o radix sort aparece como "qual é o vetor depois da segunda
// passada?" e o counting sort como "qual é o vetor C?". Junte os dois: ordene
// os 8 códigos de rastreio (3 dígitos) de uma agência dos Correios com radix
// LSD em base 10 e, em CADA passada, mostre:
//
// - o dígito usado de cada número;
// - o vetor C depois das somas acumuladas (C[d] = quantos têm dígito <= d);
// - o vetor depois da passada.
//
//   Saída esperada:
//   Passada div = 1
//   dígitos: 5 1 2 7 3 0 5 1
//   C acumulado: 1 3 4 5 5 7 7 8 8 8
//   vetor: 540 331 801 902 283 465 615 747
//   Passada div = 10
//   dígitos: 4 3 0 0 8 6 1 4
//   C acumulado: 2 3 3 4 6 6 7 7 8 8
//   vetor: 801 902 615 331 540 747 465 283
//   Passada div = 100
//   dígitos: 8 9 6 3 5 7 4 2
//   C acumulado: 0 0 1 2 3 4 5 6 7 8
//   vetor: 283 331 465 540 615 747 801 902
//
// Dicas:
// 1. Dígito da passada com divisor div: (x / div) % 10, com div = 1, 10, 100.
// 2. C acumulado diz onde termina cada bloco: os de dígito d ocupam as
//    posições C[d - 1] até C[d] - 1.
// 3. Um dígito que não aparece repete o valor do anterior em C: o bloco dele
//    tem tamanho zero.
// 4. Resposta esperada: depois das unidades, 540 801 331 902 283 465 615 747;
//    depois das dezenas, 801 902 615 331 540 747 465 283; no fim, 283 331 465
//    540 615 747 801 902.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 8

int main(void) {
    int cod[N] = {465, 331, 902, 747, 283, 540, 615, 801};

    for (int i = 0; i < N; i++) printf("%d ", cod[i]);
    printf("\n");
    return 0;
}

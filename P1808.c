// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1808 · ★☆☆ · Radix sort bit a bit: zeros na frente, uns atrás
//
// O radix sort não precisa de base 10: em base 2, cada passada olha um bit.
// Com um bit só, o counting sort vira uma SEPARAÇÃO ESTÁVEL: primeiro todos
// os que têm aquele bit 0, na ordem em que estão, depois todos os que têm 1,
// também na ordem.
//
// Os códigos das 8 linhas de um terminal de ônibus vão de 0 a 15 (4 bits).
// Escreva a passada (bit b: (x >> b) & 1) e rode o radix LSD do bit 0 ao
// bit 3, mostrando o vetor em binário e em decimal depois de cada passada.
//
//   Saída esperada:
//   início 1100 0101 1001 1110 0011 1010 0110 1011 | 12 5 9 14 3 10 6 11
//   bit 0   1100 1110 1010 0110 0101 1001 0011 1011 | 12 14 10 6 5 9 3 11
//   bit 1   1100 0101 1001 1110 1010 0110 0011 1011 | 12 5 9 14 10 6 3 11
//   bit 2   1001 1010 0011 1011 1100 0101 1110 0110 | 9 10 3 11 12 5 14 6
//   bit 3   0011 0101 0110 1001 1010 1011 1100 1110 | 3 5 6 9 10 11 12 14
//
// Dicas:
// 1. Uma passada: conte quantos têm o bit 0 (zeros); percorra o vetor
//    copiando os de bit 0 para saida[iz++] (iz começa em 0) e os de bit 1
//    para saida[iu++] (iu começa em zeros). É o counting sort com k = 2, sem
//    precisar ler de trás para frente.
// 2. Para imprimir em binário, mostre os bits 3, 2, 1 e 0 de cada número.
// 3. Depois da passada do bit b, o vetor está ordenado pelos b + 1 bits de
//    baixo: é o invariante do radix LSD.
// 4. Resposta esperada: no fim, 0011 0101 0110 1001 1010 1011 1100 1110
//    (3 5 6 9 10 11 12 14).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 8

int main(void) {
    int linha[N] = {12, 5, 9, 14, 3, 10, 6, 11};

    for (int i = 0; i < N; i++) printf("%d ", linha[i]);
    printf("\n");
    return 0;
}

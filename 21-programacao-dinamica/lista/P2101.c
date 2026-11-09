// Lista · Módulo 21 · Programação dinâmica
// Exercício P2101 · ★☆☆ · Tribonacci com e sem memória
//
// A sequência de Tribonacci soma os TRÊS anteriores: T(0) = 0, T(1) = 0,
// T(2) = 1 e T(n) = T(n - 1) + T(n - 2) + T(n - 3). O programa abaixo tem
// a versão recursiva ingênua, que conta as chamadas. Estenda-o com a
// versão memoizada: um vetor memo[] com -1 em "ainda não calculado", e a
// função só calcula quando não sabe a resposta. Mostre T(25) e as chamadas
// das duas versões.
//
//   Saída esperada:
//   Ingênua: T(25) = 755476, 2700421 chamadas
//   Memoizada: T(25) = 755476, 70 chamadas
//
// Dicas:
// 1. long long memo[MAX]; preencha com -1 no main antes de chamar.
// 2. Na memoizada, conte a chamada logo na entrada (antes de olhar o memo):
//    assim a conta inclui as chamadas que voltam na hora.
// 3. Resposta esperada: T(25) = 755476; a ingênua faz mais de um milhão
//    de chamadas e a memoizada, 73 (3 por valor de n, menos as bordas).
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define MAX 64

long chamadas;

long long trib(int n) {
    chamadas++;
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return trib(n - 1) + trib(n - 2) + trib(n - 3);
}

int main(void) {
    chamadas = 0;
    long long r = trib(25);
    printf("Ingênua: T(25) = %lld, %ld chamadas\n", r, chamadas);
    return 0;
}

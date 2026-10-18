// 0138 · Memoização
// Exercício E824 · ★☆☆
//
// A prefeitura vai refazer uma calçada com lajotas de 2 m e de 3 m, uma atrás
// da outra. Quantas sequências diferentes de lajotas cobrem exatamente n
// metros? Pensando na última lajota: c(n) = c(n - 2) + c(n - 3), com c(0) = 1
// (nada a fazer), c(1) = 0 (impossível) e c(2) = 1.
//
// O programa abaixo já calcula c(40) com a recursão pura e conta as chamadas.
// Complete a função calcada_memo() nos lugares marcados com COMPLETE AQUI,
// para ela guardar cada resposta no vetor memo[], e use-a para calcular c(40)
// e c(120). Não mexa na versão recursiva.
//
//   Saída esperada:
//   recursão pura: c(40) = 31572 com 110809 chamadas
//   memoização:    c(40) = 31572 com 75 chamadas
//   memoização:    c(120) = 185855747875876
//
// Dicas:
// 1. Antes de calcular, olhe memo[n]; se já tem resposta, devolva ela.
// 2. Use -1 como "não calculado": 0 é uma resposta válida aqui (c(1) = 0)!
// 3. Lembre de encher o memo com -1 antes de usar (o laço já está no main).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define MAX 150

long long chamadas = 0;
long long memo[MAX + 1];

long long calcada_rec(int n) {
    chamadas++;
    if (n == 0 || n == 2) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }
    return calcada_rec(n - 2) + calcada_rec(n - 3);
}

long long calcada_memo(int n) {
    chamadas++;
    if (n == 0 || n == 2) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }
    // COMPLETE AQUI: se memo[n] já foi calculado, devolva memo[n]

    // COMPLETE AQUI: calcule com calcada_memo(n - 2) + calcada_memo(n - 3),
    // guarde em memo[n] e devolva
    return 0;
}

int main(void) {
    chamadas = 0;
    long long r = calcada_rec(40);
    printf("recursão pura: c(40) = %lld com %lld chamadas\n", r, chamadas);

    for (int i = 0; i <= MAX; i++) {
        memo[i] = -1;
    }
    chamadas = 0;
    r = calcada_memo(40);
    printf("memoização:    c(40) = %lld com %lld chamadas\n", r, chamadas);
    printf("memoização:    c(120) = %lld\n", calcada_memo(120));
    return 0;
}

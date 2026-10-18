// 0125 · Subconjuntos
// Exercício E746 · ★☆☆
//
// No bolso há três moedas: R$ 1,00, R$ 0,50 e R$ 0,25. O programa abaixo
// quer mostrar todos os valores que dá para pagar escolhendo um subconjunto
// delas. Ele usa um vetor de bool, pega[i], em vez da cesta do texto, e
// decide o caminho "com a moeda" ANTES do caminho "sem a moeda". Complete a
// função gera nos pontos marcados (quatro linhas).
//
//   Saída esperada:
//   R$ 1.75: 100 50 25
//   R$ 1.50: 100 50
//   R$ 1.25: 100 25
//   R$ 1.00: 100
//   R$ 0.75: 50 25
//   R$ 0.50: 50
//   R$ 0.25: 25
//   R$ 0.00:
//
// Dicas:
// 1. Caminho 1: marque pega[i] como true e chame gera(i + 1).
// 2. Caminho 2: marque pega[i] como false e chame gera(i + 1) de novo.
// 3. Com o "com" primeiro, a ordem sai do maior valor para o menor. Por
//    quê? Pense na moeda de 100: todas as escolhas com ela vêm antes.
// 4. Resposta esperada: as 8 linhas acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

#define N 3

const int moedas[N] = {100, 50, 25}; // centavos
bool pega[N];

void gera(int i) {
    if (i == N) {
        int total = 0;
        for (int j = 0; j < N; j++) {
            if (pega[j]) {
                total += moedas[j];
            }
        }
        printf("R$ %d.%02d:", total / 100, total % 100);
        for (int j = 0; j < N; j++) {
            if (pega[j]) {
                printf(" %d", moedas[j]);
            }
        }
        printf("\n");
        return;
    }
    // caminho 1: com a moeda i


    // caminho 2: sem a moeda i


}

int main(void) {
    gera(0);
    return 0;
}

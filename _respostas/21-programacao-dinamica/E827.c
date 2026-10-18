// 0138 · Memoização
// Exercício E827 · ★★★
//
// Resposta: o memo usava 0 como "ainda não calculei". Só que 0 é a resposta
// certa de toda posição acima das prateleiras fora da coluna 0 (dali o robô
// não alcança a passagem). Essas posições guardavam 0, o teste concluía "não
// calculado" e a recursão descia de novo, de forma exponencial. Conserto:
// encher o memo com -1 e testar memo[i][j] != -1.

#include <stdio.h>

#define TAM 16

int prateleira[TAM][TAM];
long long memo[TAM][TAM];
long long chamadas = 0;

long long caminhos(int i, int j) {
    chamadas++;
    if (i >= TAM || j >= TAM || prateleira[i][j]) {
        return 0;
    }
    if (i == TAM - 1 && j == TAM - 1) {
        return 1;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    memo[i][j] = caminhos(i + 1, j) + caminhos(i, j + 1);
    return memo[i][j];
}

int main(void) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            memo[i][j] = -1; // -1 nunca é uma contagem de caminhos
        }
    }
    for (int j = 1; j < TAM; j++) {
        prateleira[8][j] = 1;
    }
    long long total = caminhos(0, 0);
    printf("%lld caminhos, %lld chamadas\n", total, chamadas);
    return 0;
}

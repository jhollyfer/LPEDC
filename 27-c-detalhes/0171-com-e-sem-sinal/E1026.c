// 0171 · Com sinal e sem sinal
// Exercício E1026 · ★★★
//
// Escreva três funções que fazem contas com unsigned sem cair nas
// pegadinhas, e teste com os valores da saída:
//
//   - unsigned sub_saturada(unsigned a, unsigned b): a - b, mas para em 0
//     em vez de dar a volta;
//   - bool soma_cabe(unsigned a, unsigned b): diz se a + b cabe num
//     unsigned, SEM fazer a soma que estoura;
//   - int compara(int a, unsigned b): devolve -1, 0 ou 1 conforme a é menor,
//     igual ou maior que b na matemática de verdade (-1 é menor que 0u!).
//
//   Saída esperada:
//   sub_saturada(2, 3) = 0
//   sub_saturada(10, 3) = 7
//   soma_cabe(4000000000, 300000000) = nao
//   soma_cabe(4000000000, 294967295) = sim
//   compara(-1, 0) = -1
//   compara(5, 5) = 0
//   compara(7, 3) = 1
//
// Dicas:
// 1. sub_saturada: se a < b, devolva 0.
// 2. a + b cabe quando a <= UINT_MAX - b (essa subtração nunca dá a volta).
// 3. compara: trate a < 0 primeiro. Depois a já é positivo, e
//    (unsigned)a é seguro.
// 4. (x > y) - (x < y) dá -1, 0 ou 1 numa linha só.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

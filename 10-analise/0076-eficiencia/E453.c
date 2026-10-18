// 0076 · Eficiência: contar passos
// Exercício E453 · ★★☆
//
// O texto disse que, em média, a busca sequencial custa (n + 1) / 2
// comparações. Não acredite: meça. Escreva um programa que, para n = 10, 100
// e 1000:
//
// 1. preenche um vetor com os códigos de produto v[i] = 3 * i + 1;
// 2. busca, um por um, TODOS os códigos que estão no vetor, somando os passos
// de todas as buscas;
// 3. mostra o total e a média de passos por busca.
//
//   Saída esperada:
//   n =   10: total     55, média   5.5
//   n =  100: total   5050, média  50.5
//   n = 1000: total 500500, média 500.5
//
// Dicas:
// 1. Use um vetor de 1000 posições e só as n primeiras em cada rodada.
// 2. Reaproveite a busca do A151 com o contador global; zere-o uma vez por n,
//    não a cada busca, para acumular o total.
// 3. Achar o código da posição i custa i + 1 passos. Somando de 1 até n dá
//    n(n + 1) / 2; dividindo por n, (n + 1) / 2.
// 4. Resposta esperada: médias 5.5, 50.5 e 500.5.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

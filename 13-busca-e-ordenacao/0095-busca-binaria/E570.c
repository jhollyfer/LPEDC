// 0095 · Busca binária
// Exercício E570 · ★★★
//
// Busca binária não precisa de vetor: basta uma pergunta de sim ou não que
// muda de resposta uma única vez. Um terreno quadrado tem que caber numa área
// de A m². Qual o maior lado INTEIRO possível? Ou seja: o maior L com
// L * L <= A. Sem sqrt: faça uma busca binária no intervalo de 0 a A e conte
// as voltas. Teste com 50, 1000000, 2147395600 e 2147483647.
//
//   Saída esperada:
//   50 m²: lado 7 m (6 voltas)
//   1000000 m²: lado 1000 m (20 voltas)
//   2147395600 m²: lado 46340 m (31 voltas)
//   2147483647 m²: lado 46340 m (31 voltas)
//
// Dicas:
// 1. Para L = 0, 1, 2, ... a resposta de "L * L <= A?" é sim, sim, ..., não,
//    não. Você procura o último sim.
// 2. Use long long: com int, meio * meio estoura bem antes de 2 bilhões.
// 3. Invariante: a resposta está em [ini, fim]. Se meio serve, ini = meio;
//    senão, fim = meio - 1. Pare quando ini == fim.
// 4. Com ini = meio, calcule meio arredondando para CIMA,
//    ini + (fim - ini + 1) / 2; senão, com fim = ini + 1, o laço nunca acaba.
// 5. Resposta esperada: a saída acima (46340² = 2147395600).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2001 · ★☆☆ · A senha do painel
//
// No painel do posto de saúde, as senhas chamadas hoje estão em ordem
// crescente: 3 8 12 15 21 27 33 40 46 52 58 64 71 79 85 90. Escreva do
// zero a busca binária RECURSIVA busca(v, ini, fim, x): olha o meio; se é
// x, devolve o índice; se x é menor, procura só na metade da esquerda;
// senão, só na da direita. Pedaço vazio (ini > fim) devolve -1. Conte as
// chamadas e procure as senhas 64, 3 e 50.
//
//   Saída esperada:
//   Senha 64: posição 11 (2 chamadas)
//   Senha 3: posição 0 (4 chamadas)
//   Senha 50: não chamada (5 chamadas)
//
// Dicas:
// 1. int meio = ini + (fim - ini) / 2; escrito assim, ini + fim nunca
//    estoura em vetores enormes.
// 2. Zere o contador antes de cada busca. Com 16 elementos, são no máximo
//    lg 16 + 1 = 5 chamadas que olham o vetor, mais a do pedaço vazio.
// 3. Resposta esperada: 64 na posição 11 (4 chamadas), 3 na posição 0 (4
//    chamadas) e 50 não chamada (6 chamadas, a última com o pedaço vazio).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

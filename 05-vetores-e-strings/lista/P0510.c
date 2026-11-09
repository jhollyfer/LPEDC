// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0510 · ★☆☆ · Quantos de cada número
//
// Uma sapataria vendeu 14 pares de tênis num sábado, com estes números:
//
//   int vendidos[14] = {38, 40, 37, 42, 40, 39, 40, 35, 38, 41, 40, 44, 38, 37};
//
// A loja trabalha do 34 ao 44. Conte quantos pares de cada número saíram,
// usando um vetor de contadores de 11 posições (uma por número), e mostre só
// os números que venderam, com um # por par:
//
//   Saída esperada:
//   35: # (1)
//   37: ## (2)
//   38: ### (3)
//   39: # (1)
//   40: #### (4)
//   41: # (1)
//   42: # (1)
//   44: # (1)
//
// Dicas:
// 1. O número 34 vai na posição 0, o 35 na 1... o número n vai em n - 34.
// 2. Zere o vetor de contadores na declaração: int cont[11] = {0};
// 3. Um laço passa pelos 14 pares fazendo cont[vendidos[i] - 34]++; outro
//    laço mostra de 0 a 10, pulando quem tem contador 0.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int vendidos[14] = {38, 40, 37, 42, 40, 39, 40, 35, 38, 41, 40, 44, 38, 37};
    (void) vendidos; // apague esta linha quando escrever

    return 0;
}

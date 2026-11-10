// Lista · Módulo 03 · Laços
// Exercício P0324 · ★★★ · Os primos até 10 000
//
// Sem vetor, não dá para montar o crivo de Eratóstenes, mas dá para testar cada
// número com a versão econômica: descarte os pares (fora o 2) e tente só os
// divisores ímpares d com d * d <= n. Escreva um programa que conte os primos
// até 10 000, mostre o maior deles e o maior buraco entre dois primos
// seguidos (e quais são eles):
//
//   Saída esperada:
//   Primos até 10000: 1229
//   Maior primo: 9973
//   Maior buraco: 36, entre 9551 e 9587
//
// Dicas:
// 1. Comece contando o 2 e ande de n = 3 em n += 2.
// 2. Guarde o último primo encontrado (anterior). A cada novo primo, compare
//    n - anterior com o maior buraco até agora.
// 3. Use break no laço dos divisores assim que achar um.
// 4. Resposta esperada: 1229 primos, maior 9973, buraco de 36 entre 9551 e
//    9587.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

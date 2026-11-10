// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2924 · ★★★ · Código de Gray: um ciclo hamiltoniano no hipercubo
//
// No hipercubo de dimensão 4, os vértices são os números de 0 a 15 e dois
// são vizinhos quando diferem em exatamente um bit. O código de Gray,
// g(i) = i ^ (i >> 1), percorre os 16 vértices formando um ciclo
// hamiltoniano. Escreva o programa que gera a sequência, mostra cada
// vértice em binário (4 dígitos) e confere com um verificador: 16 vértices
// distintos, e cada vizinho da sequência (inclusive o último com o
// primeiro) difere em um bit só.
//
//   Saída esperada:
//   0000 0001 0011 0010 0110 0111 0101 0100
//   1100 1101 1111 1110 1010 1011 1001 1000
//   Ciclo hamiltoniano: sim
//
// Dicas:
// 1. x e y diferem em um bit só quando z = x ^ y é potência de 2: z != 0 e
//    (z & (z - 1)) == 0.
// 2. Mostre os bits com um laço de b = 3 até 0: (x >> b) & 1.
// 3. Resposta esperada: a saída acima. Para o hipercubo, achar o ciclo é fácil
//    porque o grafo tem estrutura; o difícil é o caso geral.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}

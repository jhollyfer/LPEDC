// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2807 · ★☆☆ · Divisão e colisões
//
// A locadora de bicicletas espalha as matrículas 1013, 2026, 3039, 4052,
// 5065, 1500, 2600 e 3700 numa tabela de m = 13 baldes com h(k) = k mod 13.
// Mostre o balde de cada matrícula, o número de colisões (chaves que caem
// num balde já ocupado) e repita com m = 10.
//
//   Saída esperada:
//   m = 13: 12 11 10 9 8 5 0 8 | colisões: 1
//   m = 10: 3 6 9 2 5 0 0 0 | colisões: 2
//
// Dicas:
// 1. Um vetor de contagem por balde: colisão é quando conta[h] já era maior
//    que 0.
// 2. Repare que 1013, 2026, ... são múltiplos de 1013 = 13 · 78 - 1.
// 3. Com m = 10, a função só vê o último dígito.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

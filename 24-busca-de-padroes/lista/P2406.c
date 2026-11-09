// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2406 · ★☆☆ · A janela que rola pelo código de barras
//
// O código de barras do pacote de café é "7891000315507". Escreva do zero
// um programa que mostra o hash (base 10, módulo Q = 97) de cada janela de
// 4 dígitos, mas calculando do zero SÓ a primeira: as outras saem rolando,
// tirando o dígito da esquerda e pondo o da direita.
//
//   Saída esperada:
//   0: 7891 -> 34
//   1: 8910 -> 83
//   2: 9100 -> 79
//   3: 1000 -> 30
//   4: 0003 ->  3
//   5: 0031 -> 31
//   6: 0315 -> 24
//   7: 3155 -> 51
//   8: 1550 -> 95
//   9: 5507 -> 75
//
// Dicas:
// 1. Calcule antes pot = 10^(m-1) mod Q (com m = 4, pot = 1000 % 97 = 30).
// 2. Rolar: h = (h - esquerda * pot % Q + Q) % Q e depois
//    h = (h * 10 + direita) % Q. O "+ Q" evita resto negativo.
// 3. Resposta esperada: a janela 0003 dá 3, e a última, 5507, dá 75
//    (5507 = 56 × 97 + 75).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}

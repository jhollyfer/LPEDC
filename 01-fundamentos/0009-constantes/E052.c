// 0009 · Constantes
// Exercício E052 · ★★☆
//
// Para cada literal, diga o tipo e o valor. Depois escreva um programa que
// mostre o sizeof de cada um (com %zu) para confirmar os tipos.
//
//   10     10.0     10.0f     010     0x10     '0'     "0"     1e3
//
//   Saída esperada:
//   10: 4 bytes
//   10.0: 8 bytes
//   10.0f: 4 bytes
//   010: 4 bytes
//   0x10: 4 bytes
//   '0': 4 bytes
//   "0": 2 bytes
//   1e3: 8 bytes
//
// Dicas:
// 1. Sem ponto é int; com ponto é double; o sufixo f faz float.
// 2. Zero à esquerda é octal; 0x é hexadecimal; aspas simples dão o código
//    do caractere (um int); aspas duplas são texto com o byte zero no fim.
// 3. Resposta esperada: 10 int (10); 10.0 double (10); 10.0f float (10);
//    010 int (8, octal); 0x10 int (16); '0' int (48, o código do caractere
//    zero); "0" texto de 2 bytes ('0' e '\0'); 1e3 double (1000).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

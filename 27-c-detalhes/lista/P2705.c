// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2705 · ★☆☆ · Para onde vai o negativo
//
// Converter um valor para um tipo sem sinal é sempre definido: o C soma ou
// subtrai 2^bits até o valor caber. Escreva um programa que guarde cada valor
// abaixo numa variável do tipo pedido e mostre o resultado:
//
//   -1 em unsigned char      256 em unsigned char    300 em unsigned char
//   -2 em unsigned short     -3 em unsigned
//
//   Saída esperada:
//   (unsigned char)-1 = 255
//   (unsigned char)256 = 0
//   (unsigned char)300 = 44
//   (unsigned short)-2 = 65534
//   (unsigned)-3 = 4294967293
//
// Dicas:
// 1. unsigned char tem 8 bits: a conta é módulo 256. unsigned short tem 16:
//    módulo 65536.
// 2. Use o cast para o gcc não reclamar de constante grande demais:
//    unsigned char a = (unsigned char)300;
// 3. unsigned char e unsigned short viram int no printf: %d serve. O
//    unsigned vai com %u.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

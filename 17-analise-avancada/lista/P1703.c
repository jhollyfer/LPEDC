// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1703 · ★☆☆ · O hodômetro do ônibus: custo amortizado em base 10
//
// O hodômetro mecânico de um ônibus tem 4 rodinhas de dígitos (0000 a 9999)
// e soma 1 a cada quilômetro. Girar uma rodinha custa 1. Quase sempre só a
// rodinha das unidades gira, mas de 0999 para 1000 giram quatro.
//
// Guarde os dígitos num vetor int d[4] (d[0] = unidades) e escreva int
// incrementa(int d[]), que soma 1 e devolve quantas rodinhas giraram. Mostre
// o custo de cada passo de 0997 até 1000, e o custo TOTAL e o custo por incremento
// depois de 10, 100, 1000 e 10000 quilômetros a partir de 0000.
//
//   Saída esperada:
//   0998 (giraram 1)
//   0999 (giraram 1)
//   1000 (giraram 4)
//      10 km:    11 rodinhas, 1.100 por km
//     100 km:   111 rodinhas, 1.110 por km
//    1000 km:  1111 rodinhas, 1.111 por km
//   10000 km: 11110 rodinhas, 1.111 por km
//
// Dicas:
// 1. incrementa: i = 0; enquanto i < 4 e d[i] == 9, d[i] = 0 e i++ (cada
//    uma é uma rodinha girada); se i < 4, d[i]++ (mais uma).
// 2. Análise agregada: em n incrementos, a rodinha das unidades gira n
//    vezes, a das dezenas n/10, a das centenas n/100... A soma fica abaixo
//    de n · 10/9 ≈ 1,111 n.
// 3. Em 10000 km o hodômetro volta para 0000: a rodinha dos milhares também
//    gira 10 vezes.
// 4. Resposta esperada: 1, 1 e 3 rodinhas nos passos 0997 -> 0998 -> 0999 ->
//    1000;
//    1111 rodinhas em 1000 km e 11110 em 10000 km (1,111 por km).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int d[4] = {7, 9, 9, 0}; // 0997, das unidades para os milhares

    printf("%d%d%d%d\n", d[3], d[2], d[1], d[0]);
    return 0;
}

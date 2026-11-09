// Lista · Módulo 01 · Fundamentos de C
// Exercício P0126 · ★★★ · Previsão da maratona
//
// A fórmula de Riegel prevê o tempo numa prova mais longa a partir de uma mais
// curta: T2 = T1 × (D2 / D1) elevado a 1.06. Você correu 10 km em 50 min.
// Escreva um programa que preveja o tempo na maratona (42.195 km), arredonde
// para segundos inteiros e mostre no formato h:mm:ss, além do pace previsto:
//
//   Saída esperada:
//   Previsão: 13801 s
//   Maratona em 3:50:01
//   Pace previsto: 5:27 por km
//
// Dicas:
// 1. T1 = 50 * 60 segundos. pow(42.195 / 10, 1.06) vem do math.h.
// 2. Converta com (int)round(...) e depois use / e % por 3600 e por 60.
// 3. O pace é o total em segundos / 42.195, cortado para int.
// 4. Resposta esperada: Maratona em 3:50:01.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}

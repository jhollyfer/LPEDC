// 0030 · Escopo e tempo de vida
// Exercício E180 · ★★★
//
// Monte o seu próprio sorteador de dado, sem rand. Ele guarda um "estado" que
// muda a cada sorteio:
//
//   estado = (estado * 1103515245 + 12345) % 2147483648
//   dado   = estado / 65536 % 6 + 1
//
// Escreva:
//
//   void semear(unsigned int semente)   põe a semente no estado
//   int jogar_dado(void)                avança o estado e devolve de 1 a 6
//
// As duas funções precisam enxergar o MESMO estado, e o main não pode mexer
// nele direto. Por isso ele é uma global static (static fora de função). Use
// unsigned int para o estado.
//
// No main, semeie com 2026, jogue 10 vezes; semeie com 2026 de novo e jogue 10
// vezes. As duas linhas têm que ser iguais.
//
//   Saída esperada:
//   5 1 2 3 3 6 3 2 4 1
//   5 1 2 3 3 6 3 2 4 1
//
// Dicas:
// 1. static unsigned int estado = 1; fora das funções, logo depois dos includes.
// 2. Com unsigned int, a multiplicação que passa do limite dá a volta (não é
//    erro, ao contrário do int com sinal). A conta "% 2147483648" mantém o
//    estado em 31 bits.
// 3. Resposta esperada: as duas linhas iguais, como acima. Mesma semente,
//    mesma sequência: é assim que o rand e o srand funcionam por dentro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

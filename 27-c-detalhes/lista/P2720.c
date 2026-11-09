// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2720 · ★★☆ · Uma biblioteca de bits em macros
//
// Escreva quatro macros para mexer em bits de um uint8_t, com todos os
// parênteses que uma macro precisa:
//
//   BIT(n)        o número só com o bit n ligado
//   LIGA(x, n)    x com o bit n ligado
//   DESLIGA(x, n) x com o bit n desligado
//   TESTA(x, n)   1 se o bit n de x está ligado, senão 0
//
// Para provar que as macros estão blindadas, use argumentos com
// expressões: comece com uint8_t flags = 0; ligue o bit 1 + 1 e o bit 6,
// desligue o bit 2 * 3 e teste !TESTA(flags, 2) e TESTA(flags, 7 - 1).
//
//   Saída esperada:
//   BIT(1 + 1) = 4
//   depois de ligar 2 e 6: 68
//   depois de desligar 6: 4
//   !TESTA(flags, 2) = 0
//   TESTA(flags, 7 - 1) = 0
//
// Dicas:
// 1. #define BIT(n) (1u << (n)): sem os parênteses em volta de n,
//    1u << 1 + 1 até daria certo, mas BIT(a) * 2 não.
// 2. #define TESTA(x, n) (((x) >> (n)) & 1u): sem os parênteses de fora,
//    !TESTA(...) aplicaria o ! só ao primeiro pedaço.
// 3. Guarde de volta com cast: flags = (uint8_t)LIGA(flags, 1 + 1);
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}

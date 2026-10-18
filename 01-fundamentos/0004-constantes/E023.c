// 0004 · Constantes
// Exercício E023 · ★★★
//
// Alguém quis guardar o pi numa constante e calcular o comprimento de uma
// pista circular de raio 10 m. O programa compila sem aviso nenhum. Sem
// rodar, diga o que ele mostra e por quê. Depois conserte de dois jeitos:
// com const e com #define.
//
//   const int pi = 3.14159;
//   int raio = 10;
//   printf("Comprimento: %d m\n", 2 * pi * raio);
//
//   Saída esperada (depois de consertar):
//   Comprimento: 62.83 m
//
// Dicas:
// 1. const não muda o tipo: pi continua sendo um int.
// 2. Um int guarda só a parte inteira de 3.14159.
// 3. Resposta esperada: mostra "Comprimento: 60 m", porque pi virou 3 (a
//    parte depois da vírgula foi jogada fora em silêncio). Consertos:
//    const double pi = 3.14159; ou #define PI 3.14159, com %.2f no printf.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

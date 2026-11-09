// Lista · Módulo 04 · Funções e modularização
// Exercício P0412 · ★★☆ · Três linhas de ônibus no terminal
//
// No terminal, a linha 300 sai a cada 12 minutos, a 450 a cada 18 e a 640 a
// cada 30. As três saíram juntas às 06:00. Escreva o "int mdc(int a, int b)"
// recursivo de Euclides, o "int mmc(int a, int b)" que usa o mdc, e descubra
// quando as três saem juntas de novo:
//
//   Saída esperada:
//   mdc(12, 18) = 6
//   mmc(12, 18) = 36
//   As três saem juntas a cada 180 minutos
//   Próxima saída juntas: 09:00
//
// Dicas:
// 1. mdc(a, 0) = a; mdc(a, b) = mdc(b, a % b).
// 2. mmc(a, b) = a / mdc(a, b) * b. Dividir antes de multiplicar evita
//    estourar o int.
// 3. Para três números: mmc(mmc(12, 18), 30).
// 4. Resposta esperada: a cada 180 minutos, às 09:00.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

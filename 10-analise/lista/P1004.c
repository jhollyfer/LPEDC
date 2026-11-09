// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1004 · ★☆☆ · Multiplicar somando, com invariante
//
// A máquina de cartão antiga só sabia somar, então multiplicava assim:
//
//   int multiplica(int a, int b) {   // b >= 0
//       int r = 0;
//       for (int i = 0; i < b; i++) {
//           r = r + a;
//       }
//       return r;
//   }
//
// Escreva a função com DOIS assert: um no começo do corpo do for, com o
// invariante (o que vale sobre r e i em toda volta), e um depois do laço,
// com o que vale no término. Teste com 7 x 6, 12 x 0 e 3 x 15.
//
//   Saída esperada:
//   7 x 6 = 42
//   12 x 0 = 0
//   3 x 15 = 45
//
// Dicas:
// 1. Antes da volta i, quantas vezes o a já foi somado em r?
// 2. O invariante é r == a * i. Quando o laço termina, i == b, então o
//    invariante vira r == a * b, que é justamente o que se queria.
// 3. Com b = 0 o corpo nem roda, mas o assert do término ainda vale: r == 0.
// 4. Resposta esperada: a saída acima, sem nenhum assert disparar.
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdio.h>

int main(void) {

    return 0;
}

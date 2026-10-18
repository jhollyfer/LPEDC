// 0013 · Conversão e cast
// Exercício E075 · ★★☆
//
// Na eleição para síndico, a candidata Marta teve 47 dos 130 votos. Mostre
// o percentual dela com duas casas. Depois responda: por que a fórmula
// "votos / total * 100" com dois int dá 0? E por que "100 * votos / total"
// dá 36 e não 36.15?
//
//   Saída esperada:
//   Marta: 36.15% dos votos
//
// Dicas:
// 1. Basta um operando real no lugar certo: 100.0 * votos / total.
// 2. Faça cada fórmula errada passo a passo, da esquerda para a direita.
// 3. Resposta esperada: 36.15%. Em votos / total * 100, 47 / 130 é 0 (divisão
//    inteira) e 0 * 100 = 0. Em 100 * votos / total, 4700 / 130 = 36: certo
//    na parte inteira, mas os decimais somem.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

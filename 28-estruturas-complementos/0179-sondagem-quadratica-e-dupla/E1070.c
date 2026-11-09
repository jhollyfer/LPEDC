// 0179 · Sondagem quadrática e dupla
// Exercício E1070 · ★☆☆
//
// O Cormen prova que, com hash uniforme e fator de carga a < 1, uma busca
// SEM sucesso faz no máximo 1 / (1 - a) sondagens em média, e uma busca COM
// sucesso, no máximo (1 / a) · ln(1 / (1 - a)). Escreva as duas funções e
// mostre a tabela para a = 0.25, 0.5, 0.75, 0.9 e 0.99.
//
//   Saída esperada:
//   carga | sem sucesso | com sucesso
//    0.25 |        1.33 |        1.15
//    0.50 |        2.00 |        1.39
//    0.75 |        4.00 |        1.85
//    0.90 |       10.00 |        2.56
//    0.99 |      100.00 |        4.65
//
// Dicas:
// 1. ln em C é log, de <math.h>.
// 2. Use "%11.2f" para alinhar as colunas.
// 3. Resposta esperada: a saída acima. Com a tabela 99% cheia, procurar o
//    que não está custa 100 sondagens.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}

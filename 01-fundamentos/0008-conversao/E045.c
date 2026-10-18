// 0008 · Conversão e cast
// Exercício E045 · ★★☆
//
// Na eleição para síndico, a candidata Marta teve 47 dos 130 votos. Guarde
// os dois números em variáveis int e mostre o percentual dela com duas
// casas. Depois mostre também o resultado das duas fórmulas que o colega
// tentou antes, com as mesmas variáveis e %d, para ver o estrago de cada
// uma.
//
//   Saída esperada:
//   Marta: 36.15% dos votos
//   votos / total * 100 = 0
//   100 * votos / total = 36
//
// Dicas:
// 1. Basta um operando real no lugar certo: 100.0 * votos / total.
// 2. Faça cada fórmula errada passo a passo, da esquerda para a direita.
// 3. Resposta esperada: as três linhas acima. Em votos / total * 100,
//    47 / 130 é 0 (divisão inteira) e 0 * 100 = 0. Em 100 * votos / total,
//    4700 / 130 = 36: certo na parte inteira, mas os decimais somem.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

// 0065 · Typedef
// Exercício E387 · ★★☆
//
// Na receita de bolo você soma 1/4 de xícara com 1/6 de xícara. Crie o tipo
// Fracao (numerador e denominador inteiros) com typedef e escreva:
//
//   - Fracao simplificar(Fracao f): divide os dois pelo MDC;
//   - Fracao somar(Fracao a, Fracao b) e Fracao multiplicar(Fracao a, Fracao b),
//     que já devolvem a fração simplificada.
//
//   Saída esperada:
//   1/4 + 1/6 = 5/12
//   2/3 * 9/4 = 3/2
//   3/4 + 1/4 = 1/1
//
// Dicas:
// 1. a/b + c/d = (a*d + c*b) / (b*d). Depois simplifique.
// 2. MDC por Euclides (assunto 0038): mdc(a, b) = mdc(b, a % b), mdc(a, 0) = a.
// 3. Uma função pode devolver Fracao: return (Fracao){n, d}; ou monte uma
//    variável e devolva.
// 4. Resposta esperada: a saída acima (1/4 + 1/6 = 10/24 = 5/12).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

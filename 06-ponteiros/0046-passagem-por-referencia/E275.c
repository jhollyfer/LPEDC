// 0046 · Passagem por referência
// Exercício E275 · ★★★
//
// Escreva
//
//   int raizes(double a, double b, double c, double *x1, double *x2)
//
// que resolve a*x*x + b*x + c = 0. A função DEVOLVE quantas raízes reais
// existem (0, 1 ou 2) e escreve as raízes em *x1 e *x2 (quando houver uma
// só, as duas recebem o mesmo valor). Se a for 0, devolve -1 (não é do 2º
// grau). No main, teste as quatro equações e mostre o resultado:
//
//   x² - 5x + 6 = 0   ->  2 raízes: 3.00 e 2.00
//   x² + 2x + 1 = 0   ->  1 raiz: -1.00
//   x² + 1 = 0        ->  nenhuma raiz real
//   0x² + 3x + 1 = 0  ->  não é do 2º grau
//
// Dicas:
// 1. delta = b*b - 4*a*c; x = (-b ± sqrt(delta)) / (2*a). Inclua math.h.
// 2. O valor de retorno diz quantas gavetas a função preencheu; quem chama
//    só lê *x1 e *x2 se o retorno permitir.
// 3. Resposta esperada: 2 raízes (3.00 e 2.00), 1 raiz (-1.00), nenhuma e
//    "não é do 2º grau".
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}

// 0086 · Juntando tudo
// Exercício E516 · ★★★
//
// Um polinômio cabe numa lista encadeada: um nó por termo (coeficiente e
// expoente), em ordem DECRESCENTE de expoente, sem termos de coeficiente 0.
// Escreva neste arquivo:
//
//   insere_termo(lista, coef, exp)   põe o termo no lugar certo; se já
//                                    existe um com esse expoente, soma os
//                                    coeficientes, e se a soma der 0, tira
//                                    o nó
//   soma(p, q)                       devolve um polinômio NOVO com p + q
//   imprime(p)                       no formato do exemplo
//   avalia(p, x)                     o valor do polinômio para esse x
//
// Teste com P(x) = 3x^4 + 2x^2 - 5 e Q(x) = x^4 - 2x^2 + 7x.
//
//   Saída esperada:
//   P(x) = 3x^4 + 2x^2 - 5
//   Q(x) = x^4 - 2x^2 + 7x
//   P + Q = 4x^4 + 7x - 5
//   (P + Q)(2) = 73
//
// Dicas:
// 1. struct termo { int coef; int exp; struct termo *prox; }. A inserção é
//    a ordenada do assunto 0083 com o critério invertido (anda enquanto
//    p->exp > exp), mais o caso p->exp == exp.
// 2. soma: crie uma lista vazia e chame insere_termo para cada termo de p e
//    de q. O caso "soma deu 0" faz o 2x^2 e o -2x^2 sumirem sozinhos.
// 3. imprime: o primeiro termo leva o sinal colado ("-5"); os outros, " + "
//    ou " - " e o valor absoluto. Coeficiente 1 não aparece (x^4), expoente
//    1 vira "x" e expoente 0 é só o número.
// 4. Resposta esperada: a saída acima. 4*16 + 7*2 - 5 = 73. Libere os três
//    polinômios.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
